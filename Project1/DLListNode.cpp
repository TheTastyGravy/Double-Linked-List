#include "DLListNode.h"

DLListNode::DLListNode(int value) :
	value(value),
	next(nullptr),
	previous(nullptr)
{
}

DLListNode::DLListNode(int value, DLListNode* next, DLListNode* previous) :
	value(value),
	next(next),
	previous(previous)
{
}

DLListNode::~DLListNode()
{
}