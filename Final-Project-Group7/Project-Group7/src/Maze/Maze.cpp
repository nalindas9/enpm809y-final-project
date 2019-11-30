#include "Maze.h"
#include "../API/API.h"

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
            
                  if(d == 'n'){
                      maze.North[x][y] = API::wallFront();
                      maze.East[x][y] = API::wallRight();
                      maze.West[x][y] = API::wallLeft();
                      if(API::wallFront()){
                            API::setWall(x,y,'n');
                          }
                      if(API::wallRight()){
                            API::setWall(x,y,'e');
                          }
                      if(API::wallLeft()){
                            API::setWall(x,y,'w');
                          }
                  }
                  if(d == 'e'){
                      maze.North[x][y] = API::wallLeft()
                      maze.East[x][y] = API::wallFront();
                      maze.South[x][y] = API::wallRight();
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
                  if(d == 'w'){
                      maze.West[x][y] = API::wallFront();
                      maze.North[x][y] = API::wallRight();
                      maze.South[x][y] = API::wallLeft();
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
                  if(d == 's'){
                      maze.South[x][y] = API::wallFront();
                      maze.East[x][y] = API::wallLeft();
                      maze.West[x][y] = API::wallRight();
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
                  
                  
                  
                  
                  
                  
                  }
                  }
              }
            
            
            }
		}
        
	}
	// this function should modify all the four static wall matrix.
	
}


