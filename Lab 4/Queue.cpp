#include "Queue.h"
#include <memory>
#include <string>



template <>
Queue<float>::Queue(int size)
{
	queueArray = std::make_unique<float []>(size);
	setDefaults(size);
}

template <>
Queue<std::string>::Queue(int size)
{
	queueArray = std::make_unique<std::string []>(size);
	setDefaults(size);
}

template <>
Queue<int>::Queue(int size)
{	
	queueArray = std::make_unique<int []>(size);
	setDefaults(size);
}

template<class T>
void Queue<T>::setDefaults(int size)
{
	maxSize = size;
	frontIndex = 0;
	rearIndex = 0;
	itemCount = 0;
}


template <class T>
int Queue<T>::getSize() const
{
	return itemCount;
}

template <class T>
T Queue<T>::peekFront() const
{
	return queueArray[frontIndex];
}

template <class T>
bool Queue<T>::enqueue(T newEntry)
{
	bool ableToAdd = !isFull(); //Ensure there is space for another item in the queue
	if(ableToAdd)
	{
		/*
		Note that although queueArray itself is static in memory, rearIndex and frontIndex can increment freely through
		their range, wrapping smoothly from the index at maxSize back to 0 */
		queueArray[rearIndex] = newEntry; /*Outside of this function, the value at queueArray[rearIndex] is always empty
											We can set queueArray[rearIndex] to the input value, then increment rearIndex.*/
		
		rearIndex = (rearIndex + 1) % maxSize; 
		itemCount++;
	}
	return ableToAdd;
}

template <class T>
bool Queue<T>::dequeue()
{
	bool ableToRemove = !isEmpty();
	if(ableToRemove)
	{
		frontIndex = (frontIndex + 1) % maxSize; /*There is no need to remove the value at frontIndex before incrementing. 
													That value is now outside of our scope, and if the index it is stored at is 
													used again, the value will be replaced by enqueue() */
		itemCount--;
	}
	return ableToRemove;
}

template <class T>
bool Queue<T>::isEmpty() const
{
	return itemCount == 0;
}

template <class T>
bool Queue<T>::isFull() const
{
	return itemCount == maxSize;
}

template <class T>
void Queue<T>::clear()
{
	setDefaults(maxSize);
}
