#include "Node.h"
#include "LinkedList.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;


/*
Program Description
This program utilizes linked lists to create an ordered list of strings of unbounded size. 
The main() function gets input from a text file (must be named "stuff.txt"), stores each line as a separate node in the list, and then displays the list to cout
Then it calls the linked list member function removeDuplicates() to remove all duplicate nodes in the list, then main() displays the modified list of strings.

IMPORTANT NOTE: The linked list class currently acts in a FILO manner internally when storing nodes. The displayList function is written in such a way that the order is returned in the correct sequence, 
	but internally, the class operates on the variables from the bottom up. This results in the removeDuplicates function saving the last instance of a duplicate line, and deleting all of the earlier instances,
	instead of the more intuitive format of saving the first instance and deleting each subsequent.
	Given more time, I would alter the addNode() and displayList() functions to act more intuitively, but this implementation meets the required criteria.
*/
void DisplayContent(LinkedList);

int main()
{
	
	ifstream infile;
	
	LinkedList list;
	
	string instring = "";
	
	infile.open("stuff.txt");

	while (getline(infile, instring)) //read in each line from the file
	{
		list.addNode(instring); //store the line in "list" as a new Node
	}
	
	cout << "-------------------------------------------" << endl;
	cout << "CONTENTS OF THE FILE, INCLUDING DUPLICATES:" << endl;
	cout << "-------------------------------------------" << endl;
	DisplayContent(list); //display raw data from the file
	
	list.removeDuplicates(); 
	
	cout << "-------------------------------------------" << endl;
	cout << "CONTENTS OF THE FILE, DUPLICATES REMOVED:" << endl;
	cout << "-------------------------------------------" << endl;
	DisplayContent(list); //display data with duplicates removed
	

}

/*
Function: DisplayContent()
Inputs: A linkedList to draw data from
Outputs: none
Purpose: Displays the content from list to standard output, with a new line between each item in the list.
*/
void DisplayContent(LinkedList list)
{
	vector<shared_ptr<Node>> displayReturn = list.displayList();
	shared_ptr<Node> currentLine(new Node());
	for(int i = 0; i < list.getLength(); i++)
	{
	
		currentLine = displayReturn.back(); //get the next line from the vector
		displayReturn.pop_back(); //remove the line from the back of the vector
		cout << currentLine->getLine() << endl; //display the line
	}
	cout << endl;
}
