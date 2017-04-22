#include "Room.hpp"
#include "UtilityLib.hpp"
#include <iostream>


/*********************************************************************
** Function: Room()
** Description: Default constructor
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Member variables initialized
*********************************************************************/
Room::Room()
{
	id = -1;
	std::string shortDesc = "";
	std::string longDesc = "";
	stay = true;
	hasLight = true;
	searched = false;
	numItems = 0;
	open = false;
	openItem = "";
	openSuccess = "";
	north = NULL;
	south = NULL;
	east = NULL;
	west = NULL;
}


/*********************************************************************
** Function: Room()
** Description: Default constructor
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Member variables initialized
*********************************************************************/
Room::Room(int id, std::string sDesc, bool stay, bool light, int items,
	bool opened, std::string oItem, std::string oSuccess)
{
	this->id = id;
	shortDesc = sDesc;
	/* longDesc intentionally omitted */
	this->stay = stay;
	hasLight = light;
	searched = false;
	numItems = items;
	open = opened;
	openItem = oItem;
	openSuccess = oSuccess;
	north = NULL;
	south = NULL;
	east = NULL;
	west = NULL;
}


/*********************************************************************
** Function: ~Room()
** Description: Default destructor
** Parameters: None
** Pre-Conditions: north, east, south, west are either NULL or valid
** Rooms (e.g. not pointing to deleted memory)
** Post-Conditions: All pointers to this Room set to NULL. Delete called
** on adjoining rooms not already in the call stack. Memory freed.
*********************************************************************/
Room::~Room()
{
	searched = true;

	/* dereference the pointers pointing to this room */
	if (north != NULL)
		north->south = NULL;
	if (east != NULL)
		east->west = NULL;
	if (south != NULL)
		south->north = NULL;
	if (west != NULL)
		west->east = NULL;

	/* delete connected rooms not already on call stack */
	if (north != NULL && north->searched == false)
		delete north;
	if (east != NULL && east->searched == false)
		delete east;
	if (south != NULL && south->searched == false)
		delete south;
	if (west != NULL && west->searched == false)
		delete west;
}


/*********************************************************************
** Function: getID()
** Description: Simple accessor method for id
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Returns id
*********************************************************************/
int Room::getID()
{
	return id;
}


/*********************************************************************
** Function: getName()
** Description: Simple accessor method for short description
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Returns shortDesc
*********************************************************************/
std::string Room::getName()
{
	return shortDesc;
}


/*********************************************************************
** Function: getStay()
** Description: Simple accessor method for stay variable
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Returns whether the player can stay in the room
** (true) or not (false)
*********************************************************************/
bool Room::getStay()
{
	return stay;
}


/*********************************************************************
** Function: getLight()
** Description: Simple accessor method for hasLight
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Returns whether the room has its own light source
** (true) or not (false)
*********************************************************************/
bool Room::getLight()
{
	return hasLight;
}


/*********************************************************************
** Function: getSearched()
** Description: Simple accessor method for searched.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Returns whether the room has already been searched
** (true) or not (false). Should be reset with setSearched() after each
** search.
*********************************************************************/
bool Room::getSearched()
{
	return searched;
}


/*********************************************************************
** Function: setSearched()
** Description: Simple mutator method for searched
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Sets searched to specified bool
*********************************************************************/
void Room::setSearched(bool s)
{
	searched = s;
}


/*********************************************************************
** Function: getNorth()
** Description: Simple accessor method for Room to north of this Room
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Returns pointer to a Room or NULL
*********************************************************************/
Room * Room::getNorth()
{
	return north;
}


/*********************************************************************
** Function: getEast()
** Description: Simple accessor method for Room to east of this Room
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Returns pointer to a Room or NULL
*********************************************************************/
Room * Room::getEast()
{
	return east;
}


/*********************************************************************
** Function: getSouth()
** Description: Simple accessor method for Room to south of this Room
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Returns pointer to a Room or NULL
*********************************************************************/
Room * Room::getSouth()
{
	return south;
}


/*********************************************************************
** Function: getWest()
** Description: Simple accessor method for Room to west of this Room
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Returns pointer to a Room or NULL
*********************************************************************/
Room * Room::getWest()
{
	return west;
}


/*********************************************************************
** Function: setNorth()
** Description: Simple mutator method to set north Room pointer
** Parameters: Room *r
** Pre-Conditions: None
** Post-Conditions: north pointer set to specified value
*********************************************************************/
void Room::setNorth(Room *r)
{
	north = r;
}


/*********************************************************************
** Function: setEast()
** Description: Simple mutator method to set east Room pointer
** Parameters: Room *r
** Pre-Conditions: None
** Post-Conditions: east pointer set to specified value
*********************************************************************/
void Room::setEast(Room *r)
{
	east = r;
}


