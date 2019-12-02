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
	char direction_;
	
public:
	virtual void GoUp(int , int)  = 0;  //Move the robot up in the maze.
	virtual void GoDown(int , int) = 0; //Move the robot down in the maze.
	virtual void TurnLeft(int , int) = 0;  //Move the robot left in the maze.
	virtual void TurnRight(int , int) = 0;  //Move the robot right in the maze.
	virtual void PickUp(std::string) = 0;   //Arm picks up an object.
	virtual void Release(std::string) = 0;  //Arm releases an object.
	
	
	/**
 * @brief
    Accessors and Mutators to access and modify base class protected attributes
 * */
 
 /**
 * @brief Accessors to get the name of the robot
 * @return Name of the robot
 * */
	std::string get_name() const{
		return name_;
	}
	
	 /**
 * @brief Accessors to get the direction of the robot
 * @return Direction of the robot
 * */
	char get_direction() const{
		return direction_;
	}

/**
 * @brief Accessors to get the speed of the robot
 * @return Driving speed of the robot
 * */
	double get_speed()const{
		return speed_;
		}
/**
 * @brief Accessors to get the length of the robot
 * @return Base length of the robot
 * */
	double get_length()const{
		return length_;
		}
/**
 * @brief Accessors to get the width of the robot
 * @return Base width of the robot
 * */
	double get_width()const{
		return width_;
		}
/**
 * @brief Accessors to get the height of the robot
 * @return Base height of the robot
 * */
	double get_height()const{
		return height_;
		}
/**
 * @brief Accessors to get the Payload capacity of the robot
 * @return Payload capacity of the robotic arm
 * */
	double get_capacity()const{
		return capacity_;
		}
/**
 * @brief Accessors to get the x coordinate of the robot
 * @return x coordinate of the robot in the maze
 * */
	int get_x()const{
		
		return x_;
		}
/**
 * @brief Accessors to get the y coordinate of the robot
 * @return y coordinate of the robot in the maze
 * */
	int get_y()const{
		
		return y_;
		}
/**
 * @brief Mutators to set the name of the robot
 * @param Name of the robot
 * */
	void set_name(std::string name){
		name_=name;
	}
/**
 * @brief Mutators to set the speed of the robot
 * @param Driving speed of the robot
 * */
	void set_speed(double speed){
		speed_= speed;
	}
/**
 * @brief Mutators to set the length of the robot
 * @param Base length of the robot
 * */
	void set_length(double length){
		length_= length;
	}
/**
 * @brief Mutators to set the width of the robot
 * @param Base width of the robot
 * */
	void set_width(double width){
		width_= width;
	}
/**
 * @brief Mutators to set the height of the robot
 * @param Base height of the robot
 * */
	void set_height(double height){
		height_= height;
	}
/**
 * @brief Mutators to set the payload capacity of the robot
 * @param Payload capacity of the robot
 * */
	void set_capacity(double capacity){
		capacity_= capacity;
	}
/**
 * @brief Mutators to set the x coordinate of the robot
 * @param x coordinate of the robot in the maze
 * */
	void set_x(int x){
		x_= x;
	}
/**
 * @brief Mutators to set the y coordinate of the robot
 * @param y coordinate of the robot in the maze
 * */
	void set_y(int y){
		y_= y;
	}
	
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
	LandBasedRobot(std::string name, double speed, double width, double length, double height, double capacity, int x, int y, char direction){
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