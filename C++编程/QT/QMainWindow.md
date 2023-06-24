# QMainWindow

## 快速使用案例

```cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMenuBar>
#include<QToolBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // 重置窗口的大小
    resize(600,400);

    // 菜单栏创建
    QMenuBar *bar = menuBar();

    // 菜单栏放入到窗口中
    setMenuBar(bar);

    // 创建菜单
    QMenu *fileMenu = bar->addMenu("文件");// 添加文件菜单
    QMenu *EditMenu = bar->addMenu("编辑");// 添加编辑菜单

    // 创建菜单项
    QAction *newAction = fileMenu->addAction("新建");
    // 添加分隔符
    fileMenu->addSeparator();
    QAction *openAction = fileMenu->addAction("打开");

    // 创建工具栏
    QToolBar *toolBar = new QToolBar(this);
    addToolBar(toolBar);

    // 设置允许左右停靠
    toolBar->setAllowedAreas(Qt::LeftToolBarArea | Qt::RightToolBarArea);

    // 设置浮动窗口
    toolBar->setFloatable(false);

    // 设置移动
    toolBar->setMovable(false);

    // 工具栏添加内容
    toolBar->addAction(newAction);
    toolBar->addSeparator();
    toolBar->addAction(openAction);


}

MainWindow::~MainWindow()
{
    delete ui;
}



```

![图 1](../../images/70c3e8245f0ccc8555609f10eb3ea7ec899998792abfc3418c23741fc791a5e1.png)  

## 状态栏

```cpp
    // 添加状态栏
    QStatusBar *stBar = statusBar();
    // 添加到窗口中
    setStatusBar(stBar);

    // 添加标签控件
    QLabel *label = new QLabel("提示信息",this);
    stBar->addWidget(label);

    QLabel *label2 = new QLabel("右侧提示信息",this);
    stBar->addPermanentWidget(label2);


```

![图 2](../../images/7656dfeab55e45245ca5655c942313973066e743a8d62a28da9936ccb6ec8adc.png)  

## 浮动窗口

```cpp
    // 设置浮动窗口
    QDockWidget *dockWidget = new QDockWidget("浮动",this);
    addDockWidget(Qt::BottomDockWidgetArea,dockWidget);

    // 设置中心部件
    QTextEdit *edit = new QTextEdit(this);
    setCentralWidget(edit);// 将编辑窗口设置为中心部件

```

![图 3](../../images/7ff8d49001e7ee9568077192aa75a5dd09fce8a775f863059cc2ee8fb83a4736.png)  



