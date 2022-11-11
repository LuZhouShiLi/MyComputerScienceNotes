# QT-事件机制

## 一、事件

&emsp;事件(event)是由系统或者Qt应用程序本身在不同的时刻发出的，当用户按下鼠标、敲下键盘，或者是窗口需要重新绘制的时候，都会发出一个相应的事件

## 二、事件处理函数

* keyPressEvent(): 键盘按键按下事件
* keyReleaseEvent(): 键盘按键松开事件
* mouseDoubleClickEvent():鼠标双击事件


重写鼠标按下事件：mousePressEvent
mylabel.h
```cpp
#ifndef MYLABEL_H
#define MYLABEL_H

#include <QWidget>
#include<QLabel>

// 继承QLabel
class MyLabel : public QLabel
{
    Q_OBJECT
public:
    explicit MyLabel(QWidget *parent = nullptr);

signals:

public slots:

protected:
    // 重写鼠标按键处理函数  参数是鼠标点击事件
    void mousePressEvent(QMouseEvent *ev);
};

#endif // MYLABEL_H


```


mylabel.cpp

```cpp
#include "mylabel.h"
#include<QMouseEvent>

MyLabel::MyLabel(QWidget *parent)
    : QLabel{parent}
{

}

void MyLabel::mousePressEvent(QMouseEvent *ev)
{
    // 输出鼠标事件的一些信息
    // 获取坐标
    int x = ev->x();
    int y = ev->y();

    QString str = QString("[%1,%2]").arg(x).arg(y);// 鼠标按下  实时输出坐标信息

    this->setText(str);
}


```



重写鼠标移动的处理函数:mouseMoveEvent

mylabel.h
```cpp
#ifndef MYLABEL_H
#define MYLABEL_H

#include <QWidget>
#include<QLabel>

// 继承QLabel
class MyLabel : public QLabel
{
    Q_OBJECT
public:
    explicit MyLabel(QWidget *parent = nullptr);

signals:

public slots:

protected:
    // 重写鼠标按键处理函数  参数是鼠标点击事件
    void mousePressEvent(QMouseEvent *ev);

    // 重写鼠标移动的处理函数
    void mouseMoveEvent(QMouseEvent *ev);
};

#endif // MYLABEL_H


```

mylabel.cpp
```cpp
#include "mylabel.h"
#include<QMouseEvent>

MyLabel::MyLabel(QWidget *parent)
    : QLabel{parent}
{

}

void MyLabel::mousePressEvent(QMouseEvent *ev)
{
    // 输出鼠标事件的一些信息
    // 获取坐标
    int x = ev->x();
    int y = ev->y();

    // 获取鼠标按键
    Qt::MouseButton btn = ev->button();
    QString strbutton ="";

    if(btn == Qt::LeftButton)
    {
        strbutton = "LeftButton";
    }

    if(btn == Qt::RightButton)
    {
        strbutton = "RightButton";
    }

    if(btn == Qt::MidButton)
    {
        strbutton = "MidButton";
    }


    QString str = QString("<h1>press[%1,%2][%3]</h1>").arg(x).arg(y).arg(strbutton);// 鼠标按下  实时输出坐标信息

    this->setText(str);
}

void MyLabel::mouseMoveEvent(QMouseEvent *ev)
{
    // 输出鼠标事件的一些信息
    // 获取坐标
    int x = ev->x();
    int y = ev->y();

    // 获取鼠标按键
    Qt::MouseButton btn = ev->button();
    QString strbutton ="";

    if(btn == Qt::LeftButton)
    {
        strbutton = "LeftButton";
    }

    if(btn == Qt::RightButton)
    {
        strbutton = "RightButton";
    }

    if(btn == Qt::MidButton)
    {
        strbutton = "MidButton";
    }


    QString str = QString("<h1>move[%1,%2][%3]</h1>").arg(x).arg(y).arg(strbutton);// 鼠标按下  实时输出坐标信息

    this->setText(str);
}

```

## 三、事件分发机制


当某个事件（鼠标或者键盘）发生的时候，窗口就会收到这个事件，并且调用相应的事件处理函数，事件处理函数的命名都是以event结尾

事件先回到达窗口的event函数，event函数返回值:true表示该事件得到处理，如果是false,没被处理，时间会继续传递到父窗口，通过判断QEvent参数的类型得到事件类型之后，调用相应的事件处理函数

