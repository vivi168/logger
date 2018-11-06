#include <math.h>
#include "logger.h"

int main()
{
        logger("ronre.log", LV_INFO, "Hello %s, Pi is %f", "World", M_PI);
        return 0;
}
