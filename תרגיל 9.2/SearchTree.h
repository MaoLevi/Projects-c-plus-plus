#pragma once
#pragma once
#include "Tree.h"
#include "QueueVector.h"
#include <iostream>
using namespace std;

template<class T>
class SearchTree : public Tree<T>
{

public:
	void add(T value);
	bool  search(T value)
	{
		return search(Tree<T>::root, value);
	}
	void remove(T val);
	T successor(T val);
	typename Tree<T>::Node* Find(typename Tree<T>::Node* current, T data);
	void deleteDuplicates();
	void deleteDuplicates(typename Tree<T>::Node* current);
	T minValue(typename Tree<T>::Node* root);
	typename Tree<T>::Node* remove(typename Tree<T>::Node* current, T val);


private:
	void add(typename Tree<T>::Node* current, T val);
	bool  search(typename Tree<T>::Node* current, T val);

};

template <class T>
void SearchTree<T>::add(T val)
{
	// add value to binary search tree 
	if (!Tree<T>::root)
	{
		Tree<T>::root = new typename Tree<T>::Node(val);
		return;
	}
	add(Tree<T>::root, val);
}

template<class T>
inline void SearchTree<T>::remove(T val)
{
	Tree<T>::root = remove(Tree<T>::root, val);

}

template<class T>
typename Tree<T>::Node* SearchTree<T>::remove(typename Tree<T>::Node* current, T val)
{
	if (current == NULL)
		return current;

	if (val < current->value)
		current->left = remove(current->left, val);

	else if (val > current->value)
		current->right = remove(current->right, val);

	else
		//If the node has no sons or has one son
	{
		if (current->left == NULL)
			return current->right;
		else if (current->right == NULL)
			return current->left;

		current->value = minValue(current->right);
		current->right = remove(current->right, current->value);
	}
	return current;
}

template<class T>
inline T SearchTree<T>::successor(T val)
//A function that returns the value of the successor node
{
	typename Tree<T>::Node* current = Find(this->root, val);
	if (current->right != NULL) {
		typename Tree<T>::Node* p = current->right;
		while (p->left != NULL)
			p = p->left;
		return p->value;
	}

	else {
		typename Tree<T>::Node* p = NULL;
		typename Tree<T>::Node* z = this->root;
		while (z != current) {
			if (z->value < current->value)
				z = z->right;

			else
			{
				p = z;
				z = z->left;
			}
		}
		if (p == NULL)
			throw "no successor";
		else return p->value;
	}
}
template<class T>
inline typename Tree<T>::Node* SearchTree<T>::Find(typename Tree<T>::Node* current, T data)
{

	if (current == NULL) return NULL;
	else if (current->value == data)return current;
	else if (current->value > data) return Find(current->left, data);
	else return Find(current->right, data);

}

template<class T>
inline void SearchTree<T>::deleteDuplicates()
{
	deleteDuplicates(this->root);

}

template<class T>
inline void SearchTree<T>::deleteDuplicates(typename Tree<T>::Node* current)
{

	static QueueVector<T> help(50);
	if (current)
	{
		deleteDuplicates(current->left);
		help.enqueue(current->value);
		deleteDuplicates(current->right);
	}

	if (current == Tree<T>::root)
	{
		T temp1, temp2;
		if (!help.isEmpty())
			temp1 = help.dequeue();

		while (!help.isEmpty())
		{
			temp2 = help.dequeue();
			if (temp1 == temp2)
			{
				remove(temp1);
			}
			temp1 = temp2;
		}
	}
}

template<class T>
inline T SearchTree<T>::minValue(typename Tree<T>::Node* root)
//Returns the smallest value in the tree
{
	typename Tree<T>::Node* current = root;

	while (current->left != NULL)
		current = current->left;
	return current->value;
}

template <class T>
void SearchTree<T>::add(typename Tree<T>::Node* current, T val)
{
	if (current->value < val)

		if (!current->right)
		{
			current->right = new typename Tree<T>::Node(val);
			return;
		}
		else add(current->right, val);
	else

		if (!current->left)
		{
			current->left = new typename Tree<T>::Node(val);
			return;
		}
		else add(current->left, val);
}

template <class T>
bool SearchTree<T>::search(typename Tree<T>::Node* current, T val)
//A function that checks if a particular value is in a tree
{
	if (!current)
		return false;
	if (current->value == val)
		return true;
	if (current->value < val)
		return search(current->right, val);
	else
		return search(current->left, val);
}

