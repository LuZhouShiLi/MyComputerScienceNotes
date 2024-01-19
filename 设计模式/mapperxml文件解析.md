# Mapper.xml文件解析


## 简单解读

&emsp;最近在做一个分布式项目，看到xml文件原先只是上网CV，还是要搞清楚吧！

* 下面是一个Mybatis的SQL映射文件的配置



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

* 这个元素定义了命名空间，用于标识这个映射文件对应的接口。在这里，命名空间指向了 cn.itedus.lottery.infrastructure.dao.IActivityDao 这个接口，表示这个映射文件用于实现该接口的数据库操作。

```xml

<mapper namespace="cn.itedus.lottery.infrastructure.dao.IActivityDao">

```

* 这部分定义了一个 resultMap，用于将查询结果映射到 cn.itedus.lottery.infrastructure.po.Activity 实体类的属性。id 元素定义了主键的映射，result 元素定义了其他属性的映射。


```xml
    <resultMap id="activityMap" type="cn.itedus.lottery.infrastructure.po.Activity">
        <!-- 映射实体类的属性与数据库字段 -->
        <id column="id" property="id"/>
        <result column="activity_id" property="activityId"/>
        <result column="activity_name" property="activityName"/>
        <!-- 其他属性映射... -->
    </resultMap>


```

* 这部分定义了一个 insert 元素，用于插入一条活动数据。parameterType 属性指定了传入的参数类型，即 cn.itedus.lottery.infrastructure.po.Activity 实体类。


```xml
    <insert id="insert" parameterType="cn.itedus.lottery.infrastructure.po.Activity">
        <!-- 插入活动数据 -->
    </insert>


```

* 这部分定义了一个 select 元素，用于根据活动 ID 查询活动数据。parameterType 属性指定了传入的参数类型，resultMap 属性指定了查询结果映射使用的 resultMap。
* 通过 XML 格式定义了插入和查询操作的 SQL 语句，并通过 resultMap 将查询结果映射到实体类的属性。这样的映射文件使得数据库操作可以使用统一的接口进行，同时将 SQL 语句和实体类属性的映射关系集中管理，提高了代码的维护性和可读性。

```xml

    <select id="queryActivityById" parameterType="java.lang.Long" resultMap="activityMap">
        <!-- 查询活动数据 -->
    </select>

```