MyLabel.cpp
```cpp
bool MyLabel::event(QEvent *e)
{
    // 返回值：true表示该事件得到处理 如果是false 没被处理 事件会继续传递到父窗口

    // QEvent就是所有Event类的父类

    // 判断event的类型
    if(e->type() == QEvent::MouseMove)
    {
        this->mouseMoveEvent(static_cast<QMouseEvent *>(e));// 转换一下数据类型
    }


    return QLabel::event(e);

}
```

MyLabel.h
```cpp
#ifndef MYLABEL_H
#define MYLABEL_H

#include <QWidget>
#include<QLabel>

// 继承QLabel
class MyLabel : public QLabel
{
    Q_OBJECT
public:
    explicit MyLabel(QWidget *parent = nullptr);

signals:

public slots:

protected:
    // 重写鼠标按键处理函数  参数是鼠标点击事件
    void mousePressEvent(QMouseEvent *ev);

    // 重写鼠标移动的处理函数
    void mouseMoveEvent(QMouseEvent *ev);

    // 重写event分发函数
    bool event(QEvent *e);
};

#endif // MYLABEL_H

```

## 四、事件过滤器

MyLabel.cpp
```cpp
#include "mylabel.h"
#include<QMouseEvent>

MyLabel::MyLabel(QWidget *parent)
    : QLabel{parent}
{
    this->setMouseTracking(true);
    
    // 事件过滤器的使用
    // 窗口调用installEventFilter 来安装一个事件过滤器
    // 参数是一个事件过滤器对象QObject,该对象的类要重写eventFilter的函数
    // 事件过滤的时候 事件会先到达事件过滤器的eventFilter函数
    
    this->installEventFilter(this);
}

void MyLabel::mousePressEvent(QMouseEvent *ev)
{
    // 输出鼠标事件的一些信息
    // 获取坐标
    int x = ev->x();
    int y = ev->y();

    // 获取鼠标按键
    Qt::MouseButton btn = ev->button();
    QString strbutton ="";

    if(btn == Qt::LeftButton)
    {
        strbutton = "LeftButton";
    }

    if(btn == Qt::RightButton)
    {
        strbutton = "RightButton";
    }

    if(btn == Qt::MidButton)
    {
        strbutton = "MidButton";
    }


    QString str = QString("<h1>press[%1,%2][%3]</h1>").arg(x).arg(y).arg(strbutton);// 鼠标按下  实时输出坐标信息

    this->setText(str);
}

void MyLabel::mouseMoveEvent(QMouseEvent *ev)
{
    // 输出鼠标事件的一些信息
    // 获取坐标
    int x = ev->x();
    int y = ev->y();

    // 获取鼠标按键
    Qt::MouseButton btn = ev->button();
    QString strbutton ="";

    if(btn == Qt::LeftButton)
    {
        strbutton = "LeftButton";
    }

    if(btn == Qt::RightButton)
    {
        strbutton = "RightButton";
    }

    if(btn == Qt::MidButton)
    {
        strbutton = "MidButton";
    }


    QString str = QString("<h1>move[%1,%2][%3]</h1>").arg(x).arg(y).arg(strbutton);// 鼠标按下  实时输出坐标信息

    this->setText(str);
}

bool MyLabel::event(QEvent *e)
{
    // 返回值：true表示该事件得到处理 如果是false 没被处理 事件会继续传递到父窗口

    // QEvent就是所有Event类的父类

    // 判断event的类型
    if(e->type() == QEvent::MouseMove)
    {
        this->mouseMoveEvent(static_cast<QMouseEvent *>(e));// 转换一下数据类型
    }


    return QLabel::event(e);
    
}

bool MyLabel::eventFilter(QObject *watched, QEvent *event)
{
    // 拦截鼠标移动事件
    if(event->type() == QEvent::MouseMove)
    {
        return true;
    }
}


```

MyLabel.h

```cpp
#ifndef MYLABEL_H
#define MYLABEL_H

#include <QWidget>
#include<QLabel>

// 继承QLabel
class MyLabel : public QLabel
{
    Q_OBJECT
public:
    explicit MyLabel(QWidget *parent = nullptr);

signals:

public slots:

protected:
    // 重写鼠标按键处理函数  参数是鼠标点击事件
    void mousePressEvent(QMouseEvent *ev);

    // 重写鼠标移动的处理函数
    void mouseMoveEvent(QMouseEvent *ev);

    // 重写event分发函数
    bool event(QEvent *e);
    
    // 重写eventFilter
    bool eventFilter(QObject *watched,QEvent *event);
};

#endif // MYLABEL_H


```



## 五、定时器事件

