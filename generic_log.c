#include "generic_log.h"

static LOG_LEVEL_E __log_level_dyn = LOG_ERR;

static const char* type[LOG_LEVEL_LEN] = {
    "DEBUG",
    "INFO",
    "WARN",
    "ERR"
}; 


static const char* colors[LOG_LEVEL_LEN + 1] = {
    "\x1b[37m", // white
    "\x1b[32m", // green 
    "\x1b[1;33m", // yellow
    "\x1b[1;31m" // red
    "\x1b[m"     //normal
};

#ifdef DYN_LOG
    void log_level_set(LOG_LEVEL_E level) {
        __log_level_dyn = level;
    }
#endif


void generic_logger(LOG_LEVEL_E level, const char * fmt, ...) {
    if (level < LOG_LEVEL_CUR || level >= LOG_LEVEL_LEN) {
        return;
    }
    va_list args;
    va_start(args, fmt);
        #ifndef NO_ANSI 
            printf("%s", colors[level]);
        #endif
        
        printf("[%s]",type[level]); 
        vfprintf(stdout, fmt, args);
        printf("%s",colors[LOG_LEVEL_LEN]);
        printf("\n%s", colors[LOG_DBG]);
    va_end(args);
}