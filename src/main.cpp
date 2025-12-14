#include <iostream>
#include <ctime>
#include "die.h"
#include "roll.h"
#include "shooter.h"
#include "come_out_phase.h"
#include "point_phase.h"


int main() 
{
	
	srand(static_cast<unsigned int>(time(0)));

	Die die1, die2;

	Shooter shooter;

	Roll* roll = nullptr;

	int point = 0;

	ComeOutPhase come_out_phase;
	RollOutcome outcome = RollOutcome::no_point;

	do {

		roll = shooter.throw_dice(die1, die2);
		int rolled_value = roll->roll_value();
		outcome = come_out_phase.get_outcome(roll);

		if (outcome == RollOutcome::natural || outcome == RollOutcome::craps){

			std::cout << "Rolled" << rolled_value << "roll again" << std::endl;
		}
	} while (outcome == RollOutcome::natural || outcome == RollOutcome::craps);

	point = roll->roll_value();

	outcome = RollOutcome::point;

while (!(outcome == RollOutcome::seven_out || outcome == RollOutcome::point)){

	std::cout << "Rolled" << roll->roll_value() << "roll again" << std::endl;

	roll = shooter.throw_dice(die1, die2);
	outcome = point_phase.get_outcome(roll);
}

std::cout << "Rolled" << roll->roll_value() << "end of point phase" << std::endl;

shooter.display_rolled_values();

	return 0;
}