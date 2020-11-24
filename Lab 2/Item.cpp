#include "Item.h"
#include <string>

//Item constructor
Item::Item()
{
	name = "";
	color = "";
}

//name accessor
std::string Item::getName()
{
	return name;
}

//color accessor
std::string Item::getColor()
{
	return color;
}

//name mutator
bool Item::setName(std::string n)
{
	name = n;
}

//color mutator
bool Item::setColor(std::string c)
{
	color = c;
}
