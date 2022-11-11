# QT-信号与槽机制

## 一、标准信号和槽

* 信号：各种事件
* 槽：响应信号的动作
  
&emsp;当某个事件发生之后，某个按钮被点击之后，他就会发出一个被点击的信号

&emsp;某个对象接收到这个信号之后，就会做一些相关的处理动作(slot)

&emsp;要想让一个对象收到另一个对象发出的信号，这是需要建立连接connect

```cpp
#include "widget.h"
#include<QPushButton>
#include"mypushbutton.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QPushButton *btn = new QPushButton("按钮1",this);

    // 按钮
    // 被点击
    // 窗口
    // 关闭

    // 建立四者的关系 按钮  被点击  窗口 关闭
    
    // connect(信号发送者，信号，信号接收者，槽)
    connect(btn,&QPushButton::clicked,this,&Widget::close);

}

Widget::~Widget()
{
}

```

* 信号发送者
* 信号
* 信号接收者
* 槽

## 二、自定义信号与槽

* 自定义信号
  * 函数声明在类头文件的signals域下面
  * void类型的函数 没有返回值
  * 可以有参数，也可以重载
  * 只有声明，没有实现定义
  * 触发信号  emit obj->sign(参数...)
  
* 自定义槽
  * 函数声明在类头文件的public/private/protected slots域下面（qt4以前版本）qt5就可以声明在类的任何位置，还可以是静态成员函数，全局函数、lambda表达式
  * void 类型的函数  没有返回值
  * 可以有参数 也可以重载
  * 不仅有声明 还得有实现

### 2.1 信号与槽的案例-无参数

下课了 老师饥饿  学生请客吃饭

teacher.h  添加一个饥饿信号  不需要实现 函数
```cpp
#ifndef TEACHER_H
#define TEACHER_H

#include <QObject>

class Teacher : public QObject
{
    Q_OBJECT
public:
    explicit Teacher(QObject *parent = nullptr);

signals:
    
    // 添加信号  只有声明 没有实现  信号就是一个函数
    void hungry();

};

#endif // TEACHER_H


```

teacher.cpp
```cpp
#include "teacher.h"

Teacher::Teacher(QObject *parent) : QObject(parent)
{

}
```



student.h  自定义槽函数形式 需要实现

```cpp
#ifndef STUDENT_H
#define STUDENT_H

#include <QObject>

class Student : public QObject
{
    Q_OBJECT
public:
    explicit Student(QObject *parent = nullptr);

signals:

public slots:

    // 自定义槽 学生请吃饭   函数形式 需要实现
    void treat();

};

#endif // STUDENT_H


```


student.cpp 槽函数需要在cpp文件中进行实现

```cpp
#include "student.h"
#include<QDebug>

Student::Student(QObject *parent) : QObject(parent)
{

}

// 函数声明的实现  使用类作用域符号进行引入
void Student::treat()
{
    qDebug()<<"Stduent treat teacher";
}
```


widget.h

```cpp
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include"student.h"
#include"teacher.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    
    // 自定义触发信号  在里面发射信号
    void classOver();

private:
    
    // 引入成员  私有化
    Teacher *pT;
    Student *pS;
};
#endif // WIDGET_H
```

widget.cpp

```cpp
#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    // 根据私有成员 新建两个对象
    pT = new Teacher(this);
    pS = new Student(this);

    // 建立连接
    connect(pT,&Teacher::hungry,pS,&Student::treat);

    this->classOver();// 调用  触发信号
}

Widget::~Widget()
{
}


// 发射自定义信号
void Widget::classOver()
{
    // 触发老师饥饿的信号
    emit pT->hungry();
}


```


### 2.2 有参数的信号与槽案例

**带参数的自定义信号和槽函数，就声明函数的时候带上参数就行，老师说他饿了，说要吃黄焖鸡，学生就请客吃黄焖鸡**

