#include "Algorithm.h"
#include "../Maze/Maze.h"
#include "../API/API.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//fp::Maze maze_algo;

struct Node{
    int px,py;
    int cx,cy;
    char dir;
    string actions;
};


vector<Node> valid;

void fp::Algorithm::ValidNodes(fp::Maze maze_algo,int x,int y, char dir){
    Node temp;
    valid.clear();
    
    // If robot is facing North
    if(dir=='n'){
    if(maze_algo.North[x][y]!=1){
        temp.px=x;
        temp.py=y;
        temp.cx=x;
        temp.cy=y+1;
        temp.dir='n';
        if(temp.cy>=0 && temp.cy<=15){
        temp.actions="Go Forward";// Action = Go Forward
        valid.push_back(temp);
        temp.actions.clear();
        }
    }
    if(maze_algo.West[x][y]!=1){
        temp.px=x;
        temp.py=y;
        temp.cx=x-1;
        temp.cy=y;
        temp.dir='w';
        if(temp.cx>=0 && temp.cx<=15){
        temp.actions="Turn Left";
         // Action = Turn Left and Go forward
        valid.push_back(temp);
        temp.actions.clear();
        }
    }
    if(maze_algo.East[x][y]!=1){
        temp.px=x;
        temp.py=y;
        temp.cx=x+1;
        temp.cy=y;
        temp.dir='e';
        if(temp.cx>=0 && temp.cx<=15){
        temp.actions="Turn Right";
        // Action = Turn Right and Go forward
        valid.push_back(temp);
        temp.actions.clear();
        }
    }
    }
    
    // If robot is facing east
    else if(dir=='e'){
    if(maze_algo.East[x][y]!=1){
        temp.px=x;
        temp.py=y;
        temp.cx=x+1;
        temp.cy=y;
        temp.dir='e';
        if(temp.cx>=0 && temp.cx<=15){
        temp.actions="Go Forward"; // Action = Go forward
        valid.push_back(temp);
        temp.actions.clear();
        }
    }
    if(maze_algo.North[x][y]!=1){
        temp.px=x;
        temp.py=y;
        temp.cx=x;
        temp.cy=y+1;
        temp.dir='n';
        if(temp.cy>=0 && temp.cy<=15){
        temp.actions="Turn Left";
        // Action = Turn Left and Go forward
        valid.push_back(temp);
        temp.actions.clear();
        }
    }
    if(maze_algo.South[x][y]!=1){
        temp.px=x;
        temp.py=y;
        temp.cx=x;
        temp.cy=y-1;
        temp.dir='s';
        if(temp.cy>=0 && temp.cy<=15){
        temp.actions="Turn Right";
        // Action = Turn right and Go forward
        valid.push_back(temp);
        temp.actions.clear();
        }
    }
    }
    
    // If robot is facing West
    else if(dir=='w'){
    if(maze_algo.North[x][y]!=1){
        temp.px=x;
        temp.py=y;
        temp.cx=x;
        temp.cy=y+1;
        temp.dir='n';
        if(temp.cy>=0 && temp.cy<=15){
        temp.actions="Turn Right";
        // Action = Turn right and Go forward
        valid.push_back(temp);
        temp.actions.clear();
        }
    }
    if(maze_algo.South[x][y]!=1){
        temp.px=x;
        temp.py=y;
        temp.cx=x;
        temp.cy=y-1;
        temp.dir='s';
        if(temp.cy>=0 && temp.cy<=15){
        temp.actions="Turn Left";
        // Action = Turn Left and Go forward
        valid.push_back(temp);
        temp.actions.clear();
        }
    }
    if(maze_algo.East[x][y]!=1){
        temp.px=x;
        temp.py=y;
        temp.cx=x-1;
        temp.cy=y;
        temp.dir='w';
        if(temp.cx>=0 && temp.cx<=15){
        temp.actions="Go Forward";// Action = Go forward
        valid.push_back(temp);
        temp.actions.clear();
        }
    }
    }
    
    // If robot is facing South
    if(dir=='s'){
    if(maze_algo.South[x][y]!=1){
        temp.px=x;
        temp.py=y;
        temp.cx=x;
        temp.cy=y-1;
        temp.dir='s';
        if(temp.cy>=0 && temp.cy<=15){
        temp.actions="Go Forward";// Action = Go forward
        valid.push_back(temp);
        temp.actions.clear();
        }
    }
    if(maze_algo.West[x][y]!=1){
        temp.px=x;
        temp.py=y;
        temp.cx=x-1;
        temp.cy=y;
        temp.dir='w';
        if(temp.cx>=0 && temp.cx<=15){
        temp.actions="Turn Right";
        // Action = Turn right and Go forward
        valid.push_back(temp);
        temp.actions.clear();
        }
    }
    if(maze_algo.East[x][y]!=1){
        temp.px=x;
        temp.py=y;
        temp.cx=x+1;
        temp.cy=y;
        temp.dir='e';
        if(temp.cx>=0 && temp.cx<=15){
        temp.actions="Turn Left";
        // Action = Turn Left and Go forward
        valid.push_back(temp);
        temp.actions.clear();
        }
    }
    }
}

