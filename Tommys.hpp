#ifndef TOMMYS_HPP
#define TOMMYS_HPP

#include "Room.hpp"
class Tommys :
	public Room
{
public:
	Tommys();
	virtual ~Tommys();
	virtual bool enter(bool isLit);
	virtual Room* showDirections();
	virtual bool use(Item *i);
	virtual Item* showGetMenu(bool isLit);
	virtual void showOpenMenu(bool isLit);
private:
	bool backpack;
};

#endif