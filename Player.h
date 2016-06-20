#pragma once
#include "Board.h"
#ifndef PLAYER_H
#define PLAYER_H

class Player
{
private:
	Board plBoard;
public:
	Player();
	~Player();
	void hit(int i,int j);
	Board& get_board();
	bool gameOver();
	void game();
	

};


#endif // !PLAYER_H
