#include "Board.h"



Board::Board()
{
}

Board::~Board()
{
}
/*
void Board::set_Submarines()
{
	//1 cell
	int x, y;
	srand(time(NULL));
	do
	{
		// generates number between 0 and 10:
		x = rand() % 10;
		y = rand() % 10;
	} while (sea[x][y].get_occupied());
	sea[x][y].set_occupied();

}

void Board::set_Destroyer()
{
	//2 cells
	int x, y;
	bool surrounding;
	do
	{
		// generates number between 0 and 10:
		x = rand() % 10;
		y = rand() % 10;
		surrounding = sea[x + 1][y].get_occupied() ||
			sea[x - 1][y].get_occupied() ||
			sea[x][y - 1].get_occupied() ||
			sea[x][y + 1].get_occupied();
	} while (sea[x][y].get_occupied() && surrounding);

	sea[x][y].set_occupied();

	bool r = x + 1 <= 9 && !sea[x + 1][y].get_occupied();
	bool l = x - 1 <= 9 && !sea[x - 1][y].get_occupied();
	bool t = y - 1 <= 9 && !sea[x][y - 1].get_occupied();
	bool b = y + 1 <= 9 && !sea[x][y + 1].get_occupied();

	if (t && b && l && r)
	{
		//rand of all 4
		int r = rand() % 4;
		switch (r)
		{
		case 0: sea[x][y - 1].set_occupied();
			break;
		case 1: sea[x + 1][y].set_occupied();
			break;
		case 2: sea[x][y + 1].set_occupied();
			break;
		case 3: sea[x - 1][y].set_occupied();
			break;
		default:
			break;
		}
	}
	else if (t && b && l)
	{
		int r = rand() % 3;
		switch (r)
		{
		case 0: sea[x][y - 1].set_occupied();
			break;
		case 1: sea[x][y + 1].set_occupied();
			break;
		case 2: sea[x - 1][y].set_occupied();
			break;
		default:
			break;
		}
	}
	else if (t && b && r)
	{

		int r = rand() % 3;
		switch (r)
		{
		case 0: sea[x][y - 1].set_occupied();
			break;
		case 1: sea[x][y + 1].set_occupied();
			break;
		case 2: sea[x + 1][y].set_occupied();
			break;
		default:
			break;
		}
	}
	else if (t && l && r)
	{

		int r = rand() % 3;
		switch (r)
		{
		case 0: sea[x][y - 1].set_occupied();
			break;
		case 1: sea[x][y + 1].set_occupied();
			break;
		case 2: sea[x + 1][y].set_occupied();
			break;
		default:
			break;
		}
	}
	else if (b && l && r)
	{

		int r = rand() % 3;
		switch (r)
		{
		case 0: sea[x][y + 1].set_occupied();
			break;
		case 1: sea[x - 1][y].set_occupied();
			break;
		case 2: sea[x + 1][y].set_occupied();
			break;
		default:
			break;
		}
	}
	else if (t && b)
	{
		int r = rand() % 2;
		switch (r)
		{
		case 0: sea[x][y - 1].set_occupied();
			break;
		case 1: sea[x][y + 1].set_occupied();
			break;
		default:
			break;
		}
	}
	else if (t && l)
	{
		int r = rand() % 2;
		switch (r)
		{
		case 0: sea[x][y - 1].set_occupied();
			break;
		case 1: sea[x - 1][y].set_occupied();
			break;
		default:
			break;
		}
	}
	else if (t && r)
	{
		int r = rand() % 2;
		switch (r)
		{
		case 0: sea[x][y - 1].set_occupied();
			break;
		case 1: sea[x + 1][y].set_occupied();
			break;
		default:
			break;
		}
	}
	else if (b && l)
	{
		int r = rand() % 2;
		switch (r)
		{
		case 0: sea[x][y + 1].set_occupied();
			break;
		case 1: sea[x - 1][y].set_occupied();
			break;
		default:
			break;
		}
	}
	else if (b && r)
	{
		int r = rand() % 2;
		switch (r)
		{
		case 0: sea[x][y + 1].set_occupied();
			break;
		case 1: sea[x + 1][y].set_occupied();
			break;
		default:
			break;
		}
	}
	else if (l && r)
	{
		int r = rand() % 2;
		switch (r)
		{
		case 0: sea[x - 1][y].set_occupied();
			break;
		case 1: sea[x + 1][y].set_occupied();
			break;
		default:
			break;
		}
	}
	else if (b)
	{
		sea[x][y + 1].set_occupied();
	}
	else if (t)
	{
		sea[x][y - 1].set_occupied();
	}
	else if (l)
	{
		sea[x - 1][y].set_occupied();
	}
	else if (r)
	{
		sea[x + 1][y].set_occupied();
	}

}

void Board::set_Cruiser()
{
	//3 cells
	int x, y;
	bool surrounding;
	do
	{
		// generates number between 0 and 10:
		x = rand() % 10;
		y = rand() % 10;
		surrounding = sea[x + 1][y].get_occupied() && sea[x + 2][y].get_occupied() ||
			sea[x - 1][y].get_occupied() && sea[x - 2][y].get_occupied() ||
			sea[x][y - 1].get_occupied() && sea[x][y - 2].get_occupied() ||
			sea[x][y + 1].get_occupied() && sea[x][y + 2].get_occupied();
	} while (sea[x][y].get_occupied() && surrounding);

	sea[x][y].set_occupied();
	bool r = x + 2 <= 9 && !sea[x + 1][y].get_occupied() && !sea[x + 2][y].get_occupied();
	bool l = x - 2 <= 9 && !sea[x - 1][y].get_occupied() && !sea[x - 2][y].get_occupied();
	bool t = y - 2 <= 9 && !sea[x][y - 1].get_occupied() && !sea[x][y - 2].get_occupied();
	bool b = y + 2 <= 9 && !sea[x][y + 1].get_occupied() && !sea[x][y + 2].get_occupied();

	if (t && b && l && r)
	{
		//rand of all 4
		int r = rand() % 4;
		switch (r)
		{
		case 0: sea[x][y - 1].set_occupied();
			sea[x][y - 2].set_occupied();
			break;
		case 1: sea[x + 1][y].set_occupied();
			sea[x + 2][y].set_occupied();
			break;
		case 2: sea[x][y + 1].set_occupied();
			sea[x][y + 2].set_occupied();
			break;
		case 3: sea[x - 1][y].set_occupied();
			sea[x - 2][y].set_occupied();
			break;
		default:
			break;
		}
	}
	else if (t && b && l)
	{
		int r = rand() % 3;
		switch (r)
		{
		case 0: sea[x][y - 1].set_occupied();
			sea[x][y - 2].set_occupied();
			break;
		case 1: sea[x][y + 1].set_occupied();
			sea[x][y + 2].set_occupied();
			break;
		case 2: sea[x - 1][y].set_occupied();
			sea[x - 2][y].set_occupied();
			break;
		default:
			break;
		}
	}
	else if (t && b && r)
	{

		int r = rand() % 3;
		switch (r)
		{
		case 0: sea[x][y - 1].set_occupied();
			sea[x][y - 2].set_occupied();
			break;
		case 1: sea[x][y + 1].set_occupied();
			sea[x][y + 2].set_occupied();
			break;
		case 2: sea[x + 1][y].set_occupied();
			sea[x + 2][y].set_occupied();
			break;
		default:
			break;
		}
	}
	else if (t && l && r)
	{

		int r = rand() % 3;
		switch (r)
		{
		case 0: sea[x][y - 1].set_occupied();
			sea[x][y - 2].set_occupied();
			break;
		case 1: sea[x][y + 1].set_occupied();
			sea[x][y + 2].set_occupied();
			break;
		case 2: sea[x + 1][y].set_occupied();
			sea[x + 2][y].set_occupied();
			break;
		default:
			break;
		}
	}
	else if (b && l && r)
	{

		int r = rand() % 3;
		switch (r)
		{
		case 0: sea[x][y + 1].set_occupied();
			sea[x][y + 2].set_occupied();
			break;
		case 1: sea[x - 1][y].set_occupied();
			sea[x - 2][y].set_occupied();
			break;
		case 2: sea[x + 1][y].set_occupied();
			sea[x + 2][y].set_occupied();
			break;
		default:
			break;
		}
	}
	else if (t && b)
	{
		int r = rand() % 2;
		switch (r)
		{
		case 0: sea[x][y - 1].set_occupied();
			sea[x][y - 2].set_occupied();
			break;
		case 1: sea[x][y + 1].set_occupied();
			sea[x][y + 2].set_occupied();
			break;
		default:
			break;
		}
	}
	else if (t && l)
	{
		int r = rand() % 2;
		switch (r)
		{
		case 0: sea[x][y - 1].set_occupied();
			sea[x][y - 2].set_occupied();
			break;
		case 1: sea[x - 1][y].set_occupied();
			sea[x - 2][y].set_occupied();
			break;
		default:
			break;
		}
	}
	else if (t && r)
	{
		int r = rand() % 2;
		switch (r)
		{
		case 0: sea[x][y - 1].set_occupied();
			sea[x][y - 2].set_occupied();
			break;
		case 1: sea[x + 1][y].set_occupied();
			sea[x + 2][y].set_occupied();
			break;
		default:
			break;
		}
	}
	else if (b && l)
	{
		int r = rand() % 2;
		switch (r)
		{
		case 0: sea[x][y + 1].set_occupied();
			sea[x][y + 2].set_occupied();
			break;
		case 1: sea[x - 1][y].set_occupied();
			sea[x - 2][y].set_occupied();
			break;
		default:
			break;
		}
	}
	else if (b && r)
	{
		int r = rand() % 2;
		switch (r)
		{
		case 0: sea[x][y + 1].set_occupied();
			sea[x][y + 2].set_occupied();
			break;
		case 1: sea[x + 1][y].set_occupied();
			sea[x + 2][y].set_occupied();
			break;
		default:
			break;
		}
	}
	else if (l && r)
	{
		int r = rand() % 2;
		switch (r)
		{
		case 0: sea[x - 1][y].set_occupied();
			sea[x - 2][y].set_occupied();
			break;
		case 1: sea[x + 1][y].set_occupied();
			sea[x + 2][y].set_occupied();
			break;
		default:
			break;
		}
	}
	else if (b)
	{
		sea[x][y + 1].set_occupied();
		sea[x][y + 2].set_occupied();
	}
	else if (t)
	{
		sea[x][y - 1].set_occupied();
		sea[x][y - 2].set_occupied();
	}
	else if (l)
	{
		sea[x - 1][y].set_occupied();
		sea[x - 2][y].set_occupied();
	}
	else if (r)
	{
		sea[x + 1][y].set_occupied();
		sea[x + 2][y].set_occupied();
	}

}

void Board::set_Battleship()
{
	// 4 cells
	int x, y;
	bool surrounding;
	do
	{
		// generates number between 0 and 10:
		x = rand() % 10;
		y = rand() % 10;
		surrounding = sea[x + 1][y].get_occupied() && sea[x + 2][y].get_occupied() && sea[x + 3][y].get_occupied() ||
			sea[x - 1][y].get_occupied() && sea[x - 2][y].get_occupied() && sea[x - 3][y].get_occupied() ||
			sea[x][y - 1].get_occupied() && sea[x][y - 2].get_occupied() && sea[x][y - 3].get_occupied() ||
			sea[x][y + 1].get_occupied() && sea[x][y + 2].get_occupied() && sea[x][y + 3].get_occupied();
	} while (sea[x][y].get_occupied() && surrounding);

	sea[x][y].set_occupied();
	bool r = x + 2 <= 9 && !sea[x + 1][y].get_occupied() && !sea[x + 2][y].get_occupied() && !sea[x + 3][y].get_occupied();
	bool l = x - 2 <= 9 && !sea[x - 1][y].get_occupied() && !sea[x - 2][y].get_occupied() && !sea[x - 3][y].get_occupied();
	bool t = y - 2 <= 9 && !sea[x][y - 1].get_occupied() && !sea[x][y - 2].get_occupied() && !sea[x][y - 3].get_occupied();
	bool b = y + 2 <= 9 && !sea[x][y + 1].get_occupied() && !sea[x][y + 2].get_occupied() && !sea[x][y + 3].get_occupied();

	if (t && b && l && r)
	{
		//rand of all 4
		int r = rand() % 4;
		switch (r)
		{
		case 0: sea[x][y - 1].set_occupied();
			sea[x][y - 2].set_occupied();
			sea[x][y - 3].set_occupied();
			break;
		case 1: sea[x + 1][y].set_occupied();
			sea[x + 2][y].set_occupied();
			sea[x + 3][y].set_occupied();
			break;
		case 2: sea[x][y + 1].set_occupied();
			sea[x][y + 2].set_occupied();
			sea[x][y + 3].set_occupied();
			break;
		case 3: sea[x - 1][y].set_occupied();
			sea[x - 2][y].set_occupied();
			sea[x - 3][y].set_occupied();
			break;
		default:
			break;
		}
	}
	else if (t && b && l)
	{
		int r = rand() % 3;
		switch (r)
		{
		case 0: sea[x][y - 1].set_occupied();
			sea[x][y - 2].set_occupied();
			sea[x][y - 3].set_occupied();
			break;
		case 1: sea[x][y + 1].set_occupied();
			sea[x][y + 2].set_occupied();
			sea[x][y + 3].set_occupied();
			break;
		case 2: sea[x - 1][y].set_occupied();
			sea[x - 2][y].set_occupied();
			sea[x - 3][y].set_occupied();
			break;
		default:
			break;
		}
	}
	else if (t && b && r)
	{

		int r = rand() % 3;
		switch (r)
		{
		case 0: sea[x][y - 1].set_occupied();
			sea[x][y - 2].set_occupied();
			sea[x][y - 3].set_occupied();
			break;
		case 1: sea[x][y + 1].set_occupied();
			sea[x][y + 2].set_occupied();
			sea[x][y + 3].set_occupied();
			break;
		case 2: sea[x + 1][y].set_occupied();
			sea[x + 2][y].set_occupied();
			sea[x + 3][y].set_occupied();
			break;
		default:
			break;
		}
	}
	else if (t && l && r)
	{

		int r = rand() % 3;
		switch (r)
		{
		case 0: sea[x][y - 1].set_occupied();
			sea[x][y - 2].set_occupied();
			sea[x][y - 3].set_occupied();
			break;
		case 1: sea[x][y + 1].set_occupied();
			sea[x][y + 2].set_occupied();
			sea[x][y + 3].set_occupied();
			break;
		case 2: sea[x + 1][y].set_occupied();
			sea[x + 2][y].set_occupied();
			sea[x + 3][y].set_occupied();
			break;
		default:
			break;
		}
	}
	else if (b && l && r)
	{

		int r = rand() % 3;
		switch (r)
		{
		case 0: sea[x][y + 1].set_occupied();
			sea[x][y + 2].set_occupied();
			sea[x][y + 3].set_occupied();
			break;
		case 1: sea[x - 1][y].set_occupied();
			sea[x - 2][y].set_occupied();
			sea[x - 3][y].set_occupied();
			break;
		case 2: sea[x + 1][y].set_occupied();
			sea[x + 2][y].set_occupied();
			sea[x + 3][y].set_occupied();
			break;
		default:
			break;
		}
	}
	else if (t && b)
	{
		int r = rand() % 2;
		switch (r)
		{
		case 0: sea[x][y - 1].set_occupied();
			sea[x][y - 2].set_occupied();
			sea[x][y - 3].set_occupied();
			break;
		case 1: sea[x][y + 1].set_occupied();
			sea[x][y + 2].set_occupied();
			sea[x][y + 3].set_occupied();
			break;
		default:
			break;
		}
	}
	else if (t && l)
	{
		int r = rand() % 2;
		switch (r)
		{
		case 0: sea[x][y - 1].set_occupied();
			sea[x][y - 2].set_occupied();
			sea[x][y - 3].set_occupied();
			break;
		case 1: sea[x - 1][y].set_occupied();
			sea[x - 2][y].set_occupied();
			sea[x - 3][y].set_occupied();
			break;
		default:
			break;
		}
	}
	else if (t && r)
	{
		int r = rand() % 2;
		switch (r)
		{
		case 0: sea[x][y - 1].set_occupied();
			sea[x][y - 2].set_occupied();
			sea[x][y - 3].set_occupied();
			break;
		case 1: sea[x + 1][y].set_occupied();
			sea[x + 2][y].set_occupied();
			sea[x + 3][y].set_occupied();
			break;
		default:
			break;
		}
	}
	else if (b && l)
	{
		int r = rand() % 2;
		switch (r)
		{
		case 0: sea[x][y + 1].set_occupied();
			sea[x][y + 2].set_occupied();
			sea[x][y + 3].set_occupied();
			break;
		case 1: sea[x - 1][y].set_occupied();
			sea[x - 2][y].set_occupied();
			sea[x - 3][y].set_occupied();
			break;
		default:
			break;
		}
	}
	else if (b && r)
	{
		int r = rand() % 2;
		switch (r)
		{
		case 0: sea[x][y + 1].set_occupied();
			sea[x][y + 2].set_occupied();
			sea[x][y + 3].set_occupied();
			break;
		case 1: sea[x + 1][y].set_occupied();
			sea[x + 2][y].set_occupied();
			sea[x + 3][y].set_occupied();
			break;
		default:
			break;
		}
	}
	else if (l && r)
	{
		int r = rand() % 2;
		switch (r)
		{
		case 0: sea[x - 1][y].set_occupied();
			sea[x - 2][y].set_occupied();
			sea[x - 3][y].set_occupied();
			break;
		case 1: sea[x + 1][y].set_occupied();
			sea[x + 2][y].set_occupied();
			sea[x + 3][y].set_occupied();
			break;
		default:
			break;
		}
	}
	else if (b)
	{
		sea[x][y + 1].set_occupied();
		sea[x][y + 2].set_occupied();
		sea[x][y + 3].set_occupied();
	}
	else if (t)
	{
		sea[x][y - 1].set_occupied();
		sea[x][y - 2].set_occupied();
		sea[x][y - 3].set_occupied();
	}
	else if (l)
	{
		sea[x - 1][y].set_occupied();
		sea[x - 2][y].set_occupied();
		sea[x - 3][y].set_occupied();
	}
	else if (r)
	{
		sea[x + 1][y].set_occupied();
		sea[x + 2][y].set_occupied();
		sea[x + 3][y].set_occupied();
	}

}
*/

