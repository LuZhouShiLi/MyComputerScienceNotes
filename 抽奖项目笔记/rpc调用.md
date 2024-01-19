# RPC调用以及系统初步搭建


## 工程的总POM文件

* modelVersion: 模型版本，指定POM模型的版本，目前使用的是Maven 4.0.0版本。

* groupId: 项目的组织标识符，通常是组织的域名倒序。在这里是 cn.itedus.lottery。

* artifactId: 项目的唯一标识符，通常是项目的名称。在这里是 Lottery。

* packaging: 项目的打包方式，这里是 pom，表示这是一个聚合项目，不生成可执行的JAR或WAR文件，而是用于管理其他子模块。

* version: 项目的版本号，这里是 1.0-SNAPSHOT，表示当前是一个开发中的版本。

* modules: 定义了项目包含的子模块，这里包括了 lottery-application、lottery-domain、lottery-infrastructure、lottery-interfaces、lottery-rpc、lottery-common。

* properties: 定义了一些项目的属性，例如JDK版本和编码方式。

* parent: 指定了项目的父级，这个项目是基于Spring Boot的，继承自 spring-boot-starter-parent，版本是 2.3.5.RELEASE。

* build: 构建配置的部分，定义了一些构建插件。

* maven-surefire-plugin: Maven的测试插件，这里配置了跳过测试（<skipTests>true</skipTests>）。

* maven-compiler-plugin: Maven的编译插件，这里配置了Java源代码和目标字节码的版本都是 1.8。
  
* <maven-surefire-plugin>：这是用于执行测试的Maven插件。在这里，配置了插件的版本为 2.20，并且通过 <skipTests>true</skipTests> 配置跳过测试。这意味着在构建项目时将不会执行测试用例。

* <maven-compiler-plugin>：这是Maven的编译插件，用于编译Java源代码。在这里，配置了源码的Java版本和生成的字节码的目标Java版本，都为 8。这表示项目的源代码和生成的字节码都将兼容Java 8。


```xml
<?xml version="1.0" encoding="UTF-8"?>
<project xmlns="http://maven.apache.org/POM/4.0.0"
         xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
         xsi:schemaLocation="http://maven.apache.org/POM/4.0.0 http://maven.apache.org/xsd/maven-4.0.0.xsd">
    <modelVersion>4.0.0</modelVersion>

    <groupId>cn.itedus.lottery</groupId>
    <artifactId>Lottery</artifactId>
    <packaging>pom</packaging>
    <version>1.0-SNAPSHOT</version>

    <modules>
        <module>lottery-application</module>
        <module>lottery-domain</module>
        <module>lottery-infrastructure</module>
        <module>lottery-interfaces</module>
        <module>lottery-rpc</module>
        <module>lottery-common</module>
    </modules>

    <properties>
        <!-- Base -->
        <jdk.version>1.8</jdk.version>
        <sourceEncoding>UTF-8</sourceEncoding>
    </properties>

    <parent>
        <groupId>org.springframework.boot</groupId>
        <artifactId>spring-boot-starter-parent</artifactId>
        <version>2.3.5.RELEASE</version>
        <relativePath/> <!-- lookup parent from repository -->
    </parent>

    <build>
        <plugins>
            <plugin>
                <groupId>org.apache.maven.plugins</groupId>
                <artifactId>maven-surefire-plugin</artifactId>
                <version>2.20</version>
                <configuration>
                    <skipTests>true</skipTests>
                </configuration>
            </plugin>
            <plugin>
                <groupId>org.apache.maven.plugins</groupId>
                <artifactId>maven-compiler-plugin</artifactId>
                <configuration>
                    <source>8</source>
                    <target>8</target>
                </configuration>
            </plugin>
        </plugins>
    </build>

</project>

```


## Common模块

* 定义通用的类，比如响应

### Pom文件配置


* parent：定义了当前项目的父模块。在这里，父模块的信息包括了 groupId 为 cn.itedus.lottery、artifactId 为 Lottery、version 为 1.0-SNAPSHOT。

* modelVersion：指定 POM 模型的版本，这里是 Maven 4.0.0 版本。

* packaging：定义了项目的打包方式，这里是 jar，表示将会生成一个 JAR 文件。

* artifactId：项目的唯一标识符，这里是 lottery-common。

* build：构建配置的部分，包含了生成最终产物的相关设置。

