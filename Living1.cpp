#include "Living1.hpp"
#include <iostream>


/*********************************************************************
** Function: Living1()
** Description: Default constructor
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Base constructor called, long description set,
** default Item(s) added.
*********************************************************************/
Living1::Living1() : Room(10, "The Living Room", true, true, 1, false, "", "")
{
	longDesc =
		"Low lamplight in the corner of the room illuminates a grey sectional\n"
		"sofa next to two large, crushed velvet armchairs. They encircle a classic\n"
		"brick fireplace covered in old greeting cards.";

	items.add(new Item(100, 4, -1, "a green silicone pacifier",
		"A silicone green pacifier is stuck between the sofa cushions.",
		"You cautiously dangle it near her mouth. The Creature sucks it right in\n"
		"and subsides into a contented silence. You breathe a huge sigh of relief."));
}


/*********************************************************************
** Function: ~Living1()
** Description: Default destructor
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Memory freed. Virtual destructor calls base destructor.
*********************************************************************/
Living1::~Living1()
{
}


/*********************************************************************
** Function: use(Item *i)
** Description: Returns true if the Item was successfully used, else false
** Parameters: Item *i
** Pre-Conditions: None
** Post-Conditions: There are no items that interact with this Room. Returns false.
*********************************************************************/
bool Living1::use(Item * i)
{
	std::cout << "Nothing happens." << std::endl;
	return false;
}