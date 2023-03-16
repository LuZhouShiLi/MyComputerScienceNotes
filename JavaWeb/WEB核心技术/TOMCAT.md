# Tomcat

## 服务器

 ![图 2](../images/b7498c394e17f76d014a58f40eb40d76002d6f5d325514b13b7c44a4e9fc8d9f.png)  

![图 3](../images/39634fd2b56bd749ec52462caa8faa46685c12fc1b1747d12c12d27940d59fab.png)  

## Tomcat下载和安装

![图 4](../images/fc22ce1ee507e21cab40c5beac16d8b97528138e24fa778034818f85d2bf126e.png)  

将下载好的文件解压即可

## Tomcat的目录结构

![图 5](../images/da61cb23ab4247c06af8ba95404cdade2056fa4416d8998d0cad0b4490973fef.png)  

## 基本使用
 
![图 7](../images/036adf1d69ff93c17f1a02d7aec226255708b4dea67bd3e6a57cd8955e884b33.png)  

* 这里在webapps目录下面创建一个hello文件夹，并且在hello文件夹下面创建hello.html

![图 8](../images/f705278d4494e0ff737e35edd8075306f76799fa2e82292dcf5bf508bb65e00d.png)  

* 在浏览器地址栏中输入相应的地址 回车

![图 9](../images/798ea8c57f47fa2508799fbffb9b8a78855717b94f44166b6a0f01372fad0b35.png)  

## 控制台乱码的问题

![图 10](../images/14a42ec0aea0917eb723ff806b6e7c656a8ae5e6f63bada3c2a80da03679afeb.png)  

**将utf-8改成windows默认的GBK**

![图 11](../images/e8dae8f52777fb1f09fa8a05d28d99b5ae647c51be3cceb31855771d15529703.png)  

![图 12](../images/4c008a84cde684a757a6deb2ba11eabf92c50b6a4c5b216cdfde5143ef801dcf.png)  


## IDEA集成Tomcat

* 步骤一
![图 13](../images/80f2bfe7ac6d9ebe7e074bba8c9d8968585b703a710acd3dc7327c3b76fc008a.png)  

* 步骤二
![图 14](../images/c7aa5bd17db0a348605aee8078442bcb6ce50d4bddfdd25cb671f273ebfc3cb5.png)  

* 步骤三
![图 15](../images/fbff71a5b36d8a1cb285e20ae4602254b8cd2cb31a53a751048320bc874a93b4.png)  


* 创建Java web工程

这里选择的是IDEA 2022版本，首先创建一个普通的工程。

![图 19](../images/447c65d1f0017ec76cbd0c74bdfd460e2e3944f859c20c51bcfd5815a9903725.png)  


![图 20](../images/df07b2609b7c4829d801c5ac1f21d3af79f358007a3a50bc167896e9bd3f6c39.png)  

部署tomcat

![图 21](../images/0c8603876998161dd39de1fccb887bdc01c2d5d40296a7db51ea0dac6072fb67.png)  

![图 22](../images/7914a4685d3d48e91808c2d553e033f3dec000894852582a6611d5b5c7f5e9ae.png)  

## JavaWeb项目的目录结构

![图 23](../images/ef89e6f77b9ddb655df6f98b5a1de1243bcd103941bf52a107e1ccf788648c8d.png)  

## Tomcat-idea发布项目

* 步骤一

![图 24](../images/eed8223f74abd0a2649d41c2af379568488ba84ffa819c882f9f2886823c89af.png)  

* 步骤二

![图 25](../images/ef54121cf82786dba1ef8d78d9d93a323c6c1ca9da4ee6f20bd9d41f2e02936d.png)  

确认war包是否存在，可以自行设定访问路径

* 步骤三

![图 26](../images/42d6a9a1a26726922eee9308d6a26529b7ae8b1169ebbcbb953840137fd42df0.png)  

关联默认浏览器，选定8080端口

* 步骤四

![图 27](../images/dc706d34586ed0eb9de7202c45d81a5c13d52bdd81120610c9f9b2e1b21af3e1.png)  

* 步骤五
![图 28](../images/226678e594835b018b704b13cbeb98c26273eec638f2c0cd33950b19a7549d92.png)  

## Tomcat-WAR包发布项目

* 步骤一: 这里有一个.  代表当前路径

![图 29](../images/2152e613b853ad93a4466481079bc5fe993fc83c9b229063435638624d25878f.png)  


* 步骤二

![图 30](../images/c447ef9542776fe6525c7bc0a3b93a5609918929d5161b997901cb39068083d3.png)  


* 步骤三

![图 31](../images/60fdf26256b6f4e045430b65a27dacbf61665953e2af1458685861ac93b3227f.png)  



## Tomcat配置文件的介绍

* 主配置文件server.xml,该配置文件在tomcat的conf文件夹下面

![图 32](../images/248f4a045a8390f8141fd02dda7f5ba6ea8a0dc5b55ebea87788d1cbe1415177.png)  

![图 33](../images/a9631fd2b96d7d92da156c2a4d2679b605865339ce32c7128ce09580547e0aeb.png)  

8080端口：tomcat服务默认端口号，访问url地址之后必须手动写8080

80端口：HTTP协议采用的端口号。访问url地址之后不用写80


## Tomcat配置虚拟目录

作用：可以发布任意目录下的项目

先找到tomcat文件夹下面的conf文件夹下面的server.xml
![图 34](../images/523312ed494a15f113258056d874ca92a2f12ee1a3238a3669c5b95967809c61.png)  

## Tomcat配置虚拟主机

作用：可以指定访问路径的名称

![图 36](../images/68b4c8aa3280f05a567c99728210296bc4a8ab4bc64ffba6c574f585513d518e.png)  

* 编辑server.xml配置文件，找到engine标签 添加内容，这里添加webapps下面的myweb项目

![图 37](../images/7e15cde0fff127e611b443030e2c3770b78535da13ea9372a21bc68809721584.png)  

解释：

* name属性：访问虚拟主机的名称
* appBase属性：项目存放的路径
* unpackWARs属性：是否自动解压war包
* autoDeploy属性：是否自动发布

* 修改host文件
![图 38](../images/8d9c4137057d7ccb511813e0f8bd07b022b0712ee60cdda8a9086b40e95afa4f.png)  

这里注意下，修改host需要文件权限，更改方法如下

![图 39](../images/0fd3e828a0a27a4f3f0735a3d7716235a7b3141c5cde4b08b7f2752f8d374b50.png)  


**在地址栏中输入www.myweb.com:8080,回车**

![图 40](../images/46c175f7de0a2b57fa595f331e14a5f719c352bef4d25ffd40ae739d27ad3d58.png)  

