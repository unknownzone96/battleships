#pragma once
#include <iostream>
using namespace std;
#ifndef CELL_H
#define CELL_H

class Cell
{
private:
	bool occupied;
	bool hit;
public:
	Cell();
	~Cell();
	void set_occupied();
	void set_hit();
	bool get_occupied();
	bool get_hit();

};

#endif // !CELL_H
