#include "Node.h"
#include <string>

Node::Node()
{
	line = "";
	next = nullptr;
}

std::string Node::getLine()
{
	return line;
}

std::shared_ptr<Node> Node::getNext()
{
	return next;
}

bool Node::setLine(std::string newLine)
{
	line = newLine;
	return true;
}

bool Node::setNext(std::shared_ptr<Node> newNext)
{
	next = newNext;
	return true;
}
