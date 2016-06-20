#pragma once
#include "Player.h"
#ifndef GAME_H
#define GAME_H

class Game
{
private:
	Player players[2];

public:
	Game();
	~Game();
	void start();
	void single();
	void multy();
};


#endif
