# Lambda表达式


## 简单介绍

* = 表示函数体可以使用lambda所在作用范围内所有可见的局部变量，并且是值传递方式
* & 函数体可以使用Lambda所在作用范围内的所有可见的局部变量，并且是引用传递方式
* this 函数体可以使用Lambda所在类中的成员变量
* a，表示a按照值传递 按照值传递，函数体不可以修改传递进来的a的拷贝，因为默认情况下函数是const的，**要修改传递进来的a的拷贝可以添加mutable修饰符**
* &a 表示a按照引用进行传递

```cpp
    [=](){
        btn->setText("asdsd");
    }();// lambda表达式

    [btn](){
      btn->setText("diuscghfvijdsh");
    }();

```


## 简单案例-点击按钮，关闭窗口

```cpp
    // 利用lambda 表达式 实现点击按钮 关闭窗口
    QPushButton *btn2 = new QPushButton;
    btn2->setText("关闭");
    btn2->move(100,0);
    btn2->setParent(this);


    // 使用Lambda表达式 鼠标点击信号  然后关闭窗口
    connect(btn2,&QPushButton::clicked,this,[=](){
       this->close();
    });

```



