# git提交报错

```java

git报错：Failed to connect to github.com port 443: Timed out
```

## 解决办法

* 使用ping github.com 发现ping不通
* 修改hosts文件，让主机跳过DNS服务器 直接根据hosts配置信息进行替换域名
* 在ipaddress.com查询Github真实IP地址

![图 0](../images/7e635bea4fe5809d9b56e7e807ac1a5fb6ad16bb4b18c87d14ba590716838cac.png)  

* 打开hosts文件 添加配置 一般位于C:\Windows\System32\drivers\etc\hosts

![图 2](../images/32683cbe96a740b225d65f2b4b228945697b29805db55c015bb022e58cacd7eb.png)  
