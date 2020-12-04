#ifndef EMPLOYEEINFO_H
#define EMPLOYEEINFO_H

#include <string>

class EmployeeInfo
{
	private:
		int id;
		std::string name;
		
	public:
		EmployeeInfo();
		EmployeeInfo(int, std::string);
		//EmployeeInfo(
		
		int getID() const;
		std::string getName() const;
		bool setID(int);
		bool setName(std::string);
		
		//Operators: > 
		
		bool operator>(const EmployeeInfo&);
		bool operator<(const EmployeeInfo&);
		bool operator==(const EmployeeInfo&);
};

#endif
