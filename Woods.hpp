#ifndef WOODS_HPP
#define WOODS_HPP

#include "Room.hpp"
class Woods :
	public Room
{
public:
	Woods();
	virtual ~Woods();
	virtual bool use(Item *i);
	virtual bool enter(bool isLit);
};

#endif