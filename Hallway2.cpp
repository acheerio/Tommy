#include "Hallway2.hpp"
#include <iostream>


/*********************************************************************
** Function: Hallway2()
** Description: Default constructor
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Base constructor called, long description set.
*********************************************************************/
Hallway2::Hallway2() : Room(6, "The Hallway", true, true, 0, false, "", "")
{
	longDesc =
		"Here the family portraits on the walls are older: the photos are black\n"
		"and white, the elegantly coiffed subjects formally seated. The warmth\n"
		"and comfort of bed call you from one side, while the smell of musty\n"
		"books drifts in from the other.";
}


/*********************************************************************
** Function: ~Hallway2
** Description: Default destructor
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Memory freed. Virtual destructor calls base destructor.
*********************************************************************/
Hallway2::~Hallway2()
{
}


/*********************************************************************
** Function: use(Item *i)
** Description: Returns true if the Item was successfully used, else false
** Parameters: Item *i
** Pre-Conditions: None
** Post-Conditions: There are no items that interact with this Room. Returns false.
*********************************************************************/
bool Hallway2::use(Item * i)
{
	std::cout << "Nothing happens." << std::endl;
	return false;
}