* finalName：定义生成的 JAR 文件的名称，这里是 lottery-common。

* plugins：包含了 Maven 插件的配置信息。

* maven-compiler-plugin：Maven 的编译插件，用于配置 Java 编译的相关参数。在这里，指定了 Java 源码和目标字节码的版本，都使用了变量 ${jdk.version}，表示从项目的属性中获取。同时，指定了编译器版本为 1.8。

```xml
<?xml version="1.0" encoding="UTF-8"?>
<project xmlns="http://maven.apache.org/POM/4.0.0"
         xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
         xsi:schemaLocation="http://maven.apache.org/POM/4.0.0 http://maven.apache.org/xsd/maven-4.0.0.xsd">
    <parent>
        <artifactId>Lottery</artifactId>
        <groupId>cn.itedus.lottery</groupId>
        <version>1.0-SNAPSHOT</version>
    </parent>


    <modelVersion>4.0.0</modelVersion>
    <packaging>jar</packaging>

    <artifactId>lottery-common</artifactId>

    <build>
        <finalName>lottery-common</finalName>
        <plugins>
            <plugin>
                <groupId>org.apache.plugins</groupId>
                <artifactId>maven-compiler-plugin</artifactId>
                <configuration>
                    <source>${jdk.version}</source>
                    <target>${jdk.version}</target>
                    <compilerVersion>1.8</compilerVersion>
                </configuration>
            </plugin>
        </plugins>
    </build>

</project>

```
### constants——响应返回的状态


```java
ResponseCode 枚举类：包含了四个枚举常量，每个常量都表示一个响应码和对应的信息。这些常量分别是：

SUCCESS: 表示成功，对应响应码为 "0000"，信息为 "成功"。

UN_ERROR: 表示未知失败，对应响应码为 "0001"，信息为 "未知失败"。

ILLEGAL_PARAMETER: 表示非法参数，对应响应码为 "0002"，信息为 "非法参数"。

INDEX_DUP: 表示主键冲突，对应响应码为 "0003"，信息为 "主键冲突"。

构造函数：ResponseCode 枚举类中定义了一个私有的构造函数，用于初始化每个枚举常量的 code 和 info 属性。

getCode() 方法：用于获取枚举常量的响应码。

getInfo() 方法：用于获取枚举常量的信息。

```


```java
public class Constants{

    // 定义枚举类
    public  enum ResponseCode{

        SUCCESS("0000","成功"),

        UN_ERROR("0001","未知失败"),

        ILLEGAL_PARAMETER("0002","非法参数"),

        INDEX_DUP("0003","主键冲突");

        private String code;

        private String info;

        ResponseCode(String code,String info){
            this.code = code;
            this.info = info;
        }

        public String getCode(){
            return code;
        }

        public  String getInfo(){
            return info;
        }

    }
}

```


### Result-响应返回的结果


* Serializable 接口：Result 类实现了 Serializable 接口，这表示该类的对象可以被序列化，可以在网络上传输或保存到文件中。

* serialVersionUID：标识类的版本号，用于在反序列化时验证类的版本一致性。

* code 和 info 属性：分别表示响应码和对应的信息。

* buildResult 静态方法：用于构建自定义的响应结果，接受响应码和信息作为参数。

* buildSuccessResult 和 buildErrorResult 静态方法：分别用于构建成功和失败的响应结果，使用了预定义的成功和失败的响应码和信息。

* Result 构造函数：接受响应码和信息作为参数，用于创建 Result 的实例。

* getCode 和 getInfo 方法：用于获取响应码和信息。

* setCode 和 setInfo 方法：用于设置响应码和信息。

```java
public class Result implements Serializable{
    private static  final long serialVersionUID = -3826891916021780628L;

    private String code;// code代表响应码

    private String info;// 代表对应的信息

    public static Reult buildResult(String code,String info){
        return new Result(code,info);
    }

    // 响应成功
    public static buildSuccessResult(){
        return new Result(Constants.ResponseCode.SUCCESS.getCode(),Constants.ResponseCode.SUCCESS.getInfo());
    }

    public static buildErrorResult(){
        return new Result(Constants.ResponseCode.UNERROR.getCode(),Constants.ResponseCode.UNERROR.getInfo());
    }


    public Result(String code,String info){
        this.code = code;
        this.info = info;
    }

    public String getCode(){
        return code;
    }


    public void setCode(String code){
        this.code = code;
    }

    public String getInfo(){
        return info;
    }

    public void setInfo(String info){
        this.info = info;
    }
}

```

