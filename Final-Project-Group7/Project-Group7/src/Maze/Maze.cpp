#include "Maze.h"
#include "../API/API.h"
#include <vector>

// Maze maze;
//Create for 2D vectors for North, South, East and West
//
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
//                      North[x][y] = API::wallFront();
//                      East[x][y] = API::wallRight();
//                      West[x][y] = API::wallLeft();
                      if(API::wallFront()==true){
                            API::setWall(x,y,'n');
							North[x][y] = true;
                          }
                      if(API::wallRight()){
                            API::setWall(x,y,'e');
							East[x][y] = true;
                          }
                      if(API::wallLeft()){
                            API::setWall(x,y,'w');
							West[x][y] = true;
                          }
                  }
                  if(dir == 'e'){
                      North[x][y] = API::wallLeft();
                      East[x][y] = API::wallFront();
                      South[x][y] = API::wallRight();
                      if(API::wallFront()){
                            API::setWall(x,y,'e');
                          }
                      if(API::wallRight()){
                            API::setWall(x,y,'s');
                          }
                      if(API::wallLeft()){
                            API::setWall(x,y,'n');
                          }
                  }
                  if(dir == 'w'){
                      West[x][y] = API::wallFront();
                      North[x][y] = API::wallRight();
                      South[x][y] = API::wallLeft();
                      if(API::wallFront()){
                            API::setWall(x,y,'w');
                          }
                      if(API::wallRight()){
                            API::setWall(x,y,'n');
                          }
                      if(API::wallLeft()){
                            API::setWall(x,y,'s');
                          }
                  }
                  if(dir == 's'){
                      South[x][y] = API::wallFront();
                      East[x][y] = API::wallLeft();
                      West[x][y] = API::wallRight();
                      if(API::wallFront()){
                            API::setWall(x,y,'s');
                          }
                      if(API::wallRight()){
                            API::setWall(x,y,'w');
                          }
                      if(API::wallLeft()){
                            API::setWall(x,y,'e');
                          }
                  }
}
// this function should modify all the four static wall matrix.
//void fp::Maze::colorPath(std::vector<int> &X, std::vector<int> &Y){
//    for(auto num:X)
//        API::setColor(X[num],Y[num],'b'); //Sets color to the path x,y as blue. Note: the index of x and y are considered to be the same and thus, iterating variable doesnt matter
//        
//}

