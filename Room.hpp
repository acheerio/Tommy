#ifndef ROOM_HPP
#define ROOM_HPP

#include <string>
#include "Item.hpp"
#include "LinkedList.hpp"

class Room
{
public:
	Room();
	Room(int id, std::string sDesc, bool stay, bool light, int items,
		bool opened, std::string oItem, std::string oSuccess);
	virtual ~Room();
	int getID();
	std::string getName();
	bool getStay();
	bool getLight();
	bool getSearched();
	void setSearched(bool s);
	Room* getNorth();
	Room* getEast();
	Room* getSouth();
	Room* getWest();
	void setNorth(Room* r);
	void setEast(Room* r);
	void setSouth(Room* r);
	void setWest(Room* r);
	virtual void print(bool isLit);
	virtual bool enter(bool isLit);
	virtual Room* showDirections();
	virtual Item* showGetMenu(bool isLit);
	virtual void showOpenMenu(bool isLit);
	virtual bool use(Item *i) = 0;
private:	
	int id;
	bool searched;
protected:
	std::string shortDesc;
	std::string longDesc;
	bool stay; /* whether the player can stay in the room upon entry */
	bool hasLight; /* if the room has its own light source */
	bool open; /* whether door/object is open */
	std::string openItem; /* name of obj to open */
	std::string openSuccess; /* success message when opening openItem */
	int numItems;
	LinkedList items;
	Room *north;
	Room *east;
	Room *south;
	Room *west;
};

#endif