* 使用函数指针进行赋值
```cpp
#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    // 根据私有成员 新建两个对象
    pT = new Teacher(this);
    pS = new Student(this);
    
    // 使用函数指针赋值  让编译器挑选符合类型的函数
    void (Teacher::*teacher_qString)(QString) = &Teacher::hungry;
    void (Student::*student_qString)(QString) = &Student::treat;

    // 建立连接
    connect(pT,teacher_qString,pS,student_qString);

    this->classOver();// 调用  触发信号
}

Widget::~Widget()
{
}


// 发射自定义信号
void Widget::classOver()
{
    // 触发老师饥饿的信号  然后触发槽函数
    emit pT->hungry();

    // 发射带参数的信号
    emit pT->hungry("黄焖鸡");
}

```

* 使用static_cast 强制进行转换 也是让编译器自动挑选符合类型的函数

```cpp
#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    // 根据私有成员 新建两个对象
    pT = new Teacher(this);
    pS = new Student(this);

    // 使用函数指针赋值  让编译器挑选符合类型的函数
    void (Teacher::*teacher_qString)(QString) = &Teacher::hungry;
    void (Student::*student_qString)(QString) = &Student::treat;

    // 建立连接
//    connect(pT,teacher_qString,pS,student_qString);

    // 使用static_cast 来转换无参数的函数
    connect(pT,static_cast<void (Teacher::*)()>(&Teacher::hungry),pS,static_cast<void (Student::*)()>(&Student::treat));

    this->classOver();// 调用  触发信号
}

Widget::~Widget()
{
}


// 发射自定义信号
void Widget::classOver()
{
    // 触发老师饥饿的信号  然后触发槽函数
    emit pT->hungry();

    // 发射带参数的信号
    emit pT->hungry("黄焖鸡");
}

```

参数二义性问题：

* 使用函数指针赋值，让编译器自动挑选符合类型的函数
* 使用static_cast强制转换  让编译器自动挑选符合类型的函数


## 三、信号和槽的扩展

* 一个信号可以连接多个槽
  一个信号建立了多个connect,那么当信号发射的时候，槽函数的调用顺序：随机

* 一个槽可以连接多个信号

* 信号可以连接信号
  connect(第一个信号发送者，第一个信号，第二个信号发送者，第二个信号)

* 信号可以断开连接，disconnect
  connect 参数怎么填写，disconnect就怎么填写

* 信号和槽的参数关系，必须满足以下两点
  * 信号和槽函数的参数类型必须对应
  * 信号和槽函数的参数个数不需要一致，信号函数参数个数>= 槽函数参数个数

## 四、Qt4的信号和槽函数

* 使用两个宏SIGNAL、SLOT
* connect使用不一样，信号和槽函数声明差不多
* connect(信号发送者，SIGNAL(函数原型),信号接收者，SLOT(函数原型))

```cpp
connect(pT,SIGNAL(hungry(QString)),pS,SLOT(treat(QString)));// 传入的信号与槽都是带有参数的函数
```

**不存在二义性问题**

SIGNAL和SLOT宏的原理，就是将后边的参数转换成字符串， 类似于#define toStr(arg)|#arg -> "arg"

好处：不存在二义性问题
坏处：写错函数名，编译不会出错

## 五、QDebug的输出转义问题

* QString 转成char *
  ```cpp
  qDebug()<<"Stduent treat teacher with "<<what.toUtf8().data();
  ```
* 使用qDebug().noquote()
  ```cpp
  qDebug().noquote()<<"Student treat teacher with"<<what;
  ```

## 六、lambda表达式

定义匿名函数对象，简化编程工作,Lambda表达式的基本构成：

[局部变量捕获列表]、（函数参数）、函数额外属性设置opt、函数返回值->retype、{函数主体}


```cpp
[capture](parameters)opt->retType
{

}

```

### 6.1 简单的案例

// 下面的代码  捕获 a b 变量 输出10 和 20


* 下面的代码是值传递 传递参数
```cpp
#include "widget.h"
#include "ui_widget.h"
#include<QDebug>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);// 初始化窗口

    // 局部变量捕获
    int a = 10;
    int b = 20;

    // 传入参数 将a b 都捕获进来

    [a,b]()
    {
        qDebug()<<"Hello Lambda";
        qDebug()<<a<<b;// 输出10 20
    }();

}

Widget::~Widget()
{
    delete ui;
}
```


* 下面的代码是引用传递

