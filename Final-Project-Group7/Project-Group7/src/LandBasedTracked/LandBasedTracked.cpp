#include<iostream>
#include "../LandBasedRobot/LandBasedRobot.h"
#include "LandBasedTracked.h"
#include "../API/API.h"

namespace fp{
	/**
 * @brief Method definition for derived class : GoUp
 * @param x position of the robot in the maze
 * @param y position of the robot in the maze
 * */
	void LandBasedTracked::MoveForward(){
        if(LandBasedTracked::GetDirection()=='n'){
			std::cout << "LandBasedWheeled::GoUp is called\n";
			API::moveForward();
			y_++;
		}
		else if(LandBasedTracked::GetDirection()=='e'){
			std::cout << "LandBasedWheeled::GoUp is called\n";
			API::moveForward();
			x_++;
		}
		else if(LandBasedTracked::GetDirection()=='w'){
			std::cout << "LandBasedWheeled::GoUp is called\n";
			API::moveForward();
			x_--;
		}
		else if(LandBasedTracked::GetDirection()=='s'){
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
	void LandBasedTracked::TurnLeft(){
		if(LandBasedTracked::GetDirection()=='w'){
			std::cout << "LandBasedWheeled::GoUp is called\n";
			API::turnLeft();
			direction_='s';
		}
		else if(LandBasedTracked::GetDirection()=='n'){
			std::cout << "LandBasedWheeled::GoUp is called\n";
			API::turnLeft();
			direction_='w';
		}
		else if(LandBasedTracked::GetDirection()=='e'){
			std::cout << "LandBasedWheeled::GoUp is called\n";
			API::turnLeft();
			direction_='n';
		}
		else if(LandBasedTracked::GetDirection()=='s'){
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
	void LandBasedTracked::TurnRight(){
		if(LandBasedTracked::GetDirection()=='n'){
			std::cout << "LandBasedWheeled::GoUp is called\n";
			API::turnRight();
			direction_='e';
		}
		else if(LandBasedTracked::GetDirection()=='e'){
			std::cout << "LandBasedWheeled::GoUp is called\n";
			API::turnRight();
			direction_='s';
		}
		else if(LandBasedTracked::GetDirection()=='w'){
			std::cout << "LandBasedWheeled::GoUp is called\n";
			API::turnRight();
			direction_='n';
		}
		else if(LandBasedTracked::GetDirection()=='s'){
			std::cout << "LandBasedWheeled::GoUp is called\n";
			API::turnRight();
			direction_='w';
		}
		}

 
int LandBasedTracked::get_x() const{
	return x_;
}
int LandBasedTracked::get_y() const {
	return y_;
} 
char LandBasedTracked::GetDirection(){ return direction_;}

} 