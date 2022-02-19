# idea中创建javaweb项目并发布

## 一、创建javaweb项目步骤

* 在idea中创建一个工程，选择java enterprise 
* 配置好jdk tomcat
* 选择javaee版本 默认最新的javaee8
* 选择web application 勾选create web.xml
  
简单介绍目录：
![图 1](../../../images/6a8495525885fbb90e4fb95e5bbb5eeea54d969cc8f98a4879f7767413d7843e.png)  

src:保存源代码
web:放置 html css javascript 图片
web-inf:存放相关配置

## 二、将idea创建的javaweb项目进行发布
1. 选择run->edit Configurations
![图 2](../../../images/391a05da8ae2653ddbd08451cb74f80f1a56fa141e18d9dc1228b38a3a5643f7.png)  

2. open browser中的浏览器默认为谷歌浏览器，web项目启动之后会自动打开浏览器，下面就是网址
![图 4](../../../images/aa8a12ba4721ee31ed16d45f5ca73b88b7efe88173e84307fb028463c1b5d11e.png)  

3. 打开deployment 可以看到创建的javaweb项目自动被压缩成一个war包，可以通过下面的application context更改web项目访问路径
![图 5](../../../images/afa62551d91444479cba1a0bb403730837e6109f64005d0051d568114beace67.png)  

3. 勾选两个update resources 意味着当我们更新web项目，页面会自动进行更新
![图 6](../../../images/0f23b849b28f53169850a644ba44c6f6857e98292b9554b01945cf99d65fe3a9.png)  

4. 点击确定之后，可以看到web项目被自动打包成一个压缩包
![图 7](../../../images/37527708ff3de666ad3c5f4ebee08ad54be0f279451c50dfedc50f41fac73fb2.png)  

5. 点击左边的运行按钮，项目开始运行，右边一开始会有许多红色信息，不是报错，当看到connect server 说明项目启动成功，浏览器自动打开
![图 8](../../../images/1f00882e725bbc4fa5e548580f3e3e025b6a7505cc6c1a099b2fc0ffab8f5ee5.png)  
![图 9](../../../images/1b7978aba0b0e48b6993f81fa39670ec5d4cee859a977416bcfc9b6466dafb7c.png)  


6. 修改访问路径
还是选择run-> edit configurations
![图 10](../../../images/9188725b6ef82b533190e31e8a1bdab13e1fe57a881bb64499049b04e511a63c.png)  
![![图 10](../../../images/9188725b6ef82b533190e31e8a1bdab13e1fe57a881bb64499049b04e511a63c.png)  
 1](../../../images/d7738a98ca1f8c92df72a85da36c1856144e3abec9a3c2373acbee8e3a4b258a.png)  

可以看到访问路径发生了变化
![图 12](../../../images/7128968f86de17d583f1abdf2eb4b51e39a48c85e1033c64317c1ea86273a4ed.png)  

7.关于为什么显示$end$

打开index.jsp 可以看到一个类似于index
![图 13](../../../images/c5b0ac606ec9915d97c771752c5412b3280ce26e34dca475122ee2f333f1b233.png)  

修改标签
![图 15](../../../images/d168e9519c1810ce33f14eff7d4d21106292775d7298d39f422b2ae22712a33f.png)  

![图 14](../../../images/2b89f67e3c9f6ea44e2ce200220f51f89241ced80fcf6ce4a01458289b820ad3.png)  


## 三、通过war包将tomcat项目进行发布

1. 在项目的web路径下面打war包：jar -cvf javaweb01.war(注意是你创建的web项目)

web目录右键，选择show in explorer 看到我的web项目
![图 17](../../../images/cbfa8b24ea27f359e3a35c8aecd90ceadc4150f28df16a579da2e1e44ce84cd7.png)  

在这个目录下进行打包
![图 16](../../../images/283a0368b2103f13310101925cbd361d672029485171e41de1c87e223cc94706.png)  

输入如下命令进行打包
![图 18](../../../images/02320928fd9b226c68c1893e8df938ddf920f78652c7724fc7234b53b85f44c1.png)  


2. 将打好的war包剪切到tomcat的webapps路径下面
![图 19](../../../images/e0e673e5578412978b6389221b83051e7ab3bf5b6b3bd89a7532f4a36995336c.png)  


3. 启动tomcat服务，自动解压war包,然后打开startup.bat 输入网址，会发现自动解压war包
![图 20](../../../images/299b1c112c923850e01a4ad15743d5dcf93c0e10911a70673dfe2fce255ef3e7.png)  
