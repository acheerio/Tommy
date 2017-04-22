#ifndef DINING_HPP
#define DINING_HPP

#include "Room.hpp"
class Dining :
	public Room
{
public:
	Dining();
	virtual ~Dining();
	virtual bool use(Item *i);
	virtual void showOpenMenu(bool isLit);
};

#endif