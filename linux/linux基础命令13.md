# 文本搜索命令

## 1.grep命令的使用
![图 5](../../images/0d7ce457b93771f35a91a3659e610b7382c16f07d686debe732a8cd1bd8570eb.png)  



## 2.grep命令选项的使用
* -i 忽略大小写
* -n 显示匹配行号
* -v 显示不包含匹配文本的所有行

-i 忽略大小写
![图 6](../../images/5f29af6a4abddcaf0f1a37dec150fc6955b20d99245218938bed020885ec5325.png)  

-n 显示行号
![图 7](../../images/c4a63305ed672271f4223d70ccc0ccb61dd480cbd1c6c314bf1c27d68cce3299.png)  


-v 显示不包含匹配文本的所有行
![图 8](../../images/94398f12147d01627e542da2a4aa1cf7430944064b91e4be3d1bff91a7be115d.png)  


## 3.grep命令结合正则表达式的使用
* ^    以指定的字符串开头
* $    以指定的字符串结尾
* .    匹配一个非换行符的字符
  
![图 9](../../images/fca275def13e0b4ed68041832267929dc52dd084f71895d279094116a7a474df.png)  

![图 10](../../images/c97612d39ac1ada5108b1aaae9a7b72967c8e71fbb7110f60985e8f126d0227c.png)  


![图 11](../../images/24b3ddc6e1c20a194a0217ef3ce139e3afa4ec667f839d9aac29e3df1038cbd8.png)  


grep命令与管道命令相结合
![图 12](../../images/5b9c64bd9eab9544a3a23d15c6662204754f0eb19bba57f10cdeeccad72a6cc3.png)  


## 4.扩展
* grep命令还可以文本搜索管道中的内容，比如：ls / | grep 'lib'

* 在使用grep命令的时候还可以省略搜索内容的引号，比如：ls / | grep lib,grep hello 1.txt


## 5.小结
* grep命令是完成文本操作的
* 文本搜索的命令格式：grep 选项 文本搜索内容

