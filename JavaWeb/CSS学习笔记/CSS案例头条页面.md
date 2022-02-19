# 头条页面

## 实现步骤-顶部和导航条
* 创建一个html文件
* 创建顶部div标签
* 通过三个a标签实现登录、注册、更多三个超链接
* 设置顶部样式（背景色 行高 文字对齐方式 字体大小 超链接颜色 悬浮 和去除下划线）
* 创建导航条div标签
* 通过img标签引入logo图片
* 通过两个a标签实现首页、科技两个超链接
* 通过font标签实现正文两个字的显示
* 设置导航条的样式（行高）


## 实现步骤-左侧分享、中间正文、右侧广告图片
* 创建左侧分享div标签
* 通过a标签嵌套img标签和span标签实现图片和文字的显示
* 设置左侧分享样式（宽度、文字水平对齐、浮动、图片大小、文字垂直对齐）
  

## 实现步骤-底部页脚
* 创建底部页脚div标签
* 通过a标签实现超链接
* 设置页脚样式（浮动、背景色、文字水平对齐、行高、超链接颜色）


```html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>头条页面</title>

    <link rel = "stylesheet" href = "../css/02.css"/>


</head>
<body>
  <div class = "top">
    <!--顶部登录注册更多 网址设置为#不进行跳转 两个空格-->
    <a href = "#">登录&nbsp;&nbsp;</a>
    <a href = "#">注册&nbsp;&nbsp;</a>
    <a href = "#">更多&nbsp;&nbsp;</a>
  </div>

  <!--导航条-->
  <div class = "nav">
      <img src = "../img/logo3.png"/>
      <a href = “#”>首页&nbsp;&nbsp;</a>/
      <a href = “https://www.baidu.com” target = _blank>科技</a>/
      <font color = "grey">正文</font>
      <hr/>
  </div>


    <!--左侧分享 在超链接图片中设置图片还有文字  将其嵌套设置成超链接-->
    <div class = "left">
        <a href = "#"><img src = "../img/pinglun.png"/><span>&nbsp;评论</span></a>
        <hr/>

        <a href = "#"><img src = "../img/repost.png"/><span>&nbsp;转发</span></a><br/>
        <a href = "#"><img src = "../img/weibo.png"/><span>&nbsp;微博</span></a><br/>
        <a href = "#"><img src = "../img/qq.png"/><span>&nbsp;空间</span></a><br/>
        <a href = "#"><img src = "../img/wx.png"/><span>&nbsp;微信</span></a><br/>

    </div>

      <!--中间正文-->
      <div class = "center">

          <!--标题-->
          <div>
              <h1>2万亿蚂蚁暂停上市、退钱的内幕，今天终于能说了，背后博弈的水太深</h1>
          </div>

          <!--作者信息-->
          <div>
              <i><font>作者：HFUT 2088-08-08</font></i>
              <hr/>
          </div>

          <!--二级标题-->
          <div>
              <h3>顶层人士之间的博弈，步步惊心，招招要命。稍有相悖，便会坠入万丈深渊</h3>
          </div>


          <!--正文内容-->
          <div>
              <p>10月24日，马云在CF40论坛演讲，他炮轰中国金融当铺思维，指责因为P2P否定了互联网金融，声称做没有风险的创新就是扼杀创新

                  <!--有序列表-->
              <li>台下坐着的，可是周小川、易纲以及四大行负责人等金融界大佬。</li>
              <li>中国金融系统最有权势的人，都被马云指着鼻子骂了一通。最终，马云的蚂蚁金融上市被突然暂停，2万亿就此泡汤。更有专家在微博表示，蚂蚁金融可能永远也上不了市</li>
              <li>英国一家举世闻名的金融媒体Financial Times，将这件事与美国总统大选放在了一起，同在头版大事件中</li>
              </p>
              <img src = "../img/image6.png"  width = "100%"/>
              </p>
              <b>问题是，马云傻吗？</b>
              <p>
              <p><b>照着稿子念的演讲，他身后的智囊团为什么会提出如此激进的观点？马云一定是故意而为之</b></p>
              <p><b>近期，一篇揭幕顶层人士博弈的文章流出，直接回答了上述问题。看完以后，不禁觉得政商高层的水真是太深了，可谓颠覆常人认知观。</b></p>

          </div>

      </div>

      <!--右侧广告图片-->
      <div class = "right">

          <img src = "../img/ad1.png"  width = "100%"/>
          <img src = "../img/ad2.png"  width = "100%"/>
          <img src = "../img/ad3.png"  width = "100%"/>

      </div>


    <!--底部页脚超链接-->
    <div class = "footer">
          <a href = "#">关于我们</a>&nbsp;
          <a href = "#">帮助中心</a>&nbsp;
          <a href = "#">诚聘英才</a>&nbsp;
          <a href = "#">高价回收</a>&nbsp;
          <a href = "#">法律声明</a>&nbsp;
          <a href = "#">知识产权</a>&nbsp;
          <a href = "#">欢迎举报</a>&nbsp;
    </div>


</body>
</html>
```


```css
.top{
    background:black;
    line-height:40px;
    text-align:right;
    font-size:20px;
}

/*使所有的超链接没有下划线*/
a{
    text-decoration:none;
}

/*后代选择器 对div标签中嵌套标签a标签进行样式控制 使超链接成为白颜色*/
.top a{
    color:white;
}

/*设置导航条的样式  类选择器*/
.nav{
    line-height:40px;
}


/*伪类选择器 控制鼠标悬浮时的颜色*/
a:hover{
    color:red;
}

/*左侧分享样式的控制  类选择器*/
.left{
    width:20%;
    /*文字水平居中对齐*/
    text-align:center;
    /*左侧浮动效果*/
    float:left;
}

/*左侧分享图片样式   后代选择器  将left属性标签中的所有img标签设置样式*/
.left img{
    width:90px;
    height:38px;
}

/*左侧文字 垂直居中  将left标签中的所有span标签进行设置*/
.left span{
    vertical-align:50%;
}

/*中间正文样式*/
.center{
    width:60%;
    float:left;
}

/*右侧广告图片样式*/
.right{
    width:20%;
    float:left;

}

/*底部页脚超链接样式*/
.footer{
    clear:both;  /*清除浮动效果*/
    background:blue;  /*背景色*/
    text-align:center; /*文字水平居中对齐*/
    line-height:25px;  /*行高*/

}


.footer a{
    color:white;

}


```