## lottery-infrastructure

* 基础架构层
* 定义数据仓储
* 定义实体类Activoty
* 定义DAO


### pom文件


```xml

<?xml version="1.0" encoding="UTF-8"?>
<project xmlns="http://maven.apache.org/POM/4.0.0"
         xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
         xsi:schemaLocation="http://maven.apache.org/POM/4.0.0 http://maven.apache.org/xsd/maven-4.0.0.xsd">
    <parent>
        <artifactId>Lottery</artifactId>
        <groupId>cn.itedus.lottery</groupId>
        <version>1.0-SNAPSHOT</version>
    </parent>
    <modelVersion>4.0.0</modelVersion>

    <artifactId>lottery-infrastructure</artifactId>

    <packaging>jar</packaging>

<!--    引入springboot框架的依赖-->
    <dependencies>
        <dependency>
            <groupId>org.mybatis.spring.boot</groupId>
            <artifactId>mybatis-spring-boot-starter</artifactId>
            <version>2.1.4</version>
        </dependency>
    </dependencies>

    <build>
        <finalName>lottery-infrastructure</finalName>

         <plugins>
             <plugin>
                 <groupId>org.apache.maven.plugins</groupId>
                 <artifactId>maven-compiler-plugin</artifactId>
                 <configuration>
                     <source>${jdk.version}</source>
                     <target>${jdk.version}</target>
                     <compilerVersion>1.8</compilerVersion>
                 </configuration>
             </plugin>
         </plugins>
    </build>



</project>

```


### DAO

```java
package cn.itedus.lottery.infrastructure.dao;

import cn.itedus.lottery.infrastructure.po.Activity;
import org.apache.ibatis.annotations.Mapper;

@Mapper
public  interface IActivityDao{
   void insert(Activity req);// 插入一条活动
   
   Activity queryActivityById(Long activityId);// 查询活动   根据活动编号
}

```


### PO


```java
package cn.itedus.lottery.infrastructure.po;

import java.util.Date;

public class Activity {

    // 自增ID
    private Long id;

    // 活动ID
    private Long activityId;

    // 活动名称
    private String activityName;

    // 活动描述
    private String activityDesc;

    // 开始时间
    private Date beginDateTime;

    // 结束时间
    private Date endDateTime;

    // 库存
    private Integer stockCount;

    // 每人可参与次数
    private Integer takeCount;

    // 活动状态：编辑、提审、撤审、通过、运行、拒绝、关闭、开启
    private Integer state;

    // 创建人
    private String creator;

    // 创建时间
    private Date createTime;

    // 修改时间
    private Date updateTime;

    public Long getId() {
        return id;
    }

    public void setId(Long id) {
        this.id = id;
    }

    public Long getActivityId() {
        return activityId;
    }

    public void setActivityId(Long activityId) {
        this.activityId = activityId;
    }

    public String getActivityName() {
        return activityName;
    }

    public void setActivityName(String activityName) {
        this.activityName = activityName;
    }

    public String getActivityDesc() {
        return activityDesc;
    }

    public void setActivityDesc(String activityDesc) {
        this.activityDesc = activityDesc;
    }

    public Date getBeginDateTime() {
        return beginDateTime;
    }

    public void setBeginDateTime(Date beginDateTime) {
        this.beginDateTime = beginDateTime;
    }

    public Date getEndDateTime() {
        return endDateTime;
    }

    public void setEndDateTime(Date endDateTime) {
        this.endDateTime = endDateTime;
    }

    public Integer getStockCount() {
        return stockCount;
    }

    public void setStockCount(Integer stockCount) {
        this.stockCount = stockCount;
    }

    public Integer getTakeCount() {
        return takeCount;
    }

    public void setTakeCount(Integer takeCount) {
        this.takeCount = takeCount;
    }

    public Integer getState() {
        return state;
    }

    public void setState(Integer state) {
        this.state = state;
    }

    public String getCreator() {
        return creator;
    }

    public void setCreator(String creator) {
        this.creator = creator;
    }

    public Date getCreateTime() {
        return createTime;
    }

    public void setCreateTime(Date createTime) {
        this.createTime = createTime;
    }

    public Date getUpdateTime() {
        return updateTime;
    }

    public void setUpdateTime(Date updateTime) {
        this.updateTime = updateTime;
    }
}


```


