#include "Dining.hpp"
#include <iostream>


/*********************************************************************
** Function: Dining()
** Description: Default constructor
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Base constructor called, long description set.
*********************************************************************/
Dining::Dining() : Room(11, "Dining Room", true, true, 0, false, "an elegant sideboard", 
	"The sideboard drawer glides easily open at your tugging.")
{
	longDesc =
		"A long, heavy wooden table is covered by a pale green table cloth and an\n"
		"elegant table runner. In the center is an simple centerpiece: a low vase of\n"
		"pale and dark yellow daffodils arranged with dark pink tulips. White china is\n"
		"set out on the table, ready for company, and feels somewhat creepy in the dark.\n"
		"   An elegant, matching sideboard is set along the length of the wall.";
}


/*********************************************************************
** Function: ~Dining()
** Description: Default destructor
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Memory freed. Virtual destructor calls base destructor.
*********************************************************************/
Dining::~Dining()
{
}


/*********************************************************************
** Function: use(Item *i)
** Description: Returns true if the Item was successfully used, else false
** Parameters: Item *i
** Pre-Conditions: None
** Post-Conditions: There are no items that interact with this Room. Returns false.
*********************************************************************/
bool Dining::use(Item * i)
{
	std::cout << "Nothing happens." << std::endl;
	return false;
}


/*********************************************************************
** Function: showOpenMenu(bool isLit)
** Description: Displays menu of things to open, takes user
** selection. If was closed and now is open, adds Item to the room.
** Parameters: bool isLit
** Pre-Conditions: None
** Post-Conditions: Menu displayed, user selection made. Based on selection,
** Item may be added to Room.
*********************************************************************/
void Dining::showOpenMenu(bool isLit)
{
	bool wasOpen = open;
	Room::showOpenMenu(isLit);
	if (!wasOpen && open) /* value changed */
	{
		items.add(new Item(110, 0, 0, "a stale piece of toast",
			"The toast you hid during last night's dinner is still in the sideboard."));
		numItems++;
	}
}