#include "vex.h"
// #include "robot-config.cpp"

bool blocked = false;
int numDeg = 0;

/**
 * Resets the constants for auton movement.
 * Modify these to change the default behavior of functions like
 * drive_distance(). For explanations of the difference between
 * drive, heading, turning, and swinging, as well as the PID and
 * exit conditions, check the docs.
 */

void default_constants()
{
    // Each constant set is in the form of (maxVoltage, kP, kI, kD, startI).
    chassis.set_drive_constants(12, 2, 0, 1, 0);
    chassis.set_heading_constants(6, .4, 0, 1, 0);
    chassis.set_turn_constants(12, 0.1, 0.06, 0.4, 0);
    chassis.set_swing_constants(12, 0, 0, 0, 15);

    // Each exit condition set is in the form of (settle_error, settle_time, timeout).
    chassis.set_drive_exit_conditions(1, 300, 1000);
    chassis.set_turn_exit_conditions(1, 300, 1000);
    chassis.set_swing_exit_conditions(1, 300, 3000);
}

/**
 * Sets constants to be more effective for odom movements.
 * For functions like drive_to_point(), it's often better to have
 * a slower max_voltage and greater settle_error than you would otherwise.
 */

void odom_constants()
{
    default_constants();
    chassis.heading_max_voltage = 10;
    chassis.drive_max_voltage = 8;
    chassis.drive_settle_error = 3;
    chassis.boomerang_lead = .5;
    chassis.drive_min_voltage = 0;
}

/*
void rightSide(){
    chassis.drive_distance(-5.3);
    chassis.turn_to_angle(-95);
    //wait(100, msec);
    chassis.drive_distance(-2.4);
    Intake.spinFor(forward, 500, deg, 480, rpm, true);
    chassis.drive_distance(4);
    Clamp.set(true);
    //chassis.turn_to_angle(170);
    //chassis.drive_distance(-6);
}
*/

void clampTest()
{
    highStakeM.spin(reverse, 20, pct);
    chassis.turn_to_angle(60);
    chassis.drive_distance(-5);

    chassis.turn_to_angle(-30);
    chassis.drive_distance(-6);

    Clamp.set(true); // Clamp onto mobile goal
    wait(1000, msec);

    Intake.spinFor(forward, 3000, deg, 600, rpm, false); // put ring onto goal

    chassis.turn_to_angle(92);

    Intake.spinFor(forward, 3000, deg, 600, rpm, false);
}

void awp()
{

    chassis.drive_distance(-8, 0, 6, 0);
    Clamp.set(true); // Clamp onto mobile goal
    wait(500, msec);
    // Intake.spinFor(forward, 10000, deg, 600, rpm, false);        //put ring onto goal
    Intake.spin(forward, 80, pct);

    chassis.turn_to_angle(99);

    chassis.drive_distance(9.5); // get bottom ring
    wait(900, msec);

    chassis.turn_to_angle(-65);
    wait(30, msec);

    chassis.drive_distance(10);

    wait(30, msec);
    // Intake.spinFor(forward, 0, deg, 0, rpm, true);

    Intake.stop();
    Clamp.set(false); // drop mobile goal halfway over

    chassis.drive_distance(9.5);
    chassis.turn_to_angle(46);

    chassis.drive_distance(-12.5);
    Clamp.set(true); // Clamp onto mobile goal
    wait(30, msec);

    chassis.turn_to_angle(-76);

    Intake.spin(forward, 80, pct);
    // Intake.spinFor(forward, 6000, deg, 600, rpm, false);

    chassis.drive_distance(5); // get bottom ring
    chassis.turn_to_angle(-72);

    chassis.drive_distance(-3);
    wait(100, msec);

    // moving towards the ladder
    chassis.drive_distance(-5.5); // drive to middle
    Intake.stop();
    chassis.drive_distance(-2.5);

    wait(30, msec);
}

