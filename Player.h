#pragma once
#include "Board.h"
#ifndef PLAYER_H
#define PLAYER_H

class Player
{
private:
	int health_points;
	Board plBoard;
public:
	
	Player();
	~Player();
	void hit(int i, int j);
	void draw();
	Board& get_board();
	bool gameOver();
	void game();


};


#endif // !PLAYER_H
