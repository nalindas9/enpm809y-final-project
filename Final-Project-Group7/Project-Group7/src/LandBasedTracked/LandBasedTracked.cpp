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
		std::cout << "LandBasedTracked::GoUp is called\n";
//		API::moveForward();
		} 
/**
 * @brief Method definition for derived class : GoDown
 * @param x position of the robot in the maze
 * @param y position of the robot in the maze
 * */
//	void LandBasedTracked:: GoDown(){
//		std::cout << "LandBasedTracked::GoDown is called\n";
//		API::turnLeft();
//		API::turnLeft();
//		API::moveForward();
//		} 
/**
 * @brief Method definition for derived class : TurnLeft
 * @param x position of the robot in the maze
 * @param y position of the robot in the maze
 * */
	void LandBasedTracked::TurnLeft(){
		std::cout << "LandBasedTracked::TurnLeft is called\n";
		API::turnLeft();
		} 
/**
 * @brief Method definition for derived class : TurnRight
 * @param x position of the robot in the maze
 * @param y position of the robot in the maze
 * */
	void LandBasedTracked::TurnRight(){
		std::cout << "LandBasedTracked::TurnRight is called\n";
		API::turnRight();
		} 
int LandBasedTracked::get_x() const{
	return x_;
}
int LandBasedTracked::get_y() const {
	return y_;
} 
char LandBasedTracked::GetDirection(){ return direction_;}
///**
// * @brief Method definition for derived class : PickUp
// * @param Pick up from the robotic arm
// * */
//	void LandBasedTracked::PickUp(std::string){
//		std::cout << "LandBasedTracked::Pickup is called\n";
//		} 
///**
// * @brief Method definition for derived class : Release
// * @param Release from the robotic arm
// * */
//	void LandBasedTracked::Release(std::string){
//		std::cout << "LandBasedTracked::Release is called\n";
//		}
} 