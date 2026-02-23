#pragma once
#include <stdio.h>
#include <stdarg.h>

#define LOG_LEVEL_LEN 4

typedef enum {
    LOG_DBG,
    LOG_INFO,
    LOG_WARN,
    LOG_ERR
} LOG_LEVEL_E;




#ifdef GENERIC_LOG_LEVEL_SET
    #define LOG_LEVEL_CUR GENERIC_LOG_LEVEL_SET
#elif defined(DYN_LOG)
    #define LOG_LEVEL_CUR __log_level_dyn
    void log_level_set(LOG_LEVEL_E level);
#else
    #error "must define either DYN_LOG or LOG_LEVEL."
#endif

void generic_logger(LOG_LEVEL_E level, const char * fmt, ...);

#define LOGD(fmt, ...) generic_logger(LOG_DBG, fmt, ##__VA_ARGS__)
#define LOGI(fmt, ...) generic_logger(LOG_INFO, fmt, ##__VA_ARGS__)
#define LOGW(fmt, ...) generic_logger(LOG_WARN, fmt, ##__VA_ARGS__)
#define LOGE(fmt, ...) generic_logger(LOG_ERR, fmt, ##__VA_ARGS__)