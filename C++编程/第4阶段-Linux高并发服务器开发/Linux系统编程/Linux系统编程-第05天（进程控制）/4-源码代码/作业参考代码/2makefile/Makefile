#一条规则
all: a b


a:a.o
	gcc $< -o $@

b:b.o
	gcc $< -o $@


#模式规则
%.o:%.c
	gcc -c $< -o $@


.PHONY:clean
clean:
	-rm --f a b *.o
