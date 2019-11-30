#pragma once

#include "../API/API.h"
namespace fp
{

class Maze
{
public:
    int x;
    int y;
	static bool north_wall; // Marix to store whether the node has wall in front or not
	static bool east_wall; // Marix to store whether the node has wall in right or not
	static bool west_wall; // Marix to store whether the node has wall in back or not
	static bool south_wall; // Marix to store whether the node has wall in left or not
    int North[16][16]{};
    int South[16][16]{};
    int East[16][16]{};
    int West[16][16]{};
    
	void ReadMaze(int x,int y,char direction);
};

}

