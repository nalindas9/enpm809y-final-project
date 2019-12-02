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
        }
    }
    if(maze_algo.West[x][y]!=1){
        temp.px=x;
        temp.py=y;
        temp.cx=x-1;
        temp.cy=y;
        temp.dir='w';
        if(temp.cx>=0 && temp.cx<=15){
        temp.actions="Go Forward";// Action = Go forward
        valid.push_back(temp);
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
        }
    }
    }
}

void fp::Algorithm::GenerateSequence(fp::Maze maze_algo, fp::LandBasedWheeled robot)
{
  //Node a;
  int Start_x{robot.get_x()},Start_y{robot.get_y()};
  char Start_dir{robot.get_direction()};
  //maze_algo.MazeInitialisation();
  while (1)
  {
	  API::clearAllColor();
  bool seen[16][16]{false};
  bool flag{false};
  vector<Node> queue;
  
  Node temp_node;
  temp_node.px = 100;
  temp_node.py = 100;
  temp_node.cx = Start_x;
  temp_node.cy = Start_y;
  temp_node.dir = Start_dir;
//  cerr<<"Starting x : "<<Start_x<<" y : "<<Start_y<<" dir : "<<Start_dir<<endl;
  temp_node.actions = "";
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
//       cerr<<"-----------------------"<<endl;
//      
//       for(int l=0;l<queue.size();l++){
//       cerr<<"("<<queue[l].px<<","<<queue[l].py<<")  ("<<queue[l].cx<<","<<queue[l].cy<<")   "<<queue[l].dir<<"  "<<queue[l].actions<<endl;
//       for(int m=4;m<=0;m++){
//           for(int n=0;n<5;n++)
//           cout<<seen[n][m]<<" ";
//           cout<<endl;
//       }
//   }
//   cerr<<"-----------------------"<<endl;
//cerr<<" Direction last : "<<queue[queue.size()-1].dir<<endl;

      vector<int> X;
      vector<int> Y;
	  vector<char> direc;
      vector<string> Actions;
//      X.push_back(queue[queue.size()-1].cx);
//      Y.push_back(queue[queue.size()-1].cy);
//	  Actions.push_back("");
//	  direc.push_back('a');
      X.push_back(queue[queue.size()-1].px);
      Y.push_back(queue[queue.size()-1].py);
	  Actions.push_back(queue[queue.size()-1].actions);
	  direc.push_back(queue[queue.size()-1].dir);
//	  cerr<<" Direction appended : "<<queue[queue.size()-1].dir<<endl;
//      cerr<<" Direction in direc : "<<direc[0]<<endl;
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
		  //direc.push_back('n');
        //   cout<<" b = "<<b<<" i = "<<i<<endl; 
      }
//	  X.pop_back();
//	  Y.pop_back();
      std::reverse(X.begin(),X.end());
	  std::reverse(direc.begin(),direc.end());
      std::reverse(Y.begin(),Y.end());

    //   for (int i=0;i<X.size();i++){
    //       cout<<X[i]<<","<<Y[i]<<"  ";
    //   }
    //   cout<<endl;
      std::reverse(Actions.begin(),Actions.end());
//	  cerr<<"============="<<endl;
//	  for(int i=0;i<direc.size();i++){
//		  cerr<<"Direc ["<<i<<"] = "<<direc[i]<<endl;
//	  }
	  maze_algo.colorPath(X,Y);
	  cerr<<"============="<<endl;
	  for(int i=0;i<Actions.size();i++){
		  cerr<<"("<<X[i]<<","<<Y[i]<<")	"<<direc[i]<<"	"<<Actions[i]<<endl;
	  }
//	  cerr<<"============="<<endl;
//	  cerr<<" Action Size : "<<Actions.size()<<endl;
      for (int i=0;i<Actions.size();i++){
          if(Actions[i]=="Go Forward"){
			  maze_algo.ReadMaze(X[i],Y[i],direc[i]);
//			  cerr<<"\n Display Maze matrix : "<<endl;
//	  cerr<<" North : "<<endl;
//	  for(int k=0;k<16;k++){
//		  for (int l=0;l<16;l++){
//			  cerr<<maze_algo.North[k][l] <<" ";
//		  }
//		  cerr<<endl;
//	  }
//	  cerr<<" East : "<<endl;
//	  	  for(int k=0;k<16;k++){
//		  for (int l=0;l<16;l++){
//			  cerr<<maze_algo.East[k][l] <<" ";
//		  }
//		  cerr<<endl;
//	  }
//	  cerr<<" South : "<<endl;
//	  	  for(int k=0;k<16;k++){
//		  for (int l=0;l<16;l++){
//			  cerr<<maze_algo.South[k][l] <<" ";
//		  }
//		  cerr<<endl;
//	  }
//	  cerr<<" West : "<<endl;
//	  	  for(int k=0;k<16;k++){
//		  for (int l=0;l<16;l++){
//			  cerr<<maze_algo.West[k][l]<<" ";
//		  }
//		  cerr<<endl;
//	  }
  
			  if(direc[i]=='n'){
//			  cerr<<"x : "<<X[i]<<" y : "<<Y[i]<<" dir : "<<direc[i]<<" Action : "<<Actions[i]<<" wall check : "<<maze_algo.North[X[i]][Y[i]]<<endl;
			  if (maze_algo.East[X[i]][Y[i]]==1 && maze_algo.West[X[i]][Y[i]]==1 && maze_algo.North[X[i]][Y[i]]==1){
				  Start_x=X[i];
				  Start_y=Y[i];
				  fp::API::turnLeft();
				  fp::API::turnLeft();
				  Start_dir = 's';
				  break;
			  }
			  else if(maze_algo.North[X[i]][Y[i]]==1){
				  Start_x=X[i];
				  Start_y=Y[i];
				  Start_dir=direc[i];
				  break;
			  }
			  else{
				  fp::API::moveForward();
			  }
			  }
			  else if(direc[i]=='e'){
//			  cerr<<"x : "<<X[i]<<" y : "<<Y[i]<<" dir : "<<direc[i]<<" Action : "<<Actions[i]<<endl;
			  if (maze_algo.North[X[i]][Y[i]]==1 && maze_algo.South[X[i]][Y[i]]==1 && maze_algo.East[X[i]][Y[i]]==1){
				  Start_x=X[i];
				  Start_y=Y[i];
				  fp::API::turnLeft();
				  fp::API::turnLeft();
				  Start_dir = 'w';
				  break;
			  }
			  else if(maze_algo.East[X[i]][Y[i]]==1){
				  Start_x=X[i];
				  Start_y=Y[i];
				  Start_dir=direc[i];
				  break;
			  }
			  else{
				  fp::API::moveForward();
			  }
			  }
			  else if(direc[i]=='w'){
//			  cerr<<"x : "<<X[i]<<" y : "<<Y[i]<<" dir : "<<direc[i]<<" Action : "<<Actions[i]<<endl;
			  if (maze_algo.North[X[i]][Y[i]]==1 && maze_algo.South[X[i]][Y[i]]==1 && maze_algo.West[X[i]][Y[i]]==1){
				  Start_x=X[i];
				  Start_y=Y[i];
				  fp::API::turnLeft();
				  fp::API::turnLeft();
				  Start_dir = 'e';
				  break;
			  }
			  else if(maze_algo.West[X[i]][Y[i]]==1){
				  Start_x=X[i];
				  Start_y=Y[i];
				  Start_dir=direc[i];
				  break;
			  }
			  else{
				  fp::API::moveForward();
			  }
			  }
			  else if(direc[i]=='s'){
//			  cerr<<"x : "<<X[i]<<" y : "<<Y[i]<<" dir : "<<direc[i]<<" Action : "<<Actions[i]<<endl;
			  if (maze_algo.East[X[i]][Y[i]]==1 && maze_algo.West[X[i]][Y[i]]==1 && maze_algo.South[X[i]][Y[i]]==1){
				  Start_x=X[i];
				  Start_y=Y[i];
				  fp::API::turnLeft();
				  fp::API::turnLeft();
				  Start_dir = 'n';
				  break;
			  }
			  else if(maze_algo.South[X[i]][Y[i]]==1){
				  Start_x=X[i];
				  Start_y=Y[i];
				  Start_dir=direc[i];
				  break;
			  }
			  else{
				  fp::API::moveForward();
			  }
			  }
			  }
			  
		  else if(Actions[i]=="Turn Left"){
			  maze_algo.ReadMaze(X[i],Y[i],direc[i]);
//			  cerr<<"\n Display Maze matrix : "<<endl;
//	  cerr<<" North : "<<endl;
//	  for(int k=0;k<16;k++){
//		  for (int l=0;l<16;l++){
//			  cerr<<maze_algo.North[k][l] <<" ";
//		  }
//		  cerr<<endl;
//	  }
//	  cerr<<" East : "<<endl;
//	  	  for(int k=0;k<16;k++){
//		  for (int l=0;l<16;l++){
//			  cerr<<maze_algo.East[k][l]<<" ";
//		  }
//		  cerr<<endl;
//	  }
//	  cerr<<" South : "<<endl;
//	  	  for(int k=0;k<16;k++){
//		  for (int l=0;l<16;l++){
//			  cerr<<maze_algo.South[k][l] <<" ";
//		  }
//		  cerr<<endl;
//	  }
//	  cerr<<" West : "<<endl;
//	  	  for(int k=0;k<16;k++){
//		  for (int l=0;l<16;l++){
//			  cerr<<maze_algo.West[k][l] <<" ";
//		  }
//		  cerr<<endl;
//	  }
//  
			  if(direc[i]=='w'){
//				cerr<<"x : "<<X[i]<<" y : "<<Y[i]<<" dir : "<<direc[i]<<" Action : "<<Actions[i]<<endl;
			  if (maze_algo.North[X[i]][Y[i]]==1 && maze_algo.West[X[i]][Y[i]]==1 && maze_algo.South[X[i]][Y[i]]==1){
				  Start_x=X[i];
				  Start_y=Y[i];
				  fp::API::turnLeft();
				  fp::API::turnLeft();
				  Start_dir = 'e';
				  break;
			  }
			  else if(maze_algo.South[X[i]][Y[i]]==1){
				  Start_x=X[i];
				  Start_y=Y[i];
				  Start_dir=direc[i];
				  //fp::API::turnLeft();
				  break;
			  }
			  else{
				fp::API::turnLeft();
				fp::API::moveForward();
			  }
			  }
			  else if(direc[i]=='n'){
//			  cerr<<"x : "<<X[i]<<" y : "<<Y[i]<<" dir : "<<direc[i]<<" Action : "<<Actions[i]<<endl;
			  if (maze_algo.East[X[i]][Y[i]]==1 && maze_algo.West[X[i]][Y[i]]==1 && maze_algo.North[X[i]][Y[i]]==1){
				  Start_x=X[i];
				  Start_y=Y[i];
				  fp::API::turnLeft();
				  fp::API::turnLeft();
				  Start_dir = 's';
				  break;
			  }
			  else if(maze_algo.West[X[i]][Y[i]]==1){
				  Start_x=X[i];
				  Start_y=Y[i];
				  Start_dir=direc[i];
				  //fp::API::turnLeft();
				  break;
			  }
			  else{
				fp::API::turnLeft();
				fp::API::moveForward();
			  }
			  }
			  else if(direc[i]=='e'){
//			  cerr<<"x : "<<X[i]<<" y : "<<Y[i]<<" dir : "<<direc[i]<<" Action : "<<Actions[i]<<endl;
			  if (maze_algo.East[X[i]][Y[i]]==1 && maze_algo.North[X[i]][Y[i]]==1 && maze_algo.South[X[i]][Y[i]]==1){
				  Start_x=X[i];
				  Start_y=Y[i];
				  fp::API::turnLeft();
				  fp::API::turnLeft();
				  Start_dir = 'w';
				  break;
			  }
			  else if(maze_algo.North[X[i]][Y[i]]==1){
				  Start_x=X[i];
				  Start_y=Y[i];
				  Start_dir=direc[i];
				  //fp::API::turnLeft();
				  break;
			  }
			  else{
				fp::API::turnLeft();
				fp::API::moveForward();
			  }
			  }
			  else if(direc[i]=='s'){
//			  cerr<<"x : "<<X[i]<<" y : "<<Y[i]<<" dir : "<<direc[i]<<" Action : "<<Actions[i]<<endl;
			  if (maze_algo.East[X[i]][Y[i]]==1 && maze_algo.West[X[i]][Y[i]]==1 && maze_algo.South[X[i]][Y[i]]==1){
				  Start_x=X[i];
				  Start_y=Y[i];
				  fp::API::turnLeft();
				  fp::API::turnLeft();
				  Start_dir = 'n';
				  break;
			  }
			  else if(maze_algo.East[X[i]][Y[i]]==1){
				  Start_x=X[i];
				  Start_y=Y[i];
				  Start_dir=direc[i];
				  //fp::API::turnLeft();
				  break;
			  }
			  else{
				fp::API::turnLeft();
				fp::API::moveForward();
			  }
			  }
		  }
		  
		  else if(Actions[i]=="Turn Right"){
			  maze_algo.ReadMaze(X[i],Y[i],direc[i]);
//			  cerr<<"\n Display Maze matrix : "<<endl;
//	  cerr<<" North : "<<endl;
//	  for(int k=0;k<16;k++){
//		  for (int l=0;l<16;l++){
//			  cerr<<maze_algo.North[k][l] <<" ";
//		  }
//		  cerr<<endl;
//	  }
//	  cerr<<" East : "<<endl;
//	  	  for(int k=0;k<16;k++){
//		  for (int l=0;l<16;l++){
//			  cerr<<maze_algo.East[k][l]<<" ";
//		  }
//		  cerr<<endl;
//	  }
//	  cerr<<" South : "<<endl;
//	  	  for(int k=0;k<16;k++){
//		  for (int l=0;l<16;l++){
//			  cerr<<maze_algo.South[k][l] <<" ";
//		  }
//		  cerr<<endl;
//	  }
//	  cerr<<" West : "<<endl;
//	  	  for(int k=0;k<16;k++){
//		  for (int l=0;l<16;l++){
//			  cerr<<maze_algo.West[k][l]<<" ";
//		  }
//		  cerr<<endl;
//	  }
  
			  if(direc[i]=='n'){
//			  cerr<<"x : "<<X[i]<<" y : "<<Y[i]<<" dir : "<<direc[i]<<" Action : "<<Actions[i]<<endl;
			  if (maze_algo.East[X[i]][Y[i]]==1 && maze_algo.West[X[i]][Y[i]]==1 && maze_algo.North[X[i]][Y[i]]==1){
				  Start_x=X[i];
				  Start_y=Y[i];
				  fp::API::turnLeft();
				  fp::API::turnLeft();
				  Start_dir = 's';
				  break;
			  }
			  else if(maze_algo.East[X[i]][Y[i]]==1){
				  Start_x=X[i];
				  Start_y=Y[i];
				  Start_dir=direc[i];
				  ///fp::API::turnRight();
				  break;
			  }
			  else{
				fp::API::turnRight();
				fp::API::moveForward();
			  }
			  }
			  else if(direc[i]=='e'){
//			  cerr<<"x : "<<X[i]<<" y : "<<Y[i]<<" dir : "<<direc[i]<<" Action : "<<Actions[i]<<endl;
			  if (maze_algo.East[X[i]][Y[i]]==1 && maze_algo.South[X[i]][Y[i]]==1 && maze_algo.North[X[i]][Y[i]]==1){
				  Start_x=X[i];
				  Start_y=Y[i];
				  fp::API::turnLeft();
				  fp::API::turnLeft();
				  Start_dir = 'w';
				  break;
			  }
			  else if(maze_algo.South[X[i]][Y[i]]==1){
				  Start_x=X[i];
				  Start_y=Y[i];
				  Start_dir=direc[i];
				  //fp::API::turnRight();
				  break;
			  }
			  else{
				fp::API::turnRight();
				fp::API::moveForward();
			  }
			  }
			  else if(direc[i]=='s'){
//			  cerr<<"x : "<<X[i]<<" y : "<<Y[i]<<" dir : "<<direc[i]<<" Action : "<<Actions[i]<<endl;
			  if (maze_algo.East[X[i]][Y[i]]==1 && maze_algo.West[X[i]][Y[i]]==1 && maze_algo.South[X[i]][Y[i]]==1){
				  Start_x=X[i];
				  Start_y=Y[i];
				  fp::API::turnLeft();
				  fp::API::turnLeft();
				  Start_dir = 'n';
				  break;
			  }
			  else if(maze_algo.West[X[i]][Y[i]]==1){
				  Start_x=X[i];
				  Start_y=Y[i];
				  Start_dir=direc[i];
				  //fp::API::turnRight();
				  break;
			  }
			  else{
				fp::API::turnRight();
				fp::API::moveForward();
			  }
			  }
			  else if(direc[i]=='w'){
//			  cerr<<"x : "<<X[i]<<" y : "<<Y[i]<<" dir : "<<direc[i]<<" Action : "<<Actions[i]<<endl;
			  if (maze_algo.South[X[i]][Y[i]]==1 && maze_algo.West[X[i]][Y[i]]==1 && maze_algo.North[X[i]][Y[i]]==1){
				  Start_x=X[i];
				  Start_y=Y[i];
				  fp::API::turnLeft();
				  fp::API::turnLeft();
				  Start_dir = 'e';
				  break;
			  }
			  else if(maze_algo.North[X[i]][Y[i]]==1){
				  Start_x=X[i];
				  Start_y=Y[i];
				  Start_dir=direc[i];
				  //fp::API::turnRight();
				  break;
			  }
			  else{
				fp::API::turnRight();
				fp::API::moveForward();
			  }
			  }
			  }
		  }
      }
  }
}
  
