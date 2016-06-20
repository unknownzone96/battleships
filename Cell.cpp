#include "Cell.h"

Cell::Cell()
{
	this->occupied = false;
	this->hit = false;
	this->missed = false;
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

void Cell::clear()
{
	this->occupied = false;
}

void Cell::set_missed()
{
	this->missed = true;
}

bool Cell::get_occupied()const
{
	return occupied;
}

bool Cell::get_hit()const
{
	return hit;
}

bool Cell::get_missed()const
{
	return missed;
}

