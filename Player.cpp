#include "Player.h"

Player::Player()
{
	plBoard.placeShips();
}

Player::~Player()
{
}


void Player::hit(int i,int j)
{
	int k, p;
	if (i > 9 || j > 9 || i < 0 || j < 0 || plBoard.getCell(i, j).get_hit() || plBoard.getCell(i, j).get_missed())
	{
		cout << "Not a cell on the board or You already fired here !" << endl;
		do
		{
			cout << "Enter coords to hit" << endl;
			cin >> k >> p;
		} while (k > 9 || p > 9 || k < 0 || p < 0 || plBoard.getCell(k, p).get_hit() || plBoard.getCell(k,p).get_missed());
		if (plBoard.getCell(k, p).get_occupied())
		{
			plBoard.getCell(k, p).set_hit(); 
			plBoard.draw();
			cout << "You are on a streak " << endl;
			if (!gameOver())
			{
				cout << "Enter coords to hit " << endl;
				cin >> k >> p;
				hit(k, p);
			}
			
		}
		else
		{
			plBoard.getCell(k,p).set_missed();
			plBoard.draw();
		}
	}
	else
	{
		if (plBoard.getCell(i, j).get_occupied())
		{
			plBoard.getCell(i, j).set_hit();
			plBoard.draw();
			cout << "You are on a streak " << endl;
			if (!gameOver())
			{
				cout << "Enter coords to hit " << endl;
				cin >> k >> p;
				hit(k, p);
			}
		}
		else
		{
			plBoard.getCell(i, j).set_missed();
			plBoard.draw();
		}
	}
}

Board& Player::get_board()
{
	return plBoard;
}

bool Player::gameOver()
{
	if (get_board().num_of_hit() == get_board().num_of_occupied())
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Player::game()
{
	
}


