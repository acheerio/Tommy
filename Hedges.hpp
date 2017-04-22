#ifndef HEDGES_HPP
#define HEDGES_HPP

#include "Room.hpp"
class Hedges :
	public Room
{
public:
	Hedges();
	virtual ~Hedges();
	virtual bool use(Item *i);
};

#endif