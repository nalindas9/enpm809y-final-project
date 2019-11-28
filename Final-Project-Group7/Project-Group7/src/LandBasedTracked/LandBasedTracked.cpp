#include<iostream>
#include "LandBasedRobot.h"
#include "LandBasedTracked.h"

namespace rwa3{
	/**
 * @brief Method definition for derived class : GoUp
 * @param x position of the robot in the maze
 * @param y position of the robot in the maze
 * */
	void LandBasedTracked::GoUp(int x_, int y_){
		std::cout << "LandBasedTracked::GoUp is called\n";
		} 
/**
 * @brief Method definition for derived class : GoDown
 * @param x position of the robot in the maze
 * @param y position of the robot in the maze
 * */
	void LandBasedTracked:: GoDown(int x_, int y_){
		std::cout << "LandBasedTracked::GoDown is called\n";
		} 
/**
 * @brief Method definition for derived class : TurnLeft
 * @param x position of the robot in the maze
 * @param y position of the robot in the maze
 * */
	void LandBasedTracked::TurnLeft(int x_, int y_){
		std::cout << "LandBasedTracked::TurnLeft is called\n";
		} 
/**
 * @brief Method definition for derived class : TurnRight
 * @param x position of the robot in the maze
 * @param y position of the robot in the maze
 * */
	void LandBasedTracked::TurnRight(int x_, int y_){
		std::cout << "LandBasedTracked::TurnRight is called\n";
		} 
/**
 * @brief Method definition for derived class : PickUp
 * @param Pick up from the robotic arm
 * */
	void LandBasedTracked::PickUp(std::string){
		std::cout << "LandBasedTracked::Pickup is called\n";
		} 
/**
 * @brief Method definition for derived class : Release
 * @param Release from the robotic arm
 * */
	void LandBasedTracked::Release(std::string){
		std::cout << "LandBasedTracked::Release is called\n";
		}
} 