# QFrame详解

## 一、描述

是一个基类，可以选择直接使用，主要用来控制一些边框样式：凸起，凹下，阴影，线宽

## 二、继承
QWidget



## 三、功能作用
### 3.1 创建QFrame对象



### 3.2 框架形状
![图 26](../../images/2d402f3abb8862bb595e0ccd610b748af5adb1275ec753e47144a41b84ac72c5.png)  



### 3.3 框架阴影
![图 27](../../images/ddad9e37955af7fc5e577a298ba40eb48a13e1ac43089fd0d0ca8935ac2ab695.png)  




### 3.4 框架的几个线宽
![图 28](../../images/19db6efb957bc3c4af1ab96baa1b5dc2426379c188b69a56d05d5fff3476474a.png)  





### 3.5 框架样式
![图 29](../../images/dc4fae16cfc9ca5d0519586549938696661c02bd76c93ec6feec9b7ccd98e747.png)  




### 3.6 框架矩形
![图 30](../../images/ac170786582578c452d403e17a45239aca083a9fcaf36cc9a246408779a5e1fe.png)  





## 四、信号

继承自父类



测试代码：

```python
from PyQt5.Qt import *
import sys



if __name__ == '__main__':

    app = QApplication(sys.argv)

    window = QWidget()
    window.setWindowTitle("QFrame功能测试")
    window.resize(500,500)


    frame = QFrame(window)
    frame.move(100,100)
    frame.resize(100,100)
    frame.setStyleSheet("background-color:red;")

    frame.setFrameShape(QFrame.Box)   # 围绕其内容绘制一个框
    frame.setFrameShadow(QFrame.Raised)  # 设置阴影效果

    # 设置凸起效果
    frame.setLineWidth(6)  # 外线
    frame.setMidLineWidth(12)  # 中线

    print(frame.frameWidth())  # 打印框架的宽度


    window.show()

    sys.exit(app.exec_())
```



