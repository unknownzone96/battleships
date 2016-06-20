#include "Game.h"

Game::Game()
{
}

Game::~Game()
{
}

void Game::start()
{
	int mode;
	do
	{
		cout << " Singleplayer - press 1 " << endl << " Multiplayer - press 2" << endl;
		cin >> mode;
	} while (mode != 1 && mode != 2);

	if (mode == 1)
	{
		single();
	}
	else
	{
		multy();
	}
}

void Game::single()
{
	players[0].get_board().draw();
	int i, j;
	int hits = 0;
	do
	{
		cout << "Enter coords to hit" << endl;
		cin >> i >> j;
		players[0].hit(i, j);
		hits++;
		players[0].get_board().draw();
	} while (!players[0].gameOver());

	cout << "It took you " << hits << " hits to destroy all enemy ships." << endl;
}

void Game::multy()
{
	if (players[0].get_board().num_of_hit() != 0)
	{
		players[0].get_board().Clear_board();
		players[0].get_board().placeShips();
	}
	if (players[1].get_board().num_of_hit() != 0)
	{
		players[1].get_board().Clear_board();
		players[1].get_board().placeShips();
	}
	int i, j;
	do
	{
		if (!players[0].gameOver() && !players[1].gameOver())
		{
			players[1].get_board().draw();
			cout << " P2s board -^" << endl;
			cout << "Enter coords to hit " << endl;
			cin >> i >> j;
			players[1].hit(i, j);
		}
		if (!players[0].gameOver() && !players[0].gameOver())
		{
			players[0].get_board().draw();
			cout << "P1s board -^" << endl;
			cout << "Enter coords to hit " << endl;
			cin >> i >> j;
			players[0].hit(i, j);
		}
	} while (!players[1].gameOver() && !players[0].gameOver());

	if (players[0].gameOver())
	{
		for (int i = 0; i < 5; i++)
		{
			cout << "VICTORY for Player 2 " << endl;
		}
		
	}
	else if (players[1].gameOver())
	{
		for (int i = 0; i < 5; i++)
		{
			cout << "VICTORY for Player 1 " << endl;
		}
	}
}
