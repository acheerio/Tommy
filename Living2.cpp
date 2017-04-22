#include "Living2.hpp"
#include <iostream>


/*********************************************************************
** Function: Living2()
** Description: Default constructor
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Base constructor called, long description set,
** default Item(s) added.
*********************************************************************/
Living2::Living2() : Room(12, "The Living Room", true, true, 1, false, "glass sliding doors", 
	"With some effort, you push open the heavy glass doors.")
{
	longDesc =
		"In front of the television, several large, colorful bean bags are strewn\n"
		"across a thick, dark rug. Sliding glass doors connect to the backyard, but\n"
		"it is so dark outside you can only see your dim reflection in the glass.";

	items.add(new Item(120, 9, 9, "a plastic red sippy cup",
		"A plastic sippy cup lies in a small wet spot on the rug.",
		"You place the cup on the ground and carefully fill it with juice. You even\n"
		"remember to put the carton back in the fridge!"));
}


/*********************************************************************
** Function: ~Living2()
** Description: Default destructor
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Memory freed. Virtual destructor calls base destructor.
*********************************************************************/
Living2::~Living2()
{
}


/*********************************************************************
** Function: showDirections()
** Description: Returns the selected Room pointer if that is a valid
** direction, NULL if no exit that way or door closed
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Takes Returns the selected Room pointer if that is a
** valid direction, NULL if no exit that way or door closed
*********************************************************************/
Room* Living2::showDirections()
{
	Room *r = Room::showDirections();
	if (r != NULL && east != NULL 
		&& r->getID() == east->getID() && !open)
	{
		std::cout << "The doors may be glass, but they're still there!" << std::endl;
		return NULL;
	}
	else
		return r;
}


/*********************************************************************
** Function: use(Item *i)
** Description: Returns true if the Item was successfully used, else false
** Parameters: Item *i
** Pre-Conditions: None
** Post-Conditions: There are no items that interact with this Room. Returns false.
*********************************************************************/
bool Living2::use(Item * i)
{
	std::cout << "Nothing happens." << std::endl;
	return false;
}