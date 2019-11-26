exe = 		\
    zlogtest

all     :       $(exe)

$(exe)  :       %:%.o
	gcc -O2 -g -o $@ $^ -L../lib -lzlog -lpthread -Wl,-rpath .

.c.o	:
	gcc -O2 -g -Wall -D_GNU_SOURCE -o $@ -c $< -I. -I../include

clean	:
	rm -f press.log* *.o $(exe)

.PHONY : clean all
