#pragma once
#include <memory>
#include "../Maze/Maze.h"
#include "../API/API.h"
#include "../LandBasedWheeled/LandBasedWheeled.h"
namespace fp
{

class Algorithm
{
	public:
	bool goal_flag;
	struct Node{
	int px,py;
    int cx,cy;
    char prev_dir,next_dir;
    //string actions;
};
	std::vector<Node> queue;
	std::vector<int> X;
	std::vector<int> Y;
	std::vector<char> direc;
	
	//vector<string> Actions;
	bool CheckNode(int, int,char);
	void GenerateSequence(fp::Maze&, std::shared_ptr<fp::LandBasedRobot>);
	void MoveRobot(fp::Maze&, std::shared_ptr<fp::LandBasedRobot>);
	void ValidNodes(fp::Maze&,int,int, char);
	void SolveMaze(fp::Maze&, std::shared_ptr<fp::LandBasedRobot>);

};

}
