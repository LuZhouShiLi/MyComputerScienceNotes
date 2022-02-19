# 一文搞定github&git

## 一、版本控制

### 1.版本控制介绍
&emsp;工业设计领域中使用版本控制管理工程蓝图的设计过程。在IT开发过程中也可以使用版本控制思想管理代码的版本迭代。


（1）个人开发改进迭代

（2）团队协作


### 2.版本控制工具介绍

集中式版本控制工具：CVS、SVN、VSS

分布式版本控制工具：Git、Mercurial、Bazaar、Darcs



版本控制工具应该具备的功能：

* 协同修改
  多人并行修改服务器的同一个文件

* 数据备份
  不仅保存目录和文件的当前状态，还能保存提交过的历史状态

* 版本管理
  在保存每一个版本的文件信息的时候要做到不保存重复数据，以节约存储空间，提高运行效率。这方面SVN采用的是增量式管理的方式，而Git采取了文件系统快照的方式。

* 权限控制
  对团队中参与开发的人员进行权限控制
  对团队外开发者贡献的代码进行审核——Git独有

* 历史记录
  查看修改人、修改时间、修改内容、日志信息
  将本地文件恢复到某一个历史状态

* 分支管理
  允许开发团队在工作过程中多条生产线同时推进任务，进一步提高效率



## 二、Git简介

（1）Git历史
![图 1](../images/466a3490aec5e9210e0a7a7732b5c76b001b87a4510c3726076b07908b60c378.png)  


（2）Git官网
```
https://git-scm.com/

```

（3）Git优势
* 大部分操作在本地完成，不需要联网
* 完整性保证
* 尽可能添加数据而不是删除或者修改数据
* 分支操作非常快捷流畅
* 与Linux命令全面兼容


（4）Git结构
![图 10](../images/4f71f1275ef61a90764137c3b85a4a4adafc0d91bef79411cda4629af9e79e09.png)  



（5）Git和代码托管中心
 代码托管中心的任务：维护远程库

 * 局域网环境下：GitLab服务器
 * 外网环境下：Github  码云

（1）团队内部远程库操作
![图 11](../images/8194795bfcc4f50767206f91f0faf3f8e91c906d8f8f84ff026c734b7999d19b.png)  

使用push命令将本地库推送到github，团队其他成员使用clone命令将代码下载下来，同时对代码进行修改，修改完毕之后使用push命令推送到github远程库。同时可以使用pull命令将代码拉取本地


（2）团队外部成员远程库操作

![图 12](../images/0a133d22f3a475a70976df99bdee8f738fdf1044c7520b8d58232ef698daa3ea.png)  

团队外的成员如果想使用代码 首先需要进行fork，将代码变成自己的远程库，同时可以在自己的远程库进行clone、push操作，如果想要将自己的代码上传到原始的远程库，那就需要先提出pull request请求，审核之后进行merge合并。



（6）Git安装

  * 双击 选择安装路径
  ![图 2](../images/4c247d70f885e5f0ea4e92a97c7a2fdd659c6b59699c4aab86f09455276be1c9.png)  


  * 保持默认设置
  ![图 3](../images/b01537fddf0da75aceeaf9ac1e2ed5c8fd4022ee799c7ceeff3649936e7f6551.png)  


  * 选择默认的版本编辑器（Linux下使用vim）
  ![图 4](../images/1187a69cc4b89ab2bd448cf079a5cb3828ccfd0de2e6ca366e4ba8cf36734dad.png)  


  * 选择环境变量  选择第一个（完全不修改PATH环境变量，仅仅在bash中使用Git）
  ![图 5](../images/7efbb539712c001287d66c04a0c33b4b185f7801b065683b4acba67b2d44b308.png)  

  * 选择默认值
  ![图 6](../images/b23b7ccd1144818d980041bc66bb018892ab313b5c9671d574518450d165d79b.png)  

  * 使用默认值
  ![图 7](../images/385265c358531b8639c99315b7e221015bfb7b41b77449e71e0d5cb7cdb454ee.png)  

  * 使用git bash默认的终端
  ![图 8](../images/135cc4074e34c24e53cefd663fa1ab6d6c2af98bbff49be102bf351781b1e6de.png)  


  * 使用默认值，下一步install
  ![图 9](../images/f0ab164cf4e7b927ee3dd87f88d9799f5890e0132fbc0ddb7865a4f8f3abb17e.png)  



## 三、Git命令行操作

### 3.1 本地库初始化

* 命令：git init
* 效果：
  
  在D盘新建一个Agit文件夹，进入文件夹，右键菜单选择git bash
  ![图 1](../images/a3d3b8dcff1ad9141312ca232db019c1c52be6ad7b0ac1867a5c509dc31e7b5f.png)  

