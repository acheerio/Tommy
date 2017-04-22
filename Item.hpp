#ifndef ITEM_HPP
#define ITEM_HPP


#include <string>


class Item
{
public:
	Item();
	Item(int id, int active, int target, std::string sDesc, std::string lDesc);
	Item(int id, int active, int target, std::string sDesc, std::string lDesc, std::string uDesc);
	virtual ~Item();
	std::string getName();
	int getID();
	int getActive();
	int getTarget();
	void printLong();
	void use();
private:
	int id;
	int activeRm;
	int targetRm;
	std::string shortDesc;
	std::string longDesc;
	std::string useDesc;
};

#endif