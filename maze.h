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

#define BLACK 0xFF
#define WHITE 0x00

#define ON_LINE 			((WHITE & 0xF0) | (BLACK & 0x0F))
#define RIGHT_DRIFT 		((WHITE & 0xE0) | (BLACK & 0x1F))
#define LEFT_DRIFT 			((WHITE & 0xF8) | (BLACK & 0x03))
#define OFF_TO_THE_RIGHT 	((WHITE & 0xC0) | (BLACK & 0x3F))
#define OFF_TO_THE_LEFT 	((WHITE & 0xFC) | (BLACK & 0x03))
#define ALMOST_ALL_BLACK 	((WHITE & 0x80) | (BLACK & 0x7F))
#define ALMOST_ALL_WHITE 	((WHITE & 0xF7) | (BLACK & 0x01))
#define ALL_WHITE 			(WHITE)
#define ALL_BLACK 			(BLACK)

// navigateMaze() utilizes the functions in this file, motor.h, 
// and qtr_driver.h to drive through the maze using a right-hand search.
void navigateMaze();

#endif
