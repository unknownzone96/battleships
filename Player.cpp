#include "Player.h"

Player::Player()
{
	plBoard.placeShips();
	this->health_points = 100;
}

Player::~Player()
{
}


void Player::hit(int i, int j)
{
	if (i > 9 || j > 9 || i < 0 || j < 0)
	{
		cout << "Not a cell on the board " << endl;
	}
	else if (plBoard.getCell(i, j).get_hit())
	{
		cout << "You already fired here !" << endl;
	}
	else
	{
		if (plBoard.getCell(i, j).get_occupied())
		{
			plBoard.getCell(i, j).set_hit();
		}
		else
		{
			plBoard.getCell(i, j).set_missed();
		}
	}


}

void Player::draw()
{
	system("cls");
	for (int i = 0; i < 10; i++)
	{
		if (i==0)
		{
			cout << " .__0";
		}
		else
		{
			cout << "__" << i << "_";
		}
		
	}
	cout <<" ."<<"\n";
	//cout << "._______________________________________." << endl;
	for (int i = 0; i < 10; i++)
	{
		
		for (int j = 0; j < 10; j++)
		{
			if (j == 0)
			{
				cout << i;
			}
			if (j == 9)
			{
				if (plBoard.getCell(i, j).get_hit())
				{
					cout << "_X_|" << endl;
				}
				else if (plBoard.getCell(i, j).get_missed())
				{
					cout << "_o_|" << endl;
				}
				else
				{
					cout << "_~_|" << endl;
				}
			}
			else if (j == 0)
			{
				if (plBoard.getCell(i, j).get_hit())
				{
					cout << "|_X_|";
				}
				else if (plBoard.getCell(i, j).get_missed())
				{
					cout << "|_o_|";
				}
				else
				{
					cout << "|_~_|";
				}
			}
			else
			{
				if (plBoard.getCell(i, j).get_hit())
				{
					cout << "_X_|";
				}
				else if (plBoard.getCell(i, j).get_missed())
				{
					cout << "_o_|";
				}
				else
				{
					cout << "_~_|";
				}
			}
		}
	}

}

Board& Player::get_board()
{
	return plBoard;
}

bool Player::gameOver()
{
	if (this->get_board().num_of_hit() == this->get_board().num_of_occupied())
	{
		cout << "-----.VICTORY.----- " << endl;
		return true;
	}
	else if (this->health_points <= 0)
	{
		cout << " You are dead." << endl;
		return true;
	}
	else
	{
		return false;
	}

}

void Player::game()
{
	int i, j;
	draw();
	do
	{
		do
		{			
			cout << "Enter coords to hit " << endl;
			cin >> i >> j;
			if (i > 9 || j > 9 || i < 0 || j < 0)
			{
				cout << "Coords not on board. Try again." << endl;
			}
			else if (plBoard.getCell(i, j).get_hit() || plBoard.getCell(i,j).get_missed())
			{
				cout << " You already shot there. Try again." << endl;
			}
		} while (i > 9 || j > 9 || i < 0 || j < 0 || plBoard.getCell(i, j).get_hit() || plBoard.getCell(i,j).get_missed());
		hit(i, j);
		draw();
	} while (!gameOver());

}
