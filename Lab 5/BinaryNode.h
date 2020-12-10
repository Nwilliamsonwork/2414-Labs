#ifndef BINARYNODE_H
#define BINARYNODE_H

#include <memory>


template<class T>
class BinaryNode
{
	private:
		T item;
		std::shared_ptr<BinaryNode<T>> leftChild;
		std::shared_ptr<BinaryNode<T>> rightChild;
		
	public:

		BinaryNode(const T& newItem);

		void setItem(const T& anItem);
		T getItem() const;
		
		bool isLeaf() const;
		
		std::shared_ptr<BinaryNode<T>> getLeftChild() const;
		std::shared_ptr<BinaryNode<T>> getRightChild() const;
		
		void setLeftChild(std::shared_ptr<BinaryNode<T>> newLeft);
		void setRightChild(std::shared_ptr<BinaryNode<T>> newRight);

};

#endif
