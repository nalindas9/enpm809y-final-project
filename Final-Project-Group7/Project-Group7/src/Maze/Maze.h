#pragma once

#include "../API/API.h"
#include <vector>

namespace fp
{

class Maze
{
public:
    int x;
    int y;
    int dir;
	 // Marix to store whether the node has wall in left or not
    bool North[16][16];
    bool South[16][16];
    bool East[16][16];
    bool West[16][16];
	void MazeInitialisation();
	Maze(){
		North[16][16]={};
		South[16][16]={};
		East[16][16]={};
		West[16][16]={};
		for(int i=0 ; i<16 ; i++){
			for(int j=0 ; j<16 ; j++){
				if(i==0) {
					West[i][j]=true;
					API::setWall(i,j,'w');
					
				}
				else{
					West[i][j]=false;
				}
				if(i==15){
					East[i][j]=true;
					API::setWall(i,j,'e');
				}
				else{
					East[i][j]=false;
				}
				if(j==0){
					South[i][j]=true;
					//API::turnRight();
					API::setWall(i,j,'s');
				}
				else{
					South[i][j]=false;
				}
				if(j==15){
					North[i][j]=true;
					API::setWall(i,j,'n');
				}
				else{
					North[i][j]=false;
				}
//				if(i>=1 && i<= 14 && j>=1 && j<= 14){
//					North[i][j]=false;
//					East[i][j]=false;
//					South[i][j]=false;
//					West[i][j]=false;
				//}
			}
		}
	}
    
	void ReadMaze(int x,int y,char direction);
    void colorPath(std::vector<int> &X, std::vector<int> &Y);
	//void ResetColor();
};

}

