#ifndef ARRAY_STACK_
#define ARRAY_STACK_
#include "Item.h"

class ArrayStack
{
	private:
		static const int DEFAULT_CAPACITY = 20;
		Item stack[DEFAULT_CAPACITY];
		int top;
	public:
		ArrayStack();
		bool isEmpty() const;
		bool push(const Item& newEntry);
		bool pop();
		Item peek() const;
		void display();
};

//#include "ArrayStack.cpp"
#endif
