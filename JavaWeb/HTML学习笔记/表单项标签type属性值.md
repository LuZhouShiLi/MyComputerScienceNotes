# 表单项标签type属性值
* text         普通文本框
* password     密码框
* email        邮箱框，简单验证
* radio        单选框  选项必须有相同的Name属性值，value属性设置实际提交的值。checked属性代表默认选中
* checkbox     复选框，选项必须有相同的name属性值，value属性设置实际提交的值，checked属性代表默认选中
* date         日期框
* time         时间框
* datetime-local  时间日期框
* number       数字框
* range        滚动条数值框  min 最小值 max最大值 step步进值
* search       可清除文本框
* tel          电话框
* url          网址框
* file         文件上传框
* hidden       隐藏域   value属性设置实际提交的值



```HTML

type属性
<input type = "text"/>   普通文本输入框
<input type = "password"/>  密码输入框
<input type = "email"/> 邮箱输入框
<input type = "radio"/>  单选框。必须有相同的name属性值，value属性真实提交的数据，checked属性默认选中
<input type = "checkbox"/> 多选框。必须有相同的name属性值，value属性真实提交的数据，checked属性默认选中
```


```
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>表单项标签</title>
</head>
<body>


    <!--
    表单项标签：<label>  表单元素说明
    属性：for属性，属性值必须和表单标签id属性值一致

    表单项标签：<input>  多种类型数据

    属性：
        type-数据类型
        id-唯一标识
        name-提交服务器的标识
        value-默认的数据值
        placeholder-默认的提示信息
        required-是否必须


    按钮标签：<button>

    属性：
        type-按钮的类型（submit提交、reset重置、button普通按钮）

    -->

    <form action = "#" method = "get" autocomplete="off">
        <label for = "username">用户名：</label>
        <input type = "text" id = "username" name = "usernname" /><br/>

        <label for = "password">密码：</label>
        <input type = "password" id = "password" name = "password" /><br/>

        <label for = "email">邮箱：</label>
        <input type = "email" id = "email" name = "email"/>  <br/>

        <!--单选框   name属性值必须相同  value时提交的数据-->
        <label for = "gender">性别：</label>
        <input type="radio" id = "gender" name = "gender" value="man"/>男
        <input type="radio"  name = "gender" value="woman"/>女
        <input type="radio"  name = "gender" value="other"/>其他<br/>


        <!--多选框  选择checked标识已经选上-->
        <label for = "hobby">爱好：</label>
        <input type = "checkbox" id = "hobby" name = "hobby" value = "music" checked/>音乐
        <input type = "checkbox" name = "hobby" value = "game"/>游戏<br/>

        <label for = "birthday">生日：</label>
        <input type = "date" id = "birthday" name = "birthday"/><br/>

        <label for = "time">当前时间：</label>
        <input type = "time" id  = "time" name = "time"/><br/>

        <label for = "insert">注册时间：</label>
        <input type = "datetime-local" id = "insert" name = "insert"/><br/>

        <label for = "age">年龄：</label>
        <input type = "number" id = "age" name = "age"/><br/>

        <label for = "range">心情值(1~10):</label>
        <input type = "range" id  = "range" name = "range" min = "1" max = "10" step = "1"/><br/>

        <label for search>可全部清除文本：</label>
        <input type = "search" id = "search" name = "search"/><br/>

        <label for = "tel">电话：</label>
        <input type = “tel” id = "tel" name = "tel"/><br/>

        <label for = "url">个人网站：</label>
        <input type = "url" id = "url" name = "url"/>

        <label for = "file">文件上传：</label>
        <input type = "file" id = "file" name = "file"/>

        <label for = "hidden">隐藏信息：</label>
        <input type = "hidden" id = "hidden" name = "hidden"/>

        <button type = "submit">提交<button>
        <button type = "reset">重置<button>
    </form>

</body>
</html>
```