int Board::num_of_occupied()
{
	int count = 0;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (sea[i][j].get_occupied())
			{
				count++;
			}
		}
	}
	return count;
}

CellCoord randCoord() {
	CellCoord randResult;
	srand(time(NULL));
	// generates number between 0 and 10:
	randResult.x = rand() % 10;
	randResult.y = rand() % 10;
	return randResult;
}

surround Board::checkSurround(CellCoord cc, int range) {
	surround result;
	result.bot = true;
	result.top = true;
	result.left = true;
	result.right = true;

	for (int i = 0; i < range; i++)
	{
		if (sea[cc.x + range - i][cc.y].get_occupied() || cc.x + range > 9)
		{
			result.right = false;
		}
		if (sea[cc.x - range - i][cc.y].get_occupied() || cc.x - range > 9)
		{
			result.left = false;
		}
		if (sea[cc.x][cc.y + range - i].get_occupied() || cc.y + range > 9)
		{
			result.bot = false;
		}
		if (sea[cc.x][cc.y - range - i].get_occupied() || cc.y - range > 9)
		{
			result.top = false;
		}
	}
	return result;
}

void Board::randShip(int n) {
	CellCoord CellCheck;
	int r;
	do
	{
		do
		{
			CellCheck = randCoord();
		} while (sea[CellCheck.x][CellCheck.y].get_occupied());

	} while (!checkSurround(CellCheck, n).bot &&
		!checkSurround(CellCheck, n).top && !checkSurround(CellCheck, n).left &&
		!checkSurround(CellCheck, n).right);

	sea[CellCheck.x][CellCheck.y].set_occupied();

	if (checkSurround(CellCheck, n).bot && checkSurround(CellCheck, n).top &&
		checkSurround(CellCheck, n).left && checkSurround(CellCheck, n).right)
	{
		//rand of all 4
		r = rand() % 4;
		for (int i = 1; i < n; i++)
		{
			switch (r)
			{
			case 0: sea[CellCheck.x][CellCheck.y - i].set_occupied();
				break;
			case 1: sea[CellCheck.x + i][CellCheck.y].set_occupied();
				break;
			case 2: sea[CellCheck.x][CellCheck.y + i].set_occupied();
				break;
			case 3: sea[CellCheck.x - i][CellCheck.y].set_occupied();
				break;
			}
		}
	}
	else if (checkSurround(CellCheck, n).bot && checkSurround(CellCheck, n).top &&
		checkSurround(CellCheck, n).left)
	{
		r = rand() % 3;
		for (int i = 1; i < n; i++)
		{
			switch (r)
			{
			case 0: sea[CellCheck.x][CellCheck.y - i].set_occupied();
				break;
			case 1: sea[CellCheck.x][CellCheck.y + i].set_occupied();
				break;
			case 2: sea[CellCheck.x - i][CellCheck.y].set_occupied();
				break;
			}
		}
	}
	else if (checkSurround(CellCheck, n).bot && checkSurround(CellCheck, n).top && checkSurround(CellCheck, n).right)
	{
		r = rand() % 3;
		for (int i = 1; i < n; i++)
		{
			switch (r)
			{
			case 0: sea[CellCheck.x][CellCheck.y - i].set_occupied();
				break;
			case 1: sea[CellCheck.x][CellCheck.y + i].set_occupied();
				break;
			case 2: sea[CellCheck.x + i][CellCheck.y].set_occupied();
				break;
			}
		}

	}
	else if (checkSurround(CellCheck, n).left && checkSurround(CellCheck, n).top && checkSurround(CellCheck, n).right)
	{
		r = rand() % 3;
		for (int i = 1; i < n; i++)
		{
			switch (r)
			{
			case 0: sea[CellCheck.x][CellCheck.y - i].set_occupied();
				break;
			case 1: sea[CellCheck.x][CellCheck.y + i].set_occupied();
				break;
			case 2: sea[CellCheck.x + i][CellCheck.y].set_occupied();
				break;
			}
		}

	}
	else if (checkSurround(CellCheck, n).left && checkSurround(CellCheck, n).bot && checkSurround(CellCheck, n).right)
	{
		r = rand() % 3;
		for (int i = 1; i < n; i++)
		{
			switch (r)
			{
			case 0: sea[CellCheck.x][CellCheck.y + i].set_occupied();
				break;
			case 1: sea[CellCheck.x - i][CellCheck.y].set_occupied();
				break;
			case 2: sea[CellCheck.x + i][CellCheck.y].set_occupied();
				break;
			}
		}

	}
	else if (checkSurround(CellCheck, n).bot && checkSurround(CellCheck, n).top)
	{
		r = rand() % 2;
		for (int i = 1; i < n; i++)
		{
			switch (r)
			{
			case 0: sea[CellCheck.x][CellCheck.y - i].set_occupied();
				break;
			case 1: sea[CellCheck.x][CellCheck.y + i].set_occupied();
				break;
			}
		}
	}
	else if (checkSurround(CellCheck, n).top && checkSurround(CellCheck, n).left)
	{
		r = rand() % 2;
		for (int i = 1; i < n; i++)
		{
			switch (r)
			{
			case 0: sea[CellCheck.x][CellCheck.y - i].set_occupied();
				break;
			case 1: sea[CellCheck.x - i][CellCheck.y].set_occupied();
				break;
			}
		}
	}
	else if (checkSurround(CellCheck, n).top && checkSurround(CellCheck, n).right)
	{
		r = rand() % 2;
		for (int i = 1; i < n; i++)
		{	
			switch (r)
			{
			case 0: sea[CellCheck.x][CellCheck.y - i].set_occupied();
				break;
			case 1: sea[CellCheck.x + i][CellCheck.y].set_occupied();
				break;
			}
		}
	}
	else if (checkSurround(CellCheck, n).bot && checkSurround(CellCheck, n).left)
	{
		r = rand() % 2;
		for (int i = 1; i < n; i++)
		{
			switch (r)
			{
			case 0: sea[CellCheck.x][CellCheck.y + i].set_occupied();
				break;
			case 1: sea[CellCheck.x - i][CellCheck.y].set_occupied();
				break;
			}
		}
	}
	else if (checkSurround(CellCheck, n).bot && checkSurround(CellCheck, n).right)
	{
		r = rand() % 2;
		for (int i = 1; i < n; i++)
		{
			switch (r)
			{
			case 0: sea[CellCheck.x][CellCheck.y + i].set_occupied();
				break;
			case 1: sea[CellCheck.x + i][CellCheck.y].set_occupied();
				break;
			}
		}
	}
	else if (checkSurround(CellCheck, n).left && checkSurround(CellCheck, n).right)
	{
		r = rand() % 2;
		for (int i = 1; i < n; i++)
		{	
			switch (r)
			{
			case 0: sea[CellCheck.x - i][CellCheck.y].set_occupied();
				break;
			case 1: sea[CellCheck.x + i][CellCheck.y].set_occupied();
				break;
			}
		}
	}
	else if (checkSurround(CellCheck, n).bot)
	{
		for (int i = 1; i < n; i++)
		{
			sea[CellCheck.x][CellCheck.y + i].set_occupied();
		}
	}
	else if (checkSurround(CellCheck, n).top)
	{
		for (int i = 1; i <= n; i++)
		{
			sea[CellCheck.x][CellCheck.y - i].set_occupied();
		}

	}
	else if (checkSurround(CellCheck, n).left)
	{
		for (int i = 1; i < n; i++)
		{
			sea[CellCheck.x - i][CellCheck.y].set_occupied();
		}

	}
	else if (checkSurround(CellCheck, n).right)
	{
		for (int i = 1; i < n; i++)
		{
			sea[CellCheck.x + i][CellCheck.y].set_occupied();
		}
	}

}

void Board::set_Board()
{
	randShip(1);
	randShip(1);
	randShip(2);
	randShip(2);
	randShip(3);
	randShip(4);
	randShip(5);
}


