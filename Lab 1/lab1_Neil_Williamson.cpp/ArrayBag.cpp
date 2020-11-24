#include "ArrayBag.h"
#include <iostream>
#include <cstddef>


/*
Function: sort
Inputs: none
Outputs: none
Purpose: sorts the array "items" in this instance of ArrayBag using an implementation of the bubble sort algorithm
*/

template<class ItemType>
void ArrayBag<ItemType>::sort()
{
	bool swapped = true; //tracks if at least one swap has been made in the current pass
	for(int j = 1; j < itemCount; j++) //True while array is out of order
	{
		
		swapped = false;
		for(int i = 1; i < itemCount; i++)
		{
			if(items[i-1]> items[i]) //if two concecutive elements in the array are out of order, switch them and set swapped to True
			{
				std::swap(items[i-1], items[i]);
				swapped = true;
			}// end if
		}// end for
		if(!swapped)
			break;
	}// end for
}


/*
Function: binarySearch (base function)
Inputs: targetValue, a variable of type ItemType to search for.
		mode, false for repetition, true for recursion
Outputs: True if the bag contains targetValue
		False if the bag does not contain targetValue
Purpose: calls the desired binary search function (either repetition or recursion)
*/	

template <class ItemType>
bool ArrayBag<ItemType>::binarySearch(const ItemType& targetValue, bool mode)
{
	if(mode)// decide whether to use recursion or repetition
	{
		return binarySearchRecursion(targetValue, 0, itemCount-1); //call recursive search
	}	
	return binarySearchRepetition(targetValue);//call repetition search
}


/*
Function: binarySearchRepetition (repetition implementation)
Inputs: targetValue, a variable of type ItemType to search for
Outputs: True if the bag contains targetValue
		False if the bag does not contain targetValue
Purpose: searches for an instance of the input variable in the ArrayBag using a repetitive implementation of the binary search algorithm
*/

template <class ItemType> 
bool ArrayBag<ItemType>::binarySearchRepetition(const ItemType& targetValue) const
{
	int left = 0;
	int right = itemCount - 1;
	int m;
	while(left <= right)// loop runs while left is smaller than right 
	{
		m = (left+right)/2;
		if(items[m] < targetValue)//when middle value is smaller than the target, all values smaller than middle value cannot be the target
		{
			left = m+1;
		}
		else if (items[m] > targetValue)//when middle value is larger than the target, all values larger than middle value cannot be the target
		{
			right = m-1;
		}
		else//if middle value is not smaller or larger than target value, it must == targetvalue
		{
			return true;
		}
	}
	//when left is greater than right, all values have been checked, so the targetvalue is not in the array
	return false;
	
}


/*
Function: binarySearchRecursion (recursion implementation)
Inputs: targetValue, a variable of type ItemType to search for
		left, the starting point for this instance of the function
		right, the endpoint for this instance of the function
Outputs: True if the bag contains targetValue
		False if the bag does not contain targetValue
Purpose: searches for an instance of the input variable in the ArrayBag using a recursive implementation of the binary search algorithm
*/

template <class ItemType>
bool ArrayBag<ItemType>::binarySearchRecursion(const ItemType& targetValue, int left, int right) const
{
	
	if(left <= right)
	{
		int mid = (left + (right-1)) / 2;
		if(items[mid] == targetValue)
		{
			return true;
		}
		if(items[mid]>targetValue)
		{
			return binarySearchRecursion(targetValue, left, mid-1);
		}
		return binarySearchRecursion(targetValue, mid+1, right);
	}
	return false;
}

template<class ItemType>
ArrayBag<ItemType>::ArrayBag(): itemCount(0), maxItems(DEFAULT_CAPACITY)
{
}  // end default constructor

template<class ItemType>
int ArrayBag<ItemType>::getCurrentSize() const
{
	return itemCount;
}  // end getCurrentSize

template<class ItemType>
bool ArrayBag<ItemType>::isEmpty() const
{
	return itemCount == 0;
}  // end isEmpty

template<class ItemType>
bool ArrayBag<ItemType>::add(const ItemType& newEntry)
{
	bool hasRoomToAdd = (itemCount < maxItems);
	if (hasRoomToAdd)
	{
		items[itemCount] = newEntry;
		itemCount++;
	}  // end if
    
	return hasRoomToAdd;
}  // end add

template<class ItemType>
bool ArrayBag<ItemType>::remove(const ItemType& anEntry)
{
   int locatedIndex = getIndexOf(anEntry);
	bool canRemoveItem = !isEmpty() && (locatedIndex > -1);
	if (canRemoveItem)
	{
		itemCount--;
		items[locatedIndex] = items[itemCount];
	}  // end if
    
	return canRemoveItem;
}  // end remove

template<class ItemType>
void ArrayBag<ItemType>::clear()
{
	itemCount = 0;
}  // end clear

template<class ItemType>
int ArrayBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const
{
   int frequency = 0;
   int curIndex = 0;       // Current array index
   while (curIndex < itemCount)
   {
      if (items[curIndex] == anEntry)
      {
         frequency++;
      }  // end if
      
      curIndex++;          // Increment to next entry
   }  // end while
   
   return frequency;
}  // end getFrequencyOf

template<class ItemType>
bool ArrayBag<ItemType>::contains(const ItemType& anEntry) const
{
	return getIndexOf(anEntry) > -1;
}  // end contains

/* ALTERNATE 1: First version
template<class ItemType>
bool ArrayBag<ItemType>::contains(const ItemType& target) const 
{
   return getFrequencyOf(target) > 0;
}  // end contains

// ALTERNATE 2: Second version 
template<class ItemType>
bool ArrayBag<ItemType>::contains(const ItemType& anEntry) const
{
   bool found = false;
   int curIndex = 0;        // Current array index
   while (!found && (curIndex < itemCount))
   {
      if (anEntry == items[curIndex])
      {
         found = true;
      } // end if
      
      curIndex++;           // Increment to next entry
   }  // end while   
   
   return found;
}  // end contains
*/

template<class ItemType>
std::vector<ItemType> ArrayBag<ItemType>::toVector() const
{
   std::vector<ItemType> bagContents;
	for (int i = 0; i < itemCount; i++)
		bagContents.push_back(items[i]);
      
   return bagContents;
}  // end toVector



// private
template<class ItemType>
int ArrayBag<ItemType>::getIndexOf(const ItemType& target) const
{
	bool found = false;
   int result = -1;
   int searchIndex = 0;
   
   // If the bag is empty, itemCount is zero, so loop is skipped
   while (!found && (searchIndex < itemCount))
   {
      if (items[searchIndex] == target)
      {
         found = true;
         result = searchIndex;
      } 
      else
      {
         searchIndex++;
      }  // end if
   }  // end while
   
   return result;
}  // end getIndexOf


