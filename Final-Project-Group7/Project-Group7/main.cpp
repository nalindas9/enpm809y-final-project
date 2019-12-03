#include <stdio.h>
#include <memory>
#include "src/LandBasedRobot/LandBasedRobot.h"
#include "src/LandBasedTracked/LandBasedTracked.h"
#include "src/LandBasedWheeled/LandBasedWheeled.h"
#include "src/Maze/Maze.h"
#include "src/API/API.h"
#include "src/Algorithm/Algorithm.h"

int main()
{
	fp::Algorithm algo;
	fp::Maze maze;
	std::shared_ptr<fp::LandBasedRobot> robot = std::make_shared<fp::LandBasedWheeled>("Husky", 4, 34, 22, 34, 34, 45, 0,  0, 'n'); // std::string name = "Husky",  int wheel_num = 4, double speed = 34, double width = 22, double length = 34, double height = 34, double capacity = 45, int x = 0, int y = 0, char direction = 'n'
	
	algo.SolveMaze(maze,robot);
	
	return 0;
}
