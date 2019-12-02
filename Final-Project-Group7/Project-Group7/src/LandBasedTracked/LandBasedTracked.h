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
	//virtual void GoDown()override;
	virtual void TurnLeft()override;
	virtual void TurnRight()override;
	int get_x() const;
	int get_y() const;
//	virtual void PickUp(std::string)override;
//	virtual void Release(std::string)override;
	
	/**
 * @brief
    Accesors and Mutators to access and modify protected attributes of derived class
 * */
 
// /**
// * @brief Accesors to access protected attributes of derived class i.e. track_type
// * @return Type of track mounted on the robot
// * */
//	std::string get_track_type() const{
//		return *track_type;
//	}
//	
//	/**
// * @brief Mutators modify/set protected attributes of derived class i.e. track_type
// * @param Type of track mounted on the robot
// * */
//	void set_track_type(std::string track_of_type){
//		*track_type = track_of_type;
//	}
//	
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
		
//	/**
// * @brief Deep Copy Constructor and Destructor for Derived class
// * @param Refrence to the Object of the derived class
// * */
//	LandBasedTracked(const LandBasedTracked &obj)
//		:LandBasedRobot(obj.get_name(), obj.get_speed(), obj.get_width(), obj.get_length(), obj.get_height(), obj.get_capacity() , obj.get_x(),obj.get_y(), obj.get_direction()){
//		track_type = new std::string;
//		*track_type=obj.get_track_type();
//	}
/**
 * @brief Destructor of the derived class LandBasedTracked
 * */
	virtual ~LandBasedTracked(){
		delete track_type;
		}
};

}
