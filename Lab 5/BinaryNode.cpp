#include "BinaryNode.h"
template<class T>
BinaryNode::BinaryNode(){	};

template<class T>
BinaryNode::BinaryNode(const T& newItem){	};

template<class T>
BinaryNode::BinaryNode(const T& newItem,
						std::shared_ptr<BinaryNode<T>> leftChild,
						std::shared_ptr<BinaryNode<T>> rightChild){	};

template<class T>
void BinaryNode::setItem(const T& anItem){	};

template<class T>
T BinaryNode::getItem() const{	};

template<class T>
bool BinaryNode::isLeaf() const{	};

template<class T>
auto BinaryNode::getLeftChild() const{	};

template<class T>
auto BinaryNode::getRightChild() const{	};

template<class T>
void BinaryNode::setLeftChild(std::shared_ptr<BinaryNode<T>> newLeft){	};

template<class T>
void BinaryNode::setRightChild(std::shared_ptr<BinaryNode<T>> newRight){	};

