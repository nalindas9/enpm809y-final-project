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
	//virtual void GoDown() override;
	virtual void TurnLeft() override;
	virtual void TurnRight() override;
	virtual char GetDirection() override;
	int get_x() const;
	int get_y() const;
//	virtual void PickUp(std::string) override;
//	virtual void Release(std::string) override;
	void SpeedUp(int);
//	
//	/**
// * @brief
//    Accesors and Mutators to access and modify protected attributes of derived class
// * */
// 
// 	int get_y()
// 
//    /**
// * @brief Accesors to access protected attributes of derived class i.e. wheel_number
// * @return Wheel number of the robot
// * */
//	int get_wheel_number(){
//		
//		return wheel_number;
//		}
//	/**
// * @brief Accesors to access protected attributes of derived class i.e. wheel_type
// * @return Type of the wheel of the robot
// * */
//	std::string get_wheel_type() const{
//		return *wheel_type;
//	}
//	
//	/**
// * @brief Mutators to modify protected attributes of derived class i.e. wheel_number
// * @param Number of wheels of the robot
// * */
//	void set_wheel_number(int number){
//		wheel_number= number;
//	}
//	/**
// * @brief Mutators to modify protected attributes of derived class i.e. wheel_type
// * @param Type of wheels of the robot
// * */
//	void set_wheel_type(std::string type_of_wheel){
//		*wheel_type= type_of_wheel;
//	}
	/**
// * @brief Deep Copy Constructor and Destructor for Derived class
// * @param Refrence to the Object of the derived class
// * */
//	LandBasedWheeled(const LandBasedWheeled &obj)
//		:LandBasedRobot( obj.get_x(),obj.get_y(), obj.get_direction()){
//		wheel_number=obj.wheel_number;
//		wheel_type = new std::string;
//		*wheel_type=obj.get_wheel_type();
//	}
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
