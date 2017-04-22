#ifndef BACKYARD1_HPP
#define BACKYARD1_HPP

#include "Room.hpp"
class Backyard1 :
	public Room
{
public:
	Backyard1();
	virtual ~Backyard1();
	virtual bool use(Item *i);
};

#endif