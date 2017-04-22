#include "Roses.hpp"
#include <iostream>


/*********************************************************************
** Function: Roses()
** Description: Default constructor
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Base constructor called, long description set,
** default Item(s) added.
*********************************************************************/
Roses::Roses() : Room(15, "Mrs. Spencer's Rose Garden", false, false, 1, false, "", "")
{
	longDesc =
		"Ouch! Abruptly you notice that gone are the tickling little branches of the\n"
		"hedge. You have emerged in Mrs. Spencer's prized rose garden, where she spends\n"
		"many a happy morning tending away. There are the pink-and-white gradient Double\n"
		"Delights, giving off a sweet smell, delicate pink English roses, and too many\n"
		"others to name.\n"
		"   Mrs. Spencer's pugnacious bulldog is here, looking threatening.";

	items.add(new Item(150, 17, 17, "a sharp metal gardening spade",
		"A dark metal gardening spade lies here, obscured by the dirt.",
		"You CAREFULLY scoop up the hen with the spade while parrying her pecks."));
}


/*********************************************************************
** Function: ~Roses()
** Description: Default destructor
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Memory freed. Virtual destructor calls base destructor.
*********************************************************************/
Roses::~Roses()
{
}


/*********************************************************************
** Function: use(Item *i)
** Description: Returns true if the Item was successfully used, else false
** Parameters: Item *i
** Pre-Conditions: None
** Post-Conditions: Takes Item-specific behavior (stay = true if ham
** bone is used, adds roses if scissors used) and returns true, else false.
*********************************************************************/
bool Roses::use(Item * i)
{
	i->use();
	if (i->getID() == 90) /* ham bone */
	{
		stay = true;
		return true;
	}
	else if (i->getID() == 52) /* scissors */
	{
		items.add(new Item(151, 0, 0, "some beautiful, prize-winning roses",
			"Mrs. Spencer's prize-winning roses lie ruthlessly severed on the ground."));
		numItems++;
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
bool Roses::enter(bool isLit)
{
	print(isLit);
	if (!stay)
		std::cout << std::endl << "The dog growls, approaches, and starts barking like a maniac!" << std::endl;
	return stay;
}