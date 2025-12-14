#include "point_phase.h"
#include <iostream>
//
RollOutcome PointPhase::get_outcome(Roll *roll)
{

    if (roll == nullptr){

        return RollOutcome::no_point;
    }
    
    int value = roll->roll_value();

    if (value == point) {

        return RollOutcome::point;
    } else if (value == 7) {

        return RollOutcome::seven_out;
    } else {

        return RollOutcome::no_point;
    }
}