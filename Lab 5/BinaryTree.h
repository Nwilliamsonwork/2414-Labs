#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "BinaryNode.h"

template <class T>
class BinaryTree
{
	private:
		std::shared_ptr<BinaryNode<T>> rootPtr;
		int nodeCount;
		int height;
		
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
		
		bool search(std::shared_ptr<BinaryNode<T>> subTree,
						T &target);
	
		//auto balancedAdd(std::shared_ptr<BinaryNode<T>> subTree,
		//					std::shared_ptr<BinaryNode<T>> NewNodePtr);
							
		auto getHeightHelper(std::shared_ptr<BinaryNode<T>> subTreePtr);
		
	public:
		BinaryTree();
		BinaryTree(const T &rootItem);
		//BinarySearchTree(const BinarySearchTree<T> &tree);
		
		/*
		Function: isEmpty()
		Inputs: None
		Outputs: A boolean value. True if the tree is empty. False otherwise.
		Purpose: Allows client code determine if the tree is empty
		*/
		bool isEmpty() const;
		
		/*
		Function: getHeight
		Inputs: None
		Outputs: An integer value representing the height of the tree
		Purpose: Allows client code to see the height of the tree
		*/
		int getHeight() ;
		
		/*
		Function: getNumberOfNodes
		Inputs: None
		Outputs: An integer value representing the number of nodes in the tree
		Purpose: Allows client code to see the total number of nodes currently stored in the tree.
		*/
		int getNumberOfNodes() const;
		
		/*
		Function: getRootData
		Inputs: None
		Outputs: An object of type T to which rootPtr points
		Purpose: Allows client code to access the object at the root of the tree
		*/
		T getRootData() const; //throw(PrecondViolatedExcept);
		
		/*
		Function: setRootData
		Inputs: An object of type T
		Outputs: None
		Purpose: Allows client code to change the object contained by the node pointed to by rootPtr
		*/
		void setRootData(const T &newData);
		
		/*
		Function: add
		Inputs: An object of type T
		Outputs: None
		Purpose: Allows client code to add a new entry to the tree.
				Note that this implementation of a binary tree is sorted, so this function must insert the 
				new object at the correct location.
		*/
		bool add(const T &newEntry);
		
		/*
		Function: remove
		Inputs: An object of type T
		Outputs: A boolean value. True if an object was successfully removed. False if no object was removed.
		Purpose: Allows client code to remove the first node whose value matches that of the input.
		*/
		bool remove(const T &target);
		
		/*
		Function: clear
		Inputs: None
		Outputs: None
		Purpose: Allows client code to reset the tree and its member variables to default values.
		*/
		void clear();
		
		/*
		Function: getEntry
		Inputs: An object of type T
		Outputs: The entry in the binary tree that matches the target
		Purpose: Allows client code to retrieve a specific data item contained in the tree
		*/
		T getEntry(const T &target) const;// throw (NotFoundException);
		
		/*
		Function: contains
		Inputs: An object of type T
		Outputs: A boolean value. True if the tree contains a data item that matches the target, False if not.
		Purpose: Allows client code to test whether the specified data item occurs at least once in the tree.
		*/
		bool contains( T &target);
		
		
		
		
		//traversals if necessary
};

//#include "BinaryTree.cpp"
#endif
