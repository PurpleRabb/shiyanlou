#define final target
executable := complicated
#sources := main.c complicated.c
sources := $(wildcard *.c) #使用内嵌函数
objects := $(sources:.c=.o)
deps := $(sources:.c=.d)
CC:=@gcc #'@' make slient
RM:= rm -rf
$(executable): $(objects) 
	# gcc -o complicated main.o complicated.o
	$(CC) -o $@ $^

#static pattern,子规则，使用静态模式规则
$(ojectes): %.o : %.c
	$(CC) -o $@ -c $<
#main.o: main.c
	#gcc -o main.o -c main.c
#	$(CC) -o $@ -c $<

#complicated.o: complicated.c
	#gcc -o complicated.o -c complicated.c
#	$(CC) -o $@ -c $<

.PHONY: clean #伪指令
clean:
	$(RM)  $(executable) $(objects)

#自动规则依赖
sinclude $(deps)

$(deps):%.d:%.c
	$(CC) -MM $< > $@