* 注意：.git目录中存放的是本地库相关的子目录和文件，不要删除，也不要胡乱修改。


### 3.2 设置签名

* 形式：用户名：tom
  Email地址：goodMorning@outlook.com

* 作用：区分不同开发人员的身份
* 辨析：这里设置的签名和登录远程库（代码托管中心）的账号、密码没有任何关系
* 命令
  * 项目级别/仓库级别：仅在当前本地库范围内有效
    * git config user.name tom_pro
    * git config user.email goodmorning@outlook.com
  
  * 系统用户级别：登录当前操作系统的用户范围
    * git config --global user.name tom_glb
    * git config --global goodMorning_glb@outlook.com

  * 级别优先级：项目级别优先于系统用户级别，二者都有采用项目级别的签名


项目级别效果图：
![图 2](../images/9e236fc5dcead2a28afae55d4e80f3b210698a1bd117d38332759834b4c073ae.png)  

.git文件夹中的config文件就存放着签名

系统用户级别效果图：
![图 3](../images/f0c5b39bdfed02a03b49d7e888778780288578c223a6a5b955d5008063dc01b4.png)  

当前用户的家目录下有个gitconfig文件存放着签名信息：~/.gitconfig文件


### 3.3 git添加提交以及查看状态操作

* 使用git status命令查看状态
![图 4](../images/94b0d59d7ea29ba8077c033df426e46c1611f5264c91730b2eb523c647695b40.png)  


* 使用 git add good.txt 将good.txt文件提交到暂存区
![图 5](../images/018fedf8ab3dcefc479977c11262d34103ccbc7aca16deda8be9c9f621bca1ab.png)  

* 使用 git rm --cached good.txt 删除该文件，good.txt 成了未追踪的文件
![图 6](../images/11c0af80dab76bfdfd14025a3a244c85548a0fa86bb01e0e6584d81169afd918.png)  

* 使用 git commit good.txt 将文件提交（进入vim 编辑器 编写提交信息）
![图 7](../images/9b6e5cc3c2938badfaf988325924eca2f50fb55e5f289b5c20a35bbb50633848.png)  


* 如果提交过后，又对good.txt文件进行了修改，那么需要再次进行提交
![图 8](../images/bc8e3b9f02df7d7af5a91520aa57044f8577d3a052e0fb390ad21f2df040c0ea.png)  
![图 9](../images/ab880ae5387d9a3b487648795b6b767b9555a2e9cfbe927a785894a7f13cb274.png)  
![图 10](../images/956b46738bb2c6c38977b673fcc54a7c7a34c076885f1c127a641b653c841dc0.png)  


### 3.4 版本穿梭测试的准备工作

使用git log命令查看日志信息
![图 11](../images/e97247676baae64ad8724764acaa9454cb68572d99d5819adef2f353674e4883.png)  


### 3.5 查看历史记录的几种不同方式

* 加上参数：--pretty=oneline  可以一行显示
![图 12](../images/c24f0fe20e46a7e6b72f6d92a682584a2114da8211ed83bf4eea33a16c72b6e3.png)  


* 加上参数：reflog: 显示提交信息 HEAD@{移动到当前版本需要多少步}
  ![图 13](../images/6f77e1e38d5898e0be14a0730f6835585c8fec15ea857b374980633bf70c66c7.png)  


### 3.6 前进后退历史版本操作

历史版本前进后退操作其实是上面的HEAD指针的移动操作，当前HEAD指针所指向的是离我们最近的一个版本。

执行版本前进后退的具体操作有三种：

（1）基于索引值操作

代码：```git reset --hard 索引值```，后退到索引值代表的版本 
![图 14](../images/47f1902d8b913f1ed9e4109a2d72bba531af96b9501a03262bd6ca6cbde50d63.png)  

可以看到，指针已经移动到最开始的版本


（2）使用^符号
只能后退。使用几个^符号，就后退几个版本

![图 15](../images/2fc40c548070a03a2c2cc642d52e86ca2e83c413dcbde32565830e9974747a9b.png)  


（3）使用~符号
只能后退，git reset --hard HEAD~n，只能后退n步


### 3.7 reset命令的三个参数对比

* --soft参数
  仅仅在本地库移动HEAD指针
![图 1](../images/68a49852688064cfc4b0a1b3346d9003f361436b1b6efab2277ef522bb7b580c.png)  

这里可以看到在本地库移动Head指针，但是暂存区并没有同步（所以这里出现了good.txt被修改的迹象，意味着你只add到暂存区，并没有提交到本地库）


