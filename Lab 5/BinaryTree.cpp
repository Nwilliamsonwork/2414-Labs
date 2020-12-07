#include "BinaryTree.h"
#include "EmployeeInfo.h"

#include <memory>

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
						 T &target)
{
	if(subTree == nullptr)
		return false;
	else if(target == subTree->getItem())
		return true;
	else if (target < subTree->getItem())
		search(subTree->getLeftChild(), target);
	else
		search(subTree->getRightChild(), target);
};
/*
//COMPLETE
// WRONG FUNCTION. THIS IS FOR A NON-SORTED TREE
template<class T>
auto BinaryTree<T>::balancedAdd(std::shared_ptr<BinaryNode<T>> subTreePtr,
							std::shared_ptr<BinaryNode<T>> newNodePtr)
{
	if(subTreePtr == nullptr)
		return newNodePtr;
	else
	{
		auto leftPtr = subTreePtr->getLeftChild();
		auto rightPtr = subTreePtr->getRightChild();
		
		if(getHeightHelper(leftPtr) > getHeightHelper(rightPtr))
		{
			rightPtr = balancedAdd(rightPtr, newNodePtr);
			subTreePtr->setRightChild(rightPtr);
		}
		else
		{
			leftPtr = balancedAdd(leftPtr, newNodePtr);
			subTreePtr->setLeftChild(leftPtr);
		}
		
		return subTreePtr;
	}
};
*/

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

template class BinaryTree<EmployeeInfo>;

