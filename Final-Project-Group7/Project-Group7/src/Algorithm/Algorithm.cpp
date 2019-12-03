#include "Algorithm.h"
#include "../Maze/Maze.h"
#include "../API/API.h"
#include "../LandBasedWheeled/LandBasedWheeled.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;



std::vector<fp::Algorithm::Node> valid; // Vector to store all the Valid nodes 

/**
 * @brief Function definition for Algorithm class : CheckNode. The function checks if the current node is previously explored or not.
 * @param x position of the robot in the maze
 * @param y position of the robot in the maze
 * @param dir direction the robot is facing
 * @return True/False Returns true if the node is explored else returns false
 * */
bool fp::Algorithm::CheckNode(int x,int y, char dir){
	for(unsigned int i=0;i<fp::Algorithm::queue.size();i++){
		if(fp::Algorithm::queue[i].cx==x && fp::Algorithm::queue[i].cy==y && fp::Algorithm::queue[i].next_dir==dir){
			return true;
		}
	}
	return false;
}

/**
 * @brief Function definition for Algorithm class : ValidNodes. The function pushes valid nodes which can be explored from the current node in the vector "valid".  
 * @param maze_algo Object of the class Maze
 * @param x position of the robot in the maze
 * @param y position of the robot in the maze
 * @param dir direction the robot is facing
 * */

