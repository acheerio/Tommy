#ifndef HALLWAY1_HPP
#define HALLWAY1_HPP

#include "Room.hpp"

class Hallway1 :
	public Room
{
public:
	Hallway1();
	virtual ~Hallway1();
	virtual Room* showDirections();
	virtual bool use(Item *i);
	virtual void showOpenMenu(bool isLit);
};

#endif