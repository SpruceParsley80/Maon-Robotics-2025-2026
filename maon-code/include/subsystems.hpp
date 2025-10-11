#pragma once

#include "EZ-Template/api.hpp"
#include "api.h"

extern Drive chassis;

// Your motors, sensors, etc. should go here.  Below are examples

inline pros::Motor intake(3); //CHANGE
inline pros::Motor upper(4); //CHANGE
// inline pros::Pneumatics descore(3); //change
// inline pros::Pneumatics scrape(2); //change also
// inline pros::adi::DigitalIn limit_switch('A');