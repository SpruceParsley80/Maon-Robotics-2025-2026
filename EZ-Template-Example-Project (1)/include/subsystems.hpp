#pragma once

#include "EZ-Template/api.hpp"
#include "api.h"

extern Drive chassis;

//intakes, from bottom to top
inline pros::Motor intake1(1);
inline pros::Motor intake2(-10);
inline pros::Motor intake3(9);
inline pros::Motor intake4(21);

//pneumatics
//scraper
inline pros::adi::DigitalOut scrape(2);
//weird lifting intake thing
inline pros::adi::DigitalOut lift(3); //its probably made out of 2 pistons but still


// Your motors, sensors, etc. should go here. Below are examples

// inline pros::Motor intake(1);
// inline pros::adi::DigitalIn limit_switch('A');