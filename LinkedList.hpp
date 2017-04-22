#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP


#include "Item.hpp"


class LinkedList
{
	/* private by default,
	** placed for visibility */
	struct LinkedNode {
		Item *data;
		LinkedNode *next;
	};

public:
	LinkedList();
	~LinkedList();
	bool isEmpty();
	void add(Item *i);
	bool remove(Item *i);
	Item* displayAsMenu();
	void print();
private:
	LinkedNode *head;
	Item* find(int index);
};

#endif
