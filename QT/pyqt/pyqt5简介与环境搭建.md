# pyqt5简介与环境搭建：pyqt5 + Anaconda + pycharm

## 一、概述
python 一开始只是作为一门脚本语言进行开发，并不具备GUI功能，但是由于本身具有良好的扩展性，能够源源不断地通过C++进行功能性扩展，因此现在已经有相当多的GUI控件。其中pyqt是QT为python专门提供的GUI扩展。

关于QT：QT是挪威Trolltech公司开发的一个C++GUI程序。使用QT只需要开发一次程序，便可以阔不同的桌面和嵌入式操作系统部署该应用，不需要重新编写代码。使用QT开发的应用程序能够在Windows、linux和Mac OS平台之间轻松移植


pyqt具有如下特性：
* 基于高性能的QT的GUI控件集
* 能够跨平台运行在Windows、Linux和MacOS等系统上
* 能够使用信号/槽机制进行通信
* 对Qt库的完全封装
* 可以使用Qt成熟的IDE（比如Qt Designer）进行图形界面设计，并自动生成可以执行的代码。
* 提供了一整套的种类繁多的窗口控件


## 二、Qt与Pyqt之间的关系
pyqt是QT框架的python语言实现，Pyqt提供了一个设计良好的窗口控件组合，每一个pyqt控件都有其对应的Qt控件。所以PyQt与Qt的类库和API非常详细，而且pyqt不用在使用qmake系统和Q_OBJECT宏，使得Pyqt再也没有编译链接错误，PyQT的代码也更加友好。

在开发速度上，pyqt的运行效率会低于QT，但是代码量会减少许多，降低开发成本。

QT使用信号槽机制在窗口控件之间传递事件和消息。这种机制完全不同于其他图形界面开发库所采用的回调机制（callback），使用信号槽可以使程序更加安全和简洁。


## 三、pyqt的windows环境搭建

### 3.1 软件要求

Anaconda3 + Pycharm + win10


### 3.2 安装一些必要的Python包

以下安装过程全部都使用国内镜像源,要在Anaconda prompt 中输入命令


* 首先，你需要安装PyQt5 当然Anaconda有，不需要
  
  ```
    pip install PyQt5 -i https://pypi.douban.com/simple
  ```

  如果你安装过程中出现了warning ,请在前面添加python -m,下面类似

  ```
  python -m pip install PyQt5 -i https://pypi.douban.com/simple
  ```

* 安装pyqt-tools
  ```
    pip install PyQt5-tools -i https://pypi.douban.com/simple
  ```

* 安装sip
  ```
    pip install  sip
  ```

安装完成之后，请在你的Anaconda目录下的Lib->site-packages中查看

![图 1](../../images/1f89fa8628322517973591f075551160465cb33ae5972e4021e0cfadac35b419.png)  


### 3.3 Pycharm相关配置


#### 3.3.1 配置Python解释器
使用你的pycharm新建一个工程，之后点击file->settings  输入Interpreter,点击添加你的anaconda中的python路径

![图 2](../../images/fdbde633186ebb36eb694565af59670e9584e3cd317323c29d5e923a32fa088a.png)  
![图 3](../../images/95e9f4c21bfc4a106f93e894114ac23e734bed6cd6d433241c9cf75d9476495b.png)  


选中之后，下面会显示一些他已有的包。


这一步，是为了你的python工程添加python解释器，这个解释器是Anaconda中的python


#### 3.3.2 配置QT-Designer

点击settings，搜索exteral tools, 点击添加

![图 4](../../images/28abc670dbe4a5f9b44a7f9cade69862816dcdf06b47ae9a431732363ecd49a7.png)  


```
    Name:QtDesigner
    Group:Qt
    Programs:你的Designer路径
    Working directory：$ProjectFileDir$

```
关于你的Designer路径，我在网上看到不同的路径，笔者的路径在：

```
D:\Application\Anconda3\Lib\site-packages\qt5_applications\Qt\bin

```
![图 5](../../images/a1779ab25682aca946fcaecf905b2e5f2771ab599b70f028fc07b342982d166b.png)  



#### 3.3.3 配置PYUIC

同样的，在上面的exteral tools 中添加

```
    Name:Pyuic
    Group:Qt
    Program: 你的Anaconda中的python路径
    Arguments：-m PyQt5.uic.pyuic $FileName$ -o $FileNameWithoutExtension$.py
    Working directory：$FileDir$

```
![图 6](../../images/164403e7f7d48ba21ba4cdf31d7192df4f09289d0eb28f53fc547739ba08ce55.png)  


### 3.4 测试

欧克，开始测试

1.在你的工程右键选择QtDesigner

![图 7](../../images/e585709fb2e85054f8683c8bec8c379f81b5bc27861584efc6dbe18e99d585cc.png)  


2.创建一个简单的窗口
![图 8](../../images/be512a60daba09b14c2c325da05e9212b61f7ec3ace2ab422f71d66804c21686.png)  


选择Main Window 创建


点击左边的标签
![图 9](../../images/b7a92515139a50e2b28e1259e6db1e4b4e5e6d0778508afa262f542099fbc114.png)  

直接选中拖到中间，输入你想要的，并且更改字体大小

![图 10](../../images/dd06501f4859170811089a663998e2e5fc0caaa98bc0b1e136fdfa064eda12b9.png)  

![图 11](../../images/18cf14e73ba583026446de23f2c1a06e2cd24e3b038603ed8ac372fadecec073.png)  


点击保存，一定要保存到你的python工程下
![图 12](../../images/59e559df1cc6b879244ff1c6e0d73878ea141acb9c29c0689ecac811ca718b26.png)  

![图 13](../../images/3a36a98cd802da850a7fb8b22d50dea35cd71f3b519f7ab418c9adb8b8c65bab.png)  




3.回到你的Pycharm 
![图 14](../../images/dbcc1e84865b221deb4465dcce5a309e1b15f627f3fcc532a3bbf631d8e2abaf.png)  


选中，选择PyUic,生成一个py文件

这时，在工程下面新建一个主函数，main.py

![图 15](../../images/6219fbe78856f7fa2c1b2ca7c341dd3b811b85ebe7e41c215f9c751c0570c10b.png)  

将你刚才创建的界面文件（我命名为xxf.py）作为工具包，导入模块

在main.py中输入以下代码

```python
import sys
# 导入创建的文件模块
import xxf
from PyQt5.QtWidgets import QApplication, QMainWindow
if __name__ =='__main__':
    app = QApplication(sys.argv)
    MainWindow = QMainWindow()
    ui = xxf.Ui_MainWindow()
    ui.setupUi(MainWindow)
    MainWindow.show()
    sys.exit(app.exec_())

```

运行，成功
![图 16](../../images/42ff12deb83c3ebc5c35fac4544272211cfe2c8bdf6d19fcb4d574740171fa7a.png)  


