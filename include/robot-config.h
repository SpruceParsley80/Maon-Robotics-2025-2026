using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;

extern drivetrain Drivetrain6;
extern motor leftMotorA;
extern motor leftMotorB;
extern motor leftMotorC;
extern motor_group LeftDriveSmart;
extern motor rightMotorA;
extern motor rightMotorB;
extern motor rightMotorC;
extern motor_group RightDriveSmart;
extern motor Intake;

extern motor upper;
//rip highstakemotor 2024-2025

extern digital_out scrape;
extern digital_out Sweeper;

extern inertial inert;
extern rotation RotationS;
extern vex::distance DistanceS;
extern vex::limit LimitS;
extern optical Optical;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro. hello
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );
/**/