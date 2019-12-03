#include <iostream>
#include "../LandBasedRobot/LandBasedRobot.h"
#include "../API/API.h"
#include "LandBasedWheeled.h"

namespace fp{
	/**
 * @brief Method definition for derived class : SpeedUp
 * @param Speed of the robot
 * */
	void LandBasedWheeled::SpeedUp(int speed){
		std::cout << "LandBasedWheeled::SpeedUp is called\n";
		} 
/**
 * @brief Method definition for derived class : GoUp
 * @param x position of the robot in the maze
 * @param y position of the robot in the maze
 * */
	void LandBasedWheeled::MoveForward(){
		if(LandBasedWheeled::GetDirection()=='n'){
			std::cout << "LandBasedWheeled::GoUp is called\n";
			API::moveForward();
			y_++;
		}
		else if(LandBasedWheeled::GetDirection()=='e'){
			std::cout << "LandBasedWheeled::GoUp is called\n";
			API::moveForward();
			x_++;
		}
		else if(LandBasedWheeled::GetDirection()=='w'){
			std::cout << "LandBasedWheeled::GoUp is called\n";
			API::moveForward();
			x_--;
		}
		else if(LandBasedWheeled::GetDirection()=='s'){
			std::cout << "LandBasedWheeled::GoUp is called\n";
			API::moveForward();
			y_--;
		}
		
		}
 
/**
 * @brief Method definition for derived class : TurnLeft
 * @param x position of the robot in the maze
 * @param y position of the robot in the maze
 * */
	void LandBasedWheeled::TurnLeft(){
		if(LandBasedWheeled::GetDirection()=='w'){
			std::cout << "LandBasedWheeled::GoUp is called\n";
			API::turnLeft();
			direction_='s';
		}
		else if(LandBasedWheeled::GetDirection()=='n'){
			std::cout << "LandBasedWheeled::GoUp is called\n";
			API::turnLeft();
			direction_='w';
		}
		else if(LandBasedWheeled::GetDirection()=='e'){
			std::cout << "LandBasedWheeled::GoUp is called\n";
			API::turnLeft();
			direction_='n';
		}
		else if(LandBasedWheeled::GetDirection()=='s'){
			std::cout << "LandBasedWheeled::GoUp is called\n";
			API::turnLeft();
			direction_='e';
		}
		}
/**
 * @brief Method definition for derived class : TurnRight
 * @param x position of the robot in the maze
 * @param y position of the robot in the maze
 * */
	void LandBasedWheeled::TurnRight(){
		if(LandBasedWheeled::GetDirection()=='n'){
			std::cout << "LandBasedWheeled::GoUp is called\n";
			API::turnRight();
			direction_='e';
		}
		else if(LandBasedWheeled::GetDirection()=='e'){
			std::cout << "LandBasedWheeled::GoUp is called\n";
			API::turnRight();
			direction_='s';
		}
		else if(LandBasedWheeled::GetDirection()=='w'){
			std::cout << "LandBasedWheeled::GoUp is called\n";
			API::turnRight();
			direction_='n';
		}
		else if(LandBasedWheeled::GetDirection()=='s'){
			std::cout << "LandBasedWheeled::GoUp is called\n";
			API::turnRight();
			direction_='w';
		}
		}
int LandBasedWheeled::get_x() const{
	return x_;
}
int LandBasedWheeled::get_y() const {
	return y_;
} 
char LandBasedWheeled::GetDirection(){ return direction_;}

	}