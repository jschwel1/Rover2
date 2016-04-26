/*
* File: motor.h
* Written by: Jacob Schwell & Ryan Cuddy
* EECE 287
* 4/17/2016
*/
#ifndef MOTOR_H
#define MOTOR_H

#define MOTORS PORTC
#define MOTOR_L 2 
#define MOTOR_R 0 

#define FORWARD 0x02 // only two bits are required for motor directions
#define REVERSE 0x01
#define COAST 0x00
#define BRAKE 0x03

#define F_CPU 1000000UL  // 16 MHz

#define BLACK 0xFF
#define WHITE 0x00
#define L4_SENSORS 0xF0
#define R4_SENSORS 0x0F


/*************** functions *****************/
// coast() sets both wheels to coast
void coast();

// stop() sets both wheels to brake
void stop();

// driveForward() sets both wheels to forward.
void driveForward();

// driveBackward() sets both wheels to reverse
void driveBackward();

// rotateCW() sets the left wheel to rotate forward and the right wheel to 
// rotate in reverse, causing the rover to spin clockwise indefinately
void rotateCW();

// rotateCCW() sets the right wheel to rotate forward and the left wheel to 
// rotate in reverse, causing the rover to spin counter-clockwise indefinately
void rotateCCW();

// curveCW() sets the left wheel to forward and the right wheel to coast to 
// cause the rover to make a wide turn
void curveRight();

// curveCCW() sets the right wheel to forward and the left wheel to coast to 
// cause the rover to make a wide turn
void curveLeft();

// setUp() will set up the Data Direction Registers #defined above.
void setUp();

// setMotorR sets the right motor to the direction specified by FORWARD, 
// REVERSE, COAST, or BRAKE
void setMotorR(unsigned char dir);

// setMotorL sets the left motor to the direction specified by FORWARD, 
// REVERSE, COAST, or BRAKE
void setMotorL(unsigned char dir);

// navigateMaze() utilizes the functions in this file as well as qtr_driver.h to
// drive through the maze.
// breaking up the qtr_sensor into 4 components, if the middle two are both on 
// the line, it will go forward, if the rover has the opportunity to turn left 
// (the left two sensors are on a line), it will do so, then ontinue to drive
// forward. The sensors will ensure that keeping the middle two sections on the 
// line are a priority to make sure the rover does not get lost.
void navigateMaze();

void U_turn();

void left90();

void right90();

void hardTurnRight();

void hardTurnLeft();

#endif