/*********************************************************************
** Function: setSouth()
** Description: Simple mutator method to set south Room pointer
** Parameters: Room *r
** Pre-Conditions: None
** Post-Conditions: south pointer set to specified value
*********************************************************************/
void Room::setSouth(Room *r)
{
	south = r;
}


/*********************************************************************
** Function: setWest()
** Description: Simple mutator method to set west Room pointer
** Parameters: Room *r
** Pre-Conditions: None
** Post-Conditions: west pointer set to specified value
*********************************************************************/
void Room::setWest(Room *r)
{
	west = r;
}


/*********************************************************************
** Function: print()
** Description: If room is lit or player has light, shows room short and 
** long descriptions
** Parameters: bool isLit
** Pre-Conditions: None
** Post-Conditions: Room description (or that it's dark) outputted to
** display
*********************************************************************/
void Room::print(bool isLit)
{
	/* print room short desc */
	std::cout << std::endl << shortDesc << std::endl;
	if (isLit || hasLight)
	{
		/* print room long desc */
		std::cout << longDesc << std::endl;
		/* print items */
		if (numItems > 0)
			items.print(); /* will work for numItems = 0 but function call less efficient */
	}
	else
		std::cout << "It's dark! You can't see a thing!" << std::endl;
}


/*********************************************************************
** Function: enter(bool isLit)
** Description: prints room description and returns stay boolean. (If
** stay is false, Game will allow user to use one Item and check stay 
** again.)
** Parameters: bool isLit
** Pre-Conditions: None
** Post-Conditions: Outputs room description and returns stay boolean
*********************************************************************/
bool Room::enter(bool isLit)
{
	print(isLit);
	return stay;
}


/*********************************************************************
** Function: showDirections()
** Description: Displays a menu and reads input, returns pointer to
** Room in selected direction
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Menu outputted, valid selected read, returns pointer
** to Room in selected direction
*********************************************************************/
Room* Room::showDirections()
{
	char select = '\0';

	while (true)
	{
		std::cout << std::endl << "What direction would you like to go? ('N', 'S', 'E', 'W')" << std::endl;

		std::cout << "   North: ";
		if (north != NULL)
			std::cout << north->getName() << std::endl;
		else
			std::cout << "No exit here." << std::endl;

		std::cout << "   South: ";
		if (south != NULL)
			std::cout << south->getName() << std::endl;
		else
			std::cout << "No exit here." << std::endl;

		std::cout << "   East: ";
		if (east != NULL)
			std::cout << east->getName() << std::endl;
		else
			std::cout << "No exit here." << std::endl;

		std::cout << "   West: ";
		if (west != NULL)
			std::cout << west->getName() << std::endl;
		else
			std::cout << "No exit here." << std::endl;

		std::cin >> select;
		std::cin.ignore(1000, '\n');

		switch (select)
		{
		case 'N':
		case 'n':
			return north;
		case 'S':
		case 's':
			return south;
		case 'E':
		case 'e':
			return east;
		case 'W':
		case 'w':
			return west;
		default:
			std::cout << std::endl << "Please select a valid option." << std::endl;
			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(1000, '\n');
			}
		}
		std::cout << std::endl;
	}
}


/*********************************************************************
** Function: showGetMenu(bool isLit)
** Description: Displays menu of Items you can get in the Room (or message
** if it is too dark to see, or there is nothing to get)
** Parameters: bool isLit
** Pre-Conditions: None
** Post-Conditions: Menu displayed, valid selection inputted, the selected
** Item* (or NULL if failed) returned
*********************************************************************/
Item* Room::showGetMenu(bool isLit)
{
	if (!isLit && !hasLight)
	{
		std::cout << "It's too dark -- you can't see anything to get!" << std::endl;
		return NULL;
	}
	else
	{
		/* no Items to get */
		if (numItems == 0)
		{
			std::cout << "There's nothing here to get." << std::endl;
			return NULL;
		}
		/* select Item to get from menu */
		else
		{
			Item *toGet = items.displayAsMenu();
			if (toGet != NULL)
			{
				std::cout << "You pick up " << toGet->getName() << "." << std::endl;
				items.remove(toGet);
				numItems--;
			}
			return toGet;
		}
	}
}


/*********************************************************************
** Function: showOpenMenu(bool isLit)
** Description: Displays what you can open in the Room (or message
** if it is too dark to see, or there is nothing to open)
** Parameters: bool isLit
** Pre-Conditions: None
** Post-Conditions: Menu displayed, valid selection inputted, open is
** set to selected value
*********************************************************************/
void Room::showOpenMenu(bool isLit)
{
	/* too dark */
	if (!isLit && !hasLight)
	{
		std::cout << "It's too dark -- you can't see anything to open!" << std::endl;
	}
	/* item already opened, or nothing to open in this Room */
	else if (open || openItem == "")
		std::cout << "There is nothing to open here." << std::endl;
	else /* there is an item to open, and it is closed */
	{
		open = getSimpleTrigger("What would you like to open?", openItem, openSuccess);
	}
}
