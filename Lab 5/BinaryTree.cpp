#include "BinaryTree.h"
#include "EmployeeInfo.h"

#include <memory>
#include <iostream>

//incomplete
template<class T>
auto BinaryTree<T>::placeNode(std::shared_ptr<BinaryNode<T>> subTree,
								std::shared_ptr<BinaryNode<T>> newNode){	
	if(subTree == nullptr)
		return newNode;
	else if (subTree->getItem() > newNode->getItem())
	{
		auto tempPtr = placeNode(subTree->getLeftChild(), newNode);
		subTree->setLeftChild(tempPtr);
	}
	else
	{
		auto tempPtr = placeNode(subTree->getRightChild(), newNode);
		subTree->setRightChild(tempPtr);
	}
	return subTree;
};

template<class T>				
auto BinaryTree<T>::removeValue(std::shared_ptr<BinaryNode<T>> subTreePtr,
								const T target,
								bool &isSuccessful){	};

template<class T>
auto BinaryTree<T>::removeNode(std::shared_ptr<BinaryNode<T>> toRemove){	};

template<class T>
auto BinaryTree<T>::removeLeftmostNode(std::shared_ptr<BinaryNode<T>> subTree,
										T &inorderSuccessor){	};

template<class T>
auto BinaryTree<T>::findNode(std::shared_ptr<BinaryNode<T>> subTree,
							const T &target){	};


template<class T>
bool BinaryTree<T>::search(std::shared_ptr<BinaryNode<T>> subTree,
						 T target)
{
	//std::cout << "Target: " << target.getID() << std::endl;
	//std::cout << "subTree: " <<  (subTree->getItem()).getID() << std::endl;
	if(subTree == nullptr)
		return false;
	else if(target == subTree->getItem())
		return true;
	else if (target < subTree->getItem())
		return search(subTree->getLeftChild(), target);
	else
		return search(subTree->getRightChild(), target);
};


//COMPLETE
template<class T>
auto BinaryTree<T>::getHeightHelper(std::shared_ptr<BinaryNode<T>> subTreePtr)
{
	if(subTreePtr == nullptr)
		return 0;
	else
	return 1+std::max(getHeightHelper(subTreePtr->getLeftChild()),
				getHeightHelper(subTreePtr->getRightChild()));
};

template<class T>
BinaryTree<T>::BinaryTree(){
	rootPtr = nullptr;
	nodeCount = 0;
	height = 0;
};

template<class T>
BinaryTree<T>::BinaryTree(const T &rootItem){	};

/*
template<class T>
BinaryTree<T>::BinarySearchTree(const BinarySearchTree<T> &tree){	};
*/


template<class T>
bool BinaryTree<T>::isEmpty() const{
	return nodeCount == 0;
};

template<class T>
int BinaryTree<T>::getHeight() {
	return getHeightHelper(rootPtr);
};

template<class T>
int BinaryTree<T>::getNumberOfNodes() const{	};

template<class T>
T BinaryTree<T>::getRootData() const /*throw(PrecondViolatedExcept)*/{	};

template<class T>
void BinaryTree<T>::setRootData(const T &newEntry){	};

template<class T>
bool BinaryTree<T>::add(const T &newEntry){
	auto newNodePtr = std::make_shared<BinaryNode<T>>(newEntry);
	rootPtr = placeNode(rootPtr, newNodePtr);
	return true;
};

template<class T>
bool BinaryTree<T>::remove(const T &target){	};

template<class T>
void BinaryTree<T>::clear(){	};

template<class T>
T BinaryTree<T>::getEntry(const T &anEntry) const /*throw (NotFoundException)*/{	};

template<class T>
bool BinaryTree<T>::contains( T &anEntry)
{
	bool itemFound = search(rootPtr, anEntry);
	return itemFound;
};

template<class T>
void BinaryTree<T>::inorder(void visit(T&),
			std::shared_ptr<BinaryNode<T>> treePtr)
{
	if(treePtr != nullptr)
	{
		inorder(visit, treePtr->getLeftChild());
		T theItem = treePtr->getItem();
		visit(theItem);
		inorder(visit, treePtr->getRightChild());
	}
}

template<class T>
void BinaryTree<T>::inorderTraverse(void visit(T&))
{
	inorder(visit, rootPtr);
}

template class BinaryTree<EmployeeInfo>;

