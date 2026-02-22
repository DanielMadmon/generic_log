# generic_log
single header generic log header file.
just add [generic_log.h](generic_log.h) to your project.
# config
```
valid log levels:
    LOG_DBG,
    LOG_INFO,
    LOG_WARN,
    LOG_ERR,
```
select dynamic log or static log by passing -DLOG_LEVEL(0-3) or -DDYN_LOG to your compiler of choice
# dynamic log level setting
call 
```C
  log_level_set(LOG_LEVEL_E level)
```
for setting log level
