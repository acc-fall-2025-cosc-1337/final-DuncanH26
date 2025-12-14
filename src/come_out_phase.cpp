#include "come_out_phase.h"
#include "phase.h"
#include "roll.h"
#include <iostream>
//
RollOutcome ComeOutPhase::get_outcome(Roll* roll)
{

    if (roll == nullptr){

        return RollOutcome::no_point;
    }

    int value = roll->roll_value();

if (value == 7 || value == 11){

    return RollOutcome::natural;
} else if (value == 2 || value == 3 || value == 12){

    return RollOutcome::craps;
} else {

    return RollOutcome::point;
}

}