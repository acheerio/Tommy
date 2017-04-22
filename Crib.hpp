#ifndef CRIB_HPP
#define CRIB_HPP

#include "Room.hpp"
class Crib :
	public Room
{
public:
	Crib();
	virtual ~Crib();
	virtual Room* showDirections();
	virtual bool use(Item *i);
};

#endif