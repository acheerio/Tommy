#include "Study.hpp"
#include <iostream>


/*********************************************************************
** Function: Study()
** Description: Default constructor
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Base constructor called, long description set,
** default Item(s) added.
*********************************************************************/
Study::Study() : Room(5, "The Study", true, true, 1, false, "partly closed desk drawer",
	"It's stuck. You pull harder and the drawer finally opens with a clatter.")
{
	longDesc =
		"The sides of the room are covered with dark wood bookshelves, built into the\n"
		"walls, filled with an odd hodgepodge of books: from Chaucer in Middle English\n"
		"to a dog-eared copy of Harry Potter. Thin paperbacks are piled on heavy\n"
		"leatherbound volumes in no apparent order. Slippers are on the floor and\n"
		"papers are everywhere.\n"
		"   A heavy wooden desk sits in the center of the room, one drawer ajar.";
	
	items.add(new Item(50, 0, 0, "a handful of markers",
		"Some markers and highlighters stick out of the pencil holder."));
}


/*********************************************************************
** Function: ~Study()
** Description: Default destructor
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Memory freed. Virtual destructor calls base destructor.
*********************************************************************/
Study::~Study()
{
}


/*********************************************************************
** Function: use(Item *i)
** Description: Returns true if the Item was successfully used, else false
** Parameters: Item *i
** Pre-Conditions: None
** Post-Conditions: There are no items that interact with this Room. Returns false.
*********************************************************************/
bool Study::use(Item * i)
{
	std::cout << "Nothing happens." << std::endl;
	return false;
}


/*********************************************************************
** Function: showOpenMenu(bool isLit)
** Description: Displays menu of things to open, takes user
** selection. If was closed and now is open, adds Items to the room.
** Parameters: bool isLit
** Pre-Conditions: None
** Post-Conditions: Menu displayed, user selection made. Based on selection,
** Items may be added to Room.
*********************************************************************/
void Study::showOpenMenu(bool isLit)
{
	bool wasOpen = open;
	Room::showOpenMenu(isLit);
	if (!wasOpen && open) /* value changed */
	{
		items.add(new Item(51, 0, 0, "some construction paper",
			"A crumpled piece of red paper peeks out from the drawer."));
		items.add(new Item(52, 15, 15, "a sharp pair of scissors",
			"A pair of sharp rubber-grip scissors beckons enticingly.",
			"Snip! Snip! Several brightly colored roses spill to the ground.\n"
			"Ah, the scissors are stuck in the thorns."));
		numItems = numItems + 2;
	}

}