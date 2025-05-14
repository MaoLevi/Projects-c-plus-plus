#include <algorithm>
#include "QueueVector.h"
#include "Queue.h"

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


	void reflectRec(Node* current);
	void breadthScan();//scan tree node and print by level
	int heightRec(Node* current);
	void reflect();//create mirror image of original tree
	int height();//return tree height 


private:
	//private function for not give acsses to user
	void  clear(Node* current);
	void  preOrder(Node* current);
	void  inOrder(Node* current);
	void  postOrder(Node* current);

};

//-----------------------------------------------------------------------------------//
//							 class Tree implementation
//-----------------------------------------------------------------------------------//
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

template <class T>
void Tree<T>::inOrder(Node* current)
{
	if (current)
	{
		inOrder(current->left);
		process(current->value);
		inOrder(current->right);
	}
}

template <class T>
void Tree<T>::postOrder(typename Tree<T>::Node* current)
{
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
	if (isEmpty()) return -1;
	else return heightRec(root);
}

template<class T>
inline int Tree<T>::heightRec(Node* current)//-------------------------change meeeeeeeeeeeeee
{
	if (current == NULL) return -1;
	else return max(heightRec(current->left), heightRec(current->right)) + 1;
}

template<class T>
inline void Tree<T>::reflect()
{
	return reflectRec(root);
}

template<class T>
inline void Tree<T>::reflectRec(Node* current)//-------------------------change meeeeeeeeeeeeee
{
	if (current == NULL)
		return;
	Node* d1;
	reflectRec(current->left);
	reflectRec(current->right);
	d1 = current->left;
	current->left = current->right;
	current->right = d1;
}

template<class T>
inline void Tree<T>::breadthScan()
{
	if (!isEmpty()) {
		QueueVector<Node*> newQ(150);
		newQ.enqueue(root);
		while (!newQ.isEmpty()) {
			Node* newNode = newQ.front();
			if (newNode->left != NULL)
				newQ.enqueue(newNode->left);
			if (newNode->right != NULL)
				newQ.enqueue(newNode->right);
			cout << newNode->value << " ";
			newQ.dequeue();
		}
	}
}
