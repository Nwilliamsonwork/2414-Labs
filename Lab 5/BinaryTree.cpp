#include "BinaryTree.h"
#include "EmployeeInfo.h"

template<class T>
auto BinaryTree<T>::placeNode(std::shared_ptr<BinaryNode<T>> subTree,
								std::shared_ptr<BinaryNode<T>> newNode){	};

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
int BinaryTree<T>::getHeight() const{	};

template<class T>
int BinaryTree<T>::getNumberOfNodes() const{	};

template<class T>
T BinaryTree<T>::getRootData() const /*throw(PrecondViolatedExcept)*/{	};

template<class T>
void BinaryTree<T>::setRootData(const T &newEntry){	};

template<class T>
bool BinaryTree<T>::add(const T &newEntry){
	auto newNodePtr = std::make_shared<BinaryNode<T>>(newEntry);
	return true;
};

template<class T>
bool BinaryTree<T>::remove(const T &target){	};

template<class T>
void BinaryTree<T>::clear(){	};

template<class T>
T BinaryTree<T>::getEntry(const T &anEntry) const /*throw (NotFoundException)*/{	};

template<class T>
bool BinaryTree<T>::contains(const T &anEntry) const{	};

template class BinaryTree<EmployeeInfo>;

