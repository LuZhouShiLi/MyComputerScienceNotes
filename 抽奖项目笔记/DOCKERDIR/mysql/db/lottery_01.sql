
DROP DATABASE IF EXISTS `lottery_01`;
create database `lottery_01`  DEFAULT CHARACTER SET utf8mb4 COLLATE utf8mb4_bin;;

use `lottery_01`;



-- ----------------------------
-- Table structure for user_strategy_export_000
-- ----------------------------
DROP TABLE IF EXISTS `user_strategy_export_000`;
CREATE TABLE `user_strategy_export_000`  (
  `id` bigint(20) NOT NULL AUTO_INCREMENT COMMENT '自增ID',
  `u_id` varchar(32) CHARACTER SET utf8mb4 COLLATE utf8mb4_bin NULL DEFAULT NULL COMMENT '用户ID',
  `activity_id` bigint(20) NULL DEFAULT NULL COMMENT '活动ID',
  `order_id` bigint(20) NULL DEFAULT NULL COMMENT '订单ID',
  `strategy_id` bigint(20) NULL DEFAULT NULL COMMENT '策略ID',
  `strategy_mode` tinyint(4) NULL DEFAULT NULL COMMENT '策略方式（1:单项概率、2:总体概率）',
  `grant_type` tinyint(4) NULL DEFAULT NULL COMMENT '发放奖品方式（1:即时、2:定时[含活动结束]、3:人工）',
  `grant_date` datetime(0) NULL DEFAULT NULL COMMENT '发奖时间',
  `grant_state` tinyint(4) NULL DEFAULT NULL COMMENT '发奖状态',
  `award_id` varchar(64) CHARACTER SET utf8mb4 COLLATE utf8mb4_bin NULL DEFAULT NULL COMMENT '发奖ID',
  `award_type` tinyint(4) NULL DEFAULT NULL COMMENT '奖品类型（1:文字描述、2:兑换码、3:优惠券、4:实物奖品）',
  `award_name` varchar(64) CHARACTER SET utf8mb4 COLLATE utf8mb4_bin NULL DEFAULT NULL COMMENT '奖品名称',
  `award_content` varchar(128) CHARACTER SET utf8mb4 COLLATE utf8mb4_bin NULL DEFAULT NULL COMMENT '奖品内容「文字描述、Key、码」',
  `uuid` varchar(128) CHARACTER SET utf8mb4 COLLATE utf8mb4_bin NULL DEFAULT NULL COMMENT '防重ID',
  `mq_state` tinyint(4) NULL DEFAULT NULL COMMENT '消息发送状态（0未发送、1发送成功、2发送失败）',
  `create_time` datetime(0) NULL DEFAULT CURRENT_TIMESTAMP(0) COMMENT '创建时间',
  `update_time` datetime(0) NULL DEFAULT CURRENT_TIMESTAMP(0) COMMENT '更新时间',
  PRIMARY KEY (`id`) USING BTREE,
  UNIQUE INDEX `idx_uuid`(`uuid`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 1 CHARACTER SET = utf8mb4 COLLATE = utf8mb4_bin COMMENT = '用户策略计算结果表' ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of user_strategy_export_000
-- ----------------------------

-- ----------------------------
-- Table structure for user_strategy_export_001
-- ----------------------------
DROP TABLE IF EXISTS `user_strategy_export_001`;
CREATE TABLE `user_strategy_export_001`  (
  `id` bigint(20) NOT NULL AUTO_INCREMENT COMMENT '自增ID',
  `u_id` varchar(32) CHARACTER SET utf8mb4 COLLATE utf8mb4_bin NULL DEFAULT NULL COMMENT '用户ID',
  `activity_id` bigint(20) NULL DEFAULT NULL COMMENT '活动ID',
  `order_id` bigint(20) NULL DEFAULT NULL COMMENT '订单ID',
  `strategy_id` bigint(20) NULL DEFAULT NULL COMMENT '策略ID',
  `strategy_mode` tinyint(4) NULL DEFAULT NULL COMMENT '策略方式（1:单项概率、2:总体概率）',
  `grant_type` tinyint(4) NULL DEFAULT NULL COMMENT '发放奖品方式（1:即时、2:定时[含活动结束]、3:人工）',
  `grant_date` datetime(0) NULL DEFAULT NULL COMMENT '发奖时间',
  `grant_state` tinyint(4) NULL DEFAULT NULL COMMENT '发奖状态',
  `award_id` varchar(64) CHARACTER SET utf8mb4 COLLATE utf8mb4_bin NULL DEFAULT NULL COMMENT '发奖ID',
  `award_type` tinyint(4) NULL DEFAULT NULL COMMENT '奖品类型（1:文字描述、2:兑换码、3:优惠券、4:实物奖品）',
  `award_name` varchar(64) CHARACTER SET utf8mb4 COLLATE utf8mb4_bin NULL DEFAULT NULL COMMENT '奖品名称',
  `award_content` varchar(128) CHARACTER SET utf8mb4 COLLATE utf8mb4_bin NULL DEFAULT NULL COMMENT '奖品内容「文字描述、Key、码」',
  `uuid` varchar(128) CHARACTER SET utf8mb4 COLLATE utf8mb4_bin NULL DEFAULT NULL COMMENT '防重ID',
  `mq_state` tinyint(4) NULL DEFAULT NULL COMMENT '消息发送状态（0未发送、1发送成功、2发送失败）',
  `create_time` datetime(0) NULL DEFAULT CURRENT_TIMESTAMP(0) COMMENT '创建时间',
  `update_time` datetime(0) NULL DEFAULT CURRENT_TIMESTAMP(0) COMMENT '更新时间',
  PRIMARY KEY (`id`) USING BTREE,
  UNIQUE INDEX `idx_uuid`(`uuid`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 9 CHARACTER SET = utf8mb4 COLLATE = utf8mb4_bin COMMENT = '用户策略计算结果表' ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of user_strategy_export_001
-- ----------------------------
INSERT INTO `user_strategy_export_001` VALUES (4, 'xiaofuge', 120981321, 1650393975955292160, 10002, 2, 1, '2023-04-24 14:59:21', 1, '103', 1, '平板', '请联系活动组织者 fustack', '1650393975133208576', 1, '2023-04-24 14:59:21', '2023-04-24 14:59:21');
INSERT INTO `user_strategy_export_001` VALUES (5, 'xiaofuge', 120981321, 1650397254642728960, 10002, 2, 1, '2023-04-24 16:24:01', 1, '105', 1, '数据线', '请联系活动组织者 fustack', '1650397253875171328', 1, '2023-04-24 15:12:23', '2023-04-24 16:24:01');
INSERT INTO `user_strategy_export_001` VALUES (6, 'xiaofuge', 120981321, 1650397597413834752, 10002, 2, 1, '2023-04-24 16:24:02', 1, '102', 1, '手机', '请联系活动组织者 fustack', '1650397596621111296', 1, '2023-04-24 15:13:44', '2023-04-24 16:24:02');
INSERT INTO `user_strategy_export_001` VALUES (7, 'xiaofuge', 120981321, 1650414755468443648, 10002, 2, 1, '2023-04-18 23:01:53', 0, '105', 1, '数据线', '请联系活动组织者 fustack', '1650414754193375232', 0, '2023-04-24 16:21:55', '2023-04-24 16:21:55');
INSERT INTO `user_strategy_export_001` VALUES (8, 'xiaofuge', 120981321, 1650415286593159168, 10002, 2, 1, '2023-04-24 16:25:22', 1, '103', 1, '平板', '请联系活动组织者 fustack', '1650415285984985088', 1, '2023-04-24 16:24:02', '2023-04-24 16:25:22');

-- ----------------------------
-- Table structure for user_strategy_export_002
-- ----------------------------
DROP TABLE IF EXISTS `user_strategy_export_002`;
CREATE TABLE `user_strategy_export_002`  (
  `id` bigint(20) NOT NULL AUTO_INCREMENT COMMENT '自增ID',
  `u_id` varchar(32) CHARACTER SET utf8mb4 COLLATE utf8mb4_bin NULL DEFAULT NULL COMMENT '用户ID',
  `activity_id` bigint(20) NULL DEFAULT NULL COMMENT '活动ID',
  `order_id` bigint(20) NULL DEFAULT NULL COMMENT '订单ID',
  `strategy_id` bigint(20) NULL DEFAULT NULL COMMENT '策略ID',
  `strategy_mode` tinyint(4) NULL DEFAULT NULL COMMENT '策略方式（1:单项概率、2:总体概率）',
  `grant_type` tinyint(4) NULL DEFAULT NULL COMMENT '发放奖品方式（1:即时、2:定时[含活动结束]、3:人工）',
  `grant_date` datetime(0) NULL DEFAULT NULL COMMENT '发奖时间',
  `grant_state` tinyint(4) NULL DEFAULT NULL COMMENT '发奖状态',
  `award_id` varchar(64) CHARACTER SET utf8mb4 COLLATE utf8mb4_bin NULL DEFAULT NULL COMMENT '发奖ID',
  `award_type` tinyint(4) NULL DEFAULT NULL COMMENT '奖品类型（1:文字描述、2:兑换码、3:优惠券、4:实物奖品）',
  `award_name` varchar(64) CHARACTER SET utf8mb4 COLLATE utf8mb4_bin NULL DEFAULT NULL COMMENT '奖品名称',
  `award_content` varchar(128) CHARACTER SET utf8mb4 COLLATE utf8mb4_bin NULL DEFAULT NULL COMMENT '奖品内容「文字描述、Key、码」',
  `uuid` varchar(128) CHARACTER SET utf8mb4 COLLATE utf8mb4_bin NULL DEFAULT NULL COMMENT '防重ID',
  `mq_state` tinyint(4) NULL DEFAULT NULL COMMENT '消息发送状态（0未发送、1发送成功、2发送失败）',
  `create_time` datetime(0) NULL DEFAULT CURRENT_TIMESTAMP(0) COMMENT '创建时间',
  `update_time` datetime(0) NULL DEFAULT CURRENT_TIMESTAMP(0) COMMENT '更新时间',
  PRIMARY KEY (`id`) USING BTREE,
  UNIQUE INDEX `idx_uuid`(`uuid`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 7 CHARACTER SET = utf8mb4 COLLATE = utf8mb4_bin COMMENT = '用户策略计算结果表' ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of user_strategy_export_002
-- ----------------------------
INSERT INTO `user_strategy_export_002` VALUES (1, 'czl-test', 120981321, 1650501504496467968, 10002, 2, 1, '2023-04-24 23:16:25', 1, '105', 1, '数据线', '请联系活动组织者 fustack', '1650501503603081216', 1, '2023-04-24 22:06:38', '2023-04-24 23:16:25');
INSERT INTO `user_strategy_export_002` VALUES (2, 'czl-test', 120981321, 1650509463507075072, 10002, 2, 1, '2023-04-24 23:15:36', 1, '105', 1, '数据线', '请联系活动组织者 fustack', '1650509462714351616', 1, '2023-04-24 22:38:15', '2023-04-24 23:15:36');
INSERT INTO `user_strategy_export_002` VALUES (3, 'czl-test-lottery', 120981321, 1650878444478824448, 10002, 2, 1, '2023-04-18 23:01:53', 0, '105', 1, '数据线', '请联系活动组织者 fustack', '1650878076592226304', 0, '2023-04-25 23:04:27', '2023-04-25 23:04:27');
INSERT INTO `user_strategy_export_002` VALUES (4, 'czl-test-lottery', 120981321, 1650878848851673088, 10002, 2, 1, '2023-04-25 23:06:04', 1, '104', 1, '耳机', '请联系活动组织者 fustack', '1650878846981013504', 1, '2023-04-25 23:06:04', '2023-04-25 23:06:04');
INSERT INTO `user_strategy_export_002` VALUES (5, 'czl-test-lottery', 120981321, 1650879157426618368, 10002, 2, 1, '2023-04-25 23:07:17', 1, '103', 1, '平板', '请联系活动组织者 fustack', '1650879156306739200', 1, '2023-04-25 23:07:17', '2023-04-25 23:07:17');
INSERT INTO `user_strategy_export_002` VALUES (6, 'czl-test-lottery', 120981321, 1650886500327522304, 10002, 2, 1, '2023-04-25 23:36:28', 1, '103', 1, '平板', '请联系活动组织者 fustack', '1650886499501244416', 1, '2023-04-25 23:36:28', '2023-04-25 23:36:28');

-- ----------------------------
-- Table structure for user_strategy_export_003
-- ----------------------------
DROP TABLE IF EXISTS `user_strategy_export_003`;
CREATE TABLE `user_strategy_export_003`  (
  `id` bigint(20) NOT NULL AUTO_INCREMENT COMMENT '自增ID',
  `u_id` varchar(32) CHARACTER SET utf8mb4 COLLATE utf8mb4_bin NULL DEFAULT NULL COMMENT '用户ID',
  `activity_id` bigint(20) NULL DEFAULT NULL COMMENT '活动ID',
  `order_id` bigint(20) NULL DEFAULT NULL COMMENT '订单ID',
  `strategy_id` bigint(20) NULL DEFAULT NULL COMMENT '策略ID',
  `strategy_mode` tinyint(4) NULL DEFAULT NULL COMMENT '策略方式（1:单项概率、2:总体概率）',
  `grant_type` tinyint(4) NULL DEFAULT NULL COMMENT '发放奖品方式（1:即时、2:定时[含活动结束]、3:人工）',
  `grant_date` datetime(0) NULL DEFAULT NULL COMMENT '发奖时间',
  `grant_state` tinyint(4) NULL DEFAULT NULL COMMENT '发奖状态',
  `award_id` varchar(64) CHARACTER SET utf8mb4 COLLATE utf8mb4_bin NULL DEFAULT NULL COMMENT '发奖ID',
  `award_type` tinyint(4) NULL DEFAULT NULL COMMENT '奖品类型（1:文字描述、2:兑换码、3:优惠券、4:实物奖品）',
  `award_name` varchar(64) CHARACTER SET utf8mb4 COLLATE utf8mb4_bin NULL DEFAULT NULL COMMENT '奖品名称',
  `award_content` varchar(128) CHARACTER SET utf8mb4 COLLATE utf8mb4_bin NULL DEFAULT NULL COMMENT '奖品内容「文字描述、Key、码」',
  `uuid` varchar(128) CHARACTER SET utf8mb4 COLLATE utf8mb4_bin NULL DEFAULT NULL COMMENT '防重ID',
  `mq_state` tinyint(4) NULL DEFAULT NULL COMMENT '消息发送状态（0未发送、1发送成功、2发送失败）',
  `create_time` datetime(0) NULL DEFAULT CURRENT_TIMESTAMP(0) COMMENT '创建时间',
  `update_time` datetime(0) NULL DEFAULT CURRENT_TIMESTAMP(0) COMMENT '更新时间',
  PRIMARY KEY (`id`) USING BTREE,
  UNIQUE INDEX `idx_uuid`(`uuid`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 1 CHARACTER SET = utf8mb4 COLLATE = utf8mb4_bin COMMENT = '用户策略计算结果表' ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of user_strategy_export_003
-- ----------------------------

-- ----------------------------
-- Table structure for user_take_activity
-- ----------------------------
DROP TABLE IF EXISTS `user_take_activity`;
CREATE TABLE `user_take_activity`  (
  `id` bigint(20) NOT NULL AUTO_INCREMENT COMMENT '自增ID',
  `u_id` varchar(32) CHARACTER SET utf8mb4 COLLATE utf8mb4_bin NULL DEFAULT NULL COMMENT '用户ID',
  `take_id` bigint(20) NULL DEFAULT NULL COMMENT '活动领取ID',
  `activity_id` bigint(20) NULL DEFAULT NULL COMMENT '活动ID',
  `activity_name` varchar(64) CHARACTER SET utf8mb4 COLLATE utf8mb4_bin NULL DEFAULT NULL COMMENT '活动名称',
  `take_date` datetime(0) NULL DEFAULT NULL COMMENT '活动领取时间',
  `take_count` int(11) NULL DEFAULT NULL COMMENT '领取次数',
  `strategy_id` int(11) NULL DEFAULT NULL COMMENT '抽奖策略ID',
  `state` tinyint(4) NULL DEFAULT NULL COMMENT '活动单使用状态 0未使用、1已使用',
  `uuid` varchar(128) CHARACTER SET utf8mb4 COLLATE utf8mb4_bin NULL DEFAULT NULL COMMENT '防重ID',
  `create_time` datetime(0) NULL DEFAULT CURRENT_TIMESTAMP(0) COMMENT '创建时间',
  `update_time` datetime(0) NULL DEFAULT CURRENT_TIMESTAMP(0) COMMENT '更新时间',
  PRIMARY KEY (`id`) USING BTREE,
  UNIQUE INDEX `idx_uuid`(`uuid`) USING BTREE COMMENT '防重ID'
) ENGINE = InnoDB AUTO_INCREMENT = 32 CHARACTER SET = utf8mb4 COLLATE = utf8mb4_bin COMMENT = '用户参与活动记录表' ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of user_take_activity
-- ----------------------------
INSERT INTO `user_take_activity` VALUES (21, 'xiaofuge', 1650393975133208576, 120981321, '测试活动', '2023-04-24 06:59:20', 1, 10002, 1, 'xiaofuge_120981321_1', '2023-04-24 14:59:21', '2023-04-24 14:59:21');
INSERT INTO `user_take_activity` VALUES (22, 'xiaofuge', 1650397253875171328, 120981321, '测试活动', '2023-04-24 07:12:22', 2, 10002, 1, 'xiaofuge_120981321_2', '2023-04-24 15:12:22', '2023-04-24 15:12:22');
INSERT INTO `user_take_activity` VALUES (23, 'xiaofuge', 1650397596621111296, 120981321, '测试活动', '2023-04-24 07:13:43', 3, 10002, 1, 'xiaofuge_120981321_3', '2023-04-24 15:13:44', '2023-04-24 15:13:44');
INSERT INTO `user_take_activity` VALUES (24, 'xiaofuge', 1650414754193375232, 120981321, '测试活动', '2023-04-24 08:21:54', 4, 10002, 1, 'xiaofuge_120981321_4', '2023-04-24 16:21:55', '2023-04-24 16:21:55');
INSERT INTO `user_take_activity` VALUES (25, 'xiaofuge', 1650415285984985088, 120981321, '测试活动', '2023-04-24 08:24:01', 5, 10002, 1, 'xiaofuge_120981321_5', '2023-04-24 16:24:02', '2023-04-24 16:24:02');
INSERT INTO `user_take_activity` VALUES (26, 'czl-test', 1650501503603081216, 120981321, '测试活动', '2023-04-24 14:06:36', 1, 10002, 1, 'czl-test_120981321_1', '2023-04-24 22:06:37', '2023-04-24 22:06:37');
INSERT INTO `user_take_activity` VALUES (27, 'czl-test', 1650509462714351616, 120981321, '测试活动', '2023-04-24 14:38:14', 2, 10002, 1, 'czl-test_120981321_2', '2023-04-24 22:38:15', '2023-04-24 22:38:15');
INSERT INTO `user_take_activity` VALUES (28, 'czl-test-lottery', 1650878076592226304, 120981321, '测试活动', '2023-04-25 15:02:58', 1, 10002, 1, 'czl-test-lottery_120981321_1', '2023-04-25 23:02:59', '2023-04-25 23:02:59');
INSERT INTO `user_take_activity` VALUES (29, 'czl-test-lottery', 1650878846981013504, 120981321, '测试活动', '2023-04-25 15:06:02', 2, 10002, 1, 'czl-test-lottery_120981321_2', '2023-04-25 23:06:03', '2023-04-25 23:06:03');
INSERT INTO `user_take_activity` VALUES (30, 'czl-test-lottery', 1650879156306739200, 120981321, '测试活动', '2023-04-25 15:07:15', 3, 10002, 1, 'czl-test-lottery_120981321_3', '2023-04-25 23:07:17', '2023-04-25 23:07:17');
INSERT INTO `user_take_activity` VALUES (31, 'czl-test-lottery', 1650886499501244416, 120981321, '测试活动', '2023-04-25 15:36:28', 4, 10002, 1, 'czl-test-lottery_120981321_4', '2023-04-25 23:36:28', '2023-04-25 23:36:28');

-- ----------------------------
-- Table structure for user_take_activity_count
-- ----------------------------
DROP TABLE IF EXISTS `user_take_activity_count`;
CREATE TABLE `user_take_activity_count`  (
  `id` bigint(20) NOT NULL AUTO_INCREMENT COMMENT '自增ID',
  `u_id` varchar(20) CHARACTER SET utf8mb4 COLLATE utf8mb4_bin NULL DEFAULT NULL COMMENT '用户ID',
  `activity_id` bigint(20) NULL DEFAULT NULL COMMENT '活动ID',
  `total_count` int(11) NULL DEFAULT NULL COMMENT '可领取次数',
  `left_count` int(11) NULL DEFAULT NULL COMMENT '已领取次数',
  `create_time` datetime(0) NULL DEFAULT CURRENT_TIMESTAMP(0) COMMENT '创建时间',
  `update_time` datetime(0) NULL DEFAULT CURRENT_TIMESTAMP(0) COMMENT '更新时间',
  PRIMARY KEY (`id`) USING BTREE,
  UNIQUE INDEX `idx_uId_activityId`(`u_id`, `activity_id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 6 CHARACTER SET = utf8mb4 COLLATE = utf8mb4_bin COMMENT = '用户活动参与次数表' ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of user_take_activity_count
-- ----------------------------
INSERT INTO `user_take_activity_count` VALUES (3, 'xiaofuge', 120981321, 5, 0, '2023-04-24 14:59:21', '2023-04-24 14:59:21');
INSERT INTO `user_take_activity_count` VALUES (4, 'czl-test', 120981321, 5, 3, '2023-04-24 22:06:37', '2023-04-24 22:06:37');
INSERT INTO `user_take_activity_count` VALUES (5, 'czl-test-lottery', 120981321, 5, 1, '2023-04-25 23:02:59', '2023-04-25 23:02:59');

SET FOREIGN_KEY_CHECKS = 1;
