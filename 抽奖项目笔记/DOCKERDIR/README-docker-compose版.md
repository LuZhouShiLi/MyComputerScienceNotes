# 前期准备：

# 下载docker-ce

#

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

# 下载portainer

## 1：拉取最新的镜像

    docker pull portainer/portainer

2：启动

    docker run -d -p 9000:9000 --name=portainer --restart=always -v /var/run/docker.sock:/var/run/docker.sock portainer/portainer

## 1.4.配置镜像加速

docker官方镜像仓库网速较差，我们需要设置国内镜像服务：

参考阿里云的镜像加速文档：<https://cr.console.aliyun.com/cn-hangzhou/instances/mirrors>

# 下载docker-compose（最好是去github直接下载，然后上传，下载一个2 .18.1 版本的，连接在下面）

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

# 打包放到对应的地方

**注意 ： 要将yml配置文件做对应的修改，这里我用的都是ip地址，应该可以用服务名称，我没有尝试**

lottery-AP打成jar包，改名Lottery-API.jar 放到 lottery/api/jar

lottery 打jar包，改名Lottery.jar   放到 lottery/draw/jar

lottery-erp 打war包，改名 Lottery-ERP.war ,放到 lottery/erp/webapps

# 需要自己配置的地方

#### 1：docker-compose.yml

16 行
54 行

#### 2： nacos/conf/application.properties

5行

#### 3： mysql/Dockerfile

7 行

***

# 启动：

## **将此文件夹上传**

##### 1：可以通过sh脚本运行

```bash
#启动基础镜像
sh deploy.sh base
#启动业务镜像
sh deploy.sh services
```

##### 2: 在docker-compose 的目录下，一键全部运行

    docker-compose up  -d 

## 有几个问题：

##### 1：sql表无法自动导入，我写了命令，但是不会执行

**answer:** sql也需要提前挂载


##### 2： lottery/erp/conf 挂载的的tomcat的 /usr/local/conf/server.xml 需要自己提前配置，目前文件里的是我已经配置好了，放在这里的。

在 \<Host>\</Host>标签里添加

     <Context path="" docBase="Lottery-ERP" reloadable="true" />



##### 3 : 缺少xxlj-jop 的配置，有想法可以加上

**answer**:xxl-job 官网有答案

##### 4：kafka的主题创建通过portainer连接到容器内手动创建

抽奖系统需要2个Topic，在控制台创建；

    cd /opt/kafka

*   `创建topic lottery_activity_partake`：

*
                              bin/kafka-topics.sh --create --zookeeper lottery-zookeeper:2181 --replication-factor 1 --partitions 1 --topic lottery_activity_partake

*   `创建topic lottery_invoice`：

        bin/kafka-topics.sh --create --zookeeper lottery-zookeeper:2181 --replication-factor 1 --partitions 1 --topic lottery_invoice

**answer**可以写一些脚本命令，之后挂载，再让 compose 执行
