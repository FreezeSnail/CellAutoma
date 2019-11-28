#include "Conway.h"
#include "Globals.h"
#include "Conway.h"
#include <stdio.h>


Conway::Conway(){
  grid = &masterGrid;
	  //grid.randomize();
  // grid.grid[0] =(3<<8);
  // grid.grid[1] =(3<<8);
}


int Conway::countNeighbors(int x, int y){
	int count = 0;
	int deltas[3] = { -1, 0, 1};
		for(int vertical: deltas)
			for(int horizontal : deltas){

				if(horizontal || vertical){
					int xcord = x + horizontal;
					int ycord = y + vertical;
					if(!(xcord > gridsize-1 || xcord < 0))
						if(!(ycord > gridsize-1 || ycord < 0))
							count += grid->get(x + horizontal, y + vertical);
				}
			}
	return count;
}

int Conway::step(int x, int y){
	int neighborCount = countNeighbors(x, y);

	// count > 3 ded
	// count 0,1 -> ded
	// 2,3 lives
	// if 0 and 3, new cell
	//else ded

	bool lives = grid->get(x, y) && (neighborCount == 3 || neighborCount == 2);
	bool newCell = !grid->get(x,y) && neighborCount == 3;

	return lives || newCell;  // eithercase x,y becomes 1
}

void Conway::update(){
	Grid  up = *grid;
	for(int i = 0; i<gridsize; i++)
		for(int j = 0; j<gridsize; j++){
			//printf("count %d\n", i + j);
			up.setBit(i, j, step(i,j));
		}
	*grid = up;
}

void Conway::display(){
	grid->drawGrid();
}
