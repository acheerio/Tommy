#ifndef STUDY_HPP
#define STUDY_HPP

#include "Room.hpp"
class Study :
	public Room
{
public:
	Study();
	virtual ~Study();
	virtual bool use(Item *i);
	virtual void showOpenMenu(bool isLit);
};

#endif