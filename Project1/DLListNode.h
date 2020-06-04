#pragma once

// A single element of DLList
class DLListNode
{
public:
	// Create new node holding 'value'
	DLListNode(int value);
	// Create new node holding 'value', and pointers to 'next' and 'previous'
	DLListNode(int value, DLListNode* next, DLListNode* previous);
	~DLListNode();


	// The value held by the node
	int value;

	// Pointer to the next node in the list
	DLListNode* next;
	// Pointer to the previous node in the list
	DLListNode* previous;
};