#!/bin/sh

# 使用说明，用来提示输入参数
usage() {
	echo "Usage: sh 执行脚本.sh [base|services|stop|rm]"
	exit 1
}

# 启动基础环境（必须）
base(){
	docker-compose up -d lottery-mysql lottery-redis lottery-nacos lottery-kafka lottery-zookeeper
}

# 启动程序模块（必须）
services(){
	docker-compose up -d lottery-website lottery-api lottery-draw lottery-erp
}

# 关闭所有环境/模块
stop(){
	docker-compose stop
}

# 删除所有环境/模块
rm(){
	docker-compose rm
}
# 删除所有环境/模块
down(){
	docker-compose down
}
# 根据输入参数，选择执行对应方法，不输入则执行使用说明
case "$1" in
"base")
	base
;;
"services")
	services
;;
"stop")
	stop
;;
"rm")
	rm
;;
"down")
	down
;;
*)
	usage
;;
esac
