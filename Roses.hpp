#ifndef ROSES_HPP
#define ROSES_HPP

#include "Room.hpp"
class Roses :
	public Room
{
public:
	Roses();
	virtual ~Roses();
	virtual bool use(Item *i);
	virtual bool enter(bool isLit);
};

#endif