void fp::Algorithm::ValidNodes(fp::Maze& maze_algo,int x,int y, char dir){
    Node temp;
    valid.clear();
    
    // Whenever robot is facing North
    if(dir=='n'){
	if(maze_algo.North[x][y]==1 && maze_algo.East[x][y]==1 && maze_algo.West[x][y]==1){ //If the robot encounters walls in all the four direction - South node is explored
		//Update the parent node coordinates
		temp.px=x;
        temp.py=y;
		//Update the child node coordinates
        temp.cx=x;
        temp.cy=y-1;
		//Update the previous direction and the next direction in the struct
		temp.prev_dir = 'n';
        temp.next_dir='s';
        if(temp.cy>=0 && temp.cy<=15){
        valid.push_back(temp); //Valid node is updated
	}
	}
	if(maze_algo.East[x][y]!=1){ //If there is no wall in the East - East node is explored
        temp.px=x;
        temp.py=y;
        temp.cx=x+1;
        temp.cy=y;
        temp.prev_dir = 'n';
        temp.next_dir='e';
        if(temp.cx>=0 && temp.cx<=15){
        valid.push_back(temp);
        }
    }
    if(maze_algo.North[x][y]!=1){ //If there is no wall in the north - North node is explored
        temp.px=x;
        temp.py=y;
        temp.cx=x;
        temp.cy=y+1;
        temp.prev_dir = 'n';
        temp.next_dir='n';
        if(temp.cy>=0 && temp.cy<=15){
        valid.push_back(temp);
        }
    }
    if(maze_algo.West[x][y]!=1){ //If there is no wall in the west - West node is explored
        temp.px=x;
        temp.py=y;
        temp.cx=x-1;
        temp.cy=y;
        temp.prev_dir = 'n';
        temp.next_dir='w';
        if(temp.cx>=0 && temp.cx<=15){
        valid.push_back(temp);
        }
    }
    
    }
    
    // Whenever robot is facing east,Similar updating technique is used
    else if(dir=='e'){
	if(maze_algo.South[x][y]!=1){
        temp.px=x;
        temp.py=y;
        temp.cx=x;
        temp.cy=y-1;
		temp.prev_dir='e';
        temp.next_dir='s';
        if(temp.cy>=0 && temp.cy<=15){
        valid.push_back(temp);
        }
    }
	if(maze_algo.East[x][y]!=1){
        temp.px=x;
        temp.py=y;
        temp.cx=x+1;
        temp.cy=y;
        temp.prev_dir='e';
        temp.next_dir='e';
        if(temp.cx>=0 && temp.cx<=15){
        valid.push_back(temp);
        }
    }
	if(maze_algo.North[x][y]!=1){
        temp.px=x;
        temp.py=y;
        temp.cx=x;
        temp.cy=y+1;
        temp.prev_dir='e';
        temp.next_dir='n';
        if(temp.cy>=0 && temp.cy<=15){
        valid.push_back(temp);
        }
    }
	if(maze_algo.North[x][y]==1 && maze_algo.East[x][y]==1 && maze_algo.South[x][y]==1){
		temp.px=x;
        temp.py=y;
        temp.cx=x-1;
        temp.cy=y;
        temp.prev_dir='e';
        temp.next_dir='w';
        if(temp.cy>=0 && temp.cy<=15){
        valid.push_back(temp);
	}
	}
    }
    
    // Whenever robot is facing west,Similar updating technique is used
    else if(dir=='w'){
	if(maze_algo.South[x][y]!=1){
        temp.px=x;
        temp.py=y;
        temp.cx=x;
        temp.cy=y-1;
		temp.prev_dir = 'w';
		temp.next_dir = 's';
        if(temp.cy>=0 && temp.cy<=15){
        valid.push_back(temp);
        }
    }
	if(maze_algo.North[x][y]==1 && maze_algo.West[x][y]==1 && maze_algo.South[x][y]==1){
		temp.px=x;
        temp.py=y;
        temp.cx=x+1;
        temp.cy=y;
        temp.prev_dir = 'w';
		temp.next_dir ='e';
        if(temp.cy>=0 && temp.cy<=15){
        valid.push_back(temp);
	}
	}
    if(maze_algo.North[x][y]!=1){
        temp.px=x;
        temp.py=y;
        temp.cx=x;
        temp.cy=y+1;
        temp.prev_dir = 'w';
		temp.next_dir ='n';
        if(temp.cy>=0 && temp.cy<=15){
        valid.push_back(temp);
        }
    }
    
    if(maze_algo.West[x][y]!=1){
        temp.px=x;
        temp.py=y;
        temp.cx=x-1;
        temp.cy=y;
        temp.prev_dir = 'w';
		temp.next_dir = 'w';
        if(temp.cx>=0 && temp.cx<=15){
        valid.push_back(temp);
        }
    }
    }
    
    // Whenever robot is facing south,Similar updating technique is used
    else if(dir=='s'){
	if(maze_algo.South[x][y]!=1){
        temp.px=x;
        temp.py=y;
        temp.cx=x;
        temp.cy=y-1;
		temp.prev_dir = 's';
        temp.next_dir ='s';
        if(temp.cy>=0 && temp.cy<=15){
        valid.push_back(temp);
        }
    }
	if(maze_algo.East[x][y]!=1){
        temp.px=x;
        temp.py=y;
        temp.cx=x+1;
        temp.cy=y;
        temp.prev_dir = 's';
        temp.next_dir ='e';
        if(temp.cx>=0 && temp.cx<=15){
        valid.push_back(temp);
        }
    }
	if(maze_algo.South[x][y]==1 && maze_algo.East[x][y]==1 && maze_algo.West[x][y]==1){
		temp.px=x;
        temp.py=y;
        temp.cx=x;
        temp.cy=y+1;
        temp.prev_dir = 's';
        temp.next_dir ='n';
        if(temp.cy>=0 && temp.cy<=15){
        valid.push_back(temp);
	}
	}
    
    if(maze_algo.West[x][y]!=1){
        temp.px=x;
        temp.py=y;
        temp.cx=x-1;
        temp.cy=y;
        temp.prev_dir = 's';
        temp.next_dir ='w';
        if(temp.cx>=0 && temp.cx<=15){
        valid.push_back(temp);
        }
    }
    }
}

/**
 * @brief Function definition for Algorithm class : GenerateSequence. The function generates the path from the start node to the end goal using BFS algorithm, considering the walls detected upto that iteration  
 * @param maze_algo Object of the class Maze
 * @param a shared pointer to the object robot of the class LandBasedRobot
 * */

