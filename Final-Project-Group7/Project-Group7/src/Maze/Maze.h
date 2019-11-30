#pragma once

#include "../API/API.h"
namespace fp
{

class Maze
{
public:
    int x;
    int y;
    int dir;
	 // Marix to store whether the node has wall in left or not
    int North[16][16]{};
    int South[16][16]{};
    int East[16][16]{};
    int West[16][16]{};
    
	void ReadMaze(int x,int y,char direction);
};

}