void leftSide()
{
    Controller1.Screen.print("short leftSide");

    chassis.drive_distance(-8, 0, 6, 0);
    Clamp.set(true); // Clamp onto mobile goal
    wait(500, msec);
    Intake.spin(forward, 90, pct);

    chassis.turn_to_angle(99);

    chassis.drive_distance(8.5); // get bottom ring
    wait(300, msec);

    chassis.turn_to_angle(23);
    Intake.stop();

    Sweeper.set(true);

    wait(200, msec);
    chassis.drive_distance(12, 0, 9, 0);
    wait(100, msec);

    chassis.turn_to_angle(-50);
    // chassis.drive_distance(-1);
    Intake.spin(forward, 90, pct);
    chassis.drive_distance(3);
    wait(600, msec);
    Intake.stop();

    chassis.turn_to_angle(-157);
    chassis.drive_distance(-4);

    /*
      Intake.spin(reverse,100,pct);
      chassis.drive_distance(14);
      wait(150,msec);
      chassis.drive_distance(2.2);
      Intake.stop();
      wait(10,msec);
      chassis.drive_distance(-0.3);
      Intake.spin(forward,100,pct);
      wait(200,msec);
      chassis.drive_distance(-5);
      */

    // wait(50,msec);
    // chassis.drive_distance(-10);
    // chassis.turn_to_angle(70);
    // Intake.stop();
    // chassis.drive_distance(-13);

    /*
        chassis.turn_to_angle(60);

        //moving towards the ladder
        chassis.drive_distance(-7);
        Intake.stop();
        chassis.drive_distance(-5.5);
        */
}

// works on both sides, red and blue right sides
void rightSide()
{
    Controller1.Screen.print("short rightSide");
    chassis.drive_distance(-9, 0, 6, 0);
    Clamp.set(true); // Clamp onto mobile goal
    wait(500, msec);
    // Intake.spinFor(forward, 10000, deg, 600, rpm, false);        //put ring onto goal
    Intake.spin(forward, 80, pct);

    chassis.turn_to_angle(-95);
    chassis.drive_distance(9); // get bottom ring

    wait(100, msec);

    chassis.turn_to_angle(-70);

    // moving towards the ladder
    wait(10, msec);
    chassis.drive_distance(-9);
    Intake.stop();
    chassis.drive_distance(-5);
}

// RED SIDE ONLY --> with double stacks
void redLeftAuton()
{
    Controller1.Screen.print("redLeftAuton");

    chassis.drive_distance(-8, 0, 6, 0);
    // chassis.drive_distance(-1, 0, 6, 0);
    Clamp.set(true); // Clamp onto mobile goal
    wait(500, msec);
    Intake.spin(forward, 80, pct);

    chassis.turn_to_angle(97);

    chassis.drive_distance(9); // get bottom ring
    wait(900, msec);

    chassis.turn_to_angle(172); // turn to first ring
    chassis.drive_distance(4.5);

    wait(100, msec);

    chassis.drive_distance(-4);

    chassis.turn_to_angle(-158); // turn to second ring
    chassis.drive_distance(5.2);

    wait(100, msec);
    chassis.drive_distance(-5);

    chassis.turn_to_angle(70);

    // moving towards the ladder
    Hang.set(false);
    wait(10, msec);
    chassis.drive_distance(-8);
    Intake.stop();
    chassis.drive_distance(-5.4);
}

// BLUE SIDE ONLY --> with double stacks
void blueRightAuton()
{
    Controller1.Screen.print("blueRightAuton");

    chassis.drive_distance(-8, 0, 6, 0);
    // chassis.drive_distance(-1, 0, 6, 0);
    Clamp.set(true); // Clamp onto mobile goal
    wait(500, msec);
    // Intake.spinFor(forward, 10000, deg, 600, rpm, false);        //put ring onto goal
    Intake.spin(forward, 80, pct);

    chassis.turn_to_angle(-100);
    chassis.drive_distance(10); // get bottom ring

    wait(100, msec);

    chassis.turn_to_angle(188); // turn to first ring
    chassis.drive_distance(4); //4.3

    wait(100, msec);

    chassis.drive_distance(-4);

    chassis.turn_to_angle(153); // turn to second ring
    chassis.drive_distance(4);  //4.2

    wait(100, msec);
    chassis.drive_distance(-5);

    chassis.turn_to_angle(-73);

    // moving towards the ladder
    wait(10, msec);
    chassis.drive_distance(-8);
    Intake.stop();
    chassis.drive_distance(-5.4);
}

