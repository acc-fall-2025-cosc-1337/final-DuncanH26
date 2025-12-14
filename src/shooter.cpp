//
#include "shooter.h"
#include <iostream>
#include <algorithm>

Roll* Shooter::throw_dice(Die& die1, Die& die2){

    Roll* new_Roll = new Roll(die1, die2);
    new_Roll->roll_dice();

    rolls.push_back(new_Roll);

    return new_Roll;
}

void Shooter::display_rolled_values(){

    std::cout << rolls.size() << "rolled values: \n";
    for (const auto& roll_ptr : rolls){

        std::cout << "Roll Value: " << roll_ptr->roll_value() << "\n";
    }
}

Shooter::~Shooter(){

    std::cout << rolls.size() << "allocated rolls \n";

    for (Roll* roll_ptr : rolls){

        delete roll_ptr;
    }
}