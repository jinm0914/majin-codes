# majin-C_C++

日志打印问题

模版：easylogging（c++）： https://github.com/amrayn/easyloggingpp ；
     zlog（c）： http://hardysimpson.github.io/zlog/UsersGuide-CN.html#htoc14 ；

日志写入xx.log文本后，使用tail -f xx.log可以循环打印更新数据，常用于主程序不打印日志，

而将各种类型的日志写入不同的文本使用tail -f xx.log打印，或相同的文本使用tail -f xx.log |grep “xxx”过滤打印；

tail 命令见：https://www.runoob.com/linux/linux-comm-tail.html
