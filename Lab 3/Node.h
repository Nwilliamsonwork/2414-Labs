#ifndef NODE_H
#define NODE_H

#include <string>
#include <memory>
//using std::string, std::shared_ptr;

class Node
{
	private:
		std::string line;
		std::shared_ptr<Node> next;
		
	public:
		/*
		Function: Node() constructor
		Inputs: none
		Outputs: none
		Purpose: Initializes member variables: Line to the empty string, node to nullptr
		*/
		Node();
		
		/*
		Function: getLine()
		Inputs: none
		Outputs: a string representing the value of line
		Purpose: allows client code to access the value of line
		*/
		std::string getLine();
		
		/*
		Function: getNext()
		Inputs: none
		Outputs: A shared pointer to a node representing the node that comes after this node in a list.
		Purpose: Allows client code to access the next node in the sequence.
		*/
		std::shared_ptr<Node> getNext();
		
		/*
		Function: setLine()
		Inputs: a string representing the value to be transferred to the line member variable
		Outputs: a boolean representing whether the operation was successful
		Purpose:  Allows client code to change the value of the line member variable
		*/
		bool setLine(std::string);
		
		/*
		Function: setNext()
		Inputs: A shared pointer to a node
		Outputs:  a boolean representing whether the operation was successful
		Purpose: Allows client code to change the value of the next member variable
		*/
		bool setNext(std::shared_ptr<Node>);
};

#endif
