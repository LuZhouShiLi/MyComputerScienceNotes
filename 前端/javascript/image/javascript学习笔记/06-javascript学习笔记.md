# 06-javascript学习笔记-作用域

## 一、作用域概述

&emsp;通常来说，一段程序代码中所用到的名字不总是有效的和可用的，而限定这个名字的可用性代码范围就是这个名字的作用域。作用域的使用提高了程序逻辑的局部性，增强了程序的可靠性，减少了名字冲突。

作用域分为：全局作用域，局部作用域。

全局作用域：整个script标签或者一个单独的js文件

局部作用域：又叫函数作用域，在函数内部就是局部作用域，这个代码的名字只在函数内部有效果。

全局变量：只有浏览器关闭的时候才会销毁，比较占内存资源
局部变量：当我们程序执行完毕的时候就会销毁，比较节约内存资源

如果函数中还有一个函数，那么在这个作用域中就可以产生另外一个作用域。根据在内部函数可以访问外部函数变量的这种机制，用链式查找决定那些数据能被内部函数访问，就称作作用域链。


## 二、JS预解析

JavaScript代码是由浏览器中的JavaScript解析器来执行的。JavaScript解析器在运行JavaScript代码的时候分为两步：预解析和代码执行

```js
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>

    <script>
        // 预解析：js引擎会将js里面所有的var变量还有function提升到当前作用域的最前面
        // 代码执行：按照代码书写的顺序从上往下执行

        // 预解析分为变量预解析（变量提升）和函数预解析（函数提升）
        // 变量提升就是把所有的变量声明提升到当前的作用域最前面，不提升赋值操作
        // 函数提升 就是把所有的函数声明提升到当前作用域的最前面  不调用函数  先调用函数 后声明函数 不会报错

        console.log(num);// 输出undefined
        var num = 10;

        // 相当于 先定义变量 但是没有进行赋值  然后控制台输出这个变量（undefined） 
        // var num;
        // console.log(num);
        // num = 10;

        // 以下代码会报错
        fun();
        var fun = function(){
            console.log("赵晓凡！！！");
        }

        // 相当于执行下面的代码
        var fun;
        fun();
        fun = function(){
            console.log("赵晓凡");
        }

    </script>
</head>
<body>
    
</body>
</html>

```

预解析：经典案例
```js
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>

    <script>
        function f1(){
            // var a = b = c = 9; 
            var a;// 这里只有a是局部变量  b c 是全局变量
            a = b = c = 9;
            // 相当于 var a = 9;b = 9; c = 9; b 和 c直接赋值 没有var声明 当全局变量看待
            // 集体声明 var a = 9,b = 9,c = 9;
            console.log(a); // 输出9
            console.log(b); // 输出9
            console.log(c); // 输出9
        }
        f1();
        console.log(c); // 输出9
        console.log(b); // 输出9
        console.log(a);  // 报错
    </script>


</head>
<body>
    
</body>
</html>

```
















