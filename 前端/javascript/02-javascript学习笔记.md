# 02-javascript学习笔记-运算符

## 一、算数运算符

![图 8](../../images/a987af89541139c61e4be9ae33950b5d01a857a347478b8a1710ac05f5e6d1ff.png)  

![图 9](../../images/92fb08428081b24e65f4cc262a7baa4b34651fb80843a6066d53a6cafcc1a1e8.png)  

```javascript
    console.log(3 + 1);
    console.log(3 * 1);
    console.log(3 - 1);
    console.log(3 / 1);
    console.log(0.1 + 0.2);// 浮点数直接计算会出现误差（小数使用二进制表示会出现误差）
```
![图 10](../../images/2d6d8232f66f2bfdca572d9924bccca0fc4c209e7ab7269104e51dc37487e98e.png)  


## 二、递增和递减运算符


### 2.1 前置递增运算符
![图 11](../../images/9f3286135da33e0a4efee7236e6caa7caed43fa803460113509baee40c52e129.png)  

```javascript
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
    <script>
        var s = 10;
        console.log(++s + 10);// 前置递增运算符
        // 先加一 再返回值
    </script>

</head>
<body>
    
</body>
</html>
```


### 2.2 后置递增运算符
先返回原值，再加一

## 三、比较运算符

![图 12](../../images/230071839e2ee2719db096090d28240e663a524ea36b209f61b5213d58d25d68.png)  

需要注意：```console.log(18 == '18'); // true```

## 四、逻辑运算符
![图 13](../../images/9b2a13b6a76a72a160e7ceaf73cb8482ecf88ab14f615ce87734db80cec8325b.png)  

短路运算：当有多个表达式，左边的表达式值可以确定结果时，就不再继续运算右边的表达式的值；


### 4.1 逻辑与
* 语法：表达式1 && 表达式2
* 如果第一个表达式的值为真，则返回表达式2
* 如果第一个表达式的值为假，则返回表达式1

### 4.2 逻辑或
* 语法：表达式1 || 表达式2
* 如果第一个表达式的值为真，则返回表达式1
* 如果第一个表达式为假，则返回表达式2

下面这个案例输出的是0
```javascript
var num = 0;
console.log(123 || num++);// 123为真，返回123,num++不执行 
console.log(num);
```

## 五、赋值运算符
![图 14](../../images/6997966bb63a96d83aeee357663a309323555383af72c6287f08851ae4e3135b.png)  


## 六、运算符优先级

![图 15](../../images/2becf0a3ebe084d72cc92125f3979cdd1c0841248a36f1121dc6686a1926a0c1.png)  



