#include "LinkedList.hpp"
#include "UtilityLib.hpp"
#include <iostream>

/*********************************************************************
** Function: LinkedList()
** Description: Default constructor
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Member variables initialized
*********************************************************************/
LinkedList::LinkedList()
{
	head = NULL;
}


/*********************************************************************
** Function: ~LinkedList()
** Description: Default destructor
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Memory freed
*********************************************************************/
LinkedList::~LinkedList()
{
	while (!isEmpty())
	{
		LinkedNode *temp = head;
		head = head->next;
		delete temp->data;
		delete temp;
	}
}


/*********************************************************************
** Function: isEmpty()
** Description: Checks whether the list is empty
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Returns true if empty, otherwise false
*********************************************************************/
bool LinkedList::isEmpty()
{
	if (head == NULL)
		return true;
	else
		return false;
}


/*********************************************************************
** Function: add(Item *i)
** Description: Adds Item* to list
** Parameters: Item *i
** Pre-Conditions: None
** Post-Conditions: Item* added to end of list
*********************************************************************/
void LinkedList::add(Item *i)
{
	/* create the new node */
	LinkedNode *n = new LinkedNode();
	n->data = i;
	n->next = NULL;

	/* empty list */
	if (head == NULL)
		head = n;
	/* else find end of list to insert */
	else
	{
		LinkedNode *curr = head;
		LinkedNode *prev = NULL;

		while (curr != NULL)
		{
			prev = curr;
			curr = curr->next;
		}
		
		prev->next = n;
	}
}


/*********************************************************************
** Function: find(int index)
** Description: Helper function for displayAsMenu(). Locates and returns 
** the reference to an Item at specified index without removing.
** Parameters: int index
** Pre-Conditions: None
** Post-Conditions: Returns a pointer to an Item or NULL
*********************************************************************/
Item* LinkedList::find(int index)
{
	/* empty list */
	if (isEmpty())
		return NULL;
	/* list with nodes */
	else
	{
		LinkedNode *curr = head;
		int count = 0;

		/* loop until reaching end of list */
		while (curr != NULL)
		{
			/* break out of loop if reach index */
			if (count == index)
				return curr->data;
			else
			{
				count++;
				curr = curr->next;
			}
		}

		/* didn't find the index */
		std::cout << "That item does not exist." << std::endl;
		return NULL;
	}
}


/*********************************************************************
** Function: remove(Item *i)
** Description: Removes the Item from the list. Deallocates the node
** but not the Item. This allows other classes to perform checks on
** the selected object before confirming removing from list.
** Parameters: Item *i
** Pre-Conditions: i is not NULL
** Post-Conditions: Returns true if successfully removed, else false
** if not found
*********************************************************************/
bool LinkedList::remove(Item * i)
{
	/* empty list */
	if (isEmpty())
		return false;
	/* list with nodes */
	else
	{
		LinkedNode *curr = head;
		LinkedNode *prev = NULL;
		while (curr != NULL)
		{
			if (i->getID() == (curr->data)->getID())
			{
				LinkedNode *temp = curr;
				if (prev == NULL) /* removing the head node */
					head = curr->next;
				else
					prev->next = curr->next;
				delete temp;
				return true;
			}
			else
			{
				prev = curr;
				curr = curr->next;
			}
		}

		/* did not find the item */
		std::cout << "That item does not exist." << std::endl;
		return false;
	}
}


/*********************************************************************
** Function: displayAsMenu()
** Description: Displays all Items in the list in numbered menu and
** returns the Item selected. Used to display items to use or get.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Returns a pointer to an Item or NULL
*********************************************************************/
Item* LinkedList::displayAsMenu()
{
	int count = 0;
	LinkedNode *curr = head;

	while (curr != NULL)
	{
		count++;
		std::cout << "   " << count << ": " << (curr->data)->getName() << std::endl;
		curr = curr->next;
	}

	if (count == 0)
		return NULL;
	else
	{
		std::cout << "   " << count + 1 << ": Back to Main Menu" << std::endl;

		int selection = getPosIntInput(count + 1);

		if (selection == count + 1)
			return NULL;
		else
			return find(selection - 1);
	}
}


/*********************************************************************
** Function: print()
** Description: Prints the long descriptions of all Items within the
** list. Used to display all Items in a room.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Items displayed to output.
*********************************************************************/
void LinkedList::print()
{
	LinkedNode *curr = head;

	while (curr != NULL)
	{
		std::cout << "   ";
		(curr->data)->printLong();
		curr = curr->next;
	}
}