## lottery-interfaces


### pom文件

* packaging：定义了项目的打包方式，这里是 war，表示将会生成一个 WAR 文件
* lottery-interfaces 是整个程序的出口，也是用于构建 War 包的工程模块，所以你会看到一个 <packaging>war</packaging> 的配置。
* 在 dependencies 会包含所有需要用到的 SpringBoot 配置，也会包括对其他各个模块的引入。
* 在 build 构建配置上还会看到一些关于测试包的处理，比如这里包括了资源的引入也可以包括构建时候跳过测试包的配置。

```xml
<?xml version="1.0" encoding="UTF-8"?>
<project xmlns="http://maven.apache.org/POM/4.0.0"
         xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
         xsi:schemaLocation="http://maven.apache.org/POM/4.0.0 http://maven.apache.org/xsd/maven-4.0.0.xsd">
    <parent>
        <artifactId>Lottery</artifactId>
        <groupId>cn.itedus.lottery</groupId>
        <version>1.0-SNAPSHOT</version>
    </parent>
    <modelVersion>4.0.0</modelVersion>

    <artifactId>lottery-interfaces</artifactId>

    <packaging>war</packaging>

    <dependencies>
        <dependency>
            <groupId>org.springframework.boot</groupId>
            <artifactId>spring-boot-starter-web</artifactId>
        </dependency>
        <dependency>
            <groupId>org.springframework.boot</groupId>
            <artifactId>spring-boot-starter-test</artifactId>
            <scope>test</scope>
        </dependency>
        <dependency>
            <groupId>org.mybatis.spring.boot</groupId>
            <artifactId>mybatis-spring-boot-starter</artifactId>
            <version>2.1.4</version>
        </dependency>
        <dependency>
            <groupId>mysql</groupId>
            <artifactId>mysql-connector-java</artifactId>
            <version>5.1.34</version>
        </dependency>
        <dependency>
            <groupId>com.alibaba</groupId>
            <artifactId>fastjson</artifactId>
            <version>1.2.58</version>
        </dependency>
        <dependency>
            <groupId>org.apache.commons</groupId>
            <artifactId>commons-lang3</artifactId>
            <version>3.8</version>
        </dependency>
        <dependency>
            <groupId>junit</groupId>
            <artifactId>junit</artifactId>
            <version>4.12</version>
            <scope>test</scope>
        </dependency>
        <dependency>
            <groupId>org.apache.dubbo</groupId>
            <artifactId>dubbo</artifactId>
            <version>2.7.1</version>
        </dependency>
        <dependency>
            <groupId>org.apache.dubbo</groupId>
            <artifactId>dubbo-spring-boot-starter</artifactId>
            <version>2.7.1</version>
        </dependency>
        <dependency>
            <groupId>cn.itedus.lottery</groupId>
            <artifactId>lottery-infrastructure</artifactId>
            <version>1.0-SNAPSHOT</version>
        </dependency>
        <dependency>
            <groupId>cn.itedus.lottery</groupId>
            <artifactId>lottery-rpc</artifactId>
            <version>1.0-SNAPSHOT</version>
        </dependency>
    </dependencies>

    <build>
        <finalName>Lottery</finalName>
        <resources>
            <resource>
                <directory>src/main/resources</directory>
                <filtering>true</filtering>
                <includes>
                    <include>**/**</include>
                </includes>
            </resource>
        </resources>
        <testResources>
            <testResource>
                <directory>src/test/resources</directory>
                <filtering>true</filtering>
                <includes>
                    <include>**/**</include>
                </includes>
            </testResource>
        </testResources>
        <plugins>
            <plugin>
                <groupId>org.springframework.boot</groupId>
                <artifactId>spring-boot-maven-plugin</artifactId>
            </plugin>
            <plugin>
                <groupId>org.apache.maven.plugins</groupId>
                <artifactId>maven-compiler-plugin</artifactId>
                <configuration>
                    <source>8</source>
                    <target>8</target>
                </configuration>
            </plugin>
        </plugins>
    </build>

</project>


```


### 启动类