```cpp
#include "widget.h"
#include "ui_widget.h"
#include<QDebug>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);// 初始化窗口

    // 局部变量捕获
    int a = 10;
    int b = 20;

    // 传入参数 将a b 都捕获进来  引用传递

    [&a,&b]()
    {
        qDebug()<<"Hello Lambda";
        qDebug()<<a<<b;// 输出10 20
    }();

}

Widget::~Widget()
{
    delete ui;
}
```


**使用引用传递，可以在Lambda表达式中更改变量，但是默认情况下值传递捕获进行来的就是const**

```cpp
#include "widget.h"
#include "ui_widget.h"
#include<QDebug>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);// 初始化窗口

    // 局部变量捕获
    int a = 10;
    int b = 20;

    // 传入参数 将a b 都捕获进来  引用传递
    [a,b]() mutable
    {
        qDebug()<<"Hello Lambda";
        qDebug()<<a<<b;// 输出10 20
        
        // 进行修改  但是改不了
        a = 30;
        b= 40;
    }();

    qDebug()<<a<<b;// 输出10 20
}

Widget::~Widget()
{
    delete ui;
}


```

**使用=将所有的变量全部拷贝进来**

```cpp
#include "widget.h"
#include "ui_widget.h"
#include<QDebug>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);// 初始化窗口

    // 局部变量捕获
    int a = 10;
    int b = 20;
    int c = 0;
    int d = 9;

    // 传入参数 将a b 都捕获进来  引用传递
    // 使用 = 将所有的参数
    [=]() mutable
    {
        qDebug()<<"Hello Lambda";
        qDebug()<<a<<b<<c<<d;// 输出10 20


    }();

    qDebug()<<a<<b;// 输出10 20
}

Widget::~Widget()
{
    delete ui;
}
```


**[&]全部使用引用传递**

```cpp
#include "widget.h"
#include "ui_widget.h"
#include<QDebug>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);// 初始化窗口

    // 局部变量捕获
    int a = 10;
    int b = 20;
    int c = 0;
    int d = 9;

    // 传入参数 将a b 都捕获进来  引用传递
    // 使用 = 将所有的参数   & 全部使用引用传递
    [&]() mutable
    {
        qDebug()<<"Hello Lambda";
        qDebug()<<a<<b<<c<<d;// 输出10 20


    }();

    qDebug()<<a<<b;// 输出10 20
}

Widget::~Widget()
{
    delete ui;
}

```

**[=,&b] 除了B是引用传递 其他的都是值传递**

```cpp
#include "widget.h"
#include "ui_widget.h"
#include<QDebug>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);// 初始化窗口

    // 局部变量捕获
    int a = 10;
    int b = 20;
    int c = 0;
    int d = 9;

    // 传入参数 将a b 都捕获进来  引用传递
    // 使用 = 将所有的参数   & 全部使用引用传递
    
    
    // 除了 b是值传递  其他的都是引用传递
    [=,&b]() mutable
    {
        qDebug()<<"Hello Lambda";
        qDebug()<<a<<b<<c<<d;// 输出10 20


    }();

    qDebug()<<a<<b;// 输出10 20
}

Widget::~Widget()
{
    delete ui;
}
```

### 6.2 lambda表达式

```cpp
#include "widget.h"
#include "ui_widget.h"
#include<QDebug>
#include<QPushButton>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);// 初始化窗口

    // 局部变量捕获
    int a = 10;
    int b = 20;
    int c = 0;
    int d = 9;

    // 传入参数 将a b 都捕获进来  引用传递
    // 使用 = 将所有的参数   & 全部使用引用传递


    // 除了 b是值传递  其他的都是引用传递
    [=,&b]() mutable
    {
        qDebug()<<"Hello Lambda";
        qDebug()<<a<<b<<c<<d;// 输出10 20


    }();

    qDebug()<<a<<b;// 输出10 20

    // 创建一个按钮
    QPushButton *btn = new QPushButton("按钮1",this);// 新建一个对象

    connect(btn,&QPushButton::clicked,[&](){
        qDebug()<<a<<b;
        this->close();
    });
}

Widget::~Widget()
{
    delete ui;
}

```



 