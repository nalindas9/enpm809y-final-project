#pragma once

#include "../API/API.h"
#include <vector>

namespace fp
{

class Maze
{
public:
    int x;
    int y;
    int dir;
	 // Marix to store whether the node has wall in left or not
    bool North[16][16];
    bool South[16][16];
    bool East[16][16];
    bool West[16][16];
	Maze();
/**
 * @brief It updates the 'n','s','e','w' 2d array.
 * @param x
 * @param y
 * @param direction
 */
    
	void ReadMaze(int x,int y,char direction);
    void colorPath(std::vector<int> &X, std::vector<int> &Y);
	//void ResetColor();
};

}

