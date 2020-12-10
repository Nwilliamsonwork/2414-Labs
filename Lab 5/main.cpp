
#include "EmployeeInfo.h"
#include "BinaryTree.h"

#include <string>
#include <fstream>
#include <memory>
#include <iostream>

using namespace std;
//extern template class BinaryTree<EmployeeInfo>;

void displayEmployee(EmployeeInfo&);

int main()
{
	BinaryTree<EmployeeInfo> tree();
	//TODO: add default employee information to tree
	
	ifstream infile;
	shared_ptr<EmployeeInfo> employee;

	BinaryTree<EmployeeInfo> sortedTree;
	
	char input[256];
	
	infile.open("Employees.txt");

	while(infile.good())
	{
		infile.getline(input, 256);
		int tempInt = atoi(input);
		infile.getline(input, 256);
		string tempStr(input);
		//cout << tempInt << "	" << tempStr << endl;
		employee = make_shared<EmployeeInfo>(tempInt, tempStr);
		cout << employee->getID() << "	" << employee->getName() << endl;
		sortedTree.add(*employee);
	}
	
	infile.close();
	
	int testID;
	cout << "Enter an ID# to search for: ";
	cin >> testID;
	
	employee = make_shared<EmployeeInfo>(testID, "");
	bool found = sortedTree.contains(*employee);
	
	if(found)
		cout << "Found" << endl;
	else
		cout << "Not found" << endl;
		
	//TODO: ask user for an id # and say whether or not it was found in the tree
	
	//TODO EC: Display the tree to the user
	sortedTree.inorderTraverse(displayEmployee); 
	//TODO EC: Allow user to add an employee
	
	//TODO EC: Allow user to remove an employee
	return 0;
}

void displayEmployee(EmployeeInfo &emp)
{
	cout << "ID #: " << emp.getID() << endl;
	cout << "Name: " << emp.getName() << endl;
}

