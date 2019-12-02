#include "Maze.h"
#include "../API/API.h"
#include <vector>

// Maze maze;
//Create for 2D vectors for North, South, East and West
//
//void fp::Maze::MazeInitialisation(){
//		North[16][16]={};
//		South[16][16]={};
//		East[16][16]={};
//		West[16][16]={};
//		for(int i=0 ; i<16 ; i++){
//			for(int j=0 ; j<16 ; j++){
//				if(i==0) {
//					West[i][j]=true;
//				}
//				if(i==15){
//					East[i][j]=true;
//				}
//				if(j==0){
//					South[i][j]=true;
//				}
//				if(j==15){
//					North[i][j]=true;
//				}
//			}
//		}
//	}
//
fp::Maze::Maze(){
		fp::Maze::North[16][16]={};
		fp::Maze::South[16][16]={};
		fp::Maze::East[16][16]={};
		fp::Maze::West[16][16]={};
		for(int i=0 ; i<16 ; i++){
			for(int j=0 ; j<16 ; j++){
				if(i==0) {
					fp::Maze::West[i][j]=true;
					API::setWall(i,j,'w');
					
				}
				else{
					fp::Maze::West[i][j]=false;
				}
				if(i==15){
					fp::Maze::East[i][j]=true;
					API::setWall(i,j,'e');
				}
				else{
					fp::Maze::East[i][j]=false;
				}
				if(j==0){
					fp::Maze::South[i][j]=true;
					//API::turnRight();
					API::setWall(i,j,'s');
				}
				else{
					fp::Maze::South[i][j]=false;
				}
				if(j==15){
					fp::Maze::North[i][j]=true;
					API::setWall(i,j,'n');
				}
				else{
					fp::Maze::North[i][j]=false;
				}
			}
		}
	}

void fp::Maze::ReadMaze(int x,int y,char d) // Inputs (x,y) position and output from getDirection() of the robot NOTE: The getDirection() must return direction according to the world frame
{
	
//			
//            maze.north_wall = API::wallFront();
//            maze.east_wall = API::wallRight();
//            maze.west_wall = API::wallLeft()
//            API::turnRight();
//            maze.south_wall = API::wallRight();
//            API::turnLeft();
//            x = x;
//            y = y;
            dir = d;
                  if(dir == 'n'){
//                      fp::Maze::North[x][y] = API::wallFront();
//                      fp::Maze::East[x][y] = API::wallRight();
//                      fp::Maze::West[x][y] = API::wallLeft();
                      if(API::wallFront()==true){
                            API::setWall(x,y,'n');
							fp::Maze::North[x][y] = true;
                          }
                      if(API::wallRight()){
                            API::setWall(x,y,'e');
							fp::Maze::East[x][y] = true;
                          }
                      if(API::wallLeft()){
                            API::setWall(x,y,'w');
							fp::Maze::West[x][y] = true;
                          }
                  }
                  if(dir == 'e'){
//                      fp::Maze::North[x][y] = API::wallLeft();
//                      fp::Maze::East[x][y] = API::wallFront();
//                      fp::Maze::South[x][y] = API::wallRight();
                      if(API::wallFront()){
                            API::setWall(x,y,'e');
							fp::Maze::East[x][y] = true;
                          }
                      if(API::wallRight()){
                            API::setWall(x,y,'s');
							fp::Maze::South[x][y] = true;
                          }
                      if(API::wallLeft()){
                            API::setWall(x,y,'n');
							fp::Maze::North[x][y] = true;
                          }
                  }
                  if(dir == 'w'){
//                      fp::Maze::West[x][y] = API::wallFront();
//                      fp::Maze::North[x][y] = API::wallRight();
//                      fp::Maze::South[x][y] = API::wallLeft();
                      if(API::wallFront()){
                            API::setWall(x,y,'w');
							fp::Maze::West[x][y] = true;
                          }
                      if(API::wallRight()){
                            API::setWall(x,y,'n');
							fp::Maze::North[x][y] = true;
                          }
                      if(API::wallLeft()){
                            API::setWall(x,y,'s');
							fp::Maze::South[x][y] = true;
                          }
                  }
                  if(dir == 's'){
//                      fp::Maze::South[x][y] = API::wallFront();
//                      fp::Maze::East[x][y] = API::wallLeft();
//                      fp::Maze::West[x][y] = API::wallRight();
                      if(API::wallFront()){
                            API::setWall(x,y,'s');
							fp::Maze::South[x][y] = true;
                          }
                      if(API::wallRight()){
                            API::setWall(x,y,'w');
							fp::Maze::West[x][y] = true;
                          }
                      if(API::wallLeft()){
                            API::setWall(x,y,'e');
							fp::Maze::East[x][y] = true;
                          }
                  }
}
// this function should modify all the four static wall matrix.
void fp::Maze::colorPath(std::vector<int> &X, std::vector<int> &Y){
    for(int i=0 ; i<X.size() ; i++)
        API::setColor(X[i],Y[i],'g'); //Sets color to the path x,y as blue. Note: the index of x and y are considered to be the same and thus, iterating variable doesnt matter
        
}

//void fp::Maze::ResetColor(){
//	for(int i=0;i<16;i++){
//		for(int j=0;j<16;j++){
//			API::clearAllColor()
//		}
//	}
//}

