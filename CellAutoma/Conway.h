#pragma once
#include "Grid.h"

class Conway{

	public:
		Grid * grid;

		Conway();
		int countNeighbors(int x, int y);
		int step(int x, int y);
		void update();
		void display();
		
};
