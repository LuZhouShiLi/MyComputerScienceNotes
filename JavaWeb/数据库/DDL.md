# DDL

## 数据库、数据表、数据之间的关系

![图 1](../../images/4bb3d26f4b5b0fa09ce1fcd0fb473e2d5804dde6940fff12eff02119a86b49b1.png)  

## SQL介绍

![图 2](../../images/1d632bb91b13d7d76adf0241c4276e0190a3ea7b21f95242c38b1f9f7b82b935.png)  


## DDL 查询和创建数据库

![图 3](../../images/dbc85a2ace6568df763940d40127acb75ef85cb7130292f8db49ab36607fd83d.png)  


```sql

-- 查询所有的数据库
SHOW DATABASES;

-- 查询mysql 数据库的创建语句
SHOW CREATE DATABASE mysql;

-- -- 创建数据库
-- CREATE DATABASE db1;

-- 创建数据库 如果不存在进行创建
CREATE DATABASE IF NOT EXISTS db2;

-- 指定字符集创建数据库
CREATE DATABASE db3 CHARACTER SET utf8;

CREATE DATABASE IF NOT EXISTS db4 CHARACTER SET gbk; 
```

![图 4](../../images/209319d61cd8ed67056d8e8bb6af1be174d5202268065b905c6779025892c23e.png)  

## DDL 修改删除数据库

![图 6](../../images/0322eb45ca789ec8456d1cf17d6484e85b042d9c0848290e38d57567439b41ce.png)  

```sql
-- 修改数据库的字符集
ALTER DATABASE db4 CHARACTER SET utf8;

-- 查看db4数据库的字符集
SHOW CREATE DATABASE db4;

-- 删除指定数据库
-- DROP  DATABASE db1;

-- 如果数据库存在进行删除
DROP DATABASE IF EXISTS db2;

-- 使用数据库
USE db4;
```

## 数据表的查询

![图 7](../../images/7c0cee00d3447fffabf047d438afe832353644bd4894bad8db068b5bc968a36b.png)  

```sql
-- 使用数据库
USE mysql;

-- 展示db4有多少数据表
SHOW TABLES;

-- 查询表的结构
DESC USER;

-- 查看mysql数据库中user表字符集
SHOW TABLE STATUS FROM mysql LIKE 'user';

```

## DDL创建数据表

![图 8](../../images/c1a14c5aa96c0ab48f0ccb1b6d8b3e3ca341b1e9a5bb2897af30be4b6f57d470.png) 

**最后一个字段不要加上逗号**

```sql
-- 创建表格
CREATE TABLE product1(
	id INT,
	NAME VARCHAR(20),
	price DOUBLE,
	stock INT,
	insert_time DATE
);

```

## DDL 修改数据表

![图 9](../../images/e2bffb58a53797a3b246dd371e99729eb934fc8ee1f7578a81b5b4075e9382ce.png)  

```sql
-- 修改表名
ALTER TABLE product2 RENAME TO product3;

-- 查看db4数据库中product3数据表的字符集
SHOW TABLE STATUS FROM db3 LIKE 'product3';

-- 修改product3数据表的字符集gbk
ALTER TABLE product3 CHARACTER SET gbk;

-- 单独添加一列  product3
ALTER TABLE product3 ADD color VARCHAR(10);

-- 修改color 的数据类型
ALTER TABLE product3 MODIFY color INT;

-- 查看表的详细结构
DESC product3;


-- 将color 修改列名以及数据类型
ALTER TABLE product3 CHANGE color address VARCHAR(200);

-- 删除address
ALTER TABLE product3 DROP address;
```

## 删除数据表

![图 10](../../images/cce447c8363ad69229422d77a1935c27b12794c47894e76788677e8b08c26dcc.png)  