```java
package cn.itedus.lottery;

import org.apache.dubbo.config.spring.context.annotation.EnableDubbo;
import org.springframework.beans.factory.annotation.Configurable;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

@SpringBootApplication
@Configurable
@EnableDubbo
public class LotteryApplication {

    public static void main(String[] args) {
        SpringApplication.run(LotteryApplication.class, args);
    }

}


```

### 根据Id查询活动


```java
package cn.itedus.lottery.interfaces;

import cn.itedus.lottery.common.Constants;
import cn.itedus.lottery.common.Result;
import cn.itedus.lottery.infrastructure.dao.IActivityDao;
import cn.itedus.lottery.infrastructure.po.Activity;
import cn.itedus.lottery.rpc.IActivityBooth;
import cn.itedus.lottery.rpc.dto.ActivityDto;
import cn.itedus.lottery.rpc.req.ActivityReq;
import cn.itedus.lottery.rpc.res.ActivityRes;
import org.apache.dubbo.config.annotation.Service;

import javax.annotation.Resource;

@Service
public class ActivityBooth implements IActivityBooth {

    @Resource
    private IActivityDao activityDao;

    @Override
    public ActivityRes queryActivityById(ActivityReq req) {

        Activity activity = activityDao.queryActivityById(req.getActivityId());

        ActivityDto activityDto = new ActivityDto();
        activityDto.setActivityId(activity.getActivityId());
        activityDto.setActivityName(activity.getActivityName());
        activityDto.setActivityDesc(activity.getActivityDesc());
        activityDto.setBeginDateTime(activity.getBeginDateTime());
        activityDto.setEndDateTime(activity.getEndDateTime());
        activityDto.setStockCount(activity.getStockCount());
        activityDto.setTakeCount(activity.getTakeCount());

        return new ActivityRes(new Result(Constants.ResponseCode.SUCCESS.getCode(), Constants.ResponseCode.SUCCESS.getInfo()), activityDto);
    }

}
```



### yml配置文件

```yml
server 部分：

port: 8080：配置应用程序的端口号为 8080。
spring 部分：

datasource：配置数据库连接信息。
username: root：数据库用户名。
password: 1234：数据库密码。
url: jdbc:mysql://127.0.0.1:3306/lottery?useUnicode=true：数据库连接 URL，指向 MySQL 数据库 lottery。
driver-class-name: com.mysql.jdbc.Driver：MySQL数据库驱动类。
mybatis 部分：

mapper-locations: classpath:/mybatis/mapper/*.xml：指定 MyBatis Mapper 文件的位置。
config-location: classpath:/mybatis/config/mybatis-config.xml：指定 MyBatis 的配置文件的位置。
dubbo 部分：

application：Dubbo 应用程序的配置。
name: Lottery：Dubbo 应用程序的名称。
version: 1.0.0：Dubbo 应用程序的版本号。
registry：Dubbo 注册中心的配置。
address: N/A：注册中心地址，这里设置为 N/A 表示不使用注册中心（可根据需要更改为实际的注册中心地址）。
protocol：Dubbo 协议的配置。
name: dubbo：Dubbo 协议的名称。
port: 20880：Dubbo 协议的端口号。
scan：Dubbo 扫描的配置。
base-packages: cn.itedus.lottery.rpc：指定 Dubbo 扫描的基础包，以发现服务接口实现类。

```


```yml
server:
  port: 8080

spring:
  datasource:
    username: root
    password: 1234
    url: jdbc:mysql://127.0.0.1:3306/lottery?useUnicode=true
    driver-class-name: com.mysql.jdbc.Driver

mybatis:
  mapper-locations: classpath:/mybatis/mapper/*.xml
  config-location:  classpath:/mybatis/config/mybatis-config.xml

# Dubbo 广播方式配置
dubbo:
  application:
    name: Lottery
    version: 1.0.0
  registry:
    address: N/A #multicast://224.5.6.7:1234
  protocol:
    name: dubbo
    port: 20880
  scan:
    base-packages: cn.itedus.lottery.rpc


```

### mybatis-config.xml


* mybatis-config.xml 配置文件：

* 类型别名配置 (<typeAliases>)： 定义了 MyBatis 的类型别名，使得在 SQL 映射文件中可以使用简短的别名代替完整的类路径。
还可以包含其他全局配置，比如缓存、执行器（Executor）、拦截器等。

