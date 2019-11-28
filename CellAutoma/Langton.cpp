#include "Langton.h"
#include "Globals.h"

Langton::Langton(){
  grid = &masterGrid;
	antcount = 5;
  
}

void Langton::spawn(){
	for(int i = 0; i < antcount; i++){
		//ants[i] = { 20, 20, 1};
		antcount++;
	}
}

void Langton::step(){
	for(uint8_t i = 0; i< antcount; i++){
		ants[i].changeDirection(grid->get(ants[i].xcord, ants[i].ycord));
		ants[i].mov();
		grid->setBit(ants[i].xcord, ants[i].ycord, (grid->get(ants[i].xcord, ants[i].ycord) ? 0 : 1));
    
	}
}

 void Langton::display(){
  //arduboy.print("dix");
  //ants.printant();
  grid->drawGrid();
 }
