

DROP DATABASE IF EXISTS `lottery`;
create database `lottery`  DEFAULT CHARACTER SET utf8mb4 COLLATE utf8mb4_bin;

use `lottery`;

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for activity
-- ----------------------------
DROP TABLE IF EXISTS `activity`;
CREATE TABLE `activity`  (
  `id` bigint(0) NOT NULL AUTO_INCREMENT COMMENT '自增ID',
  `activity_id` bigint(0) NOT NULL COMMENT '活动ID',
  `activity_name` varchar(64) CHARACTER SET utf8mb4 COLLATE utf8mb4_bin NULL DEFAULT NULL COMMENT '活动名称',
  `activity_desc` varchar(128) CHARACTER SET utf8mb4 COLLATE utf8mb4_bin NULL DEFAULT NULL COMMENT '活动描述',
  `begin_date_time` datetime(0) NULL DEFAULT NULL COMMENT '开始时间',
  `end_date_time` datetime(0) NULL DEFAULT NULL COMMENT '结束时间',
  `stock_count` int(0) NULL DEFAULT NULL COMMENT '库存',
  `stock_surplus_count` int(0) NULL DEFAULT NULL COMMENT '库存剩余',
  `take_count` int(0) NULL DEFAULT NULL COMMENT '每人可参与次数',
  `strategy_id` bigint(0) NULL DEFAULT NULL COMMENT '抽奖策略ID',
  `state` tinyint(0) NULL DEFAULT NULL COMMENT '活动状态：1编辑、2提审、3撤审、4通过、5运行(审核通过后worker扫描状态)、6拒绝、7关闭、8开启',
  `creator` varchar(64) CHARACTER SET utf8mb4 COLLATE utf8mb4_bin NULL DEFAULT NULL COMMENT '创建人',
  `create_time` datetime(0) NULL DEFAULT CURRENT_TIMESTAMP(0) COMMENT '创建时间',
  `update_time` datetime(0) NULL DEFAULT CURRENT_TIMESTAMP(0) COMMENT '修改时间',
  PRIMARY KEY (`id`) USING BTREE,
  UNIQUE INDEX `unique_activity_id`(`activity_id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 6 CHARACTER SET = utf8mb4 COLLATE = utf8mb4_bin COMMENT = '活动配置' ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of activity
-- ----------------------------
INSERT INTO `activity` VALUES (5, 120981321, '测试活动', '测试活动描述', '2023-04-18 23:01:53', '2025-06-19 23:01:53', 100, 93, 5, 10002, 5, 'xiaofuge', '2023-04-18 23:01:54', '2023-04-18 23:01:54');
INSERT INTO `activity` VALUES (6, 120981322, '测试活动1', '测试活动描述', '2023-04-18 23:01:53', '2025-06-19 23:01:53', 100, 93, 4, 10002, 5, 'xiaofuge', '2023-04-18 23:01:54', '2023-04-18 23:01:54');

-- ----------------------------
-- Table structure for award
-- ----------------------------
DROP TABLE IF EXISTS `award`;
CREATE TABLE `award`  (
  `id` bigint(0) NOT NULL AUTO_INCREMENT COMMENT '自增ID',
  `award_id` varchar(64) CHARACTER SET utf8mb4 COLLATE utf8mb4_bin NULL DEFAULT NULL COMMENT '奖品ID',
  `award_type` tinyint(0) NULL DEFAULT NULL COMMENT '奖品类型（1:文字描述、2:兑换码、3:优惠券、4:实物奖品）',
  `award_name` varchar(64) CHARACTER SET utf8mb4 COLLATE utf8mb4_bin NULL DEFAULT NULL COMMENT '奖品名称',
  `award_content` varchar(128) CHARACTER SET utf8mb4 COLLATE utf8mb4_bin NULL DEFAULT NULL COMMENT '奖品内容「文字描述、Key、码」',
  `create_time` datetime(0) NULL DEFAULT CURRENT_TIMESTAMP(0) COMMENT '创建时间',
  `update_time` datetime(0) NULL DEFAULT CURRENT_TIMESTAMP(0) COMMENT '更新时间',
  PRIMARY KEY (`id`) USING BTREE,
  UNIQUE INDEX `idx_award_id`(`award_id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 30 CHARACTER SET = utf8mb4 COLLATE = utf8mb4_bin COMMENT = '奖品配置' ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of award
-- ----------------------------
INSERT INTO `award` VALUES (26, '101', 1, '电脑', '请联系活动组织者 fustack', '2023-04-18 23:01:54', '2023-04-18 23:01:54');
INSERT INTO `award` VALUES (27, '102', 1, '手机', '请联系活动组织者 fustack', '2023-04-18 23:01:54', '2023-04-18 23:01:54');
INSERT INTO `award` VALUES (28, '103', 1, '平板', '请联系活动组织者 fustack', '2023-04-18 23:01:54', '2023-04-18 23:01:54');
INSERT INTO `award` VALUES (29, '104', 1, '耳机', '请联系活动组织者 fustack', '2023-04-18 23:01:54', '2023-04-18 23:01:54');
INSERT INTO `award` VALUES (30, '105', 1, '数据线', '请联系活动组织者 fustack', '2023-04-18 23:01:54', '2023-04-18 23:01:54');

-- ----------------------------
-- Table structure for rule_tree
-- ----------------------------
DROP TABLE IF EXISTS `rule_tree`;
CREATE TABLE `rule_tree`  (
  `id` bigint(0) NOT NULL AUTO_INCREMENT COMMENT '主键ID',
  `tree_name` varchar(64) CHARACTER SET utf8mb4 COLLATE utf8mb4_bin NULL DEFAULT NULL COMMENT '规则树Id',
  `tree_desc` varchar(128) CHARACTER SET utf8mb4 COLLATE utf8mb4_bin NULL DEFAULT NULL COMMENT '规则树描述',
  `tree_root_node_id` bigint(0) NULL DEFAULT NULL COMMENT '规则树根ID',
  `create_time` datetime(0) NULL DEFAULT NULL COMMENT '创建时间',
  `update_time` datetime(0) NULL DEFAULT NULL COMMENT '更新时间',
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 2110081902 CHARACTER SET = utf8mb4 COLLATE = utf8mb4_bin ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of rule_tree
-- ----------------------------
INSERT INTO `rule_tree` VALUES (2110081902, '抽奖活动规则树', '用于决策不同用户可参与的活动', 1, '2021-10-08 15:38:05', '2021-10-08 15:38:05');

-- ----------------------------
-- Table structure for rule_tree_node
-- ----------------------------
DROP TABLE IF EXISTS `rule_tree_node`;
CREATE TABLE `rule_tree_node`  (
  `id` bigint(0) NOT NULL AUTO_INCREMENT COMMENT '主键ID',
  `tree_id` int(0) NULL DEFAULT NULL COMMENT '规则树ID',
  `node_type` int(0) NULL DEFAULT NULL COMMENT '节点类型；1子叶、2果实',
  `node_value` varchar(32) CHARACTER SET utf8mb4 COLLATE utf8mb4_bin NULL DEFAULT NULL COMMENT '节点值[nodeType=2]；果实值',
  `rule_key` varchar(16) CHARACTER SET utf8mb4 COLLATE utf8mb4_bin NULL DEFAULT NULL COMMENT '规则Key',
  `rule_desc` varchar(32) CHARACTER SET utf8mb4 COLLATE utf8mb4_bin NULL DEFAULT NULL COMMENT '规则描述',
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 122 CHARACTER SET = utf8mb4 COLLATE = utf8mb4_bin ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of rule_tree_node
-- ----------------------------
INSERT INTO `rule_tree_node` VALUES (1, 2110081902, 1, NULL, 'userGender', '用户性别[男/女]');
INSERT INTO `rule_tree_node` VALUES (11, 2110081902, 1, NULL, 'userAge', '用户年龄');
INSERT INTO `rule_tree_node` VALUES (12, 2110081902, 1, NULL, 'userAge', '用户年龄');
INSERT INTO `rule_tree_node` VALUES (111, 2110081902, 2, '100001', NULL, NULL);
INSERT INTO `rule_tree_node` VALUES (112, 2110081902, 2, '100002', NULL, NULL);
INSERT INTO `rule_tree_node` VALUES (121, 2110081902, 2, '100003', NULL, NULL);
INSERT INTO `rule_tree_node` VALUES (122, 2110081902, 2, '100004', NULL, NULL);

-- ----------------------------
-- Table structure for rule_tree_node_line
-- ----------------------------
DROP TABLE IF EXISTS `rule_tree_node_line`;
CREATE TABLE `rule_tree_node_line`  (
  `id` bigint(0) NOT NULL AUTO_INCREMENT COMMENT '主键ID',
  `tree_id` bigint(0) NULL DEFAULT NULL COMMENT '规则树ID',
  `node_id_from` bigint(0) NULL DEFAULT NULL COMMENT '节点From',
  `node_id_to` bigint(0) NULL DEFAULT NULL COMMENT '节点To',
  `rule_limit_type` int(0) NULL DEFAULT NULL COMMENT '限定类型；1:=;2:>;3:<;4:>=;5<=;6:enum[枚举范围];7:果实',
  `rule_limit_value` varchar(32) CHARACTER SET utf8mb4 COLLATE utf8mb4_bin NULL DEFAULT NULL COMMENT '限定值',
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 6 CHARACTER SET = utf8mb4 COLLATE = utf8mb4_bin ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of rule_tree_node_line
-- ----------------------------
INSERT INTO `rule_tree_node_line` VALUES (1, 2110081902, 1, 11, 1, 'man');
INSERT INTO `rule_tree_node_line` VALUES (2, 2110081902, 1, 12, 1, 'woman');
INSERT INTO `rule_tree_node_line` VALUES (3, 2110081902, 11, 111, 3, '25');
INSERT INTO `rule_tree_node_line` VALUES (4, 2110081902, 11, 112, 4, '25');
INSERT INTO `rule_tree_node_line` VALUES (5, 2110081902, 12, 121, 3, '25');
INSERT INTO `rule_tree_node_line` VALUES (6, 2110081902, 12, 122, 4, '25');

-- ----------------------------
-- Table structure for strategy
-- ----------------------------
DROP TABLE IF EXISTS `strategy`;
CREATE TABLE `strategy`  (
  `id` bigint(0) NOT NULL AUTO_INCREMENT COMMENT '自增ID',
  `strategy_id` bigint(0) NOT NULL COMMENT '策略ID',
  `strategy_desc` varchar(128) CHARACTER SET utf8mb4 COLLATE utf8mb4_bin NULL DEFAULT NULL COMMENT '策略描述',
  `strategy_mode` tinyint(0) NULL DEFAULT NULL COMMENT '策略方式（1:单项概率、2:总体概率）',
  `grant_type` tinyint(0) NULL DEFAULT NULL COMMENT '发放奖品方式（1:即时、2:定时[含活动结束]、3:人工）',
  `grant_date` datetime(0) NULL DEFAULT NULL COMMENT '发放奖品时间',
  `ext_info` varchar(128) CHARACTER SET utf8mb4 COLLATE utf8mb4_bin NULL DEFAULT NULL COMMENT '扩展信息',
  `create_time` datetime(0) NULL DEFAULT CURRENT_TIMESTAMP(0) ON UPDATE CURRENT_TIMESTAMP(0) COMMENT '创建时间',
  `update_time` datetime(0) NULL DEFAULT CURRENT_TIMESTAMP(0) ON UPDATE CURRENT_TIMESTAMP(0) COMMENT '修改时间',
  PRIMARY KEY (`id`) USING BTREE,
  UNIQUE INDEX `strategy_strategyId_uindex`(`strategy_id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 5 CHARACTER SET = utf8mb4 COLLATE = utf8mb4_bin COMMENT = '策略配置' ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of strategy
-- ----------------------------
INSERT INTO `strategy` VALUES (5, 10002, '抽奖策略', 2, 1, '2023-04-18 23:01:53', '', '2023-04-19 21:39:43', '2023-04-19 21:39:43');

-- ----------------------------
-- Table structure for strategy_detail
-- ----------------------------
DROP TABLE IF EXISTS `strategy_detail`;
CREATE TABLE `strategy_detail`  (
  `id` bigint(0) NOT NULL AUTO_INCREMENT COMMENT '自增ID',
  `strategy_id` bigint(0) NOT NULL COMMENT '策略ID',
  `award_id` varchar(64) CHARACTER SET utf8mb4 COLLATE utf8mb4_bin NULL DEFAULT NULL COMMENT '奖品ID',
  `award_name` varchar(128) CHARACTER SET utf8mb4 COLLATE utf8mb4_bin NULL DEFAULT NULL COMMENT '奖品描述',
  `award_count` int(0) NULL DEFAULT NULL COMMENT '奖品库存',
  `award_surplus_count` int(0) NULL DEFAULT 0 COMMENT '奖品剩余库存',
  `award_rate` decimal(5, 2) NULL DEFAULT NULL COMMENT '中奖概率',
  `create_time` datetime(0) NULL DEFAULT CURRENT_TIMESTAMP(0) COMMENT '创建时间',
  `update_time` datetime(0) NULL DEFAULT CURRENT_TIMESTAMP(0) COMMENT '修改时间',
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 25 CHARACTER SET = utf8mb4 COLLATE = utf8mb4_bin COMMENT = '策略明细' ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of strategy_detail
-- ----------------------------
INSERT INTO `strategy_detail` VALUES (21, 10002, '101', '一等奖', 10, 10, 0.05, '2023-04-18 23:01:54', '2023-04-18 23:01:54');
INSERT INTO `strategy_detail` VALUES (22, 10002, '102', '二等奖', 20, 19, 0.15, '2023-04-18 23:01:54', '2023-04-18 23:01:54');
INSERT INTO `strategy_detail` VALUES (23, 10002, '103', '三等奖', 50, 46, 0.20, '2023-04-18 23:01:54', '2023-04-18 23:01:54');
INSERT INTO `strategy_detail` VALUES (24, 10002, '104', '四等奖', 100, 99, 0.25, '2023-04-18 23:01:54', '2023-04-18 23:01:54');
INSERT INTO `strategy_detail` VALUES (25, 10002, '105', '五等奖', 500, 495, 0.35, '2023-04-18 23:01:54', '2023-04-18 23:01:54');

SET FOREIGN_KEY_CHECKS = 1;
