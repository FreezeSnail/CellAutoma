#include "Ant.hpp"
#include "Grid.h"
#include "Globals.h"

Ant::Ant(){
  xcord = random(0,64);
  ycord = random(0,64);
  dir = random(1,4);
  }
Ant::Ant(uint8_t x, uint8_t y, uint8_t d){
  xcord = x;
  ycord = y;
  dir = d;
}
void Ant::mov(){
	if(dir == 1){
		xcord +=1;
			if (xcord == gridsize){
				xcord--;
        //dir++;
			}
	}
	else if(dir == 2){
		ycord += 1;
		if (ycord == gridsize){
      //dir++;
			ycord--;
		}
	}
	else if(dir == 3){
		xcord -= 1;
		if (xcord < 0){
				xcord++;
        //dir++;
		}
        
	}
	else{
		ycord -= 1;
		if (ycord < 0){
				ycord++;
        //dir--;
		}
	}
}

void Ant::changeDirection(uint8_t color){
	if(color){
		dir++;
		if(dir == 5)
			dir = 1;
	}
	else{
		dir--;
		if(dir == 0)
			dir = 4;
	}
}


void Ant::printant(){
  //arduboy.print("penis");
  arduboy.drawPixel(xcord, ycord);
}