```java

<?xml version="1.0" encoding="UTF-8"?>：指定 XML 文档的版本和字符编码。

<!DOCTYPE configuration PUBLIC "-//mybatis.org//DTD Config 3.0//EN" "http://mybatis.org/dtd/mybatis-3-config.dtd">：声明 XML 文档的 Document Type Definition (DTD)，用于指定 XML 文档的结构和约束。在这里，指定了 MyBatis 3.0 的 DTD。

<configuration>：配置的根元素，包含了 MyBatis 全局配置信息。

<typeAliases>：配置 MyBatis 的类型别名。在这里，通过 <package> 元素指定了一个包，用于扫描包下的类并为其创建类型别名。

<package name="cn.itedus.lottery.infrastructure.po.Activity"/>：指定了包名 cn.itedus.lottery.infrastructure.po.Activity，MyBatis 将会扫描该包下的所有类，并为它们创建类型别名，使得在 MyBatis 映射文件中可以使用简短的类名来引用。
这个配置文件的作用是配置 MyBatis 类型别名，以方便在 MyBatis 映射文件中引用实体类而不需要写完整的类路径。在这个例子中，配置了一个包 cn.itedus.lottery.infrastructure.po.Activity 下的类型别名。这样，映射文件中就可以直接使用 Activity 代替完整的类路径。
```

```xml
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE configuration
        PUBLIC "-//mybatis.org//DTD Config 3.0//EN"
        "http://mybatis.org/dtd/mybatis-3-config.dtd">
<configuration>
    <typeAliases>
        <package name="cn.itedus.lottery.infrastructure.po.Activity"/>
    </typeAliases>
</configuration>

```


### myabtis映射文件 

```xml
<?xml version="1.0" encoding="UTF-8"?>：指定 XML 文档的版本和字符编码。

<!DOCTYPE mapper PUBLIC "-//mybatis.org//DTD Mapper 3.0//EN" "http://mybatis.org/dtd/mybatis-3-mapper.dtd">：声明 XML 文档的 Document Type Definition (DTD)，用于指定 XML 文档的结构和约束。在这里，指定了 MyBatis 3.0 的 DTD。

<mapper namespace="cn.itedus.lottery.infrastructure.dao.IActivityDao">：指定映射文件的命名空间，通常与对应的 DAO 接口的全限定名一致。

<resultMap>：定义了一个结果映射，将数据库查询结果映射到实体类 Activity 的属性。

<id>：定义了数据库表中的主键字段映射。
<result>：定义了其他字段的映射。
<insert>：定义了插入操作的 SQL 语句，使用了 MyBatis 的参数绑定语法 #{}。

<select>：定义了查询操作的 SQL 语句，使用了 MyBatis 的参数绑定语法 #{}。在这里，通过 resultMap 属性引用了前面定义的结果映射。

```

```xml
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE mapper PUBLIC "-//mybatis.org//DTD Mapper 3.0//EN" "http://mybatis.org/dtd/mybatis-3-mapper.dtd">
<mapper namespace="cn.itedus.lottery.infrastructure.dao.IActivityDao">

    <resultMap id="activityMap" type="cn.itedus.lottery.infrastructure.po.Activity">
        <id column="id" property="id"/>
        <result column="activity_id" property="activityId"/>
        <result column="activity_name" property="activityName"/>
        <result column="activity_desc" property="activityDesc"/>
        <result column="begin_date_time" property="beginDateTime"/>
        <result column="end_date_time" property="endDateTime"/>
        <result column="stock_count" property="stockCount"/>
        <result column="take_count" property="takeCount"/>
        <result column="state" property="state"/>
        <result column="creator" property="creator"/>
        <result column="create_time" property="createTime"/>
        <result column="update_time" property="updateTime"/>
    </resultMap>

    <insert id="insert" parameterType="cn.itedus.lottery.infrastructure.po.Activity">
        INSERT INTO activity
        (activity_id, activity_name, activity_desc, begin_date_time, end_date_time,
        stock_count, take_count, state, creator, create_time, update_time)
        VALUES
        (#{activityId}, #{activityName}, #{activityDesc}, #{beginDateTime}, #{endDateTime},
         #{stockCount}, #{takeCount}, #{state}, #{creator}, now(), now())
    </insert>

    <select id="queryActivityById" parameterType="java.lang.Long" resultMap="activityMap">
        SELECT activity_id, activity_name, activity_desc, begin_date_time, end_date_time,
        stock_count, take_count, state, creator, create_time, update_time
        FROM activity
        WHERE activity_id = #{activityId}
    </select>

</mapper>


```

