#pragma once
#include "DLListNode.h"

// Custom Double-Linked List class, using DLListNode as elements
class DLList
{
public:
	DLList();
	~DLList();


	// Add a new node with 'value' to the front of the list
	void pushFront(int value);
	// Add a new node with 'value' to the end of the list
	void pushEnd(int value);
	// Add a new node with 'value' at the location of 'node'
	void insert(int value, DLListNode* node);

	// Remove the node at the front of the list
	void popFront();
	// Remove the node at the end of the list
	void popEnd();
	// Remove 'node' from the list
	void remove(DLListNode* node);

	// Returns the number of elements in the list
	int count();
	// Are there any nodes currently in the list?
	bool isEmpty();

	// Returns the first node in the list
	DLListNode* getFirst() { return first; }
	// Returns the last node in the list
	DLListNode* getLast() { return last; }

	// Sort the list
	void sort();

private:
	// These should only be changed when nodes are added or removed,
	// and are therefore private with public getters
	DLListNode* first;
	DLListNode* last;
};