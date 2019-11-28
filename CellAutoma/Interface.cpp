#include "Interface.h"
#include "Globals.h"
char ants[] = "ants";
//char menu[3][5] = { "ants", "conway", "cells"};



void Interface::indexUdpate(){
  if(arduboy.justPressed(DOWN_BUTTON))
    index +=10;
  else if(arduboy.justPressed(UP_BUTTON))
    index -= 10;
}
void Interface::back(){
  if(arduboy.justPressed(B_BUTTON))
    gamestate = states::menu;
}

void Interface::menu(){
  indexUdpate();
  arduboy.drawTriangle(cursx-1, cursy-1+index, cursx, cursy+index, cursx-1, cursy+1+index);
  arduboy.setCursor(8,1);
  arduboy.print("Ants");
  arduboy.setCursor(7,11);
  arduboy.print("Cellular");
  arduboy.setCursor(7,21);
  arduboy.print("Game of Life");
  arduboy.setCursor(7,31);
  arduboy.print("cursor");

  if(arduboy.justPressed(A_BUTTON))
    switch(index){
      case 0: 
      gamestate = states::lanton;
      break;
      case 10: 
      gamestate = states::elem;
      break;
      case 20: 
      gamestate = states::conway;
      break;
      case 30:
      gamestate = states::paint;
      break;
    }
}

void Interface::paintCells(){
  back();
  masterGrid.drawGrid();
  masterGrid.useCursor();
}


void Interface::conway(){
  back();
  life.update();
  life.display();
  }
  
void Interface::elem(){
    back();
    cell.update();
    cell.display();
  }
void Interface::lanton(){
    back();
    ant.step();
    ant.display();
  }
