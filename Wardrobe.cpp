#include "Wardrobe.hpp"
#include <iostream>


/*********************************************************************
** Function: Wardrobe()
** Description: Default constructor
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Base constructor called, long description set,
** default Item(s) added.
*********************************************************************/
Wardrobe::Wardrobe() : Room(2, "Inside the Wardrobe", true, false, 1, false, "", "")
{
	longDesc =
		"It's pretty much an ordinary wardrobe. You would know, as it is a coveted\n"
		"location for hide-and-seek. But the odd thing is, it seems bigger than you\n"
		"remember. And... colder? Abruptly, you realize that what you're feeling is\n"
		"not wool coats, but... fir trees? Hmmm...";

	items.add(new Item(20, -1, 1, "a small wool coat",
		"A small, smart blue wool coat hangs here, smelling of mothballs.",
		"You slip the soft coat right on, and feel snug and warm."));
}


/*********************************************************************
** Function: ~Wardrobe()
** Description: Default destructor
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Memory freed. Virtual destructor calls base destructor.
*********************************************************************/
Wardrobe::~Wardrobe()
{
}


/*********************************************************************
** Function: use(Item *i)
** Description: Returns true if the Item was successfully used, else false
** Parameters: Item *i
** Pre-Conditions: None
** Post-Conditions: There are no items that interact with this Room. Returns false.
*********************************************************************/
bool Wardrobe::use(Item * i)
{
	std::cout << "Nothing happens." << std::endl;
	return false;
}