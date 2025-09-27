#include "vex.h"
//#include "robot-config.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain Brain;

//VEXcode device constructors
controller Controller1 = controller(primary);

//the "true" and "false" is the neutral direction of the motor --> if the drivetrain locks up, change the C motors to the oppostie
// motor leftMotorA = motor(PORT12, ratio18_1, false); 
// motor leftMotorB = motor(PORT11, ratio18_1, true); 
// motor leftMotorC = motor(PORT13, ratio18_1, false);  
motor leftMotorA = motor(PORT12, ratio18_1, true);  
motor leftMotorB = motor(PORT11, ratio18_1, false); 
motor leftMotorC = motor(PORT13, ratio18_1, true);   
motor_group LeftDriveSmart = motor_group(leftMotorA, leftMotorB, leftMotorC);
motor rightMotorA = motor(PORT18, ratio18_1, false); 
motor rightMotorB = motor(PORT19, ratio18_1, true);
motor rightMotorC = motor(PORT17, ratio18_1, false); 
motor_group RightDriveSmart = motor_group(rightMotorA, rightMotorB, rightMotorC);

drivetrain Drivetrain6 = drivetrain(LeftDriveSmart, RightDriveSmart, 319.19, 295, 40, mm, 0.75);

motor Intake = motor(PORT9, ratio18_1, false); 
motor upper = motor(PORT10, ratio18_1, false); 



digital_out scrape = digital_out(Brain.ThreeWirePort.A);
digital_out Sweeper = digital_out(Brain.ThreeWirePort.H);

inertial inert(PORT1);     //if changing this port, MUST CHANGE at the top of main as well





// VEXcode generated functions

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  LeftDriveSmart.setVelocity(600, rpm); //These values are for correcting drift through code so we don't have to correct it in hardware yet and I don't even know if this is gonna work
  RightDriveSmart.setVelocity(600, rpm);
  scrape.set(false);
  Sweeper.set(false); //this comment is to undo what i did earlier idk

  inert.calibrate();
  wait(1, seconds);
}