#ifndef _MOCAR_LOG_H_
#define _MOCAR_LOG_H_

#include "zlog.h"

#define MOCAR_LOG_CONF   "/usr/local/config/mocar_log.conf"
#define MOCAR_LOG_RELOAD_TIME  60

#define MOCAR_LOG_INIT(_CONF_PATH_, _CNAME_)    dzlog_init(_CONF_PATH_, _CNAME_)   

#define MOCAR_LOG_RELOAD(_CONF_PATH_)           zlog_reload(_CONF_PATH_)                                  

#define MOCAR_LOG_FINI()        \
    do                                       \
    {                                        \
        zlog_fini();        \
    } while (0)   

#define MOCAR_LOG_FATAL(_MSG_)                  \
    do                                       \
    {                                        \
        dzlog_fatal(_MSG_); \
    } while (0)
#define MOCAR_LOG_FATAL_FMT(_FMT_, ...)                            \
    do                                                          \
    {                                                           \
        dzlog_fatal(_FMT_, ##__VA_ARGS__); \
    } while (0)

#define MOCAR_LOG_ERROR(_MSG_)                  \
    do                                       \
    {                                        \
        dzlog_error(_MSG_); \
    } while (0)
#define MOCAR_LOG_ERROR_FMT(_FMT_, ...)                            \
    do                                                          \
    {                                                           \
        dzlog_error(_FMT_, ##__VA_ARGS__); \
    } while (0)

#define MOCAR_LOG_WARN(_MSG_)                  \
    do                                      \
    {                                       \
        dzlog_warn(_MSG_); \
    } while (0)
#define MOCAR_LOG_WARN_FMT(_FMT_, ...)                            \
    do                                                         \
    {                                                          \
        dzlog_warn(_FMT_, ##__VA_ARGS__); \
    } while (0)

#define MOCAR_LOG_NOTICE(_MSG_)                  \
    do                                      \
    {                                       \
        dzlog_notice(_MSG_); \
    } while (0)
#define MOCAR_LOG_NOTICE_FMT(_FMT_, ...)                            \
    do                                                         \
    {                                                          \
        dzlog_notice(_FMT_, ##__VA_ARGS__); \
    } while (0)

#define MOCAR_LOG_INFO(_MSG_)                  \
    do                                       \
    {                                        \
        dzlog_info(_MSG_); \
    } while (0)
#define MOCAR_LOG_INFO_FMT(_FMT_, ...)                            \
    do                                                          \
    {                                                           \
        dzlog_info(_FMT_, ##__VA_ARGS__); \
    } while (0)

#define MOCAR_LOG_DEBUG(_MSG_)                  \
    do                                       \
    {                                        \
        dzlog_debug(_MSG_); \
    } while (0)
#define MOCAR_LOG_DEBUG_FMT(_FMT_, ...)                            \
    do                                                          \
    {                                                           \
        dzlog_debug(_FMT_, ##__VA_ARGS__); \
    } while (0)


#define ESC_START       "\033["
#define ESC_END         "\033[0m"
#define COLOR_FATAL     "31;40;5m"
#define COLOR_ALERT     "31;40;1m"
#define COLOR_CRIT      "31;40;1m"
#define COLOR_ERROR     "35;40;1m"
#define COLOR_WARN      "33;40;1m"
#define COLOR_NOTICE    "34;40;1m"
#define COLOR_INFO      "32;40;1m"
#define COLOR_DEBUG     "36;40;1m"
#define COLOR_TRACE     "37;40;1m"

#define LOG_FATAL(fmt,args...)         \
    zlog(defult, __FILE__, sizeof(__FILE__)-1, \
    __func__, sizeof(__func__)-1, __LINE__, \
    ZLOG_LEVEL_FATAL, ESC_START COLOR_FATAL fmt ESC_END, ##args);

#define LOG_ERROR(fmt , args...)    \
    zlog(defult, __FILE__, sizeof(__FILE__)-1, \
    __func__, sizeof(__func__)-1, __LINE__, \
    ZLOG_LEVEL_ERROR, ESC_START COLOR_ERROR fmt ESC_END, ##args);
    
#define LOG_WARN(fmt, args...)        \
    zlog(defult, __FILE__, sizeof(__FILE__)-1, \
    __func__, sizeof(__func__)-1, __LINE__, \
    ZLOG_LEVEL_WARN, ESC_START COLOR_WARN fmt ESC_END, ##args);
    
#define LOG_NOTICE(fmt , args...)    \
    zlog(defult, __FILE__, sizeof(__FILE__)-1, \
    __func__, sizeof(__func__)-1, __LINE__, \
    ZLOG_LEVEL_NOTICE, ESC_START COLOR_NOTICE fmt ESC_END, ##args);
    
#define LOG_INFO(fmt,args...)         \
    zlog(defult, __FILE__, sizeof(__FILE__)-1, \
    __func__, sizeof(__func__)-1, __LINE__, \
    ZLOG_LEVEL_INFO, ESC_START COLOR_INFO fmt ESC_END, ##args);
    
#define LOG_DEBUG(fmt , args...)    \
    zlog(defult, __FILE__, sizeof(__FILE__)-1, \
    __func__, sizeof(__func__)-1, __LINE__, \
    ZLOG_LEVEL_DEBUG, ESC_START COLOR_DEBUG fmt ESC_END, ##args);


#define C_LOG_FATAL(log_category,fmt,args...)         \
    zlog(log_category, __FILE__, sizeof(__FILE__)-1, \
    __func__, sizeof(__func__)-1, __LINE__, \
    ZLOG_LEVEL_FATAL, ESC_START COLOR_FATAL fmt ESC_END, ##args);
    
#define C_LOG_ERROR(log_category,fmt , args...)    \
    zlog(log_category, __FILE__, sizeof(__FILE__)-1, \
    __func__, sizeof(__func__)-1, __LINE__, \
    ZLOG_LEVEL_ERROR, ESC_START COLOR_ERROR fmt ESC_END, ##args);
    
#define C_LOG_WARN(log_category,fmt, args...)        \
    zlog(log_category, __FILE__, sizeof(__FILE__)-1, \
    __func__, sizeof(__func__)-1, __LINE__, \
    ZLOG_LEVEL_WARN, ESC_START COLOR_WARN fmt ESC_END, ##args);
    
#define C_LOG_NOTICE(log_category,fmt , args...)    \
    zlog(log_category, __FILE__, sizeof(__FILE__)-1, \
    __func__, sizeof(__func__)-1, __LINE__, \
    ZLOG_LEVEL_NOTICE, ESC_START COLOR_NOTICE fmt ESC_END, ##args);
    
#define C_LOG_INFO(log_category,fmt,args...)         \
    zlog(log_category, __FILE__, sizeof(__FILE__)-1, \
    __func__, sizeof(__func__)-1, __LINE__, \
    ZLOG_LEVEL_INFO, ESC_START COLOR_INFO fmt ESC_END, ##args);
    
#define C_LOG_DEBUG(log_category,fmt , args...)    \
    zlog(log_category, __FILE__, sizeof(__FILE__)-1, \
    __func__, sizeof(__func__)-1, __LINE__, \
    ZLOG_LEVEL_DEBUG, ESC_START COLOR_DEBUG fmt ESC_END, ##args);
#endif
