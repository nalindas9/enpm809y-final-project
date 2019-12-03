#include "Maze.h"
#include "../API/API.h"
#include <vector>


fp::Maze::Maze(){
    //Creates a data set of North, East, West and South wall, a 16x16 matrix
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
	
            dir = d;
                  if(dir == 'n'){
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
    for(unsigned int i=0 ; i<X.size() ; i++)
        API::setColor(X[i],Y[i],'g'); //Sets color to the path x,y as green by calling the API function.
        
}