* 通过startTimer来启动一个定时器，参数是毫秒，每隔相应的事件就会触发一个定时器事件，返回值就是定时器的Id
* 通过killTimer来杀死一个定时器，参数就是定时器的Id
* timerEvent定时器事件处理函数中通过event参数获取当前事件是哪一个定时器发出的，event->timerId()


widget.h

```cpp
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

protected:
    // 定时器事件的处理
    void timerEvent(QTimerEvent *event);

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H

```


widget.cpp

```cpp
#include "widget.h"
#include "ui_widget.h"
#include<QDebug>

void Widget::timerEvent(QTimerEvent *event)
{
    qDebug()<<"闹钟";
}

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //创建定时器
    startTimer(1000);

}

Widget::~Widget()
{
    delete ui;
}

```

## 六、绘图

绘图事件：窗口需要重新显示的时候，就会收到一个绘图事件，paintEvent收到绘图事件之后，窗口就要讲自己画出来

画画的人：QPainter
画笔：QPen
画布：QPaintDevice

widget.cpp
```cpp
#include "widget.h"
#include "ui_widget.h"
#include<QPainter>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
    // 在这里画画  设置一个画布
    QPainter painter(this);

    // 创建一支画笔
    QPen pen;
    pen.setWidth(3);
    pen.setColor(QColor(255,0,0));// 设置颜色

    // 画刷
    QBrush brush;
    brush.setColor(Qt::cyan);// 画刷颜色
    // 画家设置画刷
    painter.setBrush(brush);


    // 画家设置画笔
    painter.setPen(pen);

    pen.setStyle(Qt::DashLine);// 设置画笔风格

    // 画一条线
    painter.drawLine(0,0,100,100);

    // 画矩形
    painter.drawRect(20,20,50,50);


    // 画圆形  使用椭圆
    painter.drawEllipse(QPoint(100,100),50,50);

    // 文字
    painter.drawText(200,100,"好好学习 天天向上");
}

```

widget.h
```cpp
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;

protected:
    // 设置绘图事件
    void paintEvent(QPaintEvent *event);

};
#endif // WIDGET_H

```

* QPainter(参数是绘图设备，this表示在窗口上)
* drawLine 划线 两点一线 参数就是两个点的坐标
* drawRect  矩形 参数是左上角点 宽和高 另一种就是圆心 + rx + ry
* 设置画家的画笔 setPen(QPen)  画笔可以设置颜色风格
* 设置画家的画刷 setBrush(QBrush) 填充封闭的图形 也可以设置颜色 


## 七、手动触发绘图事件

使用两个函数：

* repaint：会马上触发绘图事件
* update:update做了一些优化
* 不要在paintEvent处理函数中再触发绘图事件，会导致无限循环

widget.h
```cpp
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;

public:
    int mPox;

protected:
    // 设置绘图事件
    void paintEvent(QPaintEvent *event);

private slots:
    void on_pushButton_clicked();
};
#endif // WIDGET_H

```


widget.cpp

```cpp
#include "widget.h"
#include "ui_widget.h"
#include<QPainter>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    mPox = 0;

}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
   // painter绘制已经存在的图片
    QPainter painter(this);
    QPixmap pixmap(":/Talyor/T001M001000qrPik2w6lDr_99.jpg");
    painter.drawPixmap(mPox,0,pixmap);// 绘制图像
}


void Widget::on_pushButton_clicked()
{
    // 每次点击按钮 图片向右移动 10px

    mPox += 10;

    // 手动触发绘图事件
    // repaint
    // update
    this->update();
}

```


## 八、绘图设备

* QPixmap专门为图像在屏幕上的显示做了优化
* QBitmap是QPixmax的一个子类，他的色深限定为1，可以使用QPixmap的isQBitmapx()函数来确定这个QPixmap是不是一个QBitmap.
* QImage专门为图像的像素级访问做了优化
* QPicture则可以记录何重现QPainter的逐条命令
* 图片可以通过save和load命令进行加载以及保存

```cpp
#include "widget.h"
#include "ui_widget.h"
#include<QPainter>
#include<QPixmap>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QPixmap pix(300,300);// 设置300 x 300绘图区域
    pix.fill(Qt::white);// 将画布背景填充为白色
    QPainter painter(&pix);

    // 设置画笔颜色
    painter.setPen(QColor(255,0,0));

    painter.drawEllipse(QPoint(150,150),100,100);// 绘制椭圆

    pix.save("D:\\pictures\\hh.png");// 保存图片
}

Widget::~Widget()
{
    delete ui;
}
```


