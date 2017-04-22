#ifndef HALLWAY2_HPP
#define HALLWAY2_HPP

#include "Room.hpp"

class Hallway2 :
	public Room
{
public:
	Hallway2();
	virtual ~Hallway2();
	virtual bool use(Item *i);
};

#endif