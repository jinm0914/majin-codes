 //
 // This file is part of Easylogging++ samples
 //
 // Very basic sample to configure using global configuration (el::Loggers::configureFromGlobal)
 //
 // Revision 1.1
 // @author majin
 //


#include <unistd.h>
#include "easylogging++.h"
#define MAJIN(LEVEL) CLOG(LEVEL,"MAJIN","LZL") //自定义打印名称以及多logger

INITIALIZE_EASYLOGGINGPP

int main(void) {  
    el::Loggers::addFlag(el::LoggingFlag::CreateLoggerAutomatically); //设置默认配置文件
    el::Loggers::addFlag(el::LoggingFlag::MultiLoggerSupport); //自动注册logger id，无此句每次创建logger后需要手动注册
    el::Configurations confFromFile("default.conf"); //设置默认配置文件
    el::Loggers::setDefaultConfigurations(confFromFile, true);

    el::Configurations conf1("my1.conf");//定义配置文件路径
    el::Loggers::reconfigureLogger("logger_id_1", conf1);//读取配置文件并与logger id绑定
    CLOG(INFO,"logger_id_1")<<" ------logger_id_1------  ";//以logger_id_1配置文件打印其信息

    el::Configurations conf2("my2.conf"); 
    el::Loggers::reconfigureLogger("logger_id_2", conf2);
    CLOG(INFO,"logger_id_2")<<" ------logger_id_2------  ";


    el::Loggers::addFlag(el::LoggingFlag::ColoredTerminalOutput); //打印显示颜色

    // el::Loggers::getLogger("logger_id"); //创建logger后需要手动注册
    int i=0;

    while(1){
        Sleep(1000);
        MAJIN(TRACE) << "this is TRACE  " << i;
        MAJIN(DEBUG) << "this is DEBUG  " <<i;
        MAJIN(WARNING) << "this is WARNING  " << i;
        MAJIN(INFO) << "this is INFO  " << i;
        MAJIN(ERROR) << "this is ERROR  " << i++;   
        // MAJIN(VERBOSE) << "this is VERBOSE  " << i++;   
        // MAJIN(UNKNOWN) << "this is UNKNOWN  " << i++;   
        // MAJIN(FATAL) << "this is FATAL  " << i++;   
        // MAJIN(GLOBAL) << "this is GLOBAL  " << i++;   
    }
    return 0;
}