* --mixed参数
  在本地库移动HEAD指针
  重置暂存区
![图 2](../images/82b2d9bdc0cc02cf890003e080b27003dcfb1ecb756236e872051f3ad1493b0a.png)  




* --hard参数
  在本地库移动HEAD指针
  重置暂存区
  重置工作区

使用```git reset --hard HEAD``` 对三个工作区都进行重置


### 3.8 本地库删除文件并且找回
![图 3](../images/632eeab90d43a60d86262ef425b72f4dd8b986d7912f716b4f20489980dd534a.png)  

要找回被删除的文件，只需要会退一个版本即可。
![图 4](../images/0dcf77f984f514b2b3975204f0bda166e1dad2054d72951cdf43dc1a624bc999.png)  


### 3.9 删除文件并找回总结
前提：删除前，文件存在时的状态提交到了本地库
操作：git reset --hard[指针位置]

* 删除操作已经提交到本地库: 指针位置指向历史记录
* 删除操作尚未提交到本地库：指针位置使用HEAD


### 3.10 比较文件

* git diff[文件名]
  将工作区中的文件和暂存区进行比较

* git diff[本地库中历史版本][文件名]
  将工作区中的文件和本地库历史记录比较

* 不带文件名比较多个文件

![图 5](../images/ba50bd8a573b8da9354514a79fd899a39b9ad1ab4ada52d2d53c45c72e72757b.png)  




## 四、分支操作

### 4.1 分支概述
&emsp;在版本控制过程中，使用多条线同时推进多个任务。

&emsp;好处：各个分支在开发过程中，如果某一个分支开发失败，不会对其他分支有任何影响。失败的分支删除重新开始即可。



### 4.2 分支操作命令

常用操作命令:

```git
git branch -v # 查看当前所有分支 以及 当前所在分支
git branch 分支名  # 新建一个分支
git checkout 分支名 # 切换分支

# 合并分支操作

* 第一步：切换到接受修改的分支（被合并，增加新内容）
git checkout [被合并的分支名]

* 第二步：执行merge命令
git merge [有新内容分支名]

```

![图 6](../images/6ef3abdf2464bf25be76119ae96a1fb65dbd4abc10d4b17a76a27a0f187da40c.png)  

![图 7](../images/6fab7541902cebe28acc41d2ec6bbb5d461aee196de035e127f867bfff0b8e0a.png)  


### 4.3 解决分支合并之后产生的冲突

![图 8](../images/eb2e52e17e429299bddb7d945946b130b4e5a7ad91c141903e12558eeba316af.png)  

```
将文件里面冲突的部分去掉即可
然后执行下面的语句：
git add 文件名
git commit -m "日志信息"

```


## 五、Git的基本原理

### 5.1 哈希
![图 9](../images/56a84be2663cd0f8671c432db79109afe6d19903670e46144ff52301a9584bf7.png)  

![图 10](../images/84e1f3d08c5d4befa5f2896264b84778e8c44eb2ea71c499513afda68020e484.png)  


### 5.2 git保存版本的机制
&emsp;以文件变更列表的方式存储信息。这类系统将他们保存的信息看作是一组基本文件和每个文件随时间逐步累积的差异。

![图 11](../images/550fb68d2cac5e002cc6d4cf29ffa98aa10bb4b10e8b8dd3c8352355eba84811.png)  


### 5.3 git文件管理机制
&emsp;Git将数据看作是小型文件系统的一组快照。每次提交更新时Git都会对当前的全部文件制作一个快照并保存这个快照的索引。为了搞笑，如果文件没有修改，Git不在重新存储该文件，而是只保留一个链接指向之前存储的文件。所以Git的工作方式可以称之为快照流。


## 六、GitHub相关操作

### 6.1 首先创建一个本地库

![图 12](../images/30c56bf341dc07cfdda7dbd73d52871a7065e8764c69870e1fc24e8f26342a1e.png)  


### 6.2 创建一个远程库

![图 13](../images/20f8d48c745054807ad219b43a36c3d831a9f2c78937e811339027f8c0a1a38b.png)  

![图 17](../images/c959564f2e3a99eb2fb5deced6147865412e082c8af60068fb21c3eea05e855b.png)  



（1）远程仓库创建一个文件

点击create new file 可以在远程仓库创建一个文件
![图 18](../images/72a785ce864d858566ff227c8ba10816ba8d458ff0683258d7c61496dae0393b.png)  

![图 19](../images/0d7aebc169a04c78ff6f608d597ea876dc2c0382ceec86d0455b9399ee07275a.png)  


