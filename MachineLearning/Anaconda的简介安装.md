# Anaconda与JupyterNotebook的简介与使用

## 一、Anaconda的简介
* Anaconda支持Linux，Mac,Windows，包含了众多流行的科学计算、数据分析的Python包。

* Anaconda和Jupyter notebook已经成为数据分析的标准环境

* 我们使用Anconda发行版作为Python的使用环境。
  
* Anaconda指的是一个开源的Python发行版本，其中包含了conda、python等180多个科学包以及依赖项。
  
## 二、Anaconda的下载
* 官网下载
  https://www.anaconda.com/

* 清华大学镜像
  https://mirrors.tuna.tsinghua.edu.cn/anaconda/archive/

这里 我选择anaconda3-5.3.1-windows 64位版本
![图 1](../images/871aaa8e3fd0de01b5bc9eff5f998794c66c512e899aea4785314a74d81e4c26.png)  


## 三、Anaconda的安装

1. next
![图 2](../images/6802fe8566901404d59a0697e314e4df616b93d25a4bd5d612718f63b7a62ae9.png)  

2. Agree
![图 3](../images/0e8177a848f0a8c1b6c570473c961c5318113a97a33a332465779080347835cf.png)  

3. next
![图 4](../images/65c8da0f372b404e98581fcaf8121ab25b80af86089aa1ff5ae400d35237bef3.png)  

4. 自定义安装路径
![图 5](../images/34f524f2a92c0d4b46f5437cc29c3941645ffaf64a2669f6aed195b9b5860a39.png)  

5. 全部勾选 
这里有两个选项：第二个选项会让你将anconda中的python作为默认的python，如果你安装了pycharm，则pycharm会将anaconda中的python作为解释器。第一个选项，将anconda添加到系统环境，打开命令行，输入python，会显示anaconda的环境
![图 7](../images/a4536e1b9d460f68167bd02a456012f35e6a2f3bfe45160eb4b5f868ca74c707.png)  

6. 跳过
![图 8](../images/28e4471d708a6218821c41a6cbbe4f06a73415aa6d86bdb3f6525590c6893417.png)  

## 四、关于conda
打开 Anaconda prompt 这是Anaconda自带的一个命令行，可以自动进入Anaconda虚拟环境

输入 conda list, 显示anaconda 所有的python 包
![图 9](../images/eb1845a2deb913f6c50d0cee56a20eaf5d7731cb50ba01090e5ee74d6ad390e4.png)  

关于conda:
conda 是一个包管理器

* which conda 或者conda -version命令检查是否安装正确
* conda list 查询
* conda install * 安装包
* conda update * 升级包
* conda remove * 卸载包

比如 ```conda install tensorflow-gpu==2.0.0```

由于conda下载的包默认是从国外的源进行下载的，为了下载更快捷，下面进行更改conda的下载源：执行以下命令

```
conda config --add channels https://mirrors.tuna.tsinghua.edu.cn/anaconda/pkgs/free/

conda config --add channels http://mirrors.tuna.tsinghua.edu.cn/anaconda/pkgs/main/

conda config --set show_channel_urls yes
```


这里配置的时候 我遇到了问题：
```
Warning: 'https://mirrors.tuna.tsinghua.edu.cn/anaconda/pkgs/free/' already解决
```

解决办法：

找到C盘下的用户目录，找到.condarc文件，记事本打开
![图 10](../images/1126a0cd5979a59addaadd9ff244d01c4c42fd6c2a5167089b956d9b66f2d1fd.png)  

之后将default前面的内容全部删除，重新执行上述命令即可。



如果你不希望有这么多的包，可以下载miniconda

https://conda.io/miniconda.html

安装miniconda,然后conda 安装你所需要的包

$conda install numpy



如果你不喜欢使用anaconda:
可以直接使用pip安装，使用豆瓣源进行安装：

```
pip install numpy pandas matplotlib sklearn -i http://pypi.doubanio.com/simple
```
-i 选项表示使用的镜像源 这里安装了numpy matplotlib sklearn 三个安装包

继续安装Jupyter notebook

pip install notebook


## 五、关于创建虚拟环境
新建一个python虚拟环境：

```
创建环境：conda create -n myenv python=3.6

进入环境：source activate myenv

离开环境: source deactivate

列出环境：conda env list

删除环境：conda env remove -n env_name
```

## 六、Jupyter Notebook

### 1. 概述
Jupyter Notebook (此前被称为 IPython notebook) 是一个基于网页的交互式笔记本，支持运行多种编程语言

Jupyter Notebook 的本质是一个Web应用程序，便于创建和共享文学化程序文档，支持实时代码，数学方程，可视化和markdown。用途包括数据清理和转换，数值分析，统计建模，机器学习等等。

## 2. 使用
在anaconda prompt 中输入jupyter notebook 此时浏览器会自动打开jupyter notebook

可以看到这里的Files文件 这个文件显示的是anaconda prompt中进入的文件夹
![图 11](../images/d303ac170fe2d77d94aab3437a2001f8d2c16652adc7d46d8fb42b3d6bff37fc.png)  

如何创建一个新的notebook 文件：

点击new -> python3：
![图 12](../images/63b9da5385b7fbfc01df7f2e8b5fccef0b6ec8c530d7617ac52039e621c26e63.png)  

这个标题是可以进行修改的，比如起名：test1
回到主页面，可以看到创建的文件
![图 13](../images/729557a21c0e52bd1263b54ea801f08acd37ac2f6f177e23d719c5ca303fa549.png)  


在空行输入代码，点击run运行（快捷键：shfit + enter）
![图 14](../images/8b92ba64c2fa4e1c212a5b60b1b526d798fd047ffea65536a1540d4c2365195e.png)  

工具栏介绍：
![图 15](../images/894496fd24fab688f783639097e94edac98d469aea2698b581e3544626f62fb3.png)  

* 第一个是保存按钮
* 第二个是添加行
* 第三个是剪切
* 第四个是复制
* 第五个是粘贴
* 第六、七个是上下移动行
* 第八个是运行
* 第九个是中断
* 第十个是重启
* 第十一个是重启所有代码

关于code选项框：

如果选上code,表示编辑的是代码，如果选markdown表示编辑Markdown文件，如果选上RAW NBConvert 表示不执行 只起到显示文本的作用
![图 16](../images/0c69c9eac1933731749c7bd345c96fe1f04a5a0487ebe16f61457af2e920663a.png)  

选择heading 可以编辑标题
![图 17](../images/4a8003dd6d38270a907c6c462a22556e52050fdf43243569c12ac4fdab6679a4.png)  


同样地，notebook支持TAB键自动补全功能

支持魔术命令
![图 18](../images/79448311496562381a9d268898811b6023eba6babbc65fe09616ff00cd8b974b.png)  
