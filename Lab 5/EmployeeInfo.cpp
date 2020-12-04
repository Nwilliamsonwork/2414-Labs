#include "EmployeeInfo.h"

EmployeeInfo::EmployeeInfo()
{
	id = 0;
	name = "";
};

EmployeeInfo::EmployeeInfo(int n, std::string s)
{
	id = n;
	name = s;
};
		
int EmployeeInfo::getID() const
{
	return id;
};
std::string EmployeeInfo::getName() const
{
	return name;
};
bool EmployeeInfo::setID(int n)
{
	id = n;
};
bool EmployeeInfo::setName(std::string s)
{
	name = s;
};


bool EmployeeInfo::operator> (/*const EmployeeInfo& leftSide,*/ const EmployeeInfo& rightSide)
{
	return id > rightSide.getID();
};



bool EmployeeInfo::operator< (const EmployeeInfo& rightSide)
{
	return id < rightSide.getID();
};

bool EmployeeInfo::operator== (const EmployeeInfo& rightSide)
{
	return id == rightSide.getID();
};