void goalRushRed(){
    Controller1.Screen.print("goalRushRed");

    chassis.drive_distance(10.5);
    chassis.turn_to_angle(-45);
    chassis.drive_distance(3.3);

    Sweeper.set(true);
    wait(500, msec);
    chassis.drive_distance(-3.2, 0, 4, 0); // distance, heading, drive_max_voltage, heading_max_voltage
    chassis.turn_to_angle(-120);           // turn to drag out of the way

    Sweeper.set(false);

    wait(1000, msec);
    // chassis.turn_to_angle(-98);

    chassis.turn_to_angle(-240); // turn to clamp
    chassis.drive_distance(-6, 0, 4, 0);
    // chassis.drive_distance(-1);
    Clamp.set(true); // clamp onto mogo

    Intake.spin(forward, 80, pct);

    chassis.turn_to_angle(-182);
    chassis.drive_distance(5.5); // get bottom ring
    Intake.stop();

    chassis.turn_to_angle(-35);
    // chassis.drive_distance(-3);
    Clamp.set(false);

    chassis.drive_distance(3);
    chassis.turn_to_angle(80);
    chassis.drive_distance(-5);
    Clamp.set(true); // grab second mogo
    Intake.spin(forward, 80, pct);

    chassis.turn_to_angle(-30);

    // wait(500, msec),
    chassis.drive_distance(2.7);

    // chassis.turn_to_angle()
}

void goalRushBlue()
{
    Controller1.Screen.print("goalRushBlue");

    chassis.drive_distance(10.7);
    wait(10, msec);
    chassis.turn_to_angle(28);
    chassis.drive_distance(3.3);

    Sweeper.set(true);
    wait(500, msec);
    chassis.drive_distance(-3.2, 0, 4, 0); // distance, heading, drive_max_voltage, heading_max_voltage
    chassis.turn_to_angle(83);             // turn to drag out of the way

    Sweeper.set(false);

    wait(1000, msec);
    // chassis.turn_to_angle(-98);

    chassis.turn_to_angle(255); // turn to clamp
    chassis.drive_distance(-6.5, 0, 4, 0);
    // chassis.drive_distance(-1);
    Clamp.set(true); // clamp onto mogo

    Intake.spin(forward, 80, pct);

    chassis.turn_to_angle(190);
    chassis.drive_distance(6); // get bottom ring
    Intake.stop();

    chassis.turn_to_angle(35);
    // chassis.drive_distance(-3);
    Clamp.set(false);

    chassis.drive_distance(3);
    chassis.turn_to_angle(-84);
    chassis.drive_distance(-5);
    Clamp.set(true); // grab second mogo
    Intake.spin(forward, 80, pct);

    chassis.turn_to_angle(30);

    // wait(500, msec),
    chassis.drive_distance(3);

    // chassis.turn_to_angle()
}

void red4test()
{
    Controller1.Screen.print("Running red 4 test");
    wait(200, msec);

    chassis.drive_distance(-8);
    wait(10, msec);
    chassis.drive_distance(-1.5);
    Clamp.set(true);
    Intake.spin(forward, 90, pct);
    wait(100, msec);
    chassis.turn_to_angle(132);
    chassis.drive_distance(7.5);
    wait(100, msec);
    chassis.turn_to_angle(100);
    chassis.drive_distance(3);
    wait(100, msec);
    chassis.drive_distance(-8);
    chassis.turn_to_angle(65);
    chassis.drive_distance(7);
    wait(100, msec);
    chassis.turn_to_angle(20);
    Intake.stop();
    wait(20, msec);
    Intake.spin(reverse, 100, pct);
    chassis.drive_distance(14);
    wait(150, msec);
    chassis.drive_distance(2.2);
    Intake.stop();
    wait(10, msec);
    chassis.drive_distance(-0.3);
    Intake.spin(forward, 100, pct);
    wait(200, msec);
    chassis.drive_distance(-5);

    // wait(50,msec);
    // chassis.drive_distance(-10);
    chassis.turn_to_angle(65);
    Intake.stop();
    chassis.drive_distance(-13);
}

