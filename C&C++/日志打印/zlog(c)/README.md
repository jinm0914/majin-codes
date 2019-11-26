# majin-C_C++

日志打印问题

一个简单的例子，，多logger，多打印，多输出

详情见  http://hardysimpson.github.io/zlog/UsersGuide-CN.html#htoc14

编译命令：

1：make

2：gcc -O2 -g -Wall -D_GNU_SOURCE -o xxx .o -c xxx .c -I. -I.

    gcc -O2 -g -o xxx xxx.o -L. -lzlog -lpthread -Wl,-rpath .

3：g++ xxx.c -o xxx -I include -L lib/ -static -lzlog -lpthread

实时打印log文件：tail -f xxx.log


