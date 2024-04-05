# 云服务器中使用docker

## 0.安装Docker

Docker 分为 CE 和 EE 两大版本。CE 即社区版（免费，支持周期 7 个月），EE 即企业版，强调安全，付费使用，支持周期 24 个月。

Docker CE 分为 `stable` `test` 和 `nightly` 三个更新频道。

官方网站上有各种环境下的 [安装指南](https://docs.docker.com/install/)，这里主要介绍 Docker CE 在 CentOS上的安装。

## 1.CentOS安装Docker

Docker CE 支持 64 位版本 CentOS 7，并且要求内核版本不低于 3.10， CentOS 7 满足最低内核的要求，所以我们在CentOS 7安装Docker。

## 1.1.卸载（可选）

如果之前安装过旧版本的Docker，可以使用下面命令卸载：

    yum remove docker \
                      docker-client \
                      docker-client-latest \
                      docker-common \
                      docker-latest \
                      docker-latest-logrotate \
                      docker-logrotate \
                      docker-selinux \
                      docker-engine-selinux \
                      docker-engine \
                      docker-ce

## 1.2.安装docker

首先需要大家虚拟机联网，安装yum工具

```sh
yum install -y yum-utils \
           device-mapper-persistent-data \
           lvm2 --skip-broken
```

然后更新本地镜像源：

```shell
# 设置docker镜像源
yum-config-manager \
    --add-repo \
    https://mirrors.aliyun.com/docker-ce/linux/centos/docker-ce.repo
    
sed -i 's/download.docker.com/mirrors.aliyun.com\/docker-ce/g' /etc/yum.repos.d/docker-ce.repo

yum makecache fast
```

然后输入命令：

```shell
yum install -y docker-ce
```

docker-ce为社区免费版本。稍等片刻，docker即可安装成功。

## 1.3.启动docker

通过命令启动docker：

```sh
systemctl start docker  # 启动docker服务

systemctl stop docker  # 停止docker服务

systemctl restart docker  # 重启docker服务
```

    启动
    [root@CodeGuide ~]# sudo systemctl start docker
    开机启动
    [root@CodeGuide ~]# systemctl enable docker

然后输入命令，可以查看docker版本：

    docker -v

如图：

![](https://gitee.com/liangzicao/imgs/raw/master/20230610222125.png)

## 安装portainer

1：拉取最新的镜像

    docker pull portainer/portainer

2：启动

    docker run -d -p 9000:9000 --name=portainer --restart=always -v /var/run/docker.sock:/var/run/docker.sock portainer/portainer

## 1.4.配置镜像加速

docker官方镜像仓库网速较差，我们需要设置国内镜像服务：

参考阿里云的镜像加速文档：<https://cr.console.aliyun.com/cn-hangzhou/instances/mirrors>

## 1.5：【Docker】使用SSL证书加密远程连接（附IDEA连接教程）

​		**重点：使用[docker](https://so.csdn.net/so/search?q=docker\&spm=1001.2101.3001.7020)-maven-plugin打包SpringBoot应用的Docker镜像时，服务器需要开放2375端口。会引起安全漏洞，被人入侵、挖矿、CPU飙升发生,使用安全传输层协议（TLS）进行传输并使用CA认证即可。**

如果只是自己的虚拟机做快速演示，比如idea连接docker，可以直接开启端口，无需加密，节省时间

```
vim /usr/lib/systemd/system/docker.service
将
ExecStart=/usr/bin/dockerd -H fd:// --containerd=/run/containerd/containerd.sock
改为
ExecStart=/usr/bin/dockerd -H fd:// --containerd=/run/containerd/containerd.sock -H tcp://0.0.0.0:2376
然后刷新配置，重启Docker
systemctl daemon-reload && systemctl restart docker

```

公网环境严禁直接暴露端口，机器会被端口扫描！

## 1.编写shell脚本，命名为docker\_cert.sh

开头的4个变量请自行修改

```shell
#!/bin/sh

ip=docker宿主机ip
password=eY9bU0cQ8mS8oX3r
dir=$dir # 证书生成位置,需要自己修改 ,/root/docker/cert
validity_period=10    # 证书有效期10年

# 将此shell脚本在安装docker的机器上执行，作用是生成docker远程连接加密证书

if [ ! -d "$dir" ]; then
  echo ""
  echo "$dir , not dir , will create"
  echo ""
  mkdir -p $dir
else
  echo ""
  echo "$dir , dir exist , will delete and create"
  echo ""
  rm -rf $dir
  mkdir -p $dir
fi

cd $dir || exit
# 创建根证书RSA私钥
openssl genrsa -aes256 -passout pass:"$password" -out ca-key.pem 4096
# 创建CA证书
openssl req -new -x509 -days $validity_period -key ca-key.pem -passin pass:"$password" -sha256 -out ca.pem -subj "/C=NL/ST=./L=./O=./CN=$ip"
# 创建服务端私钥
openssl genrsa -out server-key.pem 4096
# 创建服务端签名请求证书文件
openssl req -subj "/CN=$ip" -sha256 -new -key server-key.pem -out server.csr

echo subjectAltName = IP:$ip,IP:0.0.0.0 >>extfile.cnf

echo extendedKeyUsage = serverAuth >>extfile.cnf
# 创建签名生效的服务端证书文件
openssl x509 -req -days $validity_period -sha256 -in server.csr -CA ca.pem -CAkey ca-key.pem -passin "pass:$password" -CAcreateserial -out server-cert.pem -extfile extfile.cnf
# 创建客户端私钥
openssl genrsa -out key.pem 4096
# 创建客户端签名请求证书文件
openssl req -subj '/CN=client' -new -key key.pem -out client.csr

echo extendedKeyUsage = clientAuth >>extfile.cnf

echo extendedKeyUsage = clientAuth >extfile-client.cnf
# 创建签名生效的客户端证书文件
openssl x509 -req -days $validity_period -sha256 -in client.csr -CA ca.pem -CAkey ca-key.pem -passin "pass:$password" -CAcreateserial -out cert.pem -extfile extfile-client.cnf
# 删除多余文件
rm -f -v client.csr server.csr extfile.cnf extfile-client.cnf

chmod -v 0400 ca-key.pem key.pem server-key.pem

chmod -v 0444 ca.pem server-cert.pem cert.pem

```

备注：删除多余文件后，该目录下剩余：
ca.pem CA机构证书
ca.srl
ca-key.pem 根证书RSA私钥
cert.pem 客户端证书
key.pem 客户私钥
server-cert.pem 服务端证书
server-key.pem 服务端私钥

最后为了保护 key 文件，需要移除其写权限，并保证只有自己可读:

```text
chmod -v 0400 ca-key.pem server-key.pem client-key.pem
```

另外证书是任何人都可以访问的:

```text
chmod -v 0444 ca.pem server.pem client.pem
```

## 2*将unix换行符转换为windows换行符，不然报错*

```shell
yum install dos2unix

dos2unix docker_cert.sh
```

## 3 执行脚本

    sh docker_cert.sh

## 4：编辑docker.service配置文件

    vim /usr/lib/systemd/system/docker.service

**找到ExecStart = 开头的一行代码，将其替换为如下内容：**

**\$dir 需要跟脚本中定义的一样**

    ExecStart=/usr/bin/dockerd \
    --tlsverify \
    --tlscacert=$dir/ca.pem \
    --tlscert=$dir/server-cert.pem \
    --tlskey=$dir/server-key.pem \
    -H fd:// -H tcp://0.0.0.0:2376 

备注：此处指定了ca证书、服务端证书和服务端密钥，端口设置为：2376（docker默认端口）

## 5.刷新配置，重启Docker

    systemctl daemon-reload && systemctl restart docker

虚拟机记得关闭防火墙；云服务器配置下安全组，放开2376端口。

## 6.测试连接

在服务器本地测试 ，切换到证书目录

    docker --tlsverify --tlscacert=ca.pem --tlscert=cert.pem --tlskey=key.pem -H tcp://你的ip:2376 version

![](https://gitee.com/liangzicao/imgs/raw/master/20230610222142.png)

## 7：配置docker

每次执行 `docker` 命令时都提供证书是很麻烦的，我们可以把证书和密钥放在 `~/.docker` 目录下，并设置 `DOCKER_HOST` 和 `DOCKER_TLS_VERIFY` 环境变量，这样默认就走 TLS 的方式。

注：切换到证书所在的目录

```text
mkdir -p ~/.docker
cp -v {ca,cert,key}.pem ~/.docker
```

1.  打开终端窗口，执行以下命令打开 `~/.bashrc` 文件：

        vi ~/.bashrc

2.  在文件末尾添加以下内容：

        export DOCKER_HOST=tcp://$HOST:2376 DOCKER_TLS_VERIFY=1

3.  保存并退出文件，执行以下命令使配置生效：

        source ~/.bashrc

4： docker ps 测试

    docker ps 

## 8：IDEA连接docker

创建一个目录dockere-cert存放证书，将ca.pem、cert.pem、key.pem三个文件放到该目录即可

![](https://gitee.com/liangzicao/imgs/raw/master/20230610222205.png)

使用maven插件+dockerFile 一键构建镜像

## 9：使用portainer连接TSL

​	[(15条消息) Portainer添加远程Docker（TLS加密）\_portainer连接远程docker\_勤奋的树懒的博客-CSDN博客](https://blog.csdn.net/qq_42259469/article/details/128406535)

# 安装docker-compose

### Compose 简介

Compose 是用于定义和运行多容器 Docker 应用程序的工具。通过 Compose，您可以使用 YML 文件来配置应用程序需要的所有服务。然后，使用一个命令，就可以从 YML 文件配置中创建并启动所有服务。

### Compose 安装

<https://github.com/docker/compose/releases/tag/v2.18.1> ## 去官网下载，然后上传到 /usr/local/bin下

![](https://gitee.com/liangzicao/imgs/raw/master/20230618230005.png)

下载完成之后：改名

    mv docker-compose-linux-x86_64 docker-compose

将可执行权限应用于二进制文件：

```shell
sudo chmod +x /usr/local/bin/docker-compose
```

创建软链：

```shell
sudo ln -s /usr/local/bin/docker-compose /usr/bin/docker-compose
```

测试是否安装成功：

```shell
docker-compose --version

```

**注意**： 对于 alpine，需要以下依赖包： py-pip，python-dev，libffi-dev，openssl-dev，gcc，libc-dev，和 make。
