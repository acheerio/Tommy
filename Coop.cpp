#include "Coop.hpp"
#include <iostream>


/*********************************************************************
** Function: Coop()
** Description: Default constructor
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Base constructor called, long description set.
*********************************************************************/
Coop::Coop() : Room(17, "The Chicken Coop", true, false, 0, false, "", "")
{
	longDesc =
		"The chicken coop is small, but fortunately, so are you! You manage to slip\n"
		"inside with plenty of overhead even underneath the low ceiling. It is warm\n"
		"and dark here, sound is muffled, and the chicken smell (quite unlike KFC)\n"
		"is strong.\n"
		"   A fierce looking chicken is guarding her nest.";
}


/*********************************************************************
** Function: ~Coop()
** Description: Default destructor
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Memory freed. Virtual destructor calls base destructor.
*********************************************************************/
Coop::~Coop()
{
}


/*********************************************************************
** Function: use(Item *i)
** Description: Returns true if the Item was successfully used, else false
** Parameters: Item *i
** Pre-Conditions: None
** Post-Conditions: Takes Item-specific behavior (adds eggs if gardening
** spade) and returns true, else false.
*********************************************************************/
bool Coop::use(Item * i)
{
	i->use();
	if (i->getID() == 150) /* gardening spade */
	{
		items.add(new Item(170, 0, 0, "three speckled brown eggs",
			"Three speckled brown eggs are still warm in the nest."));
		numItems++;
		return true;
	}
	return false;
}