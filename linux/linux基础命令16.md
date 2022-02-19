# 文件权限命令

## 1.chmod命令的介绍

chmod修改文件权限的两种方式：
* 字母法
* 数字法
  

## 2.chmod字母法的使用

角色说明：

* u      user,表示该文件的所有者
* g      group,表示用户组
* o      other,表示其他用户
* a      all,表示所有用户

权限设置说明：

* '+'  增加权限
* '-' 撤销权限
* '=' 设置权限
  
* r  可读
* w  可写
* x  可执行
* '-' 无任何权限


文件拥有者增加读权限或者减少读权限
![图 24](../../images/73fa88770de44c1b7ef17df949b6bc5f2ef7a33636a3149e8a4965aa87ea57d1.png)  


文件拥有者增加写权限或者减少写权限
![图 25](../../images/c74fffce33244e305779e683ab46eaf1cf2957efa278bacef81a7fcfe7959b58.png)  


创建一个py文件，编辑文件  添加hello world语句 权限不够
![图 26](../../images/9443b184d51a964cdb71531f3490c3b562225e812f515ee6fd204589c1212457.png)  


添加权限之后 再执行 但是还是会报错（因为系统不知道使用哪个Python解释器）
![图 27](../../images/191da2514961890405ac32e9f0aeaab0ab835c7ac6ce288e52eb4becc6b12e75.png)  

使用python3解释器执行py文件
![图 28](../../images/d5758a3c7308f51763769d5db8382276b8df44941fc3dd39792b1a76af5a5fb0.png)  



使用which python3 查看Python解释器的位置
![图 29](../../images/1da287395f50d24283c6366146c1832e7bd553575d81ab542e2b722e624e58da.png)  

将位置进行复制 添加到py文件 声明指定的python解释器
![图 30](../../images/6356fa26a216368fc44b222cdfff559f1fddf8e2cb62f116a06532c09a6bf3a0.png)  



之后再执行就没有问题
![图 31](../../images/2a57e847bb34ec280a74d49efdd64130384eb4e9ce19f0786cd85bd42b5929c7.png)  



