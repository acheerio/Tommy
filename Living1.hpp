#ifndef LIVING1_HPP
#define LIVING1_HPP

#include "Room.hpp"

class Living1 :
	public Room
{
public:
	Living1();
	virtual ~Living1();
	virtual bool use(Item *i);
};

#endif