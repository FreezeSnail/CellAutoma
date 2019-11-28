#pragma once
#include <stdint.h>
#include "Conway.h"
#include "Elementary.h"
#include "Langton.h"

typedef enum states{
  menu,
  conway,
  elem,
  lanton,
  paint
}states_t;

class Interface{

    public:
      states_t gamestate;
      uint8_t cursx = 5;
      uint8_t cursy = 5;
      uint8_t index = 0;
      Conway life;
      Elementary cell;
      Langton ant;

      void menu();
      void conway();
      void elem();
      void lanton();
      void cursorT();
      void indexUdpate();
      void back();

      void paintCells();

      conwaySetUp();
      langtonSetUp();
      elemSetup();
};
