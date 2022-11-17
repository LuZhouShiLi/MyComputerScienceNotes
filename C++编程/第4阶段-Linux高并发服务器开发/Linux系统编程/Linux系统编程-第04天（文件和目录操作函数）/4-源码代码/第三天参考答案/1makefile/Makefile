#获取src目录中所有的.c文件
SRC=$(wildcard ./src/*.c)
#替换成目标文件  obj/*.o
OBJS=$(patsubst ./src/%.c, ./obj/%.o, $(SRC))

#变量定义
CC=gcc
INC=./inc
CFLAGS=-c 
TARGET=./bin/test

$(TARGET):$(OBJS)
	$(CC) $^ -o $@
	@#mv $(TARGET) bin/

#将对应的.c生成对应的.o文件
./obj/%.o:./src/%.c
	@#gcc -c -I./inc $< -o $@
	$(CC) $(CFLAGS) -I$(INC) $< -o $@


#伪目标
.PHONY:clean all
clean:
	$(RM) $(OBJS) $(TARGET)

#辅助调试
all:
	echo $(SRC)
	echo $(OBJS)
	echo $(RM)



