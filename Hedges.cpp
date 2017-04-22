#include "Hedges.hpp"
#include <iostream>


/*********************************************************************
** Function: Hedges()
** Description: Default constructor
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Base constructor called, long description set.
*********************************************************************/
Hedges::Hedges() : Room(14, "Inside the Hedges", true, false, 0, false, "", "")
{
	longDesc =
		"Inside the hedges, you can hardly see at all. The tiny branches touching your\n"
		"skin tickle a bit, and every small movement starts off a storm of rustling.\n"
		"There is a gap between the ground and the bottom of the wood fence, like\n"
		"something has been digging at it, and you can just manage to fit through it.";
}


/*********************************************************************
** Function: ~Hedges()
** Description: Default destructor
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Memory freed. Virtual destructor calls base destructor.
*********************************************************************/
Hedges::~Hedges()
{
}


/*********************************************************************
** Function: use(Item *i)
** Description: Returns true if the Item was successfully used, else false
** Parameters: Item *i
** Pre-Conditions: None
** Post-Conditions: There are no items that interact with this Room. Returns false.
*********************************************************************/
bool Hedges::use(Item * i)
{
	std::cout << "Nothing happens." << std::endl;
	return false;
}