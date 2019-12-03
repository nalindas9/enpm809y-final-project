#include "Algorithm.h"
#include "../Maze/Maze.h"
#include "../API/API.h"
#include "../LandBasedWheeled/LandBasedWheeled.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;



std::vector<fp::Algorithm::Node> valid;

bool fp::Algorithm::CheckNode(int x,int y, char dir){
	for(unsigned int i=0;i<fp::Algorithm::queue.size();i++){
		if(fp::Algorithm::queue[i].cx==x && fp::Algorithm::queue[i].cy==y && fp::Algorithm::queue[i].next_dir==dir){
			return true;
		}
	}
	return false;
}

void fp::Algorithm::ValidNodes(fp::Maze& maze_algo,int x,int y, char dir){
    Node temp;
    valid.clear();
    
    // If robot is facing North
    if(dir=='n'){
	if(maze_algo.North[x][y]==1 && maze_algo.East[x][y]==1 && maze_algo.West[x][y]==1){
		temp.px=x;
        temp.py=y;
        temp.cx=x;
        temp.cy=y-1;
		temp.prev_dir = 'n';
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
        temp.prev_dir = 'n';
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
        temp.prev_dir = 'n';
        temp.next_dir='n';
        if(temp.cy>=0 && temp.cy<=15){
        valid.push_back(temp);
        }
    }
    if(maze_algo.West[x][y]!=1){
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
    
    // If robot is facing east
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
    
    // If robot is facing West
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
    
    // If robot is facing South
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

void fp::Algorithm::GenerateSequence(fp::Maze& maze_algo, std::shared_ptr<fp::LandBasedRobot> robot)
{
  fp::Algorithm::queue.clear();
  int Start_x{robot->get_x()},Start_y{robot->get_y()};
  char Start_dir{robot->GetDirection()};
  maze_algo.ReadMaze(Start_x,Start_y,Start_dir);
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
  
  for(unsigned int i=0 ; i<fp::Algorithm::queue.size() ; i++){
      ValidNodes(maze_algo,fp::Algorithm::queue[i].cx,fp::Algorithm::queue[i].cy,fp::Algorithm::queue[i].next_dir);
      for(unsigned int k=0 ; k<valid.size() ; k++){
          if(fp::Algorithm::CheckNode(valid[k].cx , valid[k].cy , valid[k].next_dir)==false){
            queue.push_back(valid[k]);
            if ((valid[k].cx == 7 && valid[k].cy == 7) || (valid[k].cx == 7 && valid[k].cy == 8) || (valid[k].cx == 8 && valid[k].cy == 8) || (valid[k].cx == 8 && valid[k].cy == 7)){
                fp::Algorithm::goal_flag=true;
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

      fp::Algorithm::X.push_back(queue[queue.size()-1].cx);
      fp::Algorithm::Y.push_back(queue[queue.size()-1].cy);
	  fp::Algorithm::direc.push_back(queue[queue.size()-1].next_dir);
      fp::Algorithm::X.push_back(queue[queue.size()-1].px);
      fp::Algorithm::Y.push_back(queue[queue.size()-1].py);
	  fp::Algorithm::direc.push_back(queue[queue.size()-1].prev_dir);
      int a=queue[queue.size()-1].px;
      int b=queue[queue.size()-1].py;
	  char dir_check = queue[queue.size()-1].prev_dir;
      int i=queue.size()-1;
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
void fp::Algorithm::MoveRobot(fp::Maze& maze_algo, std::shared_ptr<fp::LandBasedRobot> robot){
	maze_algo.colorPath(fp::Algorithm::X,fp::Algorithm::Y);

	int tempx,tempy;
	char tempdir;

	for(unsigned int i=1;i<fp::Algorithm::direc.size();i++){
		
		tempx = robot->get_x();
		tempy = robot->get_y();
		tempdir = robot->GetDirection();
		maze_algo.ReadMaze(tempx,tempy,tempdir);
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

void fp::Algorithm::SolveMaze(fp::Maze& maze, std::shared_ptr<fp::LandBasedRobot> robot){
	while(fp::Algorithm::goal_flag==true ){

		fp::Algorithm::GenerateSequence(maze,robot);

		fp::Algorithm::MoveRobot(maze,robot);
        //Setting goal condition
		if ((robot->get_x() == 7 && robot->get_y() == 7) || (robot->get_x() == 7 && robot->get_y() == 8) || (robot->get_x() == 8 && robot->get_y() == 8) || (robot->get_x() == 8 && robot->get_y() == 7)) {
			fp::API::clearAllColor();
			break;
			}
	}
}
