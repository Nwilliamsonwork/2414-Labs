#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "BinaryNode.h"

template <class T>
class BinaryTree
{
	private:
		std::shared_ptr<BinaryNode<T>> rootPtr;
		
	protected:
		auto placeNode(std::shared_ptr<BinaryNode<T>> subTree,
						std::shared_ptr<BinaryNode<T>> newNode);
						
		auto removeValue(std::shared_ptr<BinaryNode<T>> subTreePtr,
						const T target,
						bool &isSuccessful);
		
		auto removeNode(std::shared_ptr<BinaryNode<T>> toRemove);
		
		auto removeLeftmostNode(std::shared_ptr<BinaryNode<T>> subTree,
								T &inorderSuccessor);
		
		auto findNode(std::shared_ptr<BinaryNode<T>> subTree,
						const T &target);
	
	public:
		BinarySearchTree();
		BinarySearchTree(const T &rootItem);
		//BinarySearchTree(const BinarySearchTree<T> &tree);
		
		
		bool isEmpty() const;
		int getHeight() const;
		int getNumberOfNodes() const;
		T getRootData() const; //throw(PrecondViolatedExcept);
		void setRootData(const T &newData);
		bool add(const T &newEntry);
		bool remove(const T &target);
		void clear();
		T getEntry(const T &anEntry) const;// throw (NotFoundException);
		bool contains(const T &anEntry) const;
		
		
		//traversals if necessary
};

#endif
