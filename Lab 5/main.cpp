
#include "EmployeeInfo.h"
#include "BinaryTree.h"

#include <string>
#include <fstream>
#include <memory>
#include <iostream>
#include <limits>

using namespace std;


void displayEmployee(EmployeeInfo&);

int main()
{	
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
		
		employee = make_shared<EmployeeInfo>(tempInt, tempStr);
		sortedTree.add(*employee);
	}
	
	infile.close();
	
	
	
	int id;
	int choice;
	string name;
	bool found;
	
	do{
		cout << endl;
		cout << "Choos an option from one of the below menu items." << endl;
		cout << "1: Search for an entry using the employee's ID #" << endl;
		cout << "2: Display the tree in order." << endl;
		cout << "3: Add an employee to the tree." << endl;
		//cout << "4: Remove an employee from the tree." << endl;
		cout << "0: Quit" << endl;
		cout << "Your choice: ";
		cin >> choice;
		
		cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
		
		switch(choice)	{
			case 1: //search for an entry
				
				cout << "Enter an ID# to search for: ";
				cin >> id;
				cin.clear();
            	cin.ignore(numeric_limits<streamsize>::max(), '\n');
				
				employee = make_shared<EmployeeInfo>(id, "");
				found = sortedTree.contains(*employee);
				
				if(found)
					cout << "Found" << endl;
				else
					cout << "Not found" << endl;
				break;
			
			case 2: //display the tree
				
				cout << "ID #: "  << "\t" << "Name:" << endl;
				cout << "__________________" << endl;
				sortedTree.inorderTraverse(displayEmployee); 
				break;
		
			case 3: //add an employee

				cout << "Enter ID # of employee to add: ";
				cin >> id;
				
				cin.clear();
            	cin.ignore(numeric_limits<streamsize>::max(), '\n');
            	
				cout << "Enter Name of employee to add: ";
				cin.getline(input, 256);
				string name(input);
				
				cin.clear();
            	cin.ignore(numeric_limits<streamsize>::max(), '\n');
            	
				
				employee = make_shared<EmployeeInfo>(id, name);
				
				sortedTree.add(*employee);
				
				break;
		
				//TODO EC: Allow user to remove an employee
				
				/*
			case 4:
				cout << "Enter ID # of employee to remove: ";
				cin >> id;
				
				employee = make_shared<EmployeeInfo(id, "");
				
				sortedTree.remove(*employee);
				break;
				*/
		}//end switch
	}while(choice == 1,2,3); //add 4 when remove option is complete


	return 0;
}

void displayEmployee(EmployeeInfo &emp)
{
	cout << emp.getID() << "\t" << emp.getName() << endl;
}