void redGoalRushClamp(){
    Controller1.Screen.print("redGoalRushClamp");

    chassis.drive_distance(-10.5);
    chassis.turn_to_angle(-35);
    chassis.drive_distance(-4.6);

    Clamp.set(true);
    wait(100, msec);

    Intake.spin(forward, 80, pct);

    chassis.turn_to_angle(13);
    chassis.drive_distance(5.5); // get bottom ring
    Intake.stop();

    chassis.turn_to_angle(150);
    chassis.drive_distance(-8);
    Clamp.set(false);

    chassis.drive_distance(3);

    wait(100, msec);
    
    chassis.turn_to_angle(-75);
    chassis.drive_distance(-10);
    chassis.drive_distance(-1);
    Clamp.set(true); // grab second mogo
    Intake.spin(forward, 80, pct);

    chassis.turn_to_angle(120);

    // wait(500, msec),
    chassis.drive_distance(4);

    // chassis.turn_to_angle()
    
}



void skills()
{
    Controller1.Screen.print("skills 19");

    wait(200, msec);

    chassis.drive_distance(-1.3);
    wait(200, msec);

    wait(20, msec);
    chassis.turn_to_angle(120); // turning towards mogo
    // wait(20, msec);
    chassis.drive_distance(-9);
    Clamp.set(true); // clamped to mogo

    wait(20, msec);
    chassis.turn_to_angle(-2);

    Intake.spin(forward, 80, pct);

    chassis.drive_distance(6); // first ring
    wait(150, msec);
    chassis.turn_to_angle(-57);
    wait(20, msec);
    chassis.drive_distance(13); // second ring       //14
    wait(400, msec);
    chassis.turn_to_angle(159); // 163
    wait(20, msec);
    chassis.drive_distance(6.3); // third ring
    wait(200, msec);
    chassis.turn_to_angle(-173);
    chassis.drive_distance(6.5); // fourth ring
    wait(600, msec);
    chassis.drive_distance(5); // fifth ring
    wait(400, msec);
    chassis.turn_to_angle(-53);
    chassis.drive_distance(5);
    wait(400, msec);

    chassis.turn_to_angle(28);
    chassis.drive_distance(-6);
    wait(20, msec);
    Intake.stop();
    Clamp.set(false);
    Intake.spin(reverse, 100, pct);
    wait(100, msec);
    Intake.stop();

    // above this, bottom left corner

    chassis.drive_distance(3);
    chassis.turn_to_angle(91);
    Intake.spin(forward, 70, pct);
    chassis.drive_distance(13);
    wait(10, msec);
    chassis.drive_distance(8.5);
    wait(90, msec);
    Intake.stop();
    chassis.turn_to_angle(-85);
    chassis.drive_distance(-3.5);
    chassis.drive_distance(-3);

    wait(20, msec);
    Clamp.set(true); // clamp onto second mogo
    wait(10, msec);
    Intake.spin(forward, 80, pct);

    chassis.turn_to_angle(6);
    chassis.drive_distance(10);
    wait(200, msec);
    chassis.turn_to_angle(105);
    wait(10, msec);
    chassis.drive_distance(9);
    wait(300, msec);
    chassis.turn_to_angle(181);
    chassis.drive_distance(6.5);
    wait(500, msec);
    chassis.drive_distance(5.5);
    wait(400, msec);
    chassis.turn_to_angle(38);
    chassis.drive_distance(7.5);
    wait(400, msec);

    chassis.turn_to_angle(-25); //-23
    chassis.drive_distance(-7);
    wait(100, msec);
    Intake.stop();
    Clamp.set(false); // release mogo in corner
    Intake.spin(reverse, 100, pct);
    wait(50, msec);
    Intake.stop();

    // done with 1st half of field

    Intake.spin(forward, 75, pct);
    chassis.drive_distance(30); // 13.5
    chassis.turn_to_angle(-50);
    chassis.drive_distance(10); // get ring
    Intake.stop();
    wait(20, msec);

    /*
        chassis.turn_to_angle(18);
        wait(10,msec);
        chassis.drive_distance(9);
        wait(50,msec);
        Intake.stop();
        // chassis.drive_distance(-5);
        wait(10,msec);
        chassis.drive_distance(-3.1);
        chassis.turn_to_angle(90);
        chassis.drive_distance(0.85);
        wait(10,msec);

        // hSfS();


        wait(30,msec);
        chassis.drive_distance(-3);
        chassis.turn_to_angle(-49);
        Intake.spin(forward,70,pct);
        chassis.drive_distance(12);
        wait(300,msec);
        Intake.stop();
        */

    chassis.turn_to_angle(130);
    chassis.drive_distance(-9.5);
    wait(10, msec);
    chassis.drive_distance(-5);
    Clamp.set(true); // clamp onto mogo
    Intake.spin(forward, 80, pct);

    wait(200, msec);
    chassis.turn_to_angle(-60);
    Intake.stop();
    chassis.drive_distance(7);
    chassis.turn_to_angle(-107);
    chassis.drive_distance(14); // push mogo into corner

    chassis.drive_distance(-7);
    chassis.turn_to_angle(80);
    chassis.drive_distance(20); // push other mogo into corner
    wait(20, msec);
    chassis.drive_distance(20);
    wait(20, msec);
    chassis.drive_distance(20);
    wait(20, msec);
    chassis.drive_distance(-5);

    // chassis.turn_to_angle(-45);
    // Intake.spin(forward, 100, pct);
    // chassis.drive_distance(-4);
    chassis.turn_to_angle(-140); // turn to ladder    //140
    wait(100, msec);
    Clamp.set(false);
    hSfS();
    wait(250, msec);

    Hang.set(true);
    Intake.stop();

    wait(50, msec);
    chassis.drive_distance(19); // hang
}

