#include "Backyard1.hpp"
#include <iostream>


/*********************************************************************
** Function: Backyard1()
** Description: Default constructor
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Base constructor called, long description set,
** default Item(s) added.
*********************************************************************/
Backyard1::Backyard1() : Room(13, "The Backyard", true, false, 1, false, "", "")
{
	longDesc =
		"A fragrant wall of creeping jasmine gives off a sweet scent in the cool\n"
		"night air. Lush green grass, just overdue for a mow, glistens with moisture, If\n"
		"you stay still, you hear the distant hooting of an owl and the closer sounds of\n"
		"canine snuffling. A high canopy of trees blocks any moonlight you might see.";

	items.add(new Item(130, 9, 9, "a painted metal pail",
		"A brightly painted metal pail is upended here, serving as a stool.",
		"You place the pail in front of the open refrigerator and climb dexterously on.\n"
		"Ah, there's the orange juice. It's heavy... WHOOPS!"));
}


/*********************************************************************
** Function: ~Backyard1()
** Description: Default destructor
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Memory freed. Virtual destructor calls base destructor.
*********************************************************************/
Backyard1::~Backyard1()
{
}


/*********************************************************************
** Function: use(Item *i)
** Description: Returns true if the Item was successfully used, else false
** Parameters: Item *i
** Pre-Conditions: None
** Post-Conditions: There are no items that interact with this Room. Returns false.
*********************************************************************/
bool Backyard1::use(Item * i)
{
	std::cout << "Nothing happens." << std::endl;
	return false;
}