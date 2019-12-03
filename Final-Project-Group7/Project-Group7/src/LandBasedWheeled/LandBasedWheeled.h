#pragma once
#include <iostream>
#include "../LandBasedRobot/LandBasedRobot.h"

namespace fp
{
/**
 * @brief
    Derived concrete class which inherits from base class LandBasedRobot
 * */
class LandBasedWheeled : public LandBasedRobot
{
protected:
	int wheel_number;
	
public:
	// Method Prototypes
	virtual void MoveForward() override;
	virtual void TurnLeft() override;
	virtual void TurnRight() override;
	virtual char GetDirection() override;
	int get_x() const;
	int get_y() const;
	void SpeedUp(int);
	/**
 * @brief Derived Constructor with default attribute values
 * @param Name of the robot
 * @param Number of Wheels of the robot
 * @param Driving speed of the robot
 * @param Type of wheels of the robot
 * @param Base width of the robot
 * @param Base length of the robot
 * @param Base height of the robot
 * @param Payload capacity of the robot
 * @param x coordinate of the robot in the maze
 * @param y coordinate of the robot in the maze 
 * */
	LandBasedWheeled(std::string name = "Husky",  int wheel_num = 4, double speed = 34, double width = 22, double length = 34, double height = 34, double capacity = 45, int x = 0, int y = 0, char direction = 'n'):LandBasedRobot(name, speed, width, length, height, capacity, x, y, direction){
		wheel_number = wheel_num;
		}
//		
/**
 * @brief Destructor of the derived class LandBasedWheeled
 * */
	virtual ~LandBasedWheeled(){
		}
		
	
};

}
