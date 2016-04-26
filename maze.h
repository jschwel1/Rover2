/*
* File: Maze.h
* Written by: Jacob Schwell & Ryan Cuddy
* EECE 287
* 04/26/2016
* Description: This file declares functions to be used to guide the Rover 5 
* Through a line-maze.
*/

#ifndef MAZE_H
#define MAZE_H

// navigateMaze() utilizes the functions in this file, motor.h, and qtr_driver.h to
// drive through the maze using a right-hand search.
void navigateMaze();

// left90() is used to spin the rover counter-clockwise until it sees the line again
void left90();

// left90() is used to spin the rover counter-clockwise until it sees the line again
void right90();

#endif
