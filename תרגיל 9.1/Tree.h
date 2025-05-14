#pragma once
#include <iostream>
#include <algorithm>
#include "Queue.h"
#include "QueueVector.h"
using namespace std;


//-----------------------------------
//  class Tree (Binary Trees)
// process nodes in Pre/In/Post  order
//-----------------------------------
template <class T>
class Tree
{
protected:
	//--------------------------------------------------------
	//  inner class Node
	//      a single Node from a binary tree
	//--------------------------------------------------------
	class Node
	{
	public:
		Node* left;
		Node* right;
		T value;
		Node(T val) : value(val), left(NULL), right(NULL) {}
		Node(T val, Node* l, Node* r) : value(val), left(l), right(r) {}
	};		//end of Node class

	//data member of tree
	Node* root;

public:
	Tree() { root = NULL; }	 // initialize tree
	~Tree();
	int isEmpty() const;
	void clear() { clear(root); root = NULL; }
	void preOrder() { preOrder(root); }
	void inOrder() { inOrder(root); }
	void postOrder() { postOrder(root); }

	virtual void process(T val) { cout << val << " "; }
	virtual void add(T val) = 0;
	virtual bool search(T val) = 0;
	virtual void remove(T val) = 0;

	int height();//return the height of the tree
	int height(Node* current);
	void reflect();
	void reflect(Node* current);
	void breadthScan();


private:
	//private function for not give acsses to user
	void  clear(Node* current);
	void  preOrder(Node* current);
	void  inOrder(Node* current);
	void  postOrder(Node* current);

};

//----------------------------------------------------------
//  class Tree implementation
//----------------------------------------------------------
template <class T>
Tree<T>::~Tree() // deallocate tree
{
	if (root != NULL)
		clear(root);
}

template <class T>
void Tree<T>::clear(Node* current)
{
	if (current)
	{    // Release memory associated with children
		if (current->left)
			clear(current->left);
		if (current->right)
			clear(current->right);
		delete current;
	}
}

template <class T>
int Tree<T>::isEmpty() const
{
	return  root == NULL;
}

// preOrder processing of tree rooted at current
template <class T>
void Tree<T>::preOrder(Node* current)
{    // visit Node, left child, right child
	if (current)
	{   // process current Node
		process(current->value);
		// then visit children
		preOrder(current->left);
		preOrder(current->right);
	}
}

// inOrder processing of tree rooted at current
template <class T>
void Tree<T>::inOrder(Node* current)
{    // visit left child, Node, right child
	if (current)
	{
		inOrder(current->left);
		process(current->value);
		inOrder(current->right);
	}
}

// postOrder processing of tree rooted at current
template <class T>
void Tree<T>::postOrder(typename Tree<T>::Node* current)
{    // visit left child, right child, node
	if (current)
	{
		postOrder(current->left);
		postOrder(current->left);
		process(current->value);

	}
}

template<class T>
inline int Tree<T>::height()
{
	if (isEmpty())
		return -1;

	else
		return height(root);
}

template<class T>
inline int Tree<T>::height(Node* current)
{
	if (current == NULL) return -1;
	else return max(height(current->left), height(current->right)) + 1;
}

template<class T>
inline void Tree<T>::reflect()
//A function that alternates between the position of the right son and the left son, in each sub-tree
{
	return reflect(root);
}

template<class T>
inline void Tree<T>::reflect(Node* current)
{
	if (current == NULL)
		return;
	Node* temp;
	reflect(current->left);//Reaches by recursion to the last left son
	reflect(current->right);//Reaches by recursion to the last right son

	//Switches between the two sons
	temp = current->left;
	current->left = current->right;
	current->right = temp;
}

template<class T>
inline void Tree<T>::breadthScan()
//A function that prints the values at tree nodes, level after level, left to right
{
	if (!isEmpty())
	{
		QueueVector<Node*> q(100);
		q.enqueue(root);
		while (!q.isEmpty())
		{
			Node* p = q.front();
			if (p->left != NULL)
				q.enqueue(p->left);
			if (p->right != NULL)
				q.enqueue(p->right);
			cout << p->value << " ";
			q.dequeue();
		}
	}
}

