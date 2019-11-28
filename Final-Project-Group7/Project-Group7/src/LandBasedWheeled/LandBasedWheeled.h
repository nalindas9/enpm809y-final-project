#pragma once
#include <iostream>
#include "LandBasedRobot.h"

namespace rwa3
{
/**
 * @brief
    Derived concrete class which inherits from base class LandBasedRobot
 * */
class LandBasedWheeled : public LandBasedRobot
{
protected:
	int wheel_number;
	std::string *wheel_type;
	
public:
	// Method Prototypes
	virtual void GoUp(int , int) override;
	virtual void GoDown(int , int) override;
	virtual void TurnLeft(int , int) override;
	void TurnRight(int , int) override;
	void PickUp(std::string) override;
	void Release(std::string) override;
	void SpeedUp(int);
	
	/**
 * @brief
    Accesors and Mutators to access and modify protected attributes of derived class
 * */
 
    /**
 * @brief Accesors to access protected attributes of derived class i.e. wheel_number
 * @return Wheel number of the robot
 * */
	int get_wheel_number(){
		
		return wheel_number;
		}
	/**
 * @brief Accesors to access protected attributes of derived class i.e. wheel_type
 * @return Type of the wheel of the robot
 * */
	std::string get_wheel_type() const{
		return *wheel_type;
	}
	
	/**
 * @brief Mutators to modify protected attributes of derived class i.e. wheel_number
 * @param Number of wheels of the robot
 * */
	void set_wheel_number(int number){
		wheel_number= number;
	}
	/**
 * @brief Mutators to modify protected attributes of derived class i.e. wheel_type
 * @param Type of wheels of the robot
 * */
	void set_wheel_type(std::string type_of_wheel){
		*wheel_type= type_of_wheel;
	}
	/**
 * @brief Deep Copy Constructor and Destructor for Derived class
 * @param Refrence to the Object of the derived class
 * */
	LandBasedWheeled(const LandBasedWheeled &obj)
		:LandBasedRobot(obj.get_name(), obj.get_speed(), obj.get_width(), obj.get_length(), obj.get_height(), obj.get_capacity() , obj.get_x(),obj.get_y()){
		wheel_number=obj.wheel_number;
		wheel_type = new std::string;
		*wheel_type=obj.get_wheel_type();
	}
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
	LandBasedWheeled(std::string name = "Husky",  int wheel_num = 4, double speed = 34, std::string type_of_wheel = "Castor", double width = 22, double length = 34, double height = 34, double capacity = 45, int x = 2, int y = 3):LandBasedRobot(name, speed, width, length, height, capacity, x, y){
		wheel_type = new std::string(type_of_wheel);
		wheel_number = wheel_num;
		}
		
/**
 * @brief Destructor of the derived class LandBasedWheeled
 * */
	virtual ~LandBasedWheeled(){
		delete wheel_type;
		}
		
	
};

}
