#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include <string>	
#include <memory>
#include <vector>
using std::shared_ptr;

class LinkedList
{
	private:
		std::shared_ptr<Node> headPtr;
		int itemCount;
		
		/*
		Function: getNodeAt()
		Inputs: position, representing the position of the node in the list to be returned
		Outputs: A shared pointer to the node at position
		Purpose: Allows member functions to easily grab a node from anywhere in the list.
		*/
		std::shared_ptr<Node> getNodeAt(int position) const;
		
	public:	
		/*
		Function: LinkedList() constructor
		Inputs: None
		Outputs: None
		Purpose: Initializes member variables: 
											headPtr to nullptr
											itemCount to 0
		*/
		LinkedList();

		/*
		Function: remove()
		Inputs: Position, representing the position of the node in the list to be removed
		Outputs: A boolean representing whether the operation was successful.
		Purpose: Allows client code to remove a node from a given position.
		*/
		bool remove(int position);
		
		/*
		Function: isEmpty()
		Inputs: None
		Outputs: A boolean representing whether or not the list is empty
		Purpose: Allows client code to see whether the list is empty
		*/
		bool isEmpty() const;
		
		/*
		Function: getLength()
		Inputs: None
		Outputs: An integer representing the number of nodes in the list
		Purpose: Allows client code to see how many nodes are in the list
		*/
		int getLength() const;
		
		/*
		Function: addNode()
		Inputs: newLine representing the string value to be added to the list
		Outputs: a boolean representing whether the operation was successful.
		Purpose: Allows client code to add new values to the list. Only adds on to the end of the list.
		*/
		bool addNode(std::string newLine);
		
		/*
		Function: removeDuplicates()
		Inputs: none
		Outputs: an integer representing the number of nodes removed
		Purpose: Allows client code to remove all the duplicates in the current list
		*/
		int removeDuplicates();
		
		/*
		Function: displayList()
		Inputs:none
		Outputs: A vector of shared pointers to nodes, containing all the string values from the list.
		Purpose: Allows client code to access copies of all the values in the list. Given more time, this would instead return a vector of strings, 
					as requiring the client to extract the strings from the nodes requires unecessary compexity 
		*/
		std::vector<shared_ptr<Node>> displayList() const;
	
		
};

#endif
