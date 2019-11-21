# majin-C_C++
日志打印问题
模版：https://github.com/amrayn/easyloggingpp（c++），zlog（c）

easyloggingpp常用功能：
1、打印等级及颜色、输出格式，写入log文件
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

日志写入xx.log文本后，使用tail -f xx.log可以循环打印更新数据，常用于主程序不打印日志，
而将各种类型的日志写入不同的文本使用tail -f xx.log打印，或相同的文本使用tail -f xx.log |grep “xxx”过滤打印；

tail 命令见：https://www.runoob.com/linux/linux-comm-tail.html