* 查询操作的唯一标识符通常与对应的 DAO 接口中的方法名相对应。在 MyBatis 中，映射文件中的 <select>、<insert>、<update>、<delete> 等元素的 id 属性通常与 DAO 接口中对应方法的名称一致，以建立映射关系。

* MyBatis 就能够根据映射文件中的 <select> 元素的 id 属性，找到对应 DAO 接口的方法，从而建立 SQL 映射。


## LOTTERY-RPC


### pom

```xml
<?xml version="1.0" encoding="UTF-8"?>
<project xmlns="http://maven.apache.org/POM/4.0.0"
         xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
         xsi:schemaLocation="http://maven.apache.org/POM/4.0.0 http://maven.apache.org/xsd/maven-4.0.0.xsd">
    <parent>
        <artifactId>Lottery</artifactId>
        <groupId>cn.itedus.lottery</groupId>
        <version>1.0-SNAPSHOT</version>
    </parent>
    <modelVersion>4.0.0</modelVersion>

    <artifactId>lottery-rpc</artifactId>

    <packaging>jar</packaging>

    <dependencies>
        <dependency>
            <groupId>cn.itedus.lottery</groupId>
            <artifactId>lottery-common</artifactId>
            <version>1.0-SNAPSHOT</version>
        </dependency>
    </dependencies>

    <build>
        <finalName>lottery-rpc</finalName>
        <plugins>
            <!-- 编译plugin -->
            <plugin>
                <groupId>org.apache.maven.plugins</groupId>
                <artifactId>maven-compiler-plugin</artifactId>
                <configuration>
                    <source>${jdk.version}</source>
                    <target>${jdk.version}</target>
                    <compilerVersion>1.8</compilerVersion>
                </configuration>
            </plugin>
        </plugins>
    </build>

</project>

```


### DTO


```java

package cn.itedus.lottery.rpc.dto;

import java.io.Serializable;
import java.util.Date;

public class ActivityDto implements Serializable {

    // 活动ID
    private Long activityId;

    // 活动名称
    private String activityName;

    // 活动描述
    private String activityDesc;

    // 开始时间
    private Date beginDateTime;

    // 结束时间
    private Date endDateTime;

    // 库存
    private Integer stockCount;

    // 每人可参与次数
    private Integer takeCount;

    // 活动状态：编辑、提审、撤审、通过、运行、拒绝、关闭、开启
    private Integer state;

    public Long getActivityId() {
        return activityId;
    }

    public void setActivityId(Long activityId) {
        this.activityId = activityId;
    }

    public String getActivityName() {
        return activityName;
    }

    public void setActivityName(String activityName) {
        this.activityName = activityName;
    }

    public String getActivityDesc() {
        return activityDesc;
    }

    public void setActivityDesc(String activityDesc) {
        this.activityDesc = activityDesc;
    }

    public Date getBeginDateTime() {
        return beginDateTime;
    }

    public void setBeginDateTime(Date beginDateTime) {
        this.beginDateTime = beginDateTime;
    }

    public Date getEndDateTime() {
        return endDateTime;
    }

    public void setEndDateTime(Date endDateTime) {
        this.endDateTime = endDateTime;
    }

    public Integer getStockCount() {
        return stockCount;
    }

    public void setStockCount(Integer stockCount) {
        this.stockCount = stockCount;
    }

    public Integer getTakeCount() {
        return takeCount;
    }

    public void setTakeCount(Integer takeCount) {
        this.takeCount = takeCount;
    }

    public Integer getState() {
        return state;
    }

    public void setState(Integer state) {
        this.state = state;
    }
}


```


### req


```java
package cn.itedus.lottery.rpc.req;

import java.io.Serializable;

public class ActivityReq implements Serializable {

    private Long activityId;

    public Long getActivityId() {
        return activityId;
    }

    public void setActivityId(Long activityId) {
        this.activityId = activityId;
    }

}


```

### res


