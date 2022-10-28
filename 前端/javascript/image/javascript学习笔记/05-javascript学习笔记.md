# 05-javascript学习笔记-函数

## 一、函数的使用

函数在使用时分为两步：声明函数和调用函数。

声明函数：
```js
function getSum(num1,num2){
    var sum = 0;
    for(var i = sum1; i <= sum2; i++)
    {
        sum += i;
    }
    console.log(sum);
}
```

函数的封装：函数的封装是把一个或者多个功能通过函数的方式封装起来，对外只提供一个简单的函数接口。

## 二、形参与实参

&emsp;在声明函数时，可以在函数名称后面的小括号中添加一些参数，这些参数被称为形参，而在调用该函数时，同样也需要传递相应的参数。

形参：形式上的参数，函数定义的时候 传递的参数 当前并不知道是什么

实参：实际上的参数，函数调用的时候 传递的参数 实参是传递给形参的

函数形参和实参个数不匹配：

* 实参个数多于形参个数  只取到形参的个数
* 实参个数小于形参个数  多的形参定义为undefined  结果为NAN


## 三、案例

### 1. 求两个数的最大值

```js
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
    <script>
        // 求两个数的最大值
        function getMax(a,b)
        {
            if (a > b)
            {
                return a;
            }
            else{
                return b;
            }
        }
        console.log(getMax(1,2));
    </script>
</head>
<body>
    
</body>
</html>
```


### 2. 求数组中的最大值

```js
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>

    <script>
        // 利用函数求数组中的最大数值
        function getArrMax(arr){
            var max = arr[0];
            for(var i = 1; i < arr.length; i++)
            {
                if(arr[i] > max)
                {
                    max = arr[i];
                }
            }
            return max;
        }
        var result = getArrMax([21,3,43,43,1,123])
        console.log(result);
    </script>
</head>
<body>
    
</body>
</html>

```

注意：函数如果有return,那么返回的是return 后面的值，如果函数没有return，那么返回undefined。



## 四、arguments的作用

&emsp;当我们不确定有多少个参数传递的时候，可以用arguments来获取。在JavaScript中，arguments实际上它是当前函数的一个内置对象。所有函数都内置了一个arguments对象，arguments对象中存储了传递的所有实参。

&emsp;arguments展示形式是一个伪数组，因此可以进行遍历，伪数组有以下特点。

* 具有length属性
* 按照索引方式储存数据
* 不具有数组的push，pop等方法

```js

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>

    <script>
        // arguments 伪数组  具有Length属性 以及按照索引方式储存数据
        function f(){
            console.log(arguments);
            console.log(arguments.length);
            console.log(arguments[1]);
        }
        f(1,2,3)
    </script>
</head>
<body> 
</body>
</html>

```

```js
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>

    <script>
        // 利用函数求任意个数的最大值
        function getMax(){
            var max = arguments[0];
            for(var i = 1; i < arguments.length; i++)
            {
                if(arguments[i] > max)
                {
                    max = arguments[i];
                }
            }
            return max;
        }
        console.log(getMax(1,2,3));
        console.log(getMax(1,2,3,4,5,6));
        console.log(getMax(11,2,3,44,543,5,1));

    </script>

</head>
<body>
</body>
</html>
```

封装冒泡排序：

```js
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>

    <script>
        function BubbleSort(arr){

            for(var i = 0; i < arr.length - 1; i++)
            {
                for(var j = 0; j < arr.length - i - 1; j++)
                {
                    if(arr[j] > arr[j + 1])
                    {
                        var temp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = temp;
                    }
                }
            }

            return arr;
        }

        var arr1 = [5,4,3,2,1];
        console.log(BubbleSort(arr1));
    </script>
</head>
<body>
    
</body>
</html>

```

判断闰年：

```js
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>

    <script>

        // 判断是否是闰年
        function Judge(year){
            var flag = false;
            if(year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
            {
                flag = true;
            }
            return flag;
        }

        console.log(Judge(20000));
    </script>
</head>
<body>
    
</body>
</html>

```


## 五、函数表达式声明函数

// 函数表达式（匿名函数）
// var 变量名 = function(){};

```js
var fun = function(){
    console.log('我是函数表达式);
}

fun();
```

注意：fun是变量名，不是函数名；函数表达式声明方式跟申明变量差不多，只不过变量里面存的是值，而是变量里面存的是值 而 函数表达式里面存的是函数。

```js
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
    <script>
        var fun = function(){
            console.log("赵晓凡是仙女！");
        }
        fun();  // 使用变量名 接受 函数表达式
    </script>
</head>
<body>
    
</body>
</html>

```





















