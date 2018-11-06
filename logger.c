#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdarg.h>
#include "logger.h"

void logger(char *file, char *fmt, ...)
{
        FILE *f = fopen(file, "a");
        if (f == NULL) {
                fprintf(stderr, "Error opening file\n");
                exit(1);
        }

        va_list ap;
        char msg[LOGSIZ];
        time_t rawtime;
        struct tm *timeinfo;

        va_start(ap, fmt);
        vsnprintf(msg, sizeof(msg), fmt, ap);
        va_end(ap);

        time(&rawtime);
        timeinfo = localtime(&rawtime);
        char buf[TIMSIZ];
        strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", timeinfo);

        fprintf(f, "[%s]: %s\n", buf, msg);

        fclose(f);
}
