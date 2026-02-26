# generic_log
single header c lib for color printed log messages with log level control.
just add [generic_log.h](generic_log.h) to your project.
# config
```
valid log levels:
    LOG_DBG(0),
    LOG_INFO(1),
    LOG_WARN(2),
    LOG_ERR(3),
```
select dynamic log or static log by passing -DGENERIC_LOG_LEVEL_SET(0-3) or -DDYN_LOG to your compiler of choice
# dynamic log level setting
call 
```C
  log_level_set(LOG_LEVEL_E level)
```
for setting log level
