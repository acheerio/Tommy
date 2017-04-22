#include "Nursery.hpp"
#include "Wardrobe.hpp"
#include "Woods.hpp" 
#include "UtilityLib.hpp"
#include <iostream>


/*********************************************************************
** Function: Nursery()
** Description: Default constructor
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Base constructor called, long description set,
** default Item(s) added.
*********************************************************************/
Nursery::Nursery() : Room(4, "Nursery", true, true, 1, false, "dark paneled wardrobe doors",
	"Cold air swirls around you as the well-oiled doors glide soundlessly open.")
{
	longDesc =
		"The nursery is a happy riot of pale pinks and off-whites. In the corner, an\n"
		"upholstered rocking chair and matching ottomon are tucked with a pink quilt\n"
		"and ruffled pink pillows. A dark wood wardrobe looks slightly out of place.\n"
		"The Creature's lair is the lacy white bassinet set close to the far wall.";

	items.add(new Item(40, -1, -1, "a glowing owl nightlight",
		"An adorable owl-shaped nightlight gives off a purple glow.",
		"You hook the owl onto your pajamas, where it illuminates your path."));
}


/*********************************************************************
** Function: ~Nursery()
** Description: Default destructor
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Memory freed. Virtual destructor calls base destructor.
*********************************************************************/
Nursery::~Nursery()
{
}


/*********************************************************************
** Function: showDirections()
** Description: Returns the selected Room pointer if that is a valid
** direction, NULL if no exit that way or door closed
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Takes Returns the selected Room pointer if that is a
** valid direction, NULL if no exit that way or door closed
*********************************************************************/
Room* Nursery::showDirections()
{
	Room* r = Room::showDirections();
	if (r != NULL && north != NULL && r->getID() == north->getID())
	{
		if (!open)
		{
			std::cout << "Good thinking, but it's closed." << std::endl;
			return NULL;
		}
		else /* open */
		{
			std::cout << "You shiver as you step inside." << std::endl;
		}
	}
	return r;
}


/*********************************************************************
** Function: use(Item *i)
** Description: Returns true if the Item was successfully used, else false
** Parameters: Item *i
** Pre-Conditions: None
** Post-Conditions: If the Item is a match, creates and adds secret
** wardrobe passageway, returns true. Else returns false.
*********************************************************************/
bool Nursery::use(Item * i)
{
	if (i->getID() == 160) /* yellow ring */
	{
		i->use();
		Room *room1 = new Woods();
		Room *room2 = new Wardrobe();
		
		room1->setSouth(room2);
		room2->setNorth(room1);
		room2->setSouth(this);

		north = room2;
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
** Item* (or NULL if failed) returned. If the item picked up was the
** nightlight, hasLight set to false.
*********************************************************************/
Item * Nursery::showGetMenu(bool isLit)
{
	Item *toGet = Room::showGetMenu(isLit);
	if (toGet != NULL && toGet->getID() == 40)
		hasLight = false;
	return toGet;
}


/*********************************************************************
** Function: showOpenMenu(bool isLit)
** Description: Displays menu of things to open, takes user
** selection. Option to open wardrobe is only displayed if the secret
** passage was added.
** Parameters: bool isLit
** Pre-Conditions: None
** Post-Conditions: Menu displayed, user selection made, success message
** displayed (if the user did not simply return to main menu).
*********************************************************************/
void Nursery::showOpenMenu(bool isLit)
{
	if (!isLit && !hasLight)
	{
		std::cout << "It's too dark -- you can't see anything to open!" << std::endl;
	}
	else if ((open) || north == NULL)
		std::cout << "There is nothing to open here." << std::endl;
	else /* passage is there but closed */
	{
		open = getSimpleTrigger("What would you like to open?", openItem, openSuccess);
	}
}