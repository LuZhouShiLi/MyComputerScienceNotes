# Nacos使用


## 快速使用

* 添加依赖
* service服务模块添加nacos的client依赖  注释eureka依赖


![图 1](../images/03fa82ba27bca525805f0ae67f618603a1fc3e32b88522f627eff5e8b867c72a.png)  

* service服务模块中的yml配置文件 注释eureka地址  添加Nacos地址  服务启动之后，将注册到Nacos服务端
![图 2](../images/42145244547f2e5275ed3d01c537113d255f4fb1cf641289d0a3cca10c01631a.png)  

* 可以看到有两个服务模块已经被注册到nacos
![图 3](../images/312e77575d74626382476361f4959f2e41240fd861c7b0d79108990590a0dbe5.png)  