// void hSfS(){
//   vex::timer Timer;
//   Timer.clear();
//   bool LeBron = true;
//   float currentTime = Timer.time(vex::timeUnits::sec);
//   while (currentTime < 4 && LeBron) {
//     if(!LimitS.pressing()){
//       Intake.spin(forward,80,pct);
//     }
//     else{
//       Intake.stop(coast);
//       wait(500,msec);
//       while (RotationS.position(deg) <= 145){
//         highStakeM.spin(forward, 70, pct);
//       }
//       wait(500,msec);
//       while (RotationS.position(deg) >= 10){
//         Intake.spin(forward, 100, pct);
//         highStakeM.spin(reverse, 70, pct);
//       }
//       LeBron = false;
//     }
//     currentTime = Timer.time(vex::timeUnits::sec);
//   }
//   Intake.stop();
// }
void hSfS()
{
    while (RotationS.position(deg) > 10)
    {
        Intake.spin(forward, 100, pct);
        highStakeM.spin(reverse, 80, pct);
    }
}

/**
 * The expected behavior is to return to the start position.
 */

void drive_test()
{
    // Controller1.Screen.clearScreen();

    // chassis.drive_distance(6);
    chassis.drive_distance(-9, 0, 7, 0);
    // chassis.drive_distance(18);
    // chassis.drive_distance(-36);
    Controller1.Screen.print("done");
}

/**
 * The expected behavior is to return to the start angle, after making a complete turn.
 */

void turn_test()
{
    // chassis.turn_to_angle(5);
    // chassis.turn_to_angle(30);
    chassis.turn_to_angle(90);
    // chassis.turn_to_angle(180);
    // chassis.turn_to_angle(225);
    // chassis.turn_to_angle(0);
    Controller1.Screen.print("done");
}

/**
 * Should swing in a fun S shape.
 */

void swing_test()
{
    chassis.left_swing_to_angle(90);
    chassis.right_swing_to_angle(0);
}

/**
 * A little of this, a little of that; it should end roughly where it started.
 */

void full_test()
{
    chassis.drive_distance(24);
    chassis.turn_to_angle(-45);
    chassis.drive_distance(-36);
    chassis.right_swing_to_angle(-90);
    chassis.drive_distance(24);
    chassis.turn_to_angle(0);
}

/**
 * Doesn't drive the robot, but just prints coordinates to the Brain screen
 * so you can check if they are accurate to life. Push the robot around and
 * see if the coordinates increase like you'd expect.
 */

void odom_test()
{
    chassis.set_coordinates(0, 0, 0);
    while (1)
    {
        Brain.Screen.clearScreen();
        Brain.Screen.printAt(5, 20, "X: %f", chassis.get_X_position());
        Brain.Screen.printAt(5, 40, "Y: %f", chassis.get_Y_position());
        Brain.Screen.printAt(5, 60, "Heading: %f", chassis.get_absolute_heading());
        Brain.Screen.printAt(5, 80, "ForwardTracker: %f", chassis.get_ForwardTracker_position());
        Brain.Screen.printAt(5, 100, "SidewaysTracker: %f", chassis.get_SidewaysTracker_position());
        // task::sleep(20);
    }
}