（2）远程仓库编辑文件
![图 20](../images/548f14fe8fc597c24e7ad447ff01969beb1b7c3036ae7a98eecd3ceb7290fd00.png)  

![图 21](../images/1e200de459613bafe164641f5622ba9e1db3b3500e5db82e5ccf65da6c14e75c.png)  

![图 22](../images/b1f39ff4e51c9704bdc3c04502fbe7b22095616f59a7112a6372d18221bcdd6a.png)  


（3）上传文件至远程仓库 upload files
![图 23](../images/f69711f12e43fbaabfad1b7ece36e3ed86f84c169c256ab5fdf712b2a594ca9a.png)  


（4）查找文件  find files
![图 24](../images/ea7357733a4a6695baf2233fde3764cc86483e67b67ee4936359d2cbce17b966.png)  


### 6.3 Github Issues

作用：发现代码BUG,但是目前没有成型的代码，需要讨论时用，或者使用开源项目出现问题时使用

情景：张三发现李四开源git库吗，发现一个问题并提交了一个issue,李四隔天登陆在github主页看到通知 冰河张三进行交流，最后关闭issue。

![图 25](../images/9c7dccdc3fa4ba9de671fef08867b1cc65902b60018d1bf46da34677515f3268.png)  

提交一个issue
![图 26](../images/5c592f10e027415a8b758e7dc0191ca1de666c90f3eaa2374bfec349c21e1f58.png)  



复制克隆项目：Fork
情景：张三fork了李四的项目，相当于张三复制了李四的项目，所以自己也单独有了一样名称的仓库（该仓库会声明来自于李四，但是独立存在）

![图 27](../images/1d2190e18427b74fab2a4ac42cfdd36155fa39ed4b2a343720ff489c44a5d972.png)  




发送请求：pull request

情景：张三修改了fork的项目中的文件，希望更新到原来的仓库，这个时候他要新建一个pull request

![图 28](../images/0a974447119705bcd52a68a4a4b24778c88f72c1dbce70a642d89ad0ee862941.png)  

![图 29](../images/1e2c436ca6799a47f1278f0984847012e2f64e058ca2e74a4d4076980147733d.png)  

步骤总结：

```
fork 项目
修改自己仓库的项目代码
新建pull request
等待作者操作审核

```


### 6.4 为远程库创建一个别名
进入这个仓库，复制HTTPS仓库地址
![图 15](../images/a785093d23c379f1ddc092c2370a52cd4c60b2a1de0767b5396b8a01d6e01fa5.png)  

使用git remote -v 可以查看所有的仓库地址别名，使用git remote add 别名 仓库地址 对仓库起一个别名

```
git remote -v

git remote add 别名 仓库地址

```

![图 14](../images/9ce03d0756205f6429d86cf625f2a764e7b8a2224bbfb9d5e31de46e8c867868.png)  


### 6.5 git clone操作
将远程仓库（github对应的项目）复制到本地
![图 30](../images/45a844993b33a579e6ccf719b34d3e4ab943cd02da9be326cb8663ff3885ec16.png)  



### 6.4 push操作

```
git push origin master #指定仓库名与分支名

```

在push操作之前先生成一个SSH公钥，
![图 1](../images/488e7bdfe2266ad66c17f48e20139e31f57dfa853b7611d6f3a0541e29139674.png)  

![图 2](../images/9eb79e85099d9c75902ef446f9c24fd0b4f4117bf2acb6b629b53270b2ce880e.png)  

![图 3](../images/ff20ebfb6b365b03b3fe8915e7267225118bb24abf33989a6eb280caadac4d6a.png)  


需要执行如下代码：

```
设置git账户：

git config user.name # 查看账户名
git config user.email # 查看邮箱


# 这两个是设置全局签名
git config --global user.name "账户名"
git config --global user.email "邮箱名" 

# 查看是否生成SSH公钥
cd ~/.ssh

# 生成命令
ssh-keygen -t rsa -C "邮箱"

# 需要三次回车

# 查看密钥SSH
cat ~/.ssh/id_rsa.pub

# 复制你的SSH 打开你的github 点击settings 将SSH复制上去

# 查看是否成功
ssh -T git@github.com


```

首先，你需要新建一个远程仓库，然后为你的远程仓库起一个别名（参考上面的操作）

![图 4](../images/89009c54e25cd5bed2fcda7f867b8577d4a4c8ddb20b88ecb41330f4cf1d4fed.png)  


之后使用 git push -u 仓库别名  分支名  推送数据
![图 5](../images/f398cdd4fd73f5b0031d674bbf30c537e2ed68144f1f39f40e9b8b68281c9e83.png)  

