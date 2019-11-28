#pragma once
#include <stdint.h>


class Ant{
	public:
		uint8_t xcord;
		uint8_t ycord;
		uint8_t dir; // up 1, down 2 left 3 right 4

    Ant();
    Ant(uint8_t x, uint8_t y, uint8_t d);
    
		void mov();
		void changeDirection(uint8_t color);
    void printant();
};
