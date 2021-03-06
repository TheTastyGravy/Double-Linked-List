#include "DLList.h"

DLList::DLList() :
	first(nullptr),
	last(nullptr)
{
}

DLList::~DLList()
{
	// Delete all nodes
	for (int i = 0; i < count(); i++)
	{
		popFront();
	}
}


void DLList::pushFront(int value)
{
	// Create new node with value to be added to the list
	DLListNode* newNode = new DLListNode(value);

	// If the list is empty, just set first and last
	if (isEmpty())
	{
		first = last = newNode;
		return;
	}
	
	// Set up the pointers, and change the first node
	first->previous = newNode;
	newNode->next = first;
	first = newNode;
}

void DLList::pushEnd(int value)
{
	// Create new node with value to be added to the list
	DLListNode* newNode = new DLListNode(value);

	// If the list is empty, just set first and last
	if (isEmpty())
	{
		first = last = newNode;
		return;
	}

	// Set up the pointers, and change the last node
	last->next = newNode;
	newNode->previous = last;
	last = newNode;
}

void DLList::insert(int value, DLListNode* node)
{
	// Create new node with value and corrent pointers
	DLListNode* newNode = new DLListNode(value, node, node->previous);

	// If the list is empty, just set first and last
	if (isEmpty())
	{
		first = last = newNode;
		return;
	}

	// If its the first element, push
	if (node == first)
	{
		pushFront(value);
		return;
	}
	// As the value is inserted before a node, it cant be at the end
	
	// Update the pointers of the two adjasent nodes
	newNode->previous->next = newNode;
	newNode->next->previous = newNode;
}


void DLList::popFront()
{
	// If the list is empty, do nothing
	if (isEmpty())
		return;
	
	// If there is only one node, 
	if (first == last)
	{
		delete first;
		first = last = nullptr;
		return;
	}

	// Delete first, and replace it with the next node
	DLListNode* temp = first->next;
	delete first;
	first = temp;
	first->previous = nullptr;
}

void DLList::popEnd()
{
	// If the list is empty, do nothing
	if (isEmpty())
		return;

	// If there is only one node
	if (first == last)
	{
		delete first;
		first = last = nullptr;
		return;
	}

	// Delete last, and replace it with the previous node
	DLListNode* temp = last->previous;
	delete last;
	last = temp;
	last->next = nullptr;
}

void DLList::removeFromList(DLListNode* node)
{
	// If the list is empty or nullptr, do nothing
	if (isEmpty() || node == nullptr)
		return;

	// If it is the only node in the list, it becomes empty
	if (node == first && node == last)
	{
		first = last = nullptr;
	}


	// Make next node first
	else if (node == first)
	{
		first = node->next;
		first->previous = nullptr;
	}
	// Make previous node last
	else if (node == last)
	{
		last = node->previous;
		last->next = nullptr;
	}

	// Make adjacent nodes point to eachother
	else
	{
		node->next->previous = node->previous;
		node->previous->next = node->next;
	}
}


int DLList::count()
{
	if (isEmpty())
		return 0;
	
	// Pointer to the current node
	DLListNode* current = first;
	int count = 1;

	// Move to the next node until the last node is reached
	while (current != last)
	{
		current = current->next;
		count++;
	}

	return count;
}

bool DLList::isEmpty()
{
	return (first == nullptr && last == nullptr);
}


void DLList::sort()
{
	// There is nothing infront of the first node, so start at the second
	DLListNode* current = first->next;

	// Iterate through all nodes
	while (current != nullptr)
	{
		// The start of the loop moves down to the next node
		DLListNode* comp = current;

		while (true)
		{
			// Get the next node down the list
			comp = comp->previous;

			if (comp->value < current->value)
			{
				// Insert it after the node smaller than it
				comp = comp->next;
				break;
			}
			else if (comp == first)
			{
				// Insert at the front as it is the smallest
				break;
			}
		}

		// Get the next node before moving current
		DLListNode* nextNode = current->next;

		// Insert the current node in its correct spot
		if (current != comp)
			move(current, comp);

		current = nextNode;
	}
}

void DLList::move(DLListNode* movedNode, DLListNode* baseNode)
{
	// Remove refrences to nodeMove
	removeFromList(movedNode);

	// Change pointers of the node
	movedNode->next = baseNode;
	movedNode->previous = baseNode->previous;

	
	// If its the first element, 'push' it
	if (baseNode == first)
	{
		// Set up the pointers, and change the first node
		first->previous = movedNode;
		movedNode->next = first;
		first = movedNode;
		return;
	}
	// As the value is inserted before a node, it cant be at the end

	// Update the pointers of the two adjasent nodes
	movedNode->previous->next = movedNode;
	movedNode->next->previous = movedNode;
}