#ifndef QUEUEINTERFACE_H
#define QUEUEINTERFACE_H

template<class T>
class QueueInterface
{
	public:
	
		/*
		Function: Constructor
		Inputs: An integer value specifying the maximum number of values in the queue
		Outputs: None
		Purpose: Sets the maxSize member object to the client-specified value. Sets all other member objects to default values.
		*/
		//virtual Queue(int) = 0;

		/*
		Function: getSize
		Inputs: None
		Outputs: An integer value representing the current number of items in the queue
		Purpose: Allows client code to access the current size of the queue
		*/
		virtual int getSize() const = 0;

		/*
		Function: peekFront
		Inputs: None
		Outputs: A value of type T representing the value at the front of the queue
		Purpose: Allows client code to access the value at the front of the queue
		*/
		virtual T peekFront() const = 0;

		/*
		Function: enqueue
		Inputs: A value of type T specifying the value to be added to the back of the queue
		Outputs: A boolean value representing whether the operation was successful: True if the item was successfully added, False if the item could not be added
		Purpose: Allows client code to add a new value to the back of the queue
		*/
		virtual bool enqueue(T) = 0;

		/*
		Function: dequeue
		Inputs: None
		Outputs: A boolean value representing whether the operation was successful: True if an item was successfully removed, False if the item could not be removed
		Purpose: Allows client code to remove the value at the front of the queue
		*/
		virtual bool dequeue() = 0;

		/*
		Function: isEmpty
		Inputs: None
		Outputs: A boolean value representing whether the queue is empty: True if the queue is empty, False if there are any amount of items in the queue
		Purpose: Allows client code to see if the queue is empty
		*/
		virtual bool isEmpty() const = 0;

		/*
		Function: isFull
		Inputs: None
		Outputs: A boolean value representing whether the queue is full: True if the queue is at maximum capacity, False otherwise
		Purpose: Allows client code to see if the queue is full
		*/
		virtual bool isFull() const = 0;

		/*
		Function: clear
		Inputs: None
		Outputs: None
		Purpose: Allows client code to reset the queue back to default values
		*/
		virtual void clear() = 0;
};

#endif
