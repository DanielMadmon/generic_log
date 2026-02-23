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


static const char* type[LOG_LEVEL_LEN] = {
    "DEBUG",
    "INFO",
    "WARN",
    "ERR"
}; 


static const char* colors[LOG_LEVEL_LEN] = {
    "\x1b[0m", // white
    "\x1b[32m", // green 
    "\x1b[1;33m", // yellow
    "\x1b[1;31m" // red
};

#ifndef LOG_LEVEL
    #ifndef DYN_LOG
        #error "must define either DYN_LOG or LOG_LEVEL."
    #endif
#endif

#ifdef DYN_LOG
    #ifdef LOG_LEVEL
        #error "can't define both DYN_LOG & LOG_LEVEL select one option"
    #endif
    #define LOG_LEVEL __log_level_dyn
    static LOG_LEVEL_E __log_level_dyn = LOG_ERR;
    void log_level_set(LOG_LEVEL_E level) {
        __log_level_dyn = level;
    }
#endif


void tiny_logger(LOG_LEVEL_E level, const char * fmt, ...) {
    if (level < LOG_LEVEL || level >= LOG_LEVEL_LEN) {
        return;
    }
    va_list args;
    va_start(args, fmt);
        #ifndef NO_ANSI 
            printf("%s", colors[level]);
        #endif
        
        printf("[%s]",type[level]); 
        vfprintf(stdout, fmt, args);
        printf("\n%s", colors[LOG_DBG]);
    va_end(args);
}

#define LOGD(fmt, ...) tiny_logger(LOG_DBG, fmt, ##__VA_ARGS__)
#define LOGI(fmt, ...) tiny_logger(LOG_INFO, fmt, ##__VA_ARGS__)
#define LOGW(fmt, ...) tiny_logger(LOG_WARN, fmt, ##__VA_ARGS__)
#define LOGE(fmt, ...) tiny_logger(LOG_ERR, fmt, ##__VA_ARGS__)