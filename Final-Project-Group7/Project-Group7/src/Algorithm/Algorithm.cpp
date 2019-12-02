#include "Algorithm.h"
#include "../Maze/Maze.h"
#include "../API/API.h"
#include "../LandBasedWheeled/LandBasedWheeled.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//fp::Maze maze_algo;
//
//struct fp::Algorithm::Node{
//    int px,py;
//    int cx,cy;
//    char dir;
//    //string actions;
//};


std::vector<fp::Algorithm::Node> valid;

bool fp::Algorithm::CheckNode(int x,int y, char dir){
	for(int i=0;i<fp::Algorithm::queue.size();i++){
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
        //temp.actions="Go Down";// Action = Go Forward
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
        //temp.actions="Turn Right";
        // Action = Turn Right and Go forward
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
        //temp.actions="Go Forward";// Action = Go Forward
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
        //temp.actions="Turn Left";
         // Action = Turn Left and Go forward
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
        //temp.actions="Turn Right";
        // Action = Turn right and Go forward
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
        //temp.actions="Go Forward"; // Action = Go forward
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
        //temp.actions="Turn Left";
        // Action = Turn Left and Go forward
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
        //temp.actions="Go Left";// Action = Go Forward
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
        //temp.actions="Turn Left";
        // Action = Turn Left and Go forward
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
        //temp.actions="Go Down";// Action = Go Forward
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
        //temp.actions="Turn Right";
        // Action = Turn right and Go forward
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
        //temp.actions="Go Forward";// Action = Go forward
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
        //temp.actions="Go Forward";// Action = Go forward
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
        //temp.actions="Turn Left";
        // Action = Turn Left and Go forward
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
        //temp.actions="Go Down";// Action = Go Forward
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
        //temp.actions="Turn Right";
        // Action = Turn right and Go forward
        valid.push_back(temp);
        }
    }
    }
}

