#include "BinaryNode.h"
template<class T>
BinaryNode<T>::BinaryNode(){	};

template<class T>
BinaryNode<T>::BinaryNode(const T& newItem){	};

template<class T>
BinaryNode<T>::BinaryNode(const T& newItem,
						std::shared_ptr<BinaryNode<T>> leftChild,
						std::shared_ptr<BinaryNode<T>> rightChild){	};

template<class T>
void BinaryNode<T>::setItem(const T& anItem){	};

template<class T>
T BinaryNode<T>::getItem() const{	};

template<class T>
bool BinaryNode<T>::isLeaf() const{	};

template<class T>
auto BinaryNode<T>::getLeftChild() const{	};

template<class T>
auto BinaryNode<T>::getRightChild() const{	};

template<class T>
void BinaryNode<T>::setLeftChild(std::shared_ptr<BinaryNode<T>> newLeft){	};

template<class T>
void BinaryNode<T>::setRightChild(std::shared_ptr<BinaryNode<T>> newRight){	};

