#pragma once
#include <iostream>
#include "../LandBasedRobot/LandBasedRobot.h"

namespace fp
{
/**
 * @brief
    Derived concrete clas which inherits from base class LandBasedRobot
 * */
class LandBasedTracked : public LandBasedRobot
{
	protected:
		std::string *track_type;  //Type of track mounted on the robot.
		
	public:
	// Method Prototypes
	virtual void MoveForward() override;
	virtual char GetDirection() override;
	
	virtual void TurnLeft()override;
	virtual void TurnRight()override;
	int get_x() const;
	int get_y() const;

	
	/**
 * @brief Derived Constructor with default attribute values
 * @param Name of the robot
 * @param Driving speed of the robot
 * @param Base width of the robot
 * @param Type of track mounted on robot
 * @param Base length of the robot
 * @param Base height of the robot
 * @param Payload capacity of the robot
 * @param x coordinate of the robot in the maze
 * @param y coordinate of the robot in the maze 
 * */
	LandBasedTracked(std::string name = "Husky", double speed = 34, double width = 22, std::string track_of_type = "Revolute", double length = 34, double height = 34, double capacity = 45, int x = 2, int y = 3, char direction = 'n'):LandBasedRobot(name, speed, width, length, height, capacity, x, y, direction){
		track_type = new std::string(track_of_type);
		}

/**
 * @brief Destructor of the derived class LandBasedTracked
 * */
	virtual ~LandBasedTracked(){
		delete track_type;
		}
};

}
