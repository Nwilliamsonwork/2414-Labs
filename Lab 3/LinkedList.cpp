#include "LinkedList.h"
#include <vector>
#include <string>
#include <memory>

using std::shared_ptr;
using std::vector;


LinkedList::LinkedList()
{
	headPtr = std::make_shared<Node>();
	itemCount = 0;
}

shared_ptr<Node> LinkedList::getNodeAt(int position) const
{
	bool inScope = ( (position >= 1) && (position <= itemCount)); //checks to make sure position refers to a real node in the list
	
	shared_ptr<Node> curPtr = headPtr;
	if(inScope)
	{
		for(int i = 1; i < position; i++) //iterate throught the list until curPtr points to the target node
		{
			curPtr = curPtr->getNext();
		}
	}
	return curPtr;
}

bool LinkedList::isEmpty() const
{
	return (itemCount == 0);
}

int LinkedList::getLength() const
{
	return itemCount;
}

bool LinkedList::remove(int position)
{
	bool ableToRemove = (position >= 1) && (position <= itemCount);//ensures position refers to a real node in the list
	if(ableToRemove)
	{
		shared_ptr<Node> curPtr = std::make_shared<Node>();
		if(position == 1)//if the node to be removed is the first node in the list, we need to reassign headPtr
		{
			curPtr = headPtr;
			headPtr = headPtr->getNext();
		}
		else
		{
			shared_ptr<Node> prevPtr = getNodeAt(position -1); //get the node at the position before the target node, so that its "next" pointer can be reassigned
			curPtr = prevPtr->getNext();
			prevPtr->setNext(curPtr->getNext()); //reassign the previous node's "next" pointer
		}
		curPtr->setNext(nullptr);
		itemCount--;
	}
	return ableToRemove;
}

int LinkedList::removeDuplicates()
{
	std::string uniqueNodes[itemCount]; // an array of strings that will store each unique value in the list
	shared_ptr<Node> curPtr = headPtr;
	shared_ptr<Node> nextPtr = std::make_shared<Node>();
	bool duplicate = false;
	int numUniqueNodes = 0;
	std::string temp;
	if(curPtr != nullptr) // if the head pointer is empty, there will be no duplicates to remove
	{
		// add the first value to the uniqueNodes array and iterate the counter
		uniqueNodes[0] = curPtr->getLine();
		numUniqueNodes++;
		while(curPtr != nullptr && curPtr->getNext() != nullptr)//while loop continues until we hit the end of the list
		{
			//reset values for next pass of while loop
			duplicate = false;
			nextPtr = curPtr->getNext();
			temp = nextPtr->getLine();
			
			for(int i = 0; i < numUniqueNodes; i++) // search previous lines for a duplicate
			{
				if(uniqueNodes[i] == temp) //true when the "next" line is a duplicate of a previous line
				{
					duplicate = true;
					i = numUniqueNodes; // "next" line is a duplicate, no need to check the remaining lines stored in uniqueNodes
				}
			}
			
			if(duplicate) // nextPtr's line is a duplicate. Remove it from the list by setting the previous node's "next" variable equal to nextPtr's "next" variable
			{
				remove(numUniqueNodes + 1);
			}
			else //nextPtr's line is not a duplicate. Add its value to the uniqueNodes array,increment its counter, and advance curPtr to the next location.
			{
				uniqueNodes[numUniqueNodes] = temp;
				numUniqueNodes++;
				curPtr = curPtr->getNext();
			}		
		}//end while
	}//end if
		
	return numUniqueNodes;
}


bool LinkedList::addNode(std::string newLine)
{
	shared_ptr<Node> newEntry = std::make_shared<Node>();
	newEntry->setLine(newLine);
	newEntry->setNext(headPtr);	
	headPtr = newEntry;
	itemCount++;
	return true;
}


vector<shared_ptr<Node>> LinkedList::displayList() const
{
	vector<shared_ptr<Node>> output;
	shared_ptr<Node> curPtr = headPtr;
	for(int i = 0; i < itemCount; i++)
	{
		output.push_back(curPtr);
		curPtr = curPtr->getNext();
	}

	return output;
}