/**
 * Should end in the same place it began, but the second movement
 * will be curved while the first is straight.
 */

void tank_odom_test()
{
    odom_constants();
    chassis.set_coordinates(0, 0, 0);
    chassis.turn_to_point(24, 24);
    chassis.drive_to_point(24, 24);
    chassis.drive_to_point(0, 0);
    chassis.turn_to_angle(0);
}

/**
 * Drives in a square while making a full turn in the process. Should
 * end where it started.
 */

void holonomic_odom_test()
{
    odom_constants();
    chassis.set_coordinates(0, 0, 0);
    chassis.holonomic_drive_to_pose(0, 18, 90);
    chassis.holonomic_drive_to_pose(18, 0, 180);
    chassis.holonomic_drive_to_pose(0, 18, 270);
    chassis.holonomic_drive_to_pose(0, 0, 0);
}


void madon() {
    Brain.Screen.print("          ");
    Brain.Screen.clearScreen();
    Brain.Screen.print(".         ");
    Brain.Screen.clearScreen();
    Brain.Screen.print("..        ");
    Brain.Screen.clearScreen();
    Brain.Screen.print("...       ");
    Brain.Screen.clearScreen();
    Brain.Screen.print("....      ");
    Brain.Screen.clearScreen();
    Brain.Screen.print(".....     ");
    Brain.Screen.clearScreen();
    Brain.Screen.print(" .....    ");
    Brain.Screen.clearScreen();
    Brain.Screen.print("  .....   ");
    Brain.Screen.clearScreen();
    Brain.Screen.print("   .....  ");
    Brain.Screen.clearScreen();
    Brain.Screen.print("    ..... ");
    Brain.Screen.clearScreen();
    Brain.Screen.print("     .....");
    Brain.Screen.clearScreen();
    Brain.Screen.print("      ....");
    Brain.Screen.clearScreen();
    Brain.Screen.print("       ...");
    Brain.Screen.clearScreen();
    Brain.Screen.print("        ..");
    Brain.Screen.clearScreen();
    Brain.Screen.print("         .");
    Brain.Screen.clearScreen();
    Brain.Screen.print("          ");
    Brain.Screen.clearScreen();
    chassis.turn_to_angle(0);
    chassis.drive_distance(5);
    chassis.turn_to_angle(90);
    chassis.drive_distance(5);
    chassis.turn_to_angle(180);
    chassis.drive_distance(5);
    chassis.turn_to_angle(270);
    chassis.drive_distance(5);
    chassis.turn_to_angle(360);
    Brain.Screen.print("          ");
    Brain.Screen.clearScreen();
    Brain.Screen.print(".         ");
    Brain.Screen.clearScreen();
    Brain.Screen.print("..        ");
    Brain.Screen.clearScreen();
    Brain.Screen.print("...       ");
    Brain.Screen.clearScreen();
    Brain.Screen.print("....      ");
    Brain.Screen.clearScreen();
    Brain.Screen.print(".....     ");
    Brain.Screen.clearScreen();
    Brain.Screen.print(" .....    ");
    Brain.Screen.clearScreen();
    Brain.Screen.print("  .....   ");
    Brain.Screen.clearScreen();
    Brain.Screen.print("   .....  ");
    Brain.Screen.clearScreen();
    Brain.Screen.print("    ..... ");
    Brain.Screen.clearScreen();
    Brain.Screen.print("     .....");
    Brain.Screen.clearScreen();
    Brain.Screen.print("      ....");
    Brain.Screen.clearScreen();
    Brain.Screen.print("       ...");
    Brain.Screen.clearScreen();
    Brain.Screen.print("        ..");
    Brain.Screen.clearScreen();
    Brain.Screen.print("         .");
    Brain.Screen.clearScreen();
    Brain.Screen.print("          ");
    Brain.Screen.clearScreen();
}

void nothing() {
    //what did you expect this auton to do
}