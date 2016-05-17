#include "Cell.h"

Cell::Cell()
{
	this->occupied = false;
	this->hit = false;
}

Cell::~Cell()
{
}

void Cell::set_occupied()
{
	this->occupied = true;
}

void Cell::set_hit()
{
	this->hit = true;
}

bool Cell::get_occupied()
{
	return occupied;
}

bool Cell::get_hit()
{
	return hit;
}