void fp::Algorithm::GenerateSequence(fp::Maze& maze_algo, std::shared_ptr<fp::LandBasedRobot> robot)
{
  fp::Algorithm::queue.clear();
  int Start_x{robot->get_x()},Start_y{robot->get_y()}; //Initialize the start node
  char Start_dir{robot->GetDirection()}; //Initialize the initial direction of the robot at the start node.
  maze_algo.ReadMaze(Start_x,Start_y,Start_dir); //Updates the maze for the start position of the robot
  //Initializing the initial conditions for generating the path
  
  fp::API::clearAllColor();
  fp::Algorithm::goal_flag=false;
  
  fp::Algorithm::Node temp_node;
  
  temp_node.px = 100;
  temp_node.py = 100;
  temp_node.prev_dir = 'a';
  temp_node.cx = Start_x;
  temp_node.cy = Start_y;
  temp_node.next_dir = Start_dir;
  fp::Algorithm::queue.push_back(temp_node);
  //Iterate through the maze and check the condition if the Goal node is reached.
  for(unsigned int i=0 ; i<fp::Algorithm::queue.size() ; i++){
      ValidNodes(maze_algo,fp::Algorithm::queue[i].cx,fp::Algorithm::queue[i].cy,fp::Algorithm::queue[i].next_dir);
      for(unsigned int k=0 ; k<valid.size() ; k++){
          if(fp::Algorithm::CheckNode(valid[k].cx , valid[k].cy , valid[k].next_dir)==false){ //If the node is not previously explored, the valid node is pushed in the queue
            queue.push_back(valid[k]);
            if ((valid[k].cx == 7 && valid[k].cy == 7) || (valid[k].cx == 7 && valid[k].cy == 8) || (valid[k].cx == 8 && valid[k].cy == 8) || (valid[k].cx == 8 && valid[k].cy == 7)){
                fp::Algorithm::goal_flag=true; //If goal is reached, returns flag as 'true'
                break;
            }
          }
      }
       
  if(fp::Algorithm::goal_flag==true){
      break;
  }
  }

  if (fp::Algorithm::goal_flag==true){

      fp::Algorithm::X.clear();
      fp::Algorithm::Y.clear();
	  fp::Algorithm::direc.clear();
	  
		//Coordinates and direction of the current node is used to update the vector of valid node coordinates and ubsequent direction 
      fp::Algorithm::X.push_back(queue[queue.size()-1].cx);
      fp::Algorithm::Y.push_back(queue[queue.size()-1].cy);
	  fp::Algorithm::direc.push_back(queue[queue.size()-1].next_dir);
      fp::Algorithm::X.push_back(queue[queue.size()-1].px);
      fp::Algorithm::Y.push_back(queue[queue.size()-1].py);
	  fp::Algorithm::direc.push_back(queue[queue.size()-1].prev_dir);
	  //Keeping track of the parent nodes 
      int a=queue[queue.size()-1].px;
      int b=queue[queue.size()-1].py;
	  char dir_check = queue[queue.size()-1].prev_dir;
      int i=queue.size()-1;
	  //Backtracking is implemented
    while(1){
          if(a==queue[i].cx && b==queue[i].cy && dir_check==queue[i].next_dir){
              fp::Algorithm::X.push_back(queue[i].px);
              fp::Algorithm::Y.push_back(queue[i].py);
              
			  fp::Algorithm::direc.push_back(queue[i].prev_dir);
              a=queue[i].px;
              b=queue[i].py;
			  dir_check = queue[i].prev_dir;
          }
          i=i-1;
          if(a==Start_x && b==Start_y && dir_check==Start_dir){
              break;
          } 
      }
      std::reverse(fp::Algorithm::X.begin(),fp::Algorithm::X.end());
	  std::reverse(fp::Algorithm::direc.begin(),fp::Algorithm::direc.end());
      std::reverse(fp::Algorithm::Y.begin(),fp::Algorithm::Y.end());
  }
}


/**
 * @brief Function definition for Algorithm class : MoveRobot. The function makes the robot move through the sequence of nodes thus generated  
 * @param maze_algo Object of the class Maze
 * @param a shared pointer to the object robot of the class LandBasedRobot
 * */

