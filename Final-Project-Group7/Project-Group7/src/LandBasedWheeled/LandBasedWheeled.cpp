#include <iostream>
#include "LandBasedRobot.h"
#include "LandBasedWheeled.h"

namespace rwa3{
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
	void LandBasedWheeled::GoUp(int x_, int y_){
		std::cout << "LandBasedWheeled::GoUp is called\n";
		} 
/**
 * @brief Method definition for derived class : GoDown
 * @param x position of the robot in the maze
 * @param y position of the robot in the maze
 * */
	void LandBasedWheeled:: GoDown(int x_, int y_){
		std::cout << "LandBasedWheeled::GoDown is called\n";
		} 
/**
 * @brief Method definition for derived class : TurnLeft
 * @param x position of the robot in the maze
 * @param y position of the robot in the maze
 * */
	void LandBasedWheeled::TurnLeft(int x_, int y_){
		std::cout << "LandBasedWheeled::TurnLeft is called\n";
		} 
/**
 * @brief Method definition for derived class : TurnRight
 * @param x position of the robot in the maze
 * @param y position of the robot in the maze
 * */
	void LandBasedWheeled::TurnRight(int x_, int y_){
		std::cout << "LandBasedWheeled::TurnRight is called\n";
		} 
/**
 * @brief Method definition for derived class : PickUp
 * @param Pick Up from the robotic arm
 * */
	void LandBasedWheeled::PickUp(std::string){
		std::cout << "LandBasedWheeled::Pickup is called\n";
		} 
/**
 * @brief Method definition for derived class : Release
 * @param Release from the robotic arm
 * */
	void LandBasedWheeled::Release(std::string){
		std::cout << "LandBasedWheeled::Release is called\n";
		}

	}