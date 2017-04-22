#ifndef LIVING2_HPP
#define LIVING2_HPP

#include "Room.hpp"

class Living2 : 
	public Room
{
public:
	Living2();
	virtual ~Living2();
	virtual Room* showDirections();
	virtual bool use(Item *i);
};

#endif