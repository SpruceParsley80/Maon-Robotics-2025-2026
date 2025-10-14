#pragma once

#include "EZ-Template/api.hpp"
#include "api.h"

extern Drive chassis;

//intakes, from bottom to top
extern pros::Motor intake1(1);
extern pros::Motor intake2(10);
extern pros::Motor intake3(9);
extern pros::Motor intake4(21);



// Your motors, sensors, etc. should go here.  Below are examples

// inline pros::Motor intake(1);
// inline pros::adi::DigitalIn limit_switch('A');