# majin-C_C++

日志打印问题

一个简单的例子，多logger，多打印，多输出

详情见 https://github.com/amrayn/easyloggingpp

编译命令：

1：make

2： g++ xxx.cc easylogging++.cc -o xxx-std=c++11

实时打印log文件：tail -f xxx.log

easyloggingpp常用功能：

1、打印等级及颜色、输出格式，写入log文件（打开颜色el::Loggers::addFlag(el::LoggingFlag::ColoredTerminalOutput)）;

2、打印著名（#define，fun（））、屏蔽（宏、配置文件，fun（））、判断（LOG_IF（））、

条件（LOG_EVERY_N()，LOG_AFTER_N(），LOG_N_TIMES(）等）、检查（check（））等


配置文件：

* GLOBAL:

   FORMAT               =  "%datetime --- %msg"
   
   FILENAME             =  "my.log"
   
   ENABLED              =  true
   
   TO_FILE              =  true
   
   TO_STANDARD_OUTPUT   =  true
   
   SUBSECOND_PRECISION  =  1
   
   PERFORMANCE_TRACKING =  true
   
   MAX_LOG_FILE_SIZE    =  2097152 ## 2MB - Comment starts with two hashes (##)
   
   LOG_FLUSH_THRESHOLD  =  1 ## Flush after every 1 logs（***写入文本刷新频率，单位：行）
   
* DEBUG:

   ##FORMAT               = "%datetime{%d/%M} %func %msg"
   
   FILENAME             =  "DEBUG.log"