#ifndef _LOGGER_H
#define _LOGGER_H

#define LOGSIZ 1024
#define TIMSIZ 21

#define LV_UNKNOWN 'U'
#define LV_FATAL   'F'
#define LV_ERROR   'E'
#define LV_WARN    'W'
#define LV_INFO    'I'
#define LV_DEBUG   'D'

void logger(char *file, char lv, char *fmt, ...);

#endif
