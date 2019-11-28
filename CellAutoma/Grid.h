#pragma once
#include <stdint.h>

#define gridsize 64
#define xorigin 64
#define yorigin 1

class Grid{

	public:
		uint32_t left[gridsize] = {0};
    uint32_t right[gridsize] = {0};
    uint8_t cursorX = 64;
    uint8_t cursorY;

		Grid();
		void setBit(int x, int y, int b);
		void flipBit(int x, int y);
		int get(int x, int y);
		int neighbor(int x, int y);
		void randomize();

    void drawRow(uint8_t y);
    void drawGrid();

    void reset();


    void paint();
    void drawCursor();
    void moveCursor();
    void useCursor();
    

};
