#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdarg.h>
#include "logger.h"

void logger(char *file, char *fmt, ...)
{
        va_list ap;
        va_start(ap, fmt);
        char msg[LOGSIZ];
        vsnprintf(msg, sizeof(msg), fmt, ap);

        time_t rawtime;
        struct tm *timeinfo;
        time(&rawtime);
        timeinfo = localtime(&rawtime);
        char buf[TIMSIZ];

        strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", timeinfo);

        FILE *f = fopen(file, "a");
        if (f == NULL) {
                printf("Error opening file\n");
                exit(1);
        }
        fprintf(f, "[%s]: %s\n", buf, msg);

        fclose(f);
        va_end(ap);
}
