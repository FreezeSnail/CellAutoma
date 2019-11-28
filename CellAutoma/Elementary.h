#pragma once
#include "Grid.h"

static uint8_t rule30 = 0b00011110;
static uint8_t rule45 = 0b00101101;
static uint8_t rule86 = 0b01010110;
static uint8_t rule90 = 0b01011010;
static uint8_t rule109 = 0b01101101;
static uint8_t rule150 = 0b10010110;

class Elementary{

	public:
		Grid * grid;
		uint8_t * ruleptr;

		Elementary();
		uint8_t getState(int x, int y);
		void fill();
		void shiftUp();
		void update();
		void display();
		void randomize();
};
