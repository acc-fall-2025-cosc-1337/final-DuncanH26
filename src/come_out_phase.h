//
#ifndef COME_OUT_PHASE_H
#define COME_OUT_PHASE_H

#include "phase.h"
#include "roll.h"

class ComeOutPhase : public Phase {

    public: 

    RollOutcome get_outcome(Roll* roll);
};

#endif