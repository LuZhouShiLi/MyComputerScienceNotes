# 标准的JavaWeb应用的目录结构

1.在Tomcat webapps下创建目录结构，起名为hello1
2.创建hello1/WEB-INF目录：这个目录用户无法通过浏览器直接访问，可以把一些受保护的文件放到这个目录下
3.创建hello1/WEB-INF/classes目录：当前项目的classes文件
4.创建hello1/WEB-INF/lib目录：当前项目所需的jar包
5.创建hello1/WEB-INF/web.xml文件：当前项目的“部署描述符文件”
6.创建hello1/index.html文件；当前项目的页面，不能把它放到WEB-INF下，不然用户没有办法进行访问

# Tomcat配置外部应用

* 找到tomcat中的server.xml文件
* 在host中添加如下配置：```<Context path="/项目名称" docBase="项目存放路径"/>```
* path:制定项目的名称
* docBase:制定项目的真是存放路径