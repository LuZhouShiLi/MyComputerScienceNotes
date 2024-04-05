# 最小要2核4G

# 1：安装docker

# 2：安装portainer

    docker pull portainer/portainer

```
docker run -d -p 9000:9000 --name=portainer --restart=always -v /var/run/docker.sock:/var/run/docker.sock -v portainer_data:/data portainer/portainer

```

# 3：安装redis ，MySQL  xxl-job

按照bugStack 安装即可

拉取镜像，开放端口，挂载文件

# 4：部署kafak

```
docker pull wurstmeister/kafka
docker pull wurstmeister/zookeeper

```

    docker run -d --name zookeeper -p 2181:2181 -t wurstmeister/zookeeper

```
docker run -d --name kafka \
-p 9092:9092 \
-e KAFKA_BROKER_ID=0 \
-e KAFKA_ZOOKEEPER_CONNECT=换成你的服务器IP:2181 \
-e KAFKA_ADVERTISED_LISTENERS=PLAINTEXT://换成你的服务器IP:9092 \
-e KAFKA_LISTENERS=PLAINTEXT://0.0.0.0:9092 \
wurstmeister/kafka

```

在 Kafka 控制台可以操作配置文件，查看日志，添加Topic

抽奖系统需要2个Topic，在控制台创建；

    cd /opt/kafka

*   `创建topic lottery_activity_partake`：

*
                      bin/kafka-topics.sh --create --zookeeper lottery-zookeeper:2181 --replication-factor 1 --partitions 1 --topic lottery_activity_partake

*   `创建topic lottery_invoice`：

        bin/kafka-topics.sh --create --zookeeper lottery-zookeeper:2181 --replication-factor 1 --partitions 1 --topic lottery_invoice

*   注意 创建Topic的时候，地址需要换成自己zookeeper的地址

**接下来是会出问题的点，但是不影响使用，等出问题再修改即可，因为服务器不同，可能不会出现问题注意：**[kafka容器报内存不足异常（failed; error='Cannot allocate memory' (errno=12)） - xiaolaotou - 博客园 (cnblogs.com)](https://www.cnblogs.com/yfb918/p/10598619.html)

可以先

    docker cp  kafka:opt/kafka/bin/kafka-server-start.sh /data/kafka/kafka-server-start.sh

vim kafka-server-start.sh  修改对应的参数

![](https://gitee.com/liangzicao/imgs/raw/master/202307201510568.png)

再执行

```
docker cp /data/kafka/kafka-server-start.sh kafka:opt/kafka/bin/kafka-server-start.sh

```

最后

    docker start kafka 

即可

# 5：安装nacos ，dubbo2.7 对应的nacos是2.0.3

**注意：nacos默认启动JVM特别大，如果你的云服务器很大，那无所谓**

**如果小，就设置的小一些，但也不要太小，不然会OOM,所以在运行nacos镜像时，我们设置一些JVM参数**

     docker pull nacos/nacos-server:v2.0.3



    #在Mysql数据库中创建库nacos_config,[nacos2.0.3数据库脚本](https://github.com/alibaba/nacos/blob/2.0.3/distribution/conf/nacos-mysql.sql)      
    #运行执行命令
    
    docker run -d \
    -e PREFER_HOST_MODE=当前服务器内网IP \
    -e MODE=standalone \
    -e SPRING_DATASOURCE_PLATFORM=mysql \
    -e MYSQL_SERVICE_HOST=mysql数据库IP \
    -e MYSQL_SERVICE_PORT=mysql数据库端口 \
    -e MYSQL_SERVICE_USER=mysql数据库用户名 \
    -e MYSQL_SERVICE_PASSWORD=mysql数据库密码 \
    -e MYSQL_SERVICE_DB_NAME=nacos配置库名称 \
    -e NACOS_AUTH_ENABLE=true \
    -e JVM_XMS=256m \
    -e JVM_XMX=256m \
    -e JVM_XMN=64m \
    -p 端口:8848 \
    --name nacos-v203 \
    --restart=always \
    nacos/nacos-server:v2.0.3

1.3访问地址

<http://IP:PORT/nacos/> 用户名：nacos 密码：nacos

# 6.在项目中修改对应的IP 端口，密码

# 7打jar包 编写DockerFile上传

# 8 将jar包与DockerFile 放在同一个目录

生成镜像

    docker build -f DockerFile  . -t 镜像名称

运行

    docker run -d  --name xx -p xx:xx  xxx

## **第七步，第八步参考：** [SpringBoot 多模块项目打包部署保姆级教程 - 掘金 (juejin.cn)](https://juejin.cn/post/7223593286698680375)

# 9：对外暴露网关项目的端口，即可访问

注意：如果可以，就加一个nginx

# 10 部署Lottery-ERP

1：打war包

###### 2、拉取镜像tomcat:8

    docker pull tomcat:8

###### 3：运行

    mkdir -p /data/tomcat/webapps
    
    docker run -d -p 8080:8080 \
    -v /data/tomcat/webapps:/usr/local/tomcat/webapps \
    --name=mytomcat tomcat:8

###### 4:  默认是8080端口，记得开放安全组

但是访问会404 ，原因是webapps下是空的

![](https://gitee.com/liangzicao/imgs/raw/master/20230614225116.png)

###### 5：上传war包到 /data/tomcat/webapps

###### 6：做一个准备工作，修改一下tomcat 的server.xml

```
docker cp mytomcat:/usr/local/tomcat/conf/server.xml /data/tomcat/

```

在 \<Host>\</Host>

标签里添加

     <Context path="" docBase="Lottery-ERP" reloadable="true" />

修改完成 把这个文件拷贝回去

    docker cp   /data/tomcat/server.xml mytomcat:/usr/local/tomcat/conf/server.xml 

7：重启tomcat

    docker restart mytomcat

8:访问

    http://服务器ip:8080/index.html

