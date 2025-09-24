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
//DON'T TREAT THIS ^ AS ABSOLUTELY TRUE; THE C MOTOR MAY NOT BE THE PROBLEM HERE
motor leftMotorA = motor(PORT20 , ratio18_1, true); 
motor leftMotorB = motor(PORT18, ratio18_1, false); 
motor leftMotorC = motor(PORT19, ratio18_1, false);  
/*LeftMotorC direction was set to true during Ri3D 
revert it to true if side locks up or if i say so*/
motor_group LeftDriveSmart = motor_group(leftMotorA, leftMotorB, leftMotorC);
motor rightMotorA = motor(PORT12, ratio18_1, true); 
motor rightMotorB = motor(PORT13, ratio18_1, false);
motor rightMotorC = motor(PORT15, ratio18_1, false); 
/*RightMotorC direction was set to true during Ri3D 
revert it to true if side locks up or if i say so*/
motor_group RightDriveSmart = motor_group(rightMotorA, rightMotorB, rightMotorC);

drivetrain Drivetrain6 = drivetrain(LeftDriveSmart, RightDriveSmart, 319.19, 295, 40, mm, 1);

motor intake = motor(PORT11, ratio18_1, false); 
/*there was a problem with the intake driving when 
controller inputs were recieved earlier TUESDAY*/
// motor intakeRight = motor(PORT14, ratio18_1, false);
// motor_group Intake = motor_group(intakeLeft, intakeRight);
motor upper = motor(PORT8, ratio18_1, true); /*Change PORT8 to whatever the upper motor is */
motor highStakeM = motor(PORT8, ratio18_1, true); /*Change PORT8 to whatever the upper motor is */

digital_out Clamp = digital_out(Brain.ThreeWirePort.A);
digital_out Sweeper = digital_out(Brain.ThreeWirePort.E);
digital_out Hang = digital_out(Brain.ThreeWirePort.C);

inertial inert(PORT3);     //if changing this port, MUST CHANGE at the top of main as well
rotation RotationS = rotation(PORT19, false);
vex::distance DistanceS(PORT20);
optical Optical = optical(PORT15);

limit LimitS = limit(Brain.ThreeWirePort.D);


// VEXcode generated functions

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  //inert.calibrate();
  //Hood.set(true);
}