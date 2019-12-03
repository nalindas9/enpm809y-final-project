#include "API.h"
#include <cstdlib>
#include <iostream>
using namespace fp;
/**
 * @brief It returns the width of the maze
 */
int API::mazeWidth() {
	std::cout << "mazeWidth" << std::endl;
	std::string response;
	std::cin >> response;
	return atoi(response.c_str());
	}
	/**
	 * @brief It returns the height of th maze
	 */
int API::mazeHeight() {
	std::cout << "mazeHeight" << std::endl;
	std::string response;
	std::cin >> response;
	return atoi(response.c_str());
	}
	/**
	 * @brief It checks for a wall in front of the robot.
	 * @return true if there is a wall in front of the robot, else false
	 */
bool API::wallFront() {
	std::cout << "wallFront" << std::endl;
	std::string response;
	std::cin >> response;
	return response == "true";
	}
	/**
	 * @brief It checks for a wall in right of the robot.
	 * @return true if there is a wall to the right of the robot, else false
	 */
bool API::wallRight() {
	std::cout << "wallRight" << std::endl;
	std::string response;
	std::cin >> response;
	return response == "true";
	}
	/**
	 * @brief It checks for a wall in left of the robot.
	 * @return //--true if there is a wall to the left of the robot, else false
	 */
bool API::wallLeft() {
	std::cout << "wallLeft" << std::endl;
	std::string response;
	std::cin >> response;
	return response == "true";
	}
	/**
	 * @brief It makes the robot move forward by one cell.
	 */
void API::moveForward() {
	std::cout << "moveForward" << std::endl;
	std::string response;
	std::cin >> response;
	if (response != "ack") {
		std::cerr << response << std::endl;
		throw;
		}
	}
	/**
	 * @brief It turns the robot ninety degrees to the right.
	 */
void API::turnRight() {
	std::cout << "turnRight" << std::endl;
	std::string ack;
	std::cin >> ack;
	}
	/**
	 * @brief It turns the robot ninety degrees to the left.
	 */
void API::turnLeft() {
	std::cout << "turnLeft" << std::endl;
	std::string ack;
	std::cin >> ack;
	}
	/**
	 * @brief It displays the wall at a given position.
	 * @param x
	 * @param y
	 * @param direction
	 */
void API::setWall(int x, int y, char direction) {
	std::cout << "setWall " << x << " " << y << " " << direction << std::endl;
	}
	/**
	 * @brief It clears the wall at a given position.
	 * @param x
	 * @param y
	 * @param direction
	 */
void API::clearWall(int x, int y, char direction) {
	std::cout << "clearWall " << x << " " << y << " " << direction << std::endl;
	}
	/**
	 * @brief It sets the color of the cell at the given position.
	 * @param x
	 * @param y
	 * @param color
	 */
void API::setColor(int x, int y, char color) {
	std::cout << "setColor " << x << " " << y << " " << color << std::endl;
	}
	/**
	 * @brief It clears the color of the cell at the given position.
	 * @param x
	 * @param y
	 */
void API::clearColor(int x, int y) {
	std::cout << "clearColor " << x << " " << y << std::endl;
	}
	/**
	 * @brief It clears the color of all the cells.
	 */
void API::clearAllColor() {
	std::cout << "clearAllColor" << std::endl;
	}
	/**
	 * @brief It sets the text of the cell at the given position
	 * @param x
	 * @param y
	 * @param text
	 */
void API::setText(int x, int y, const std::string& text) {
	std::cout << "setText " << x << " " << y << " " << text << std::endl;
	}
	/**
	 * @brief It clears the text of the cell at the given position
	 * @param x
	 * @param y
	 */
void API::clearText(int x, int y) {
	std::cout << "clearText " << x << " " << y << std::endl;
	}
	/**
	 * @brief It clears the text of all cells
	 */
void API::clearAllText() {
	std::cout << "clearAllText" << std::endl;
	}
bool API::wasReset() {
	std::cout << "wasReset" << std::endl;
	std::string response;
	std::cin >> response;
	return response == "true";
	}
void API::ackReset() {
	std::cout << "ackReset" << std::endl;
	std::string ack;
	std::cin >> ack;
	}

