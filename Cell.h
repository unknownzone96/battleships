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
	bool missed;
public:
	Cell();
	~Cell();
	void set_occupied();
	void set_hit();
	void clear();
	void set_missed();
	bool get_occupied()const;
	bool get_hit()const;
	bool get_missed()const;

};

#endif // !CELL_H