void fp::Algorithm::MoveRobot(fp::Maze& maze_algo, std::shared_ptr<fp::LandBasedRobot> robot){
	maze_algo.colorPath(fp::Algorithm::X,fp::Algorithm::Y);

	int tempx,tempy;
	char tempdir;
	//Iterating through the vector of all the nodes derived from the sequence generated
	for(unsigned int i=1;i<fp::Algorithm::direc.size();i++){
		//Storing the current coordinates and direction of the robot in the maze
		tempx = robot->get_x();
		tempy = robot->get_y();
		tempdir = robot->GetDirection();
		maze_algo.ReadMaze(tempx,tempy,tempdir);
		//Movement, if robot is facing north direction
		if(tempdir == 'n' && fp::Algorithm::direc[i] == 'n' && maze_algo.North[tempx][tempy] == false){
			std::cerr << "Robot Current " << robot->get_x() << ' ' << robot->get_y() << ' ' << robot->GetDirection() << " Next -> ";
			std::cerr << fp::Algorithm::X[i] << ' ' << fp::Algorithm::Y[i] << ' ' << fp::Algorithm::direc[i] << std::endl;
			robot->MoveForward();
		}
		else if(tempdir == 'n' && fp::Algorithm::direc[i] == 'e' && maze_algo.East[tempx][tempy] == false){
			std::cerr << "Robot Current " << robot->get_x() << ' ' << robot->get_y() << ' ' << robot->GetDirection() << " Next -> ";
			std::cerr << fp::Algorithm::X[i] << ' ' << fp::Algorithm::Y[i] << ' ' << fp::Algorithm::direc[i] << std::endl;
			robot->TurnRight();
			robot->MoveForward();
		}
		else if(tempdir == 'n' && fp::Algorithm::direc[i] == 'w' && maze_algo.West[tempx][tempy] == false){
			std::cerr << "Robot Current " << robot->get_x() << ' ' << robot->get_y() << ' ' << robot->GetDirection() << " Next -> ";
			std::cerr << fp::Algorithm::X[i] << ' ' << fp::Algorithm::Y[i] << ' ' << fp::Algorithm::direc[i] << std::endl;
			robot->TurnLeft();
			robot->MoveForward();
		}
		else if(tempdir == 'n' && fp::Algorithm::direc[i] == 's' && maze_algo.South[tempx][tempy] == false){
			std::cerr << "Robot Current " << robot->get_x() << ' ' << robot->get_y() << ' ' << robot->GetDirection() << " Next -> ";
			std::cerr << fp::Algorithm::X[i] << ' ' << fp::Algorithm::Y[i] << ' ' << fp::Algorithm::direc[i] << std::endl;
			robot->TurnLeft();
			robot->TurnLeft();
			robot->MoveForward();
		}
		
		// Movement if Robot is facing East direction
		else if(tempdir == 'e' && fp::Algorithm::direc[i] == 'e' && maze_algo.East[tempx][tempy] == false){
			std::cerr << "Robot Current " << robot->get_x() << ' ' << robot->get_y() << ' ' << robot->GetDirection() << " Next -> ";
			std::cerr << fp::Algorithm::X[i] << ' ' << fp::Algorithm::Y[i] << ' ' << fp::Algorithm::direc[i] << std::endl;
			robot->MoveForward();
		}
		else if(tempdir == 'e' && fp::Algorithm::direc[i] == 's' && maze_algo.South[tempx][tempy] == false){
			std::cerr << "Robot Current " << robot->get_x() << ' ' << robot->get_y() << ' ' << robot->GetDirection() << " Next -> ";
			std::cerr << fp::Algorithm::X[i] << ' ' << fp::Algorithm::Y[i] << ' ' << fp::Algorithm::direc[i] << std::endl;
			robot->TurnRight();
			robot->MoveForward();
		}
		else if(tempdir == 'e' && fp::Algorithm::direc[i] == 'n' && maze_algo.North[tempx][tempy] == false){
			std::cerr << "Robot Current " << robot->get_x() << ' ' << robot->get_y() << ' ' << robot->GetDirection() << " Next -> ";
			std::cerr << fp::Algorithm::X[i] << ' ' << fp::Algorithm::Y[i] << ' ' << fp::Algorithm::direc[i] << std::endl;
			robot->TurnLeft();
			robot->MoveForward();
		}
		else if(tempdir == 'e' && fp::Algorithm::direc[i] == 'w' && maze_algo.West[tempx][tempy] == false){
			std::cerr << "Robot Current " << robot->get_x() << ' ' << robot->get_y() << ' ' << robot->GetDirection() << " Next -> ";
			std::cerr << fp::Algorithm::X[i] << ' ' << fp::Algorithm::Y[i] << ' ' << fp::Algorithm::direc[i] << std::endl;
			robot->TurnLeft();
			robot->TurnLeft();
			robot->MoveForward();
		}
		
		// Movement if Robot is facing South direction
		else if(tempdir == 's' && fp::Algorithm::direc[i] == 's' && maze_algo.South[tempx][tempy] == false){
			std::cerr << "Robot Current " << robot->get_x() << ' ' << robot->get_y() << ' ' << robot->GetDirection() << " Next -> ";
			std::cerr << fp::Algorithm::X[i] << ' ' << fp::Algorithm::Y[i] << ' ' << fp::Algorithm::direc[i] << std::endl;
			robot->MoveForward();
		}
		else if(tempdir == 's' && fp::Algorithm::direc[i] == 'e' && maze_algo.East[tempx][tempy] == false){
			std::cerr << "Robot Current " << robot->get_x() << ' ' << robot->get_y() << ' ' << robot->GetDirection() << " Next -> ";
			std::cerr << fp::Algorithm::X[i] << ' ' << fp::Algorithm::Y[i] << ' ' << fp::Algorithm::direc[i] << std::endl;
			robot->TurnLeft();
			robot->MoveForward();
		}
		else if(tempdir == 's' && fp::Algorithm::direc[i] == 'w' && maze_algo.West[tempx][tempy] == false){
			std::cerr << "Robot Current " << robot->get_x() << ' ' << robot->get_y() << ' ' << robot->GetDirection() << " Next -> ";
			std::cerr << fp::Algorithm::X[i] << ' ' << fp::Algorithm::Y[i] << ' ' << fp::Algorithm::direc[i] << std::endl;
			robot->TurnRight();
			robot->MoveForward();
		}
		else if(tempdir == 's' && fp::Algorithm::direc[i] == 'n' && maze_algo.North[tempx][tempy] == false){
			std::cerr << "Robot Current " << robot->get_x() << ' ' << robot->get_y() << ' ' << robot->GetDirection() << " Next -> ";
			std::cerr << fp::Algorithm::X[i] << ' ' << fp::Algorithm::Y[i] << ' ' << fp::Algorithm::direc[i] << std::endl;
			robot->TurnLeft();
			robot->TurnLeft();
			robot->MoveForward();
		}
		
		// Movement if Robot is facing East direction
		else if(tempdir == 'w' && fp::Algorithm::direc[i] == 'w' && maze_algo.West[tempx][tempy] == false){
			std::cerr << "Robot Current " << robot->get_x() << ' ' << robot->get_y() << ' ' << robot->GetDirection() << " Next -> ";
			std::cerr << fp::Algorithm::X[i] << ' ' << fp::Algorithm::Y[i] << ' ' << fp::Algorithm::direc[i] << std::endl;
			robot->MoveForward();
		}
		else if(tempdir == 'w' && fp::Algorithm::direc[i] == 'n' && maze_algo.North[tempx][tempy] == false){
			std::cerr << "Robot Current " << robot->get_x() << ' ' << robot->get_y() << ' ' << robot->GetDirection() << " Next -> ";
			std::cerr << fp::Algorithm::X[i] << ' ' << fp::Algorithm::Y[i] << ' ' << fp::Algorithm::direc[i] << std::endl;
			robot->TurnRight();
			robot->MoveForward();
		}
		else if(tempdir == 'w' && fp::Algorithm::direc[i] == 's' && maze_algo.South[tempx][tempy] == false){
			std::cerr << "Robot Current " << robot->get_x() << ' ' << robot->get_y() << ' ' << robot->GetDirection() << " Next -> ";
			std::cerr << fp::Algorithm::X[i] << ' ' << fp::Algorithm::Y[i] << ' ' << fp::Algorithm::direc[i] << std::endl;
			robot->TurnLeft();
			robot->MoveForward();
		}
		else if(tempdir == 'w' && fp::Algorithm::direc[i] == 'e' && maze_algo.East[tempx][tempy] == false){
			std::cerr << "Robot Current " << robot->get_x() << ' ' << robot->get_y() << ' ' << robot->GetDirection() << " Next -> ";
			std::cerr << fp::Algorithm::X[i] << ' ' << fp::Algorithm::Y[i] << ' ' << fp::Algorithm::direc[i] << std::endl;
			robot->TurnLeft();
			robot->TurnLeft();
			robot->MoveForward();
		}
		else
			break;
    }
}

/**
 * @brief Function definition for Algorithm class : SolveMaze. The function finally solves the maze from the start to end and achieving the said task  
 * @param maze_algo Object of the class Maze
 * @param a shared pointer to the object robot of the class LandBasedRobot
 * */
 
void fp::Algorithm::SolveMaze(fp::Maze& maze, std::shared_ptr<fp::LandBasedRobot> robot){
	while(fp::Algorithm::goal_flag==true ){ //Executes till the goal is reached
		//Appropriate sequence is generated for the given robot in the given maze
		fp::Algorithm::GenerateSequence(maze,robot);
		//The given robot moves through the maze 
		fp::Algorithm::MoveRobot(maze,robot);
        //Setting goal condition
		if ((robot->get_x() == 7 && robot->get_y() == 7) || (robot->get_x() == 7 && robot->get_y() == 8) || (robot->get_x() == 8 && robot->get_y() == 8) || (robot->get_x() == 8 && robot->get_y() == 7)) {
			fp::API::clearAllColor();
			break;
			}
	}
}
