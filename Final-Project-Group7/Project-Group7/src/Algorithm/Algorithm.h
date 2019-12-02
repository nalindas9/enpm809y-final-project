#pragma once
#include "../Maze/Maze.h"
#include "../API/API.h"
#include "../LandBasedWheeled/LandBasedWheeled.h"
namespace fp
{

class Algorithm
{
public:
	void GenerateSequence(fp::Maze maze, fp::LandBasedWheeled robot);
	void ValidNodes(fp::Maze maze,int x,int y, char dir);

};

}