void fp::Algorithm::GenerateSequence(fp::Maze maze_algo, int Start_x, int Start_y, char Start_dir)
{
  //Node a;
//  int Start_x{0},Start_y{0},Goal_x{4},Goal_y{2};
//  char Start_dir{'n'};
  bool seen[16][16]{false};
  bool flag{false};
  vector<Node> queue;
  
  Node temp_node;
  temp_node.px = 100;
  temp_node.py = 100;
  temp_node.cx = Start_x;
  temp_node.cy = Start_y;
  temp_node.dir = Start_dir;
  cerr<<"Starting x : "<<Start_x<<" y : "<<Start_y<<" dir : "<<Start_dir<<endl;
  temp_node.actions.clear();
  seen[temp_node.cx][temp_node.cy] = 1;
  queue.push_back(temp_node);
  
  for(int i=0 ; i<queue.size() ; i++){
    //   cout<<"Iteration : "<<i<<endl;
    //   cout<<"exploring ("<<queue[i].cx<<","<<queue[i].cy<<")"<<endl;
      ValidNodes(maze_algo,queue[i].cx,queue[i].cy,queue[i].dir);
      for(int k=0 ; k<valid.size() ; k++){
          if(seen[valid[k].cx][valid[k].cy]!=1){
            seen[valid[k].cx][valid[k].cy] = 1;
            queue.push_back(valid[k]);
            if ((valid[k].cx == 7 && valid[k].cy == 7) || (valid[k].cx == 7 && valid[k].cy == 8) || (valid[k].cx == 8 && valid[k].cy == 8) || (valid[k].cx == 8 && valid[k].cy == 7)){
                // cout<<"Goal Reached "<<endl;
                flag=true;
                break;
            }
          }
      }
//       
  if(flag==true){
      break;
  }
  }
  if (flag==false){
      cout<<"goal not found";
  }
  else if (flag==true){
//       cout<<"-----------------------"<<endl;
      
//       for(int l=0;l<queue.size();l++){
//       cout<<"("<<queue[l].px<<","<<queue[l].py<<")  ("<<queue[l].cx<<","<<queue[l].cy<<")   "<<queue[l].dir<<"  ";
//       for(int j=0;j<queue[l].actions.size();j++)
//       cout<<queue[l].actions[j]<<" ";
//       cout<<endl;
//       for(int m=4;m<=0;m++){
//           for(int n=0;n<5;n++)
//           cout<<seen[n][m]<<" ";
//           cout<<endl;
//       }
//   }
//   cout<<"-----------------------"<<endl;
      vector<int> X;
      vector<int> Y;
	  vector<char> direc;
      vector<string> Actions;
      X.push_back(queue[queue.size()-1].cx);
      Y.push_back(queue[queue.size()-1].cy);
	  Actions.push_back("");
      X.push_back(queue[queue.size()-1].px);
      Y.push_back(queue[queue.size()-1].py);
	  Actions.push_back(queue[queue.size()-1].actions);
	  direc.push_back(queue[queue.size()-1].dir);
      
      int a=queue[queue.size()-1].px;
      int b=queue[queue.size()-1].py;
      int i=queue.size()-1;
    //   auto itx = X.insert(X.begin(), queue[queue.size()-1].px);
    //   auto ity = Y.insert(Y.begin(), queue[queue.size()-1].py);
      while(1){
          if(a==queue[i].cx && b==queue[i].cy){
            //   X.insert(itx, queue[i].px);
            //   Y.insert(ity, queue[i].py);
              X.push_back(queue[i].px);
              Y.push_back(queue[i].py);
              Actions.push_back(queue[i].actions);
			  direc.push_back(queue[i].dir);
              a=queue[i].px;
              b=queue[i].py;
          }
          i=i-1;
          if(a==Start_x && b==Start_y){
              break;
          }
		  direc.push_back('n');
        //   cout<<" b = "<<b<<" i = "<<i<<endl; 
      }
      std::reverse(X.begin(),X.end());
	  std::reverse(direc.begin(),direc.end());
      std::reverse(Y.begin(),Y.end());

    //   for (int i=0;i<X.size();i++){
    //       cout<<X[i]<<","<<Y[i]<<"  ";
    //   }
    //   cout<<endl;
      std::reverse(Actions.begin(),Actions.end());
      for (int i=0;i<Actions.size();i++){
          if(Actions[i]=="Go Forward"){
			  maze_algo.ReadMaze(X[i],Y[i],direc[i]);
			  cerr<<"x : "<<X[i]<<" y : "<<Y[i]<<" dir : "<<direc[i]<<" Action : "<<Actions[i]<<endl;
			  fp::API::moveForward();
			  
		  }
		  else if(Actions[i]=="Turn Left"){
			  maze_algo.ReadMaze(X[i],Y[i],direc[i]);
			  fp::API::turnLeft();
			  fp::API::moveForward();
			  
		  }
		  else if(Actions[i]=="Turn Right"){
			  maze_algo.ReadMaze(X[i],Y[i],direc[i]);
			  fp::API::turnRight();
			  fp::API::moveForward();
			  
		  }
      }
  }
  
}

