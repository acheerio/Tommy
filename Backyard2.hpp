#ifndef BACKYARD2_HPP
#define BACKYARD2_HPP

#include "Room.hpp"
class Backyard2 :
	public Room
{
public:
	Backyard2();
	virtual ~Backyard2();
	virtual Room* showDirections();
	virtual bool use(Item *i);
};

#endif