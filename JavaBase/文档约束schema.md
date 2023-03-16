# 文档约束schema

## schema与DTD之间的区别
![图 1](../images/cad2d2379909bcf688539d3c38e0bc0ccbf0a63241f5adb484108d2072682277.png)  

## schema的入门案例

![图 2](../images/f2703235047e534de865075a26c58ec45c025eff863739d31673f5ba9894ec81.png)  

```java
<?xml version="1.0" encoding="UTF-8" ?>
<schema
        xmlns="http://www.w3.org/2001/XMLSchema"
        targetNamespace="http://www.baidu.com"
        elementFormDefault="qualified">

<!--    定义persons复杂元素-->
    <element name="persons">
        <complexType>
            <sequence>
<!--                定义person复杂元素-->
                <element name = "person">
                    <complexType>
                        <sequence>
<!--                            定义name和age元素  定义简单元素-->
                            <element name = "name" type = "string"></element>
                            <element name = "age" type = "string"></element>
                        </sequence>
                    </complexType>
                </element>

            </sequence>
        </complexType>

    </element>



</schema>

```

person.xml
```java
<?xml version="1.0" encoding="UTF-8" ?>

<persons>
    <person id = "1">
        <name>张三</name>
        <age>23</age>
    </person>
</persons>
```

## 引入schema约束文件

```java
<?xml version="1.0" encoding="UTF-8" ?>

<persons
    xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
    xmlns="http://www.baidu.com"
    xsi:schemaLocation="http://www.baidu.com person.xsd"
>
    <person>
        <name>张三</name>
        <age>23</age>
    </person>
</persons>

```

## schema定义属性



![图 3](../images/0022f5ff4190470f46e97f9ab35bcdff022827ea67fb4f07e92dad5a71f0cc1f.png)  

```java
<?xml version="1.0" encoding="UTF-8" ?>
<schema
        xmlns="http://www.w3.org/2001/XMLSchema"
        targetNamespace="http://www.baidu.com"
        elementFormDefault="qualified">

<!--    定义persons复杂元素-->
    <element name="persons">
        <complexType>
            <sequence>
<!--                定义person复杂元素-->
                <element name = "person">
                    <complexType>
                        <sequence>
<!--                            定义name和age元素  定义简单元素-->
                            <element name = "name" type = "string"></element>
                            <element name = "age" type = "string"></element>
                        </sequence>
<!--                        添加一个属性-->
                        <attribute name = "id" type = "string" use = "required"></attribute>
                    </complexType>
                </element>

            </sequence>
        </complexType>

    </element>



</schema>
```

person.xml

```java
<?xml version="1.0" encoding="UTF-8" ?>

<persons
    xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
    xmlns="http://www.baidu.com"
    xsi:schemaLocation="http://www.baidu.com person.xsd"
>
    <person id = "1">
        <name>张三</name>
        <age>23</age>
    </person>
</persons>

```