void fp::Algorithm::GenerateSequence(fp::Maze& maze_algo, std::shared_ptr<fp::LandBasedRobot> robot)
{
  //Node a;
  fp::Algorithm::queue.clear();
  int Start_x{robot->get_x()},Start_y{robot->get_y()};
  char Start_dir{robot->GetDirection()};
  //cerr<<"GenerateSequence : Maze was at ("<<Start_x<<","<<Start_y<<") Direction : "<<Start_dir<<" as North = "<<maze_algo.North[Start_x][Start_y]<<", East = "<<maze_algo.East[Start_x][Start_y]<<", West = "<<maze_algo.West[Start_x][Start_y]<<", South = "<<maze_algo.South[Start_x][Start_y]<<endl;
  maze_algo.ReadMaze(Start_x,Start_y,Start_dir);
  //cerr<<"GenerateSequence : Maze updated at ("<<Start_x<<","<<Start_y<<") Direction : "<<Start_dir<<" as North = "<<maze_algo.North[Start_x][Start_y]<<", East = "<<maze_algo.East[Start_x][Start_y]<<", West = "<<maze_algo.West[Start_x][Start_y]<<", South = "<<maze_algo.South[Start_x][Start_y]<<endl;
  //maze_algo.MazeInitialisation();
	  fp::API::clearAllColor();
//  bool seen[16][16]{false};
  fp::Algorithm::goal_flag=false;
  //vector<Node> queue;
  
  fp::Algorithm::Node temp_node;
  temp_node.px = 100;
  temp_node.py = 100;
  temp_node.prev_dir = 'a';
  temp_node.cx = Start_x;
  temp_node.cy = Start_y;
  temp_node.next_dir = Start_dir;
//  cerr<<"Starting x : "<<Start_x<<" y : "<<Start_y<<" dir : "<<Start_dir<<endl;
  //temp_node.actions = "";
  //seen[temp_node.cx][temp_node.cy] = 1;
  fp::Algorithm::queue.push_back(temp_node);
  
  for(int i=0 ; i<fp::Algorithm::queue.size() ; i++){
    //   cout<<"Iteration : "<<i<<endl;
    //   cout<<"exploring ("<<queue[i].cx<<","<<queue[i].cy<<")"<<endl;
      ValidNodes(maze_algo,fp::Algorithm::queue[i].cx,fp::Algorithm::queue[i].cy,fp::Algorithm::queue[i].next_dir);
      for(int k=0 ; k<valid.size() ; k++){
          if(fp::Algorithm::CheckNode(valid[k].cx , valid[k].cy , valid[k].next_dir)==false){
            //seen[valid[k].cx][valid[k].cy] = 1;
            queue.push_back(valid[k]);
            if ((valid[k].cx == 7 && valid[k].cy == 7) || (valid[k].cx == 7 && valid[k].cy == 8) || (valid[k].cx == 8 && valid[k].cy == 8) || (valid[k].cx == 8 && valid[k].cy == 7)){
                // cout<<"Goal Reached "<<endl;
                fp::Algorithm::goal_flag=true;
                break;
            }
          }
      }
//       
  if(fp::Algorithm::goal_flag==true){
      break;
  }
  }

  if (fp::Algorithm::goal_flag==true){
//       cerr<<"-----------------------"<<endl;
//      
//       for(int l=0;l<fp::Algorithm::queue.size();l++){
//       cerr<<"[ ("<<fp::Algorithm::queue[l].px<<","<<fp::Algorithm::queue[l].py<<") "<< fp::Algorithm::queue[l].prev_dir<<"]	 [ ("<<fp::Algorithm::queue[l].cx<<","<<fp::Algorithm::queue[l].cy<<")   "<<fp::Algorithm::queue[l].next_dir<<" ] "<<endl;
////       for(int m=4;m<=0;m++){
////           for(int n=0;n<5;n++)
////           cout<<seen[n][m]<<" ";
////           cout<<endl;
////       }
//   }
//   cerr<<"-----------------------"<<endl;
//cerr<<" Direction last : "<<queue[queue.size()-1].dir<<endl;

      fp::Algorithm::X.clear();
      fp::Algorithm::Y.clear();
	  fp::Algorithm::direc.clear();
//      vector<string> Actions;
      fp::Algorithm::X.push_back(queue[queue.size()-1].cx);
      fp::Algorithm::Y.push_back(queue[queue.size()-1].cy);
	  fp::Algorithm::direc.push_back(queue[queue.size()-1].next_dir);
//	  Actions.push_back("");
//	  direc.push_back('a');
      fp::Algorithm::X.push_back(queue[queue.size()-1].px);
      fp::Algorithm::Y.push_back(queue[queue.size()-1].py);
	  //Actions.push_back(queue[queue.size()-1].actions);
	  fp::Algorithm::direc.push_back(queue[queue.size()-1].prev_dir);
//	  cerr<<" Direction appended : "<<queue[queue.size()-1].dir<<endl;
//      cerr<<" Direction in direc : "<<direc[0]<<endl;
      int a=queue[queue.size()-1].px;
      int b=queue[queue.size()-1].py;
	  char dir_check = queue[queue.size()-1].prev_dir;
      int i=queue.size()-1;
    //   auto itx = X.insert(X.begin(), queue[queue.size()-1].px);
    //   auto ity = Y.insert(Y.begin(), queue[queue.size()-1].py);
      while(1){
          if(a==queue[i].cx && b==queue[i].cy && dir_check==queue[i].next_dir){
            //   X.insert(itx, queue[i].px);
            //   Y.insert(ity, queue[i].py);
              fp::Algorithm::X.push_back(queue[i].px);
              fp::Algorithm::Y.push_back(queue[i].py);
              //Actions.push_back(queue[i].actions);
			  fp::Algorithm::direc.push_back(queue[i].prev_dir);
              a=queue[i].px;
              b=queue[i].py;
			  dir_check = queue[i].prev_dir;
          }
          i=i-1;
          if(a==Start_x && b==Start_y && dir_check==Start_dir){
//			  fp::Algorithm::direc.push_back(queue[i].dir);
              break;
          }
		  //direc.push_back('n');
        //   cout<<" b = "<<b<<" i = "<<i<<endl; 
      }
//	  X.pop_back();
//	  Y.pop_back();
      std::reverse(fp::Algorithm::X.begin(),fp::Algorithm::X.end());
	  std::reverse(fp::Algorithm::direc.begin(),fp::Algorithm::direc.end());
      std::reverse(fp::Algorithm::Y.begin(),fp::Algorithm::Y.end());
	  cerr<<"Generate sequence ended with this sequence "<<endl;
	  cerr<<"======================="<<endl;
	  for(int i=0;i<fp::Algorithm::direc.size();i++){
		  cerr<<"("<<fp::Algorithm::X[i]<<","<<fp::Algorithm::Y[i]<<")"<<"	Direc ["<<i<<"] = "<<fp::Algorithm::direc[i]<<endl;
	  }
	  cerr<<"======================="<<endl;
	  //if(fp::Algorithm::X.size()==fp::Algorithm::direc.size()){ cerr<<"X .size and direc.size equal"<<endl;}
    //return flag;
  }
}
//    //   for (int i=0;i<X.size();i++){
//    //       cout<<X[i]<<","<<Y[i]<<"  ";
//    //   }
//    //   cout<<endl;
//      //std::reverse(Actions.begin(),Actions.end());
////	  cerr<<"============="<<endl;
////	  for(int i=0;i<direc.size();i++){
////		  cerr<<"Direc ["<<i<<"] = "<<direc[i]<<endl;
////	  }
void fp::Algorithm::MoveRobot(fp::Maze& maze_algo, std::shared_ptr<fp::LandBasedRobot> robot){
	maze_algo.colorPath(fp::Algorithm::X,fp::Algorithm::Y);
//	cerr<<"Move Robot started for this series , X.size = "<<fp::Algorithm::X.size()<<endl;
//	cerr<<"======================="<<endl;
//	  for(int i=0;i<fp::Algorithm::direc.size();i++){
//		  cerr<<"("<<fp::Algorithm::X[i]<<","<<fp::Algorithm::Y[i]<<")"<<"	Direc ["<<i<<"] = "<<fp::Algorithm::direc[i]<<endl;
//	  }
//	  cerr<<"======================="<<endl;
	int tempx,tempy;
	char tempdir;
	bool flag{false};
	for(int i=1;i<fp::Algorithm::direc.size();i++){
		
//		std::cerr << "robot " << robot->get_x() << ' ' << robot->get_y() << ' ' << robot->GetDirection() << " Next -> ";
//		std::cerr << fp::Algorithm::X[i] << ' ' << fp::Algorithm::Y[i] << ' ' << fp::Algorithm::direc[i] << std::endl;
cerr<<"--------------------"<<endl;
		tempx = robot->get_x();
		tempy = robot->get_y();
		tempdir = robot->GetDirection();
		cerr<<"MoveRobot : Maze was at ("<<tempx<<","<<tempy<<") Direction : "<<tempdir<<" as North = "<<maze_algo.North[tempx][tempy]<<", East = "<<maze_algo.East[tempx][tempy]<<", West = "<<maze_algo.West[tempx][tempy]<<", South = "<<maze_algo.South[tempx][tempy]<<endl;
		cerr<<"Current X = "<<tempx<<" Y = "<<tempy<<" Direction = "<<tempdir<<endl;
		maze_algo.ReadMaze(tempx,tempy,tempdir);
		cerr<<"MoveRobot : Maze changed at ("<<tempx<<","<<tempy<<") Direction : "<<tempdir<<" as North = "<<maze_algo.North[tempx][tempy]<<", East = "<<maze_algo.East[tempx][tempy]<<", West = "<<maze_algo.West[tempx][tempy]<<", South = "<<maze_algo.South[tempx][tempy]<<endl;
		// Movement if Robot is facing North direction
		if(tempdir == 'n' && fp::Algorithm::direc[i] == 'n' && maze_algo.North[tempx][tempy] == false){
			std::cerr << "robot " << robot->get_x() << ' ' << robot->get_y() << ' ' << robot->GetDirection() << " Next -> ";
			std::cerr << fp::Algorithm::X[i] << ' ' << fp::Algorithm::Y[i] << ' ' << fp::Algorithm::direc[i] << std::endl;
			robot->MoveForward();
		}
		else if(tempdir == 'n' && fp::Algorithm::direc[i] == 'e' && maze_algo.East[tempx][tempy] == false){
			std::cerr << "robot " << robot->get_x() << ' ' << robot->get_y() << ' ' << robot->GetDirection() << " Next -> ";
			std::cerr << fp::Algorithm::X[i] << ' ' << fp::Algorithm::Y[i] << ' ' << fp::Algorithm::direc[i] << std::endl;
			robot->TurnRight();
			robot->MoveForward();
		}
		else if(tempdir == 'n' && fp::Algorithm::direc[i] == 'w' && maze_algo.West[tempx][tempy] == false){
			std::cerr << "robot " << robot->get_x() << ' ' << robot->get_y() << ' ' << robot->GetDirection() << " Next -> ";
			std::cerr << fp::Algorithm::X[i] << ' ' << fp::Algorithm::Y[i] << ' ' << fp::Algorithm::direc[i] << std::endl;
			robot->TurnLeft();
			robot->MoveForward();
		}
		else if(tempdir == 'n' && fp::Algorithm::direc[i] == 's' && maze_algo.South[tempx][tempy] == false){
			std::cerr << "robot " << robot->get_x() << ' ' << robot->get_y() << ' ' << robot->GetDirection() << " Next -> ";
			std::cerr << fp::Algorithm::X[i] << ' ' << fp::Algorithm::Y[i] << ' ' << fp::Algorithm::direc[i] << std::endl;
			robot->TurnLeft();
			robot->TurnLeft();
			robot->MoveForward();
		}
		
		// Movement if Robot is facing East direction
		else if(tempdir == 'e' && fp::Algorithm::direc[i] == 'e' && maze_algo.East[tempx][tempy] == false){
			std::cerr << "robot " << robot->get_x() << ' ' << robot->get_y() << ' ' << robot->GetDirection() << " Next -> ";
			std::cerr << fp::Algorithm::X[i] << ' ' << fp::Algorithm::Y[i] << ' ' << fp::Algorithm::direc[i] << std::endl;
			robot->MoveForward();
		}
		else if(tempdir == 'e' && fp::Algorithm::direc[i] == 's' && maze_algo.South[tempx][tempy] == false){
			std::cerr << "robot " << robot->get_x() << ' ' << robot->get_y() << ' ' << robot->GetDirection() << " Next -> ";
			std::cerr << fp::Algorithm::X[i] << ' ' << fp::Algorithm::Y[i] << ' ' << fp::Algorithm::direc[i] << std::endl;
			robot->TurnRight();
			robot->MoveForward();
		}
		else if(tempdir == 'e' && fp::Algorithm::direc[i] == 'n' && maze_algo.North[tempx][tempy] == false){
			std::cerr << "robot " << robot->get_x() << ' ' << robot->get_y() << ' ' << robot->GetDirection() << " Next -> ";
			std::cerr << fp::Algorithm::X[i] << ' ' << fp::Algorithm::Y[i] << ' ' << fp::Algorithm::direc[i] << std::endl;
			robot->TurnLeft();
			robot->MoveForward();
		}
		else if(tempdir == 'e' && fp::Algorithm::direc[i] == 'w' && maze_algo.West[tempx][tempy] == false){
			std::cerr << "robot " << robot->get_x() << ' ' << robot->get_y() << ' ' << robot->GetDirection() << " Next -> ";
			std::cerr << fp::Algorithm::X[i] << ' ' << fp::Algorithm::Y[i] << ' ' << fp::Algorithm::direc[i] << std::endl;
			robot->TurnLeft();
			robot->TurnLeft();
			robot->MoveForward();
		}
		
		// Movement if Robot is facing South direction
		else if(tempdir == 's' && fp::Algorithm::direc[i] == 's' && maze_algo.South[tempx][tempy] == false){
			std::cerr << "robot " << robot->get_x() << ' ' << robot->get_y() << ' ' << robot->GetDirection() << " Next -> ";
			std::cerr << fp::Algorithm::X[i] << ' ' << fp::Algorithm::Y[i] << ' ' << fp::Algorithm::direc[i] << std::endl;
			robot->MoveForward();
		}
		else if(tempdir == 's' && fp::Algorithm::direc[i] == 'e' && maze_algo.East[tempx][tempy] == false){
			std::cerr << "robot " << robot->get_x() << ' ' << robot->get_y() << ' ' << robot->GetDirection() << " Next -> ";
			std::cerr << fp::Algorithm::X[i] << ' ' << fp::Algorithm::Y[i] << ' ' << fp::Algorithm::direc[i] << std::endl;
			robot->TurnLeft();
			robot->MoveForward();
		}
		else if(tempdir == 's' && fp::Algorithm::direc[i] == 'w' && maze_algo.West[tempx][tempy] == false){
			std::cerr << "robot " << robot->get_x() << ' ' << robot->get_y() << ' ' << robot->GetDirection() << " Next -> ";
			std::cerr << fp::Algorithm::X[i] << ' ' << fp::Algorithm::Y[i] << ' ' << fp::Algorithm::direc[i] << std::endl;
			robot->TurnRight();
			robot->MoveForward();
		}
		else if(tempdir == 's' && fp::Algorithm::direc[i] == 'n' && maze_algo.North[tempx][tempy] == false){
			std::cerr << "robot " << robot->get_x() << ' ' << robot->get_y() << ' ' << robot->GetDirection() << " Next -> ";
			std::cerr << fp::Algorithm::X[i] << ' ' << fp::Algorithm::Y[i] << ' ' << fp::Algorithm::direc[i] << std::endl;
			robot->TurnLeft();
			robot->TurnLeft();
			robot->MoveForward();
		}
		
		// Movement if Robot is facing East direction
		else if(tempdir == 'w' && fp::Algorithm::direc[i] == 'w' && maze_algo.West[tempx][tempy] == false){
			std::cerr << "robot " << robot->get_x() << ' ' << robot->get_y() << ' ' << robot->GetDirection() << " Next -> ";
			std::cerr << fp::Algorithm::X[i] << ' ' << fp::Algorithm::Y[i] << ' ' << fp::Algorithm::direc[i] << std::endl;
			robot->MoveForward();
		}
		else if(tempdir == 'w' && fp::Algorithm::direc[i] == 'n' && maze_algo.North[tempx][tempy] == false){
			std::cerr << "robot " << robot->get_x() << ' ' << robot->get_y() << ' ' << robot->GetDirection() << " Next -> ";
			std::cerr << fp::Algorithm::X[i] << ' ' << fp::Algorithm::Y[i] << ' ' << fp::Algorithm::direc[i] << std::endl;
			robot->TurnRight();
			robot->MoveForward();
		}
		else if(tempdir == 'w' && fp::Algorithm::direc[i] == 's' && maze_algo.South[tempx][tempy] == false){
			std::cerr << "robot " << robot->get_x() << ' ' << robot->get_y() << ' ' << robot->GetDirection() << " Next -> ";
			std::cerr << fp::Algorithm::X[i] << ' ' << fp::Algorithm::Y[i] << ' ' << fp::Algorithm::direc[i] << std::endl;
			robot->TurnLeft();
			robot->MoveForward();
		}
		else if(tempdir == 'w' && fp::Algorithm::direc[i] == 'e' && maze_algo.East[tempx][tempy] == false){
			std::cerr << "robot " << robot->get_x() << ' ' << robot->get_y() << ' ' << robot->GetDirection() << " Next -> ";
			std::cerr << fp::Algorithm::X[i] << ' ' << fp::Algorithm::Y[i] << ' ' << fp::Algorithm::direc[i] << std::endl;
			robot->TurnLeft();
			robot->TurnLeft();
			robot->MoveForward();
		}
		else
			break;
		
//		if(tempx == fp::Algorithm::X[i] && tempy == fp::Algorithm::Y[i] && tempdir == fp::Algorithm::direc[i])
//		cerr<<"MoveRobot : Maze was at ("<<tempx<<","<<tempy<<") Direction : "<<tempdir<<" as North = "<<maze_algo.North[tempx][tempy]<<", East = "<<maze_algo.East[tempx][tempy]<<", West = "<<maze_algo.West[tempx][tempy]<<", South = "<<maze_algo.South[tempx][tempy]<<endl;
//		maze_algo.ReadMaze(tempx,tempy,tempdir);
//		cerr<<"MoveRobot : Maze changed at ("<<tempx<<","<<tempy<<") Direction : "<<tempdir<<" as North = "<<maze_algo.North[tempx][tempy]<<", East = "<<maze_algo.East[tempx][tempy]<<", West = "<<maze_algo.West[tempx][tempy]<<", South = "<<maze_algo.South[tempx][tempy]<<endl;
	cerr<<"----------------------------------"<<endl;
	}
}

void fp::Algorithm::SolveMaze(fp::Maze& maze, std::shared_ptr<fp::LandBasedRobot> robot){
	while(fp::Algorithm::goal_flag==true ){
		cerr<<"Solve Maze started "<<endl;
		fp::Algorithm::GenerateSequence(maze,robot);
		cerr<<"Generate sequence finished "<<endl;
		fp::Algorithm::MoveRobot(maze,robot);
		if ((robot->get_x() == 7 && robot->get_y() == 7) || (robot->get_x() == 7 && robot->get_y() == 8) || (robot->get_x() == 8 && robot->get_y() == 8) || (robot->get_x() == 8 && robot->get_y() == 7)) {break;}
	}
}
