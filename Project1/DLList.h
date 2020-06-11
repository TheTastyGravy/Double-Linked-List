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
	void removeFromList(DLListNode* node);

	// Returns the number of elements in the list
	int count();
	// Are there any nodes currently in the list?
	bool isEmpty();

	// Returns the first node in the list
	DLListNode* getFirst() { return first; }
	// Returns the last node in the list
	DLListNode* getLast() { return last; }

	// Sort the list using insertion sort
	void sort();

private:
	// Move 'movedNode' to the location of 'baseNode'
	void move(DLListNode* movedNode, DLListNode* baseNode);

	// These should only be changed when nodes are added or removed,
	// and are therefore private with public getters
	DLListNode* first;
	DLListNode* last;
};