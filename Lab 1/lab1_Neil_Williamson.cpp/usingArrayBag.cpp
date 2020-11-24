#include <iostream>
#include <string>
#include "ArrayBag.h"

using namespace std;


void bagTester(ArrayBag<int>& bag);

/*
Program Description:
Provides a menu to allow the user to interact with the arraybag. 
User has options to display, sort, search using two methods, and end the program
*/
int main()
{
	ArrayBag<int> bag;
	int items[] = {1, 33, 6, 9, 2, 65, 4, 29, 5, 8, 39, 88, 7, 25, 51, 3, 99, 14, 11, 10};
	
	
	for (int i = 0; i < 20; i++)
	{
		bag.add(items[i]);
	}  // end for
	
	
	bagTester(bag);
	
   return 0;
   
}  // end main



/*
Function: bagTester
Inputs: arrayBag<int>
Outputs: none
Purpose: Allows the user to interact with and test the new ArrayBag fuctions
*/

void bagTester(ArrayBag<int>& bag)
{
	int choice = 1;
	int targetValue;
	bool contains;
	vector<int> contents;
	
	while(choice != 0)
	{
		cout << endl << endl;
		cout << "1 - Display the bag." << endl;
		cout << "2 - Sort the bag." << endl;
		cout << "3 - Search the bag using repetition." <<endl;
		cout << "4 - Search the bag using recursion." << endl;
		cout << "0 - End the program" << endl;
		cout << "Note: the bag must be sorted before it can be properly searched" << endl;
		cout << "Your selection: ";
		cin >> choice;
		switch(choice)
		{
			case 1:
				cout << "Displaying items in the bag." << endl;
				contents = bag.toVector();
				for (int i = 0; i < bag.getCurrentSize(); i++)
				{
					cout << contents.at(i) << " ";
				}
				cout << endl;
				break;
			case 2:
				cout << "Sorting the bag." << endl;
				bag.sort();
				break;
			case 3:
				cout << "Searching the bag using repetition." << endl;
				cout << "Enter a value to search for: " ;
				cin >> targetValue;
				contains = bag.binarySearch(targetValue, false);
				if (contains)
					cout << "The bag contains the target value." << endl;
				else
					cout << "The bag does not contain the target value." << endl;
				break;
			case 4:
				cout << "Searching the bag using recursion." << endl;
				cout << "Enter a value to search for: ";
				cin >> targetValue;
				contains = bag.binarySearch(targetValue, true);
				if(contains)
					cout << "The bag contains the target value." << endl;
				else
					cout << "The bag does not contain the target value." << endl;
				break;
			case 0:
				cout << "Ending the program." << endl;
				break;
				
		}
	}
}  // end bagTester



