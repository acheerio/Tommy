#include "Woods.hpp"
#include <iostream>


/*********************************************************************
** Function: Woods()
** Description: Default constructor
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Base constructor called, long description set,
** default Item(s) added.
*********************************************************************/
Woods::Woods() : Room(1, "At the Lamppost", false, true, 1, false, "", "")
{
	longDesc =
		"In the middle of a snowy clearing is growing (growing?) a black lamppost, the\n"
		"kind of gas light fixture you've seen in movies from a long time ago (England\n"
		"in the early 1900's, to be more specific). It is cold and a little lonely here,\n"
		"surrounded by trees.";

	items.add(new Item(10, 0, 0, "a box of Turkish delight",
		"A round box of Turkish delight is here, spilling out onto the snow."));
}


/*********************************************************************
** Function: ~Woods()
** Description: Default destructor
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Memory freed. Virtual destructor calls base destructor.
*********************************************************************/
Woods::~Woods()
{
}


/*********************************************************************
** Function: use(Item *i)
** Description: Returns true if the Item was successfully used, else false
** Parameters: Item *i
** Pre-Conditions: None
** Post-Conditions: Takes Item-specific behavior (stay = true if wool
** coat is used) and returns true, else false.
*********************************************************************/
bool Woods::use(Item * i)
{
	i->use();
	if (i->getID() == 20) /* wool coat */
	{
		stay = true;
		return true;
	}
	return false;
}


/*********************************************************************
** Function: enter(bool isLit)
** Description: Prints the room description. if stay = false, outputs 
** appropriate message to explain being forced to leave. Return stay.
** Parameters: bool isLit
** Pre-Conditions: None
** Post-Conditions: Output room description, output message if stay = false,
** return stay
*********************************************************************/
bool Woods::enter(bool isLit)
{
	print(isLit);
	if (!stay)
		std::cout << std::endl << "BRRR! It's way too cold to stay here!" << std::endl;
	return stay;
}