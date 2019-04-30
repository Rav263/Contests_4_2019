#include <stdio.h>
#include <cmath>

#include "mz02_1.h"


namespace numbers {
    class complex_stack {
        unsigned int size = 0;
        unsigned int length = 10;
        unsigned int modifier = 2;

        complex *stack = new complex[length];
    };
}


