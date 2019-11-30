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
    static int North[16][16]{};
    static int South[16][16]{};
    static int East[16][16]{};
    static int West[16][16]{};
    
	void ReadMaze(int x,int y,char direction);
};

}

