#include "Crib.hpp"
#include <iostream>


/*********************************************************************
** Function: Crib()
** Description: Default constructor
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Base constructor called, long description set,
** default Item(s) added.
*********************************************************************/
Crib::Crib() : Room(8, "Inside the Crib", true, true, 1, false, "", "")
{
	longDesc =
		"Glossy dark wood posts surround a nest of blankets. The bed is soft and still\n"
		"warm, weakening your resolve. But through the wood slats, freedom is in sight!\n"
		"You can see a few stray toys on the floor, overlooked in the cleanup, and the\n"
		"door just a few feet away.";

	items.add(new Item(80, 8, 8, "a pile of stuffed animals",
		"A ratty stuffed animal collection is piled in disarray.",
		"You lob a stuffed polar bear, penguin, and giraffe over the edge!"));
}


/*********************************************************************
** Function: ~Crib()
** Description: Default destructor
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Memory freed. Virtual destructor calls base destructor.
*********************************************************************/
Crib::~Crib()
{
}


/*********************************************************************
** Function: showDirections()
** Description: Returns the selected Room pointer if that is a valid
** direction, NULL if no exit that way or door closed
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Returns the selected Room pointer if that is a
** valid direction, NULL if no exit that way or door closed
*********************************************************************/
Room * Crib::showDirections()
{
	Room* r = Room::showDirections();
	if (r != NULL && west !=NULL && r->getID() == west->getID())
	{
		if (open)
		{
			std::cout << "You climb out of the crib, landing happily on a soft pile." << std::endl;
			return r;
		}
		else
		{
			std::cout << "You can climb out, you just need something to cushion your landing." << std::endl;
			return NULL;
		}
	}

	return r;
}


/*********************************************************************
** Function: use(Item *i)
** Description: Returns true if the Item was successfully used, else false
** Parameters: Item *i
** Pre-Conditions: None
** Post-Conditions: Takes Item-specific behavior (opens = true if stuffed
** animals used) and returns true, else false.
*********************************************************************/
bool Crib::use(Item * i)
{
	i->use();
	if (i->getID() == 80) /* stuffed animals */
	{
		open = true;
		return true;
	}
	return false;
}