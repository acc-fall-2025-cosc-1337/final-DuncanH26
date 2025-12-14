//
#ifndef POINT_PHASE_H
#define POINT_PHASE_H

#include "phase.h"
#include "roll.h"


class PointPhase : public Phase {

    public:

    PointPhase(int p) : point(p) {}

    RollOutcome get_outcome(Roll* roll);

    private:

    int point;
};

#endif