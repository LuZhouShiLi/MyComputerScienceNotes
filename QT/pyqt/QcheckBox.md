# QCheckBox详解

## 一、描述

![图 8](../../images/51b5da8e23adf46f13ff965a3d86a16491c6613fc0a7d23b88c0997b6a97ce0b.png)  



## 二、继承
QAbstractButton


## 三、功能作用
![图 9](../../images/740a6bcb740448256e0aed43e3d8c01e579a58f4e1ac7831a7c511ad95044007.png)  

```python
import sys
from PyQt5.Qt import *


if __name__ == '__main__':

    app =QApplication(sys.argv)

    window =  QWidget()
    window.setWindowTitle("QCommandLinkButton使用")
    window.resize(500,500)

    print(QCheckBox.__bases__)

    # 多选框 设置文本  设置父对象  设置快捷键
    cb = QCheckBox("&Python",window)
    cb.setIcon(QIcon("img.png"))
    cb.setIconSize(QSize(60,60))

    cb.setTristate(True)  # 三种状态： 空白  填实  选中


    cb.setCheckState(Qt.Checked) # 设置成选中状态




    window.show()
    sys.exit(app.exec_())
```



## 四、信号

```python
# 选中或者清除选中的时候，发射此信号
stateChanged(int state)
```

复选框的三种状态：
![图 10](../../images/54bf54183c483b1a9fb566e3467da5aae4cd4755fa53418cd27e3150046cbdbf.png)  

```python
import sys
from PyQt5.Qt import *


if __name__ == '__main__':

    app =QApplication(sys.argv)

    window =  QWidget()
    window.setWindowTitle("QCommandLinkButton使用")
    window.resize(500,500)

    print(QCheckBox.__bases__)

    # 多选框 设置文本  设置父对象  设置快捷键
    cb = QCheckBox("&Python",window)
    cb.setIcon(QIcon("img.png"))
    cb.setIconSize(QSize(60,60))

    cb.setTristate(True)  # 三种状态： 空白  填实  选中


    cb.setCheckState(Qt.Checked) # 设置成选中状态

    cb.stateChanged.connect(lambda state:print(state))  # 三种状态


    window.show()
    sys.exit(app.exec_())
```


