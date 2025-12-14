#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "die.h"
#include "roll.h"
#include "shooter.h"
#include "come_out_phase.h"
#include "point_phase.h"
#include "phase.h"
#include <vector>
#include <numeric>

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

class MockRoll : public Roll {
private:
    int fixed_value;
public:

 MockRoll(int val) : Roll(*(new Die()), *(new Die())), fixed_value(val) {}
    void roll_dice()  
	 int roll_value() 
};

TEST_CASE("Test die returns value 1-6"){

	Die die;

	
	 for (int i = 0; i < 10; ++i) {
        int roll = die.roll();

		REQUIRE(roll >= 1);
        REQUIRE(roll <= 6);

}
}


TEST_CASE("Test die rolls value from 2-12 looped"){

	Die d1;
	Die d2;

	for (int i = 0; i < 10; ++i){

		Roll r(d1, d2);
		r.roll_dice();
		int result = r.roll_value();


		REQUIRE(result >= 2);
		REQUIRE(result <= 12);
	}
}

TEST_CASE("Test shooter returns a roll and returns value fro 2-12"){

	Die d1, d2;
	Shooter s;
	std::vector<Roll*> rolls_thrown;

	for (int i = 0; i < 10; ++i){

		Roll* current_roll_ptr = s.throw_dice(d1, d2);

		REQUIRE(current_roll_ptr != nullptr);

		int value = current_roll_ptr->roll_value();

		REQUIRE(value >= 2);
		REQUIRE(value <= 12);
	}
}

TEST_CASE("ComeOutPhase outcomes"){

	ComeOutPhase phase;

	MockRoll r7(7);
	REQUIRE(phase.get_outcome(&r7) == RollOutcome::natural);
    MockRoll r11(11);
    REQUIRE(phase.get_outcome(&r11) == RollOutcome::natural);
	MockRoll r2(2);
    REQUIRE(phase.get_outcome(&r2) == RollOutcome::craps);
    MockRoll r3(3);
    REQUIRE(phase.get_outcome(&r3) == RollOutcome::craps);
    MockRoll r12(12);
    REQUIRE(phase.get_outcome(&r12) == RollOutcome::craps);
	MockRoll r4(4);
    REQUIRE(phase.get_outcome(&r4) == RollOutcome::point);
    MockRoll r10(10);
    REQUIRE(phase.get_outcome(&r10) == RollOutcome::point);
}

TEST_CASE("Test PointPhase outcomes"){

	PointPhase phase(6);

	MockRoll r6(6);
	REQUIRE(phase.get_outcome(&r6) == RollOutcome::point);

	MockRoll r7(7);
	REQUIRE(phase.get_outcome(&r7) == RollOutcome::seven_out);

	MockRoll r4(4);
	REQUIRE(phase.get_outcome(&r4) == RollOutcome::no_point);

	MockRoll r8(8);
	REQUIRE(phase.get_outcome(&r8) == RollOutcome::no_point);
}