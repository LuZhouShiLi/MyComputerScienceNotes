# MyEclipse下编写web应用程序

JavaWeb项目是在Tomcat上运行，我们使用MyEclipse是来编写JavaWeb项目，但是最终发布到Tomcat的webapps目录下。
* MyEclipse是开发环境
* Tomcat是运行环境


打开MyEclipse 选择新建->web project
![图 1](../../images/019c125d21aa115ca68972f910385d782aaae9ef5810bee441f3ede1b2749d2d.png)  

创建好的工程如下：
![图 2](../../images/cd33be1fdb3cb7a17d9b0ff09a2cfb6d2aaf87d7a629fd9690acc248a1d62928.png)  


在Index.jsp中添加一个标签
![图 3](../../images/510873dfed05f5fe5d2c8140c12bdd71f8aed2445592b2cdeb92816a9a964ef4.png)  

将tomcat关联到Myeclipse

1.选择windows->preferences 搜索tomcat，配置jdk
![图 2](../../images/7bac22f29d792f6d6771b260de9191e315d96be99e3d131fa0fe0d7da571bff5.png)  

2.将Launch调成runmode
![图 3](../../images/d78b74a072b0f23766b275085c326de179b5cb56340369998bb82065311d977b.png)  

3.最后，选择enable,将tomcat关联起来，点击ok
![图 4](../../images/2650d45bc5954b28102bd85a55b2a389e4e0c1c9326d20dabba5c3aa2f148086.png)  



4.选择  MyEclipse 选择Add and Remove Project Deployments
![图 7](../../images/ff9b4b1842dd68b5e4ce992f2b613adbfda56ea828f50ff7162784989b7a0b8f.png)  

5.点击add 将项目添加到tomcat中
![图 6](../../images/4aad96fe1a0654e774a7e09a35393a5b26395fea582f2c1bbc0c38115fc4761e.png)  

6.运行tomcat
![图 5](../../images/2109fec8836281dc35d84eef28ce418c8ceb0fd41cd0415c50fa4a8bcb81ab13.png)  

7.打开浏览器 输入
![图 8](../../images/2966fe88c7b6049eb00628bdf668d316ec14a27a9a079f70fc097a86b9e88c59.png)  
