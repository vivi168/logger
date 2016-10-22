#include <math.h>
#include "logger.h"

int main()
{
        logger("ronre.log", "Hello %s, Pi is %f", "World", M_PI);
        return 0;
}
