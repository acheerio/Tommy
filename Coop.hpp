#ifndef COOP_HPP
#define COOP_HPP

#include "Room.hpp"
class Coop :
	public Room
{
public:
	Coop();
	virtual ~Coop();
	virtual bool use(Item *i);
};

#endif