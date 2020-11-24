#include <cassert> 
#include <iostream>
#include "ArrayStack.h"
#include "Item.h"



ArrayStack::ArrayStack() : top(-1)
{
}


bool ArrayStack::isEmpty() const
{
	return top < 0;
}



bool ArrayStack::push(const Item& newEntry)
{
	bool result = false;
	if (top < DEFAULT_CAPACITY - 1)
	{
		top++;
		stack[top] = newEntry;
		result = true;
	}
	
	return result;
}



bool ArrayStack::pop()
{
	bool result = false;
	if (!isEmpty())
	{
		top--;
		result = true;
	}
	return result;
}



Item ArrayStack::peek() const
{
	assert(!isEmpty());
	return stack[top];
}


void ArrayStack::display()
{
	std::cout << "Top" << std::endl;
	for(int i = 0; i <= top; i++)
	{
		std::cout << stack[i].getName() << " " << stack[i].getColor() << std::endl;
	}
	std::cout << "Bottom" << std::endl;
}
