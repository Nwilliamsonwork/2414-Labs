
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
	/*
	shared_ptr<BinaryTree<EmployeeInfo>> sortedTree;
	sortedTree = make_shared<BinaryTree<EmployeeInfo>>();
	*/
	BinaryTree<EmployeeInfo> sortedTree;
	
	char input[256];
	
	infile.open("Employees.txt");
	/*
	infile.getLine(input, 256);
	int secondInt = atoi(input);
	infile.getLine(input, 
	*/
	while(infile.good())
	{
		infile.getline(input, 256);
		int tempInt = atoi(input);
		infile.getline(input, 256);
		string tempStr(input);
		//cout << tempInt << "	" << tempStr << endl;
		employee = make_shared<EmployeeInfo>(tempInt, tempStr);
		cout << employee->getID() << "	" << employee->getName();
		sortedTree.add(*employee);
	}
	
	infile.close();
	
	//TODO: ask user for an id # and say whether or not it was found in the tree
	
	//TODO EC: Display the tree to the user
	
	//TODO EC: Allow user to add an employee
	
	//TODO EC: Allow user to remove an employee
	return 0;
}
