#pragma once
#include "../Maze/Maze.h"
#include "../API/API.h"
namespace fp
{

class Algorithm
{
public:
	void GenerateSequence(fp::Maze maze, int Start_x, int Start_y, char Start_dir);
	void ValidNodes(fp::Maze maze,int x,int y, char dir);

};

}
