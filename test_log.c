#include "generic_log.h"

int main() {
    log_level_set(LOG_DBG);
    LOGD("This is a debug message");
    LOGI("This is an info message");
    LOGW("This is a warning message");
    LOGE("This is an error message");
    log_level_set(LOG_INFO);
    LOGD("This is a debug message");
    LOGI("This is an info message");
    LOGW("This is a warning message");
    LOGE("This is an error message");
    log_level_set(LOG_WARN);
    LOGD("This is a debug message");
    LOGI("This is an info message");
    LOGW("This is a warning message");
    LOGE("This is an error message");
    log_level_set(LOG_ERR);
    LOGD("This is a debug message");
    LOGI("This is an info message");
    LOGW("This is a warning message");
    LOGE("This is an error message");
    return 0;
}