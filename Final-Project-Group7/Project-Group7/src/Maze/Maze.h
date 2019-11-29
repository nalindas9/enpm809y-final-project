#pragma once
#include "../API/API.h"
namespace fp
{

class Maze
{
public:
	static bool up_wall[16][16]; // Marix to store whether the node has wall in front or not
	static bool right_wall[16][16]; // Marix to store whether the node has wall in right or not
	static bool down_wall[16][16]; // Marix to store whether the node has wall in back or not
	static bool left_wall[16][16]; // Marix to store whether the node has wall in left or not
	void ReadMaze();
};

}

