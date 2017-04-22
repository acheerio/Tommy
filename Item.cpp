#include "Item.hpp"
#include <iostream>


/*********************************************************************
** Function: Item()
** Description: Default constructor
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Member variables initialized
*********************************************************************/
Item::Item()
{
	id = 0;
	activeRm = 0; /* activeRm of -1 means active anywhere */
	targetRm = 0; /* targetRm of -1 means action taken at Game level */
	shortDesc = "";
	longDesc = "";
	useDesc = "";
}


/*********************************************************************
** Function: Item(int id, int active, int target, std::string sDesc, std::string lDesc)
** Description: Constructor
** Parameters: int id, int active, int target, string sDesc, string lDesc
** Pre-Conditions: None
** Post-Conditions: Member variables initialized to specified values,
** useDesc is generic.
*********************************************************************/
Item::Item(int id, int active, int target, std::string sDesc, std::string lDesc)
{
	this->id = id;
	activeRm = active;
	targetRm = target;
	shortDesc = sDesc;
	longDesc = lDesc;
	useDesc = "You use the " + shortDesc + ".";
}


/*********************************************************************
** Function: Item(int id, int active, int target, string sDesc, string 
** lDesc, string uDesc)
** Description: Constructor
** Parameters: int id, int active, int target, string sDesc, string 
** lDesc, string uDesc
** Pre-Conditions: None
** Post-Conditions: Member variables initialized to specified values,
** including a specialized useDesc.
*********************************************************************/
Item::Item(int id, int active, int target, std::string sDesc, std::string lDesc, std::string uDesc)
{
	this->id = id;
	activeRm = active;
	targetRm = target;
	shortDesc = sDesc;
	longDesc = lDesc;
	useDesc = uDesc;
}


/*********************************************************************
** Function: ~Item()
** Description: Default virtual destructor
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Memory freed
*********************************************************************/
Item::~Item()
{
}


/*********************************************************************
** Function: getName()
** Description: Accessor method for Item's short description
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: shortDesc returned
*********************************************************************/
std::string Item::getName()
{
	return shortDesc;
}


/*********************************************************************
** Function: getID()
** Description: Accessor method for Item's ID number
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: id returned
*********************************************************************/
int Item::getID()
{
	return id;
}


/*********************************************************************
** Function: getActive()
** Description: Accessor method for Item's active room, where the Item
** can be used.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Return the active room id. Should be -1, 0, or valid room 
** ID number.
*********************************************************************/
int Item::getActive()
{
	return activeRm;
}


/*********************************************************************
** Function: getTarget()
** Description: Accessor method for Item's target room, which takes
** action depending on the used Item.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Return the target room id. Should be -1, 0, or valid
** room ID number.
*********************************************************************/
int Item::getTarget()
{
	return targetRm;
}


/*********************************************************************
** Function: printLong()
** Description: Prints the Item's long (sentence) description, used
** when showing the room description
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Long description outputted to display.
*********************************************************************/
void Item::printLong()
{
	std::cout << longDesc << std::endl;
}


/*********************************************************************
** Function: use()
** Description: Prints the Item's useDesc, when the object is succesfully
** used.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Use description outputted to display.
*********************************************************************/
void Item::use()
{
	std::cout << useDesc << std::endl;
}
