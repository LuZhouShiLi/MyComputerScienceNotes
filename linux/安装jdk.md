# Linux安装jdk tomcat


## 安装jdk步骤


* 下载jdk8安装包
* 解压安装包 命令：tar -zxvf 包名 -C /usr/local
* 配置环境变量  使用vim命令修改/etc/profile文件 在文件末尾添加如下配置
    * JAVA_HOME=/usr/local/jdk1.8.0_171
    * PATH=```$JAVA_HOME/bin:$PATH```
* 重新加载profile文件  使得更改的配置立刻生效  命令为 source /etc/profile
* 检查安装是否成功  命令为java -version

![图 0](../images/23d0d55a9d2638b73034ea66e43521126da303ead27e74a890ea297a56e1a77c.png)  


## 安装tomcat步骤

* 安装tomcat安装包
* 解压安装包 tar -zxvf apache-tomcat-7.0.57.tar.gz -C /usr/local
* 进入tomcat的bin目录启动服务 命令为sh startup.sh 或者./startup.sh

![图 1](../images/4ff6b8c78af80ffc994f36ba5277ea6b97c9e5e4a3f8ff5f352ca20514900670.png)  


* 验证tomcat是否启动成功  

![图 2](../images/b23ac926816a958dca4fe6a6c00a417ac502b51e1a073db5532fd23c88553068.png)  


&emsp;使用ps -ef命令可以查看当前运行的所有进程详细信息

![图 3](../images/14c831cdbb90259b99a1245fd7f31c87d310f67902cfbe444d65277c7cf24e56.png)  

* 关闭linux的防火墙


![图 4](../images/0a2f3e5d9ac39c3a4dc6a357cbc223f8fbf7c9a4be549de39d3f4ffa00b43c29.png)  



