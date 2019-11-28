#include <stdint.h>
#include "Globals.h"
#include "Grid.h"
//#include "Conway.h"
#include "Elementary.h"
#include "Langton.h"
#include "Interface.h"
//Conway game = Conway();
Langton game;
Interface interface;





void setup() {
  arduboy.boot();
  arduboy.setFrameRate(30);
//  game.fill();
  arduboy.initRandomSeed();
 // Conway game = Conway();
 // game.spawn();
  // 
}

//Main loop
void loop() {
  if(!arduboy.nextFrame()){
    return;
  }
  arduboy.pollButtons();
  arduboy.clear();
  switch(interface.gamestate){
    case states::menu: interface.menu();
    break;
    case states::conway: interface.conway();
    break;
    case states::elem: 
    interface.cell.fill();
    interface.elem();
    break;
    case states::lanton: interface.lanton();
    break;
    case states::paint: interface.paintCells();
    break;
  }
  
  arduboy.display();
}
