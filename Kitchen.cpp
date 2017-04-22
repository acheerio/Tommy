#include "Kitchen.hpp"
#include <iostream>


/*********************************************************************
** Function: Kitchen()
** Description: Default constructor
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Base constructor called, long description set.
*********************************************************************/
Kitchen::Kitchen() : Room(9, "Kitchen", true, true, 0, false, "a stainless steel trash can",
	"You stand on tiptoe to lift up the cover and peer inside, but -- WHOOPS!!\n"
	"You lose your footing and the trash can comes tumbling down with a deafening\n"
	"crash.")
{
	longDesc =
		"The warm glow of the front porch light spills into the kitchen from the window.\n"
		"Dark wood cabinets support dark granite countertops with coffeemaker,\n"
		"Kitchenaid mixer, and chrome finished toaster all neatly at their stations. A\n"
		"large kitchen island occupies the center of the room. If you could climb a bit\n"
		"higher, maybe you could find what you need.\n"
		"   The refrigerator door is cracked open, letting out cool air and light.";

	oj = NULL;
}


/*********************************************************************
** Function: ~Kitchen()
** Description: Default destructor
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Memory freed. Virtual destructor calls base destructor.
*********************************************************************/
Kitchen::~Kitchen()
{
	if (oj != NULL)
		delete oj;
}


/*********************************************************************
** Function: print(bool isLit)
** Description: If lit, prints Room short and long description, and some variable
** portion depending on whether or not the trash can has been opened.
** Parameters: bool isLit
** Pre-Conditions: None
** Post-Conditions: Room description (or that it's dark) outputted to screen.
*********************************************************************/
void Kitchen::print(bool isLit)
{
	std::cout << std::endl << shortDesc << std::endl;
	if (isLit || hasLight)
	{
		std::cout << longDesc << std::endl;
		if (open)
			std::cout << "   A metal trash can lies overturned, spilling out trash." << std::endl;
		else
			std::cout << "   A tall metal trash can is next to the kitchen island." << std::endl;
		if (numItems > 0)
			items.print();
	}
	else
		std::cout << "It's dark! You can't see a thing!" << std::endl;
}


/*********************************************************************
** Function: use(Item *i)
** Description: Returns true if the Item was successfully used, else false
** Parameters: Item *i
** Pre-Conditions: None
** Post-Conditions: Takes Item-specific behavior (adds orange juice if pail
** is used, cup of juice if sippy cup is used) and returns true, else false.
*********************************************************************/
bool Kitchen::use(Item * i)
{
	if (i->getID() == 130) /* stool */
	{
		i->use();
		oj = new Item(122, 0, 0, "a carton of pulpy orange juice",
			"A slightly dented carton of pulpy orange juice lies on its side.");
		items.add(oj);
		numItems++;
		return true;
	}
	if (i->getID() == 120) /* sippy cup */
	{
		if (oj == NULL)
		{
			std::cout << "But what are you planning on using it on?" << std::endl;
			return false;
		}
		else
		{
			i->use();
			items.add(new Item(121, 0, 0, "a sippy cup of orange juice",
				"A sippy cup filled with delightful citrus goodness is on the floor."));
			items.remove(oj);
			delete oj;
			oj = NULL;
			/* numItems stays the same */
			return true;
		}
	}
	return false;
}


/*********************************************************************
** Function: showOpenMenu(bool isLit)
** Description: Displays menu of things to open, takes user
** selection. If open was changed from false to true, adds an Item.
** Parameters: bool isLit
** Pre-Conditions: None
** Post-Conditions: Menu displayed, user selection made, Item added
** depending on selection.
*********************************************************************/
void Kitchen::showOpenMenu(bool isLit)
{
	bool wasOpen = open;
	Room::showOpenMenu(isLit);
	if (!wasOpen && open) /* value changed */
	{
		items.add(new Item(90, 15, 15, "a large ham bone",
			"A large ham bone lies amidst the other trash.",
			"The dog snatches the bone out of your hand and retreats with his prize."));
		numItems++;
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
Item * Kitchen::showGetMenu(bool isLit)
{
	if (!isLit && !hasLight)
	{
		std::cout << "It's too dark -- you can't see anything to get!" << std::endl;
		return NULL;
	}
	else
	{
		if (numItems == 0)
		{
			std::cout << "There's nothing here to get." << std::endl;
			return NULL;
		}
		else
		{
			Item *toGet = items.displayAsMenu();
			if (toGet != NULL)
			{
				if (toGet->getID() == 122) /* orange juice */
				{
					std::cout << "Why don't you use something to take just the amount you need?" << std::endl;
					toGet = NULL;
				}
				else
				{
					std::cout << "You pick up " << toGet->getName() << "." << std::endl;
					items.remove(toGet);
					numItems--;
				}
			}
			return toGet;
		}
	}
}
