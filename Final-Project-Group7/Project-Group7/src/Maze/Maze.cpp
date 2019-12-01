#include "Maze.h"
#include "../API/API.h"
#include <vector>

using namespace fp;

Maze maze;
//Create for 2D vectors for North, South, East and West

fp::Maze::ReadMaze(x,y,d) // Inputs (x,y) position and output from getDirection() of the robot NOTE: The getDirection() must return direction according to the world frame
{
	
//			
//            maze.north_wall = API::wallFront();
//            maze.east_wall = API::wallRight();
//            maze.west_wall = API::wallLeft()
//            API::turnRight();
//            maze.south_wall = API::wallRight();
//            API::turnLeft();
            maze.x = x;
            maze.y = y;
            maze.dir = d;
                  if(maze.dir == 'n'){
                      maze.North[maze.x][maze.y] = API::wallFront();
                      maze.East[maze.x][maze.y] = API::wallRight();
                      maze.West[maze.x][maze.y] = API::wallLeft();
                      if(API::wallFront()){
                            API::setWall(maze.x,maze.y,'n');
                          }
                      if(API::wallRight()){
                            API::setWall(maze.x,maze.y,'e');
                          }
                      if(API::wallLeft()){
                            API::setWall(maze.x,maze.y,'w');
                          }
                  }
                  if(maze.dir == 'e'){
                      maze.North[maze.x][maze.y] = API::wallLeft()
                      maze.East[maze.x][maze.y] = API::wallFront();
                      maze.South[maze.x][maze.y] = API::wallRight();
                      if(API::wallFront()){
                            API::setWall(maze.x,maze.y,'e');
                          }
                      if(API::wallRight()){
                            API::setWall(maze.x,maze.y,'s');
                          }
                      if(API::wallLeft()){
                            API::setWall(maze.x,maze.y,'n');
                          }
                  }
                  if(maze.dir == 'w'){
                      maze.West[maze.x][maze.y] = API::wallFront();
                      maze.North[maze.x][maze.y] = API::wallRight();
                      maze.South[maze.x][maze.y] = API::wallLeft();
                      if(API::wallFront()){
                            API::setWall(maze.x,maze.y,'w');
                          }
                      if(API::wallRight()){
                            API::setWall(maze.x,maze.y,'n');
                          }
                      if(API::wallLeft()){
                            API::setWall(maze.x,maze.y,'s');
                          }
                  }
                  if(maze.dir == 's'){
                      maze.South[maze.x][maze.y] = API::wallFront();
                      maze.East[maze.x][maze.y] = API::wallLeft();
                      maze.West[maze.x][maze.y] = API::wallRight();
                      if(API::wallFront()){
                            API::setWall(maze.x,maze.y,'s');
                          }
                      if(API::wallRight()){
                            API::setWall(maze.x,maze.y,'w');
                          }
                      if(API::wallLeft()){
                            API::setWall(maze.x,maze.y,'e');
                          }
                  }
}
// this function should modify all the four static wall matrix.
fp::Maze::colorPath(&X,&Y){
    for(auto num:X)
        API::setColor(X[num],Y[num],'b'); //Sets color to the path x,y as blue. Note: the index of x and y are considered to be the same and thus, iterating variable doesnt matter
        
}

