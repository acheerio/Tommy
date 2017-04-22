#ifndef NURSERY_HPP
#define NURSERY_HPP

#include "Room.hpp"
class Nursery :
	public Room
{
public:
	Nursery();
	virtual ~Nursery();
	virtual Room* showDirections();
	virtual bool use(Item *i);
	virtual Item* showGetMenu(bool isLit);
	virtual void showOpenMenu(bool isLit);
};

#endif