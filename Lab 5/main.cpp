
#include "EmployeeInfo.h"
#include "BinaryTree.h"

#include <string>
#include <fstream>
#include <memory>
#include <iostream>

using namespace std;

int main()
{
	BinaryTree<EmployeeInfo> tree();
	//TODO: add default employee information to tree
	
	ifstream infile;
	shared_ptr<EmployeeInfo> employee;
	int tempInt;
	string tempStr;
	
	infile.open("Employees.txt");
	
	while(infile >> tempInt)
	{
		infile >> tempStr;
		cout << tempInt << "/t" << tempStr << endl;
		//employee = make_shared<EmployeeInfo>(tempInt, tempStr);
	}
	infile.close();
	
	//TODO: ask user for an id # and say whether or not it was found in the tree
	
	//TODO EC: Display the tree to the user
	
	//TODO EC: Allow user to add an employee
	
	//TODO EC: Allow user to remove an employee
	return 0;
}
