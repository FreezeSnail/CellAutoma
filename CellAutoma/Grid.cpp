#include "Grid.h"
#include <stdlib.h>

#include "Globals.h" 

#define debug 0



Grid::Grid(){

}

void Grid::setBit(int x, int y, int b){
	/*if(b == 1)
		grid[y] |= 0x1 << x;
	else	
		grid[y] &= ~(0x1 << x);*/
   if(x >=32)
	  right[y] ^= (-b ^ right[y]) & (1UL << (x-32));
   else
    left[y] ^= (-b ^ left[y]) & (1UL << x);
}

void Grid::flipBit(int x, int y){
  if(x >=32)
	  right[y] ^= (1 << (x-32));
  else
    left[y] ^= (1 << x);
}

int Grid::get(int x, int y){
  if(x >= 32)
	  return (right[y] >> (x-32)) & 0x1;
  return (left[y] >> x) & 0x1;
}

int Grid::neighbor(int x, int y){
	return get( ((x+gridsize)%gridsize) , (y+gridsize)%gridsize );

}
void Grid::randomize(){
  //for(uint64_t x : grid)
   // x = random(922337203, 922337203685477580);
	

}

void Grid::drawRow(uint8_t y){
  uint32_t row =left[y];
  for(int i = 0; i < 32; i++){
    int cell = row & 1;
   // arduboy.print(gridsize);
    if(cell)
      arduboy.drawPixel(i+xorigin, y+3);
    row = row >> 1;
  }

  row =right[y];
  for(int i = 0; i < 32; i++){
    int cell = row & 1;
   // arduboy.print(gridsize);
    if(cell)
      arduboy.drawPixel(i+xorigin+32, y+3);
    row = row >> 1;
  }
}

void Grid::drawGrid(){
  for(int i = 0; i< gridsize; i++)
    drawRow(i);
  
}

void Grid::reset(){
  for(int i = 0; i < 32; i++){
    right[i] = 0;
    left[i] = 0;
  }
}


void Grid::drawCursor(){
  arduboy.drawLine(cursorX + 1, cursorY, cursorX + 3, cursorY);
  arduboy.drawLine(cursorX - 1, cursorY, cursorX - 3, cursorY);

  arduboy.drawLine( cursorX, cursorY + 1, cursorX, cursorY + 3);
  arduboy.drawLine( cursorX, cursorY - 1, cursorX, cursorY - 3);
}

void Grid::moveCursor(){
  if(arduboy.pressed(RIGHT_BUTTON))
    cursorX++;
  if(arduboy.pressed(LEFT_BUTTON))
    cursorX--;
  if(arduboy.pressed(UP_BUTTON))
    cursorY--;
  if(arduboy.pressed(DOWN_BUTTON))
    cursorY++;


}

void Grid::useCursor(){
  drawCursor();
  moveCursor();

  if(arduboy.justPressed(A_BUTTON)){
    setBit(cursorX-64, cursorY-3, (get(cursorX- 64, cursorY-3) ? 0 : 1));  
    arduboy.println(get(cursorX-64, cursorY-3));
    arduboy.print("dix");
  }
}
