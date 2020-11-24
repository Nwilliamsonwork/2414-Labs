#ifndef QUEUE_H
#define QUEUE_H
#include <memory>

#include "QueueInterface.h"

//using std::unique_ptr;


template <class T>
class Queue : public QueueInterface<T>
{
	private:
		std::unique_ptr<T []> queueArray;
		int maxSize;
		int itemCount;
		int frontIndex;
		int rearIndex;
		
		/*
		Function: setDefaults
		Inputs: An integer value representing the client-specified maximum size of the queue
		Outputs: None
		Purpose: Sets, or resets, the value maxSize to the specified integer value.
				Sets, or resets, all member variables to their default values.
		*/
		void setDefaults(int);
	public:
		Queue(int);
		
		int getSize() const;
		T peekFront() const;
		bool enqueue(T);
		bool dequeue();
		bool isEmpty() const;
		bool isFull() const;
		void clear();
};

#endif