```java
package cn.itedus.lottery.rpc.res;

import cn.itedus.lottery.common.Result;
import cn.itedus.lottery.rpc.dto.ActivityDto;

import java.io.Serializable;

public class ActivityRes implements Serializable {

    private Result result;
    private ActivityDto activity;

    public ActivityRes() {
    }

    public ActivityRes(Result result) {
        this.result = result;
    }

    public ActivityRes(Result result, ActivityDto activity) {
        this.result = result;
        this.activity = activity;
    }

    public Result getResult() {
        return result;
    }

    public void setResult(Result result) {
        this.result = result;
    }

    public ActivityDto getActivity() {
        return activity;
    }

    public void setActivity(ActivityDto activity) {
        this.activity = activity;
    }

}


```


## DUbbo配置


* 配置广播模式的Dubbo
* rpc的设计和使用都是依赖于注册中心
* 服务接口信息在程序启动的时候，推动到一个统一的注册中心
* 在其他需要调用RPC接口的服务上再通过注册中心的均衡算法来匹配可以连接的接口落到本地保存和更新
* 标准的使用方式可以提供更大的连接数和更强的负载均衡作用

```yml
广播模式的配置唯一区别在于注册地址，registry.address = multicast://224.5.6.7:1234，服务提供者和服务调用者都需要配置相同的📢广播地址。或者配置为 N/A 用于直连模式使用
application，配置应用名称和版本
protocol，配置的通信协议和端口
scan，相当于 Spring 中自动扫描包的地址，可以把此包下的所有 rpc 接口都注册到服务中

```
## 定义和开发 RPC 接口

* 将所有的RPC接口定义都放到RPC模块下
* 这里先来定义一个活动展台的接口类，用于包装活动的创建、查询、修改、审核的接口。
* 用于实现 RPC 接口的实现类 ActivityBooth 上有一个注解 @Service，这个注解是来自于 Dubbo 的 org.apache.dubbo.config.annotation.Service，也就是这个包下含有此注解配置的类可以被 Dubbo 管理。
在 queryActivityById 功能实现中目前还比较粗糙，但大体可以看出这是对数据库的操作以及对结果的封装，提供 DTO 的对象并返回 Res 结果。目前dto的创建后续可以使用门面模式和工具类进行处理

## 六、搭建测试工程调用 RPC



* 配置Pom
```xml
<dependency>
    <groupId>cn.itedus.lottery</groupId>
    <artifactId>lottery-rpc</artifactId>
    <version>1.0-SNAPSHOT</version>
</dependency>


```

* 测试之前需要把 Lottery 工程中的 lottery-rpc 进行构建打包，便于测试工程引入


* 配置广播模式 Dubbo

```java
server:
  port: 8081

# Dubbo 广播方式配置
dubbo:
  application:
    name: Lottery
    version: 1.0.0
  registry:
    address: multicast://224.5.6.7:1234
  protocol:
    name: dubbo
    port: 20880


```

* 单元测试类

  * RunWith 和SpringBootTest是Junit测试框架的注解 用于配置测试运行器和启动SpringBoot应用上下文
  * Reference是Dubbo框架的注解,用于引用远程的Dubbo服务接口，interfaceClass用来指定rpc接口类，配置中扫描该类，url指定服务的地址
  * private IActivityBooth activityBooth;用来声明一个私有成员遍历，用于保存通过Dubbo引用的远程服务
  * 调用远程服务接口的方法 并且获取返回结果
  * logger.info用来打印测试结果 使用SLF4J日志记录器

```java
package cn.itedus.lottery.test;

import cn.itedus.lottery.rpc.IActivityBooth;
import cn.itedus.lottery.rpc.req.ActivityReq;
import cn.itedus.lottery.rpc.res.ActivityRes;
import com.alibaba.fastjson.JSON;
import org.apache.dubbo.config.annotation.Reference;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.test.context.junit4.SpringRunner;


@RunWith(SpringRunner.class)
@SpringBootTest
public class ApiTest {

    private Logger logger = LoggerFactory.getLogger(ApiTest.class);

    @Reference(interfaceClass = IActivityBooth.class, url = "dubbo://127.0.0.1:20880")
    private IActivityBooth activityBooth;

    @Test
    public void test_rpc() {
        ActivityReq req = new ActivityReq();
        req.setActivityId(100001L);
        ActivityRes result = activityBooth.queryActivityById(req);
        logger.info("测试结果：{}", JSON.toJSONString(result));
    }

}


```


