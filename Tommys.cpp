#include "Tommys.hpp"
#include <iostream>


/*********************************************************************
** Function: Tommys()
** Description: Default constructor
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Base constructor called, long description set,
** default Item(s) added.
*********************************************************************/
Tommys::Tommys() : Room(7, "Tommy's Room", true, true, 3, false, "the door", 
	"You can't, it's locked!")
{
	longDesc =
		"Ah, your favorite room in the house! The walls are covered in dinosaur decals\n"
		"and posters, especially your favorite, the gallant Stegosaurus (that's how\n"
		"you think of him in your mind). Against one wall is your crib, and next to it\n"
		"is your shelf of books and toys.";

	items.add(new Item(70, -1, -1, "a cloth dinosaur backpack",
		"A half-zipped dinosaur backpack lies empty on the ground.",
		"You empty your pockets into the backpack and happily strap it on."));
	items.add(new Item(71, 7, 7, "toy knife",
		"A blue wooden toy knife is wedged underneath the toy box.",
		"You wedge the knife inside the child safety lock, disabling it and opening\n"
		"the door."));
	items.add(new Item(80, 8, 8, "a pile of stuffed animals",
		"A ratty stuffed animal collection is piled in disarray."));

	backpack = false;
}


/*********************************************************************
** Function: ~Tommys()
** Description: Default destructor
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Memory freed. Virtual destructor calls base destructor.
*********************************************************************/
Tommys::~Tommys()
{
}


/*********************************************************************
** Function: enter(bool isLit)
** Description: Removes Crib room. Prints the room description. 
** Return stay.
** Parameters: bool isLit
** Pre-Conditions: None
** Post-Conditions: Delete adjoining Room Crib, output room description, 
** return stay
*********************************************************************/
bool Tommys::enter(bool isLit)
{
	/* remove Crib as room */
	if (getEast() != NULL)
	{
		Room *temp = east;
		temp->setWest(NULL);
		east = NULL;
		delete temp;
	}

	return Room::enter(isLit);
}


/*********************************************************************
** Function: showDirections()
** Description: Returns the selected Room pointer if that is a valid
** direction, NULL if not
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Takes Returns the selected Room pointer if that is a
** valid direction, NULL if no exit that way, required task not
** accomplished (picking up backpack), or door closed
*********************************************************************/
Room* Tommys::showDirections()
{
	Room* r = Room::showDirections();
	if (r != NULL && west != NULL 
		&& r->getID() == west->getID())
	{
		if (!open)
		{
			std::cout << "There's a child safety lock on the doorknob." << std::endl;
			return NULL;
		}
		else if (!backpack) /* open but backpack not picked up yet */
		{
			std::cout << "Feeling like you're forgetting something, you turn around right as you get to\n"
				"the doorway, trip, and bang your forehead hard against the wall." << std::endl;
			return NULL;
		}
		else
			return r;
	}
	
	return r;
}


/*********************************************************************
** Function: use(Item *i)
** Description: Returns true if the Item was successfully used, else false
** Parameters: Item *i
** Pre-Conditions: None
** Post-Conditions: Takes Item-specific behavior (opens the door if
** toy knife used) and returns true, else false.
*********************************************************************/
bool Tommys::use(Item * i)
{
	i->use();
	if (i->getID() == 71) /* toy knife */
	{
		open = true;
		return true;
	}
	return false;
}


/*********************************************************************
** Function: showGetMenu(bool isLit)
** Description: Displays menu of Items you can get in the Room (or message
** if it is too dark to see, or there is nothing to get)
** Parameters: bool isLit
** Pre-Conditions: None
** Post-Conditions: Menu displayed, valid selection inputted, the selected
** Item* (or NULL if failed) returned. If the selection was backpack,
** backpack = true (will allow player to leave room).
*********************************************************************/
Item* Tommys::showGetMenu(bool isLit)
{
	Item *toGet = Room::showGetMenu(isLit);
	if (toGet != NULL && toGet->getID() == 70) /* backpack */
		backpack = true;
	return toGet;
}


/*********************************************************************
** Function: showOpenMenu(bool isLit)
** Description: Displays menu of things/doors to open, takes user
** selection. Open value does not change, because a special Item must
** be used to unlock the door.
** Parameters: bool isLit
** Pre-Conditions: None
** Post-Conditions: Menu displayed, user selection made, failure message
** displayed to user (or returned to main menu without action)
*********************************************************************/
void Tommys::showOpenMenu(bool isLit)
{
	bool wasOpen = open;
	Room::showOpenMenu(isLit);
	if (open != wasOpen) /* reset the value */
		open = wasOpen;
}