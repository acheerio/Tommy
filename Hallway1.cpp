#include "Hallway1.hpp"
#include <iostream>


/*********************************************************************
** Function: Hallway1()
** Description: Default constructor
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Base constructor called, long description set.
*********************************************************************/
Hallway1::Hallway1() : Room(3, "The Hallway", true, true, 0, false, "parents' bedroom door", 
	"What, are you crazy?! That's exactly where you don't want to go.")
{
	longDesc = 
		"Happy family portraits decorate the sides of the walls, the frames\n"
		"cast into relief by the dim glow of the hall nightlight. The sounds of\n"
		"sleepy baby babble are distantly audible to one side, and soft snoring\n"
		"comes from the other.";
}


/*********************************************************************
** Function: ~Hallway1()
** Description: Default destructor
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Memory freed. Virtual destructor calls base destructor.
*********************************************************************/
Hallway1::~Hallway1()
{
}


/*********************************************************************
** Function: showDirections()
** Description: Returns the selected Room pointer if that is a valid
** direction, NULL if no exit that way or door closed. Specifically
** displays one exit as Parents' room though there is no actual Room there.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Takes Returns the selected Room pointer if that is a
** valid direction, NULL if no exit that way or door closed
*********************************************************************/
Room* Hallway1::showDirections()
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

		/* hard coded in 'dummy' exit of parents' room */
		std::cout << "   West: Parents' Room" << std::endl;

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
			std::cout << "There's a door in the way." << std::endl;
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
** Function: use(Item *i)
** Description: Returns true if the Item was successfully used, else false
** Parameters: Item *i
** Pre-Conditions: None
** Post-Conditions: There are no items that interact with this Room. Returns false.
*********************************************************************/
bool Hallway1::use(Item * i)
{
	std::cout << "Nothing happens." << std::endl;
	return false;
}


/*********************************************************************
** Function: showOpenMenu(bool isLit)
** Description: Displays menu of things/doors to open, takes user
** selection. open value stays false, since "parents' door" is unopenable.
** Parameters: bool isLit
** Pre-Conditions: None
** Post-Conditions: Menu displayed, user selection made, failure message
** displayed to user (or returned to main menu without action)
*********************************************************************/
void Hallway1::showOpenMenu(bool isLit)
{
	Room::showOpenMenu(isLit);
	open = false;
}
