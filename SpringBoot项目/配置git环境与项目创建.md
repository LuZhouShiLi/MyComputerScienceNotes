# 配置git环境和项目创建

## 项目的逐步细分

* 匹配界面：需要用微服务
* 实况直播：webSocket  用户和服务器可以双向发请求
* 真人PK:websocket协议
* 对战列表-录像回放
* 排行榜：bot列表
* 用户中心：注册 登录  我的bot  bot的记录


## 配置git环境

作用：存档；同步不同机器的代码

以下是简单的git操作：

* 初始化仓库：git init
* git status test.txt -- 查看状态  (红色 表示没有添加到暂缓区)
* git add test.txt  --或者git add  (添加到暂缓去,提交所有文件到暂缓区)
* git commit test.txt  
//这时候会进入编辑模式,让我们添加做了哪些事情,写完之后,esc 退出编辑模式,:wq 保存并退出
* git commit -m "初始化项目"  //直接提交 
* git push  推送到github上面
* 给项目地址起别名：git remote add 别名  项目地址
* 推送：git push -u 项目别名 main(分支)


## 创建项目后端

![图 4](../images/333c403d09f73e18b64bd05ad2be2da6b61a5c18f256d6b8fcdafcaad15657f9.png)  


下载依赖：注意jdk与springboot 版本的问题

![图 2](../images/2d88e61f8de1cdb6d5f35e320d8fea09ae4fd9a02c471bfc9b36ca597ea1b2b4.png)  

找到项目的入口函数，启动项目

![图 3](../images/56711eed6c65c3a2bfff154d819d05e4e07a2af5fe8f1d4dc91bf81067892fa0.png)  

地址栏中输入：localhost:8080 出现以下情况，说明项目启动成功：

![图 5](../images/b4b0907abcce16f28b16e0ab8c356beda1b2b7a92af87addcede08c378ac5043.png)  

## 前后端不分离写法-url访问路径解析资源

**浏览器输入地址的时候记得最后加上/**

![图 6](../images/31c91fe40ed5f503400c1c1eef91aaef5440ee0b592759727ca4ed628e452763.png)  

这里访问的资源：pk目录下面的index.html，那么浏览器就会请求后端，contrroller下面的pk目录下的indexController类，根据index找到对应的注解，从而找到相应的函数，从而返回对应的资源

![图 7](../images/0d3484b9e7ba1f6895af314b95a5763f1ed995446ab86586ec64a1c73ea0596c.png)  

## 安装vue

* 安装Node.js
* 安装vue/cli：npm i -g @vue/cli
* 安装指定的vue版本：npm i -g @vue/cli@5.0.4
* 启动vue自带的图形化项目管理界面 vue ui

![图 8](../images/3f0f2ee1a831e6c6abd220b264c76b3beb28122e967fe458f6bbb2929970e9b3.png)  

* 在指定位置创建前端的文件夹

![图 9](../images/4005ebd08db2533b39ad920ccedf8353240e1eed1c30872a765df3c03297db8d.png)  

* 选择 Vue3 创建项目
![图 10](../images/633afe37b5409a8c2bfa731ca313af3e681c81f740354ccab4d0a13a600bb1dd.png)  

* 安装两个插件
![图 11](../images/e0971dacc9383c8331bf0d70503d1043b735d9f33f9766dce5d58b7558883353.png)  

* 安装jquery依赖
![图 12](../images/edb492a0ab2b8afbd87865f1751c47fdd18efbd4a4242a1155640d4aec0b9b03.png)  

* 安装bootstrap依赖

* 点击运行
![图 13](../images/329ecfb1e49018d0127b62cdc6b4640af04c376cb74a045ea97e4e51fff4fdb5.png)  

* 点击输出，点击localhost:8080
![图 14](../images/afd7cbf46b85bccc66afcc7ba712e9f4781c8425e7db61b03581292476bee2fb.png)  



## vue文件

对于每一个vue文件，style标签用来写css,script用来写js,template用来写html

![图 15](../images/b8c3053ed4efcdc04e8125a34114b012a11be65812770056e63953cbb8f3dbae.png)  


## 后端解析数据发送到前端页面解析出来

```vue
<template>
  <div>
    <div>Bot昵称:{{bot_name}}</div>
    <div>Bot战力:{{bot_rating}}</div>
  </div>
<router-view></router-view>
</template>

<script>
import $ from 'jquery';
import {ref} from 'vue';// 定义变量之前需要实现导入ref

export default{

  // 定义变量 bot_name bot_rating
  name:"App",
  setup:()=>{
    // 定义两个变量 存放后端解析出来的数据
    let bot_name = ref("");
    let bot_rating = ref("");

    // 将后端信息提取出来  先定义好后端的解析路径 采用get方式进行获取  打印成功的消息
    // ajax请求 返回resp消息 包含后端的数据
    $.ajax({
      url:"http://localhost:8080/pk/getbotinfo/",
      type:"get",
      success:resp=>{
        // console.log(resp);
        bot_name.value = resp.name;
        bot_rating.value = resp.rating;// 解析后端的数据
      }
    });
    // 返回后端获取的数据给上面的div标签
    return {
      bot_name,
      bot_rating
    }

  }
}
</script>


<style>

</style>


```

![图 16](../images/fa7a1422871856cc9521734daa6898742816f7f7f920ac30a83785eed12c89f4.png)  


