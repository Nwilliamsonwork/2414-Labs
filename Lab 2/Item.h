#ifndef ITEM_
#define ITEM_

#include <string>

class Item
{
	private:
		std::string name;
		std::string color;
	public:
		Item();
		
		std::string getName();
		bool setName(std::string);
		
		std::string getColor();
		bool setColor(std::string);
		
};

//#include "Item.cpp"
#endif
