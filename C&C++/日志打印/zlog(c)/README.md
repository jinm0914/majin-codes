# majin-C_C++

日志打印问题

一个简单的例子，编译命令：g++ xxx.c -o xxx -I include -L lib/ -static -lzlog -lpthread

gcc -O2 -g -Wall -D_GNU_SOURCE -o xxx .o -c xxx .c -I. -I.

gcc -O2 -g -o xxx xxx.o -L. -lzlog -lpthread -Wl,-rpath .

实时打印log文件：tail -f xxx.log

详情百度 zlog
