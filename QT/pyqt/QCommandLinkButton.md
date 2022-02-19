# QCommandLinkButton学习记录

## 一、描述
命令链接是windows vista引入的新控件，它的用途类似于单选按钮的用途，因为它用于在一组互斥选项之间进行选择，命令链接按钮不应单独使用，而应作为向导和对话框中单选按钮的替代选项。外观通常类似于平面按钮的外观，但是除了普通按钮文本之外，它还允许描述性文本

## 二、继承
继承自QPushButton

## 三、功能作用
![图 1](../../images/bcb7366b8bc8711a0f656da60396180481880144d60ef463ca48626dd7cbbbd8.png)  

测试代码：

```python
import sys
from PyQt5.Qt import *


if __name__ == '__main__':

    app =QApplication(sys.argv)

    window =  QWidget()
    window.setWindowTitle("QCommandLinkButton使用")
    window.resize(500,500)

    # 第一个参数是文本内容，第二个参数是描述信息
    btn = QCommandLinkButton("标题","描述",window)
    btn.setText("标题2")
    btn.setDescription("社会顺哥")
    btn.setIcon(QIcon("img.png"))

    print(btn.description())

    window.show()
    sys.exit(app.exec_())
```



## 四、信号
同QPushButton












