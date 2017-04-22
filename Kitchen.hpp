#ifndef KITCHEN_HPP
#define KITCHEN_HPP

#include "Room.hpp"
class Kitchen :
	public Room
{
public:
	Kitchen();
	virtual ~Kitchen();
	virtual void print(bool isLit);
	virtual bool use(Item *i);
	virtual void showOpenMenu(bool isLit);
	virtual Item* showGetMenu(bool isLit);
private:
	Item* oj;
};

#endif