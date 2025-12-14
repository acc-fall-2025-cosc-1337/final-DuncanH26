//
#include "die.h"
#include <cstdlib>
#include <ctime>

int Die::roll(){

    return(rand() % sides) + 1;
}