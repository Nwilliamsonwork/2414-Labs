#include "BinaryNode.h"
#include "EmployeeInfo.h"

template<class T>
BinaryNode<T>::BinaryNode(){	};

template<class T>
BinaryNode<T>::BinaryNode(const T& newItem){
	item = newItem;
	leftChild = nullptr;
	rightChild = nullptr;
};

template<class T>
BinaryNode<T>::BinaryNode(const T& newItem,
						std::shared_ptr<BinaryNode<T>> leftChild,
						std::shared_ptr<BinaryNode<T>> rightChild){	};

template<class T>
void BinaryNode<T>::setItem(const T& anItem){
	item = anItem;
};

template<class T>
T BinaryNode<T>::getItem() const{
	return item;
};

template<class T>
bool BinaryNode<T>::isLeaf() const{	};

template<class T>
std::shared_ptr<BinaryNode<T>> BinaryNode<T>::getLeftChild() const{	
	return leftChild;
};

template<class T>
std::shared_ptr<BinaryNode<T>> BinaryNode<T>::getRightChild() const{	
	return rightChild;
};

template<class T>
void BinaryNode<T>::setLeftChild(std::shared_ptr<BinaryNode<T>> newLeft){
	leftChild = newLeft;
};

template<class T>
void BinaryNode<T>::setRightChild(std::shared_ptr<BinaryNode<T>> newRight){
	rightChild = newRight;
};


template class BinaryNode<EmployeeInfo>;
