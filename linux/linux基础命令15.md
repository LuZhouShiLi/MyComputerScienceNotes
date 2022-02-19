# 压缩和解压缩命令

## 1.压缩格式的介绍
Linux默认支持的压缩格式：
* .gz
* .bz2
* .zip
  
说明：
* .gz和.bz2的压缩包需要使用tar命令来压缩和解压缩
* .zip的压缩包需要使用zip命令来压缩，使用unzip命令来解压缩
  
压缩目的：
* 节省磁盘空间
  
## 2.tar命令及其选项的使用

* -c   创建打包文件
* -v   显示打包或者解包的详细信息
* -f   指定文件名称，必须放到所有选项后面
* -z   压缩或者解压缩(.gz)
* -j   压缩或者解压缩(.bz2)
* -x   解包
* -C   解压缩到指定目录

先将三个txt文件写满内容
![图 16](../../images/e559064da572e3daab10a232ac2f65ef67cecc52b1c6cb4b4c1309bfdc2ad780.png)  


将桌面上所有的txt文件打包成一个text.tar.gz格式的压缩包
选项命令格式为zcvf组合形式，表示：压缩成gz形式 创建打包文件 显示打包信息  指定文件名称
![图 17](../../images/ceef4ed2e9995bd51a6cf2b5210fd4ffef2f240d3be7eee1b8f5d67e1e2a95e1.png)  


先将所有的txt文件删除掉，然后进行解压缩
![图 18](../../images/dce02e2c5f528e8229adcb5538b8e41bb0d4a364d81fe82d87a36bc0dfe8fb39.png)  

![图 19](../../images/3469ff8b64fbd699a019c2e358feef22b526652d56a66d967c8f7100b752e1b1.png)  

![图 20](../../images/c109de8750ab76d0bc34b8fd04e3ce2e70576b7700220836eeca659a592e5a17.png)  



解压到指定目录AA
![图 21](../../images/b4cfdc57ae580fee7e993bb8fa565998930197f2ba380bd67d2b140f3bbdc40a.png)  



## 3.zip和unzip命令及其选项的使用

* 命令 zip  压缩成.zip文件格式
* 命令 unzip  解压缩.zip格式文件


unzip命令选项：
-d 解压缩到指定目录


将所有的txt文件压缩成zip文件
![图 22](../../images/9ef69e9a761d48782f4ae0114512694659f5e51bf5c379e1a38d2069ef6da702.png)  


将所有的txt文件解压缩到BB目录
![图 23](../../images/897adf1e1170931769e12fa9a101851305f7b21924fd92d3ee047a9a8e97c389.png)  



说明：
* 压缩文件尽量使用.gz格式，因为占用的空间较小
* 使用zip命令压缩的文件占用空间比较多，当时比较通用，操作更加简单
  

## 4.小结
* .gz和.bz2的压缩文件使用tar命令来完成压缩和解压缩
* .zip的压缩文件使用zip和unzip命令来完成压缩和解压缩
  
  






