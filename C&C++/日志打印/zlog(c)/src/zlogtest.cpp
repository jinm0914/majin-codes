 //
 // This file is part of Easylogging++ samples
 //
 // Very basic sample to configure using global configuration (el::Loggers::configureFromGlobal)
 //
 // Revision 1.1
 // @author mkhan3189
 //

#define MAJIN(LEVEL) LOG(LEVEL)
#include <unistd.h>
#include "../include/majin_zlog.h"
#include <string.h>
zlog_category_t * defult = NULL;
zlog_category_t * majin1 = NULL;
zlog_category_t * majin2 = NULL;
zlog_category_t * majin3 = NULL;

int log_init() {
    //初始化.配置文件名是固定的log.conf
    if (zlog_init("../config/zlog.conf"))  {
        printf("Error: zlog_init\n");
    	zlog_fini();
        return -1;
    }
    //找到分类,在配置文件中的category
    defult = zlog_get_category("defult_log");
    majin1 = zlog_get_category("majin_log1");
    majin2 = zlog_get_category("majin_log2");
    majin3 = zlog_get_category("majin_log3");
    if (!majin3) {
	    printf("Error: get cat fail\n");
	    zlog_fini();
	    return -2;
    }
    return 0 ;
}
void log_fini() {
    zlog_fini();
}
int main(void) {

	log_init();
    int i=0;
    while(1){
    	sleep(1);
        LOG_DEBUG("This is DEBUG = %d",i);
        LOG_INFO("This is WARN = %d",i);
		LOG_INFO("This is WARN = %d",i);
		LOG_INFO("This is WARN = %d",i);
		LOG_NOTICE("This is NOTICE = %d",i);
		LOG_WARN("This is WARN = %d",i);
		LOG_ERROR("This is ERROR = %d",i);
		LOG_FATAL("This is FATAL = %d\n",i++);

		C_LOG_DEBUG(majin1,"This is DEBUG = %d",i);
        C_LOG_INFO(majin1,"This is WARN = %d",i);
		C_LOG_NOTICE(majin1,"This is NOTICE = %d",i);
		C_LOG_WARN(majin1,"This is WARN = %d",i);
		C_LOG_ERROR(majin1,"This is ERROR = %d",i);
		C_LOG_FATAL(majin1,"This is FATAL = %d\n",i++);

		C_LOG_DEBUG(majin2,"This is DEBUG = %d",i);
        C_LOG_INFO(majin2,"This is WARN = %d",i);
		C_LOG_NOTICE(majin2,"This is NOTICE = %d",i);
		C_LOG_WARN(majin2,"This is WARN = %d",i);
		C_LOG_ERROR(majin2,"This is ERROR = %d",i);
		C_LOG_FATAL(majin2,"This is FATAL = %d\n",i++);

		C_LOG_DEBUG(majin3,"This is DEBUG = %d",i);
        C_LOG_INFO(majin3,"This is WARN = %d",i);
		C_LOG_NOTICE(majin3,"This is NOTICE = %d",i);
		C_LOG_WARN(majin3,"This is WARN = %d",i);
		C_LOG_ERROR(majin3,"This is ERROR = %d",i);
		C_LOG_FATAL(majin3,"This is FATAL = %d\n",i++);
    
    }
	log_fini();
    return 0;
}
