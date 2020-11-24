#include "Queue.h"
#include <iostream>
#include <string>
using namespace std;

/*
Program Description:
This program demonstrates a basic array-based implementation of a queue. 
*/

/*
Function: menu
Inputs: A shared pointer to the queue to be operated on
Outputs: None
Purpose: Allows the user to operate on a queue of their desired type. Using a helper function that is a template function allows us to re-use the same code
		for any data type the user specifies.
*/
template <class T>
void menu(shared_ptr<Queue<T>>);

int main()
{
	int userChoice = 0;
	cout << "Enter an integer value for the maximum size of the queue: ";
	cin >> userChoice;
	const int MAX_SIZE = userChoice;
	
	cout << "Which data type would you like to use?" << endl;
	cout << "Enter 1 for int, 2 for float, 3 for string: ";
	cin >> userChoice;
	
	/*
	Queue objects are initialized as shared pointers to avoid complications with their unique pointer member variables.
	I couldn't find a way to declare only one object that could be later instantiated with a variable type
	*/
	shared_ptr<Queue<int>> intQueue = make_shared<Queue<int>>(MAX_SIZE);
	shared_ptr<Queue<float>> floatQueue = make_shared<Queue<float>>(MAX_SIZE);
	shared_ptr<Queue<string>> stringQueue = make_shared<Queue<string>>(MAX_SIZE);
	
	//Depending on the user's choice of data type, we call the helper function with the appropriate object
	cout << "You have chosen the type: ";
	switch(userChoice)
	{
		case 1:
			cout << "int" << endl;
			menu(intQueue);
			break;
		case 2:
			cout << "float" << endl;
			menu(floatQueue);
			break;
		case 3:
			cout << "string" << endl;
			menu(stringQueue);
			break;
	}

	return 0;
}

template <class T>
void menu(shared_ptr<Queue<T>> queue)
{
	int userChoice;
	int itemsInQueue;
	bool ableToOperate = false;
	T toAdd;
	T tempValue;
	
	do{ //Loops through the menu until the user chooses to exit
		cout << endl;
		cout << "Choose an option:" << endl;
		cout << "1. Add an item to the queue." << endl;
		cout << "2. Remove an item from the queue." << endl;
		cout << "3. Display the items in the queue." << endl;
		cout << "Your choice: ";
		cin >> userChoice;

		switch(userChoice)
		{
			case 1: //Add to the queue

				ableToOperate = !(queue->isFull()); //Cannot add another value if the queue is full
				
				if(ableToOperate)
				{
					cout << "Enter the value you would like to add to the queue: ";
					cin >> toAdd;
					queue->enqueue(toAdd);
					cout << toAdd << " successfully added to the queue." << endl;
				}
				else
				{
					cout << "ERROR: Queue is full. Can not add another value." << endl;
				}

				cout << endl;
				break;

			case 2: //Remove from the queue
				
				ableToOperate = !(queue->isEmpty()); //Cannot remove a value if the queue is empty

				if(ableToOperate)
				{
					tempValue = queue->peekFront(); //Save front  value for output
					queue->dequeue();
					cout << "The front value: " << tempValue << " successfully removed from the queue." << endl;
				}
				else
				{
					cout << "ERROR: Queue is empty. Item could not be removed from the queue." << endl;
				}

				cout << endl;
				break;

			case 3: //Display the queue

				if(queue->isEmpty())
				{
					cout << "Queue is empty. Nothing to display.";
				}
				else //Queue is not empty
				{
					cout << "Displaying the queue: " << endl;
					itemsInQueue = queue->getSize();

					for(int i = 0; i < itemsInQueue; i++) //Iterate through each item in the queue, display its value, then move it to the back
					{
						tempValue = queue->peekFront(); //Save the front value
						queue->dequeue();				//Move the front value to the back
						queue->enqueue(tempValue);		//
						cout << tempValue << "\t";		//Display the saved value
					}
				}
				
				cout << endl;
				break;
				
		}//end switch
		
		//Ask to exit or continue the loop
		cout << endl;
		cout << "Choose an option: " << endl;
		cout << "1. Perform another action." << endl;
		cout << "0. Exit the program." << endl;
		cout << "Your choice: ";

		cin >> userChoice;
	}while(userChoice != 0);
}
