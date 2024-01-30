# sql查询报错

## 报错


```sql
[Err] 1067 - Invalid default value for 'create_time'
``

```sql
DROP TABLE IF EXISTS `activity`;
CREATE TABLE `activity` (
  `id` bigint(20) NOT NULL AUTO_INCREMENT COMMENT '自增ID',
  `activity_id` bigint(20) NOT NULL COMMENT '活动ID',
  `activity_name` varchar(64) CHARACTER SET utf8mb4 DEFAULT NULL COMMENT '活动名称',
  `activity_desc` varchar(128) CHARACTER SET utf8mb4 DEFAULT NULL COMMENT '活动描述',
  `begin_date_time` datetime(3) DEFAULT NULL COMMENT '开始时间',
  `end_date_time` datetime(3) DEFAULT NULL COMMENT '结束时间',
  `stock_count` int(11) DEFAULT NULL COMMENT '库存',
  `stock_surplus_count` int(11) DEFAULT NULL COMMENT '库存剩余',
  `take_count` int(11) DEFAULT NULL COMMENT '每人可参与次数',
  `strategy_id` bigint(11) DEFAULT NULL COMMENT '抽奖策略ID',
  `state` tinyint(2) DEFAULT NULL COMMENT '活动状态：1编辑、2提审、3撤审、4通过、5运行(审核通过后worker扫描状态)、6拒绝、7关闭、8开启',
  `creator` varchar(64) CHARACTER SET utf8mb4 DEFAULT NULL COMMENT '创建人',
  `create_time` datetime(3) DEFAULT CURRENT_TIMESTAMP COMMENT '创建时间',
  `update_time` datetime(3) DEFAULT CURRENT_TIMESTAMP COMMENT '修改时间',
  PRIMARY KEY (`id`),
  UNIQUE KEY `unique_activity_id` (`activity_id`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_bin COMMENT='活动配置';


```

* 出现该问题的原因是因为:发现给了时间字段的列默认值一个 CURRENT_TIMESTAMP 默认值，而这个默认值在低版本的 MySQL 中是不支持的 删除即可 改成NULL
```sql
DROP TABLE IF EXISTS `activity`;
CREATE TABLE `activity` (
  `id` bigint(20) NOT NULL AUTO_INCREMENT COMMENT '自增ID',
  `activity_id` bigint(20) NOT NULL COMMENT '活动ID',
  `activity_name` varchar(64) CHARACTER SET utf8mb4 DEFAULT NULL COMMENT '活动名称',
  `activity_desc` varchar(128) CHARACTER SET utf8mb4 DEFAULT NULL COMMENT '活动描述',
  `begin_date_time` datetime(3) DEFAULT NULL COMMENT '开始时间',
  `end_date_time` datetime(3) DEFAULT NULL COMMENT '结束时间',
  `stock_count` int(11) DEFAULT NULL COMMENT '库存',
  `stock_surplus_count` int(11) DEFAULT NULL COMMENT '库存剩余',
  `take_count` int(11) DEFAULT NULL COMMENT '每人可参与次数',
  `strategy_id` bigint(11) DEFAULT NULL COMMENT '抽奖策略ID',
  `state` tinyint(2) DEFAULT NULL COMMENT '活动状态：1编辑、2提审、3撤审、4通过、5运行(审核通过后worker扫描状态)、6拒绝、7关闭、8开启',
  `creator` varchar(64) CHARACTER SET utf8mb4 DEFAULT NULL COMMENT '创建人',
  `create_time` datetime(3) DEFAULT NULL '创建时间',
  `update_time` datetime(3) DEFAULT NULL '修改时间',
  PRIMARY KEY (`id`),
  UNIQUE KEY `unique_activity_id` (`activity_id`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_bin COMMENT='活动配置';



```




