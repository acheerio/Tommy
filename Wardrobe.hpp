#ifndef WARDROBE_HPP
#define WARDROBE_HPP

#include "Room.hpp"
class Wardrobe :
	public Room
{
public:
	Wardrobe();
	virtual ~Wardrobe();
	virtual bool use(Item *i);
};

#endif