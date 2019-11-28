#include "Elementary.h"
#include "Grid.h"
#include "Globals.h"
#include <stdlib.h>

Elementary::Elementary(){
  grid = &masterGrid;
  grid->left[0] = random(); //0b100000000000000000000000000000000000;
	ruleptr = &rule30;
}


uint8_t Elementary::getState(int x, int y){
	uint8_t rule = 0b111;
	return (rule & (grid->get(x,y) <<1)) + (rule & (grid->get(x-1, y) <<2)) + (rule & grid->get(x+1, y));
	// fix so wraps around or something idk

}

void Elementary::fill(){
	uint8_t rule = 0b111;
	for(int y = 0; y <gridsize-1; y++){
		//uint8_t right = (rule & (grid.get(gridsize-1,y) <<1)) + (rule & (grid.get(gridsize-1-1, y) <<2)) + (rule & grid.get(1, y));
		//uint8_t left = (rule & (grid.get(0,y) <<1)) + (rule & grid.get(1, y)) + (rule & (grid.get(gridsize-1-1, y) <<2));
		//grid.setBit(0, y+1, left);
		//grid.setBit(gridsize-1, y+1, right);
		for(int i = 0; i < gridsize; i++){
			grid->setBit(i, y+1, (*ruleptr >> (getState(i, y)) &1 ));
	}
	}
}

void Elementary::shiftUp(){
	for(uint8_t i = 1; i < gridsize; i++){
		grid->left[i-1] = grid->left[i];
    grid->left[i] = 0;
    grid->right[i-1] = grid->right[i];
    grid->right[i] = 0;
	}
    

}

void Elementary::update(){
	uint8_t rule = 0b111;
	shiftUp();
	//uint8_t right = (rule & (grid.get(gridsize-1,gridsize-1) <<1)) + (rule & (grid.get(gridsize-1-1, gridsize-1) <<2)) + (rule & grid.get(1, gridsize-1));
	//uint8_t left = (rule & (grid.get(0,gridsize-1) <<1)) + (rule & grid.get(1, gridsize-1)) + (rule & (grid.get(gridsize-1-1, gridsize-1) <<2));
	//grid.setBit(0, gridsize-1, left);
	//grid.setBit(gridsize-1, gridsize-1, right);

	for(int i = 0; i < gridsize; i++)
			grid->setBit(i, gridsize-1, (*ruleptr >> (getState(i, gridsize-2)) &1 ));
}

void Elementary::randomize(){
	grid->left[gridsize-1] = random(); //0b100000000000000000000000000000000000;
  grid->right[gridsize-1] = random();
}

void Elementary::display(){
	grid->drawGrid();
}
