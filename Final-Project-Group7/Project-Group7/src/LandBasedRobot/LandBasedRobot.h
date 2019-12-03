#pragma once
#include <iostream>
#include <string>

namespace fp
{
/**
 * @brief
    Base abstract class from which the two classes - LandBasedTracked and LandBasedWheeled inherit from
 * */
class LandBasedRobot
{
protected:
	std::string name_;  //Name of the robot.
	double speed_;      //Driving speed of the robot.
	double width_;      //Width of the base of the robot.
	double length_;     //Length of the base of the robot.
	double height_;     //Height of the base of the robot.
	double capacity_;   //Payload of the arm.
	int x_;             //X coordinate of the robot in the maze.
	int y_;             //Y coordinate of the robot in the maze.
	char direction_;	//Direction of the robot in the maze.
	
public:
	virtual void MoveForward()  = 0;  //Move the robot up in the maze.
	virtual void TurnLeft() = 0;  //Move the robot left in the maze.
	virtual void TurnRight() = 0;  //Move the robot right in the maze.
	virtual int get_x() const = 0;
	virtual int get_y() const = 0;
	virtual char GetDirection() =0;

	/**
 * @brief Constructor for base class
 * @param Name of the robot
 * @param Driving speed of the robot
 * @param Base width of the robot
 * @param Base length of the robot
 * @param Base height of the robot
 * @param Payload capacity of the robot
 * @param x coordinate of the robot in the maze
 * @param y coordinate of the robot in the maze
 * */
	LandBasedRobot(std::string name = "Land Robot", double speed = 0, double width = 2, double length = 2, double height = 2, double capacity = 2, int x = 0, int y = 0, char direction = 'n'){
		name_ = name;
		speed_ = speed;
		width_ = width;
		length_ = length;
		height_ = height;
		capacity_ = capacity;
		x_ = x;
		y_ = y;
		direction_ = direction;
		}
	/**
 * @brief Destructor for base class
 * */
	~LandBasedRobot(){}

};

}