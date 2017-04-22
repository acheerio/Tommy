#include "Backyard2.hpp"
#include <iostream>


/*********************************************************************
** Function: Backyard2()
** Description: Default constructor
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Base constructor called, long description set,
** default Item(s) added.
*********************************************************************/
Backyard2::Backyard2() : Room(16, "The Backyard", true, false, 1, false, "wooden coop door",
	"You climb past the chicken wire and slide open the hatch.")
{
	longDesc =
		"The lush grassy lawn ends abruptly before a low wall of chicken wire held up by\n"
		"thin metal posts. On the other side  the ground is hard dirt, and the smell of\n"
		"jasmine is overpowered by a musty odor emanating from a low building in the\n"
		"corner of the yard.";
	
	items.add(new Item(160, -1, 4, "a bright yellow ring",
		"A very bright yellow ring, hidden in the grass, seems to hum with power.",
		"You slip the ring on your finger and feel your skin prickle."));
}


/*********************************************************************
** Function: ~Backyard2()
** Description: Default destructor
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Memory freed. Virtual destructor calls base destructor.
*********************************************************************/
Backyard2::~Backyard2()
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
Room* Backyard2::showDirections()
{
	Room* r = Room::showDirections();
	if (r != NULL && south != NULL && 
		r->getID() == south->getID() && !open)
	{
		std::cout << "Unfortunately, there is a hard wooden coop door in your way." << std::endl;
		return NULL;
	}
	else
		return r;
}


/*********************************************************************
** Function: use(Item *i)
** Description: Returns true if the Item was successfully used, else false.
** Parameters: Item *i
** Pre-Conditions: None
** Post-Conditions: There are no items that interact with this Room. Returns false.
*********************************************************************/
bool Backyard2::use(Item * i)
{
	std::cout << "Nothing happens." << std::endl;
	return false;
}