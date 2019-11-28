#pragma once
#include "Grid.h"
#include "Ant.hpp"

#define antamount 1


class Langton{
	public:
		Grid * grid;
		uint8_t antcount;
		Ant ants[5];// = Ant(20, 20, 1);

		Langton();
		void spawn();
		void step();
		void display();
		//void update();
};
