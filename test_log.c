#include "log.h"

int main() {
    log_level_set(LOG_DBG);
    LOG_DBG("This is a debug message");
    LOG_INFO("This is an info message");
    LOG_WARN("This is a warning message");
    LOG_ERR("This is an error message");
    log_level_set(LOG_INFO);
    LOG_DBG("This is a debug message");
    LOG_INFO("This is an info message");
    LOG_WARN("This is a warning message");
    LOG_ERR("This is an error message");
    log_level_set(LOG_WARN);
    LOG_DBG("This is a debug message");
    LOG_INFO("This is an info message");
    LOG_WARN("This is a warning message");
    LOG_ERR("This is an error message");
    log_level_set(LOG_ERR);
    LOG_DBG("This is a debug message");
    LOG_INFO("This is an info message");
    LOG_WARN("This is a warning message");
    LOG_ERR("This is an error message");
    return 0;
}