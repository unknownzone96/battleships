#pragma once
#include "Cell.h"

struct CellCoord
{
	int x;
	int y;
};

struct surround
{
	bool top;
	bool bot;
	bool left;
	bool right;
	bool centre;
};

#include <stdlib.h>     // srand, rand 
#include <time.h>       // time 
#ifndef BOARD_H
#define BOARD_H

class Board
{
private:
	Cell sea[10][10];
	
public:
	surround checkSurround(CellCoord cc, int range);
	Board();
	~Board();
	int num_of_occupied();
	void randShip(int n);
	void placeShips();
	void Clear_board();
	Cell& getCell(int i, int j);



};


#endif // !BOARD_H
