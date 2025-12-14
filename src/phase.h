//
#ifndef PHASE_H
#define PHASE_H
#include "roll.h"

enum class RollOutcome {

    natural,
    craps,
    point,
    seven_out,
    no_point
};

class Phase {

    public:

    virtual RollOutcome get_outcome(int rolled_value) = 0;

    virtual ~Phase() = default;
};

#endif