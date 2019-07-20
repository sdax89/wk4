// Implementation file for the IntList class
#include <iostream>  // For cout  and NULL
#include "IntList.h"
using namespace std;

/*
Modify the linked list class you created in the previous programming challenges
  to include a member function named search that returns the position of a specific value, x, in the linked list.
 - The first node in the list is at position 0,
 - the second node is at position 1,
 - and so on.
 -If x is not found on the list, the search should return −1.
Test the new member function using an appropriate driver program.
*/

//**************************************************
// Copy constructor                                *
//**************************************************

IntList::IntList(const IntList& listObj)
{
	ListNode* nodePtr = nullptr;

	// Initialize the head pointer.
	head = nullptr;
	tail = nullptr;
	// Point to the other object's head.
	nodePtr = listObj.head;

	// Traverse the other object.
	while (nodePtr)
	{
		// Append a copy of the other object's
		// node to this list.
		appendNode(nodePtr->value);

		// Go to the next node in the other object.
		nodePtr = nodePtr->next;
	}
}

//**************************************************
// appendNode appends a node containing the        *
// value pased into num, to the end of the list.   *
//**************************************************

void IntList::appendNode(int num)
{
	ListNode* newNode, * nodePtr = nullptr;

	// Allocate a new node & store num
	newNode = new ListNode;
	newNode->value = num;
	newNode->next = nullptr;
	newNode->previous = nullptr;

	// If there are no nodes in the list
	// make newNode the first node
	if(!head)
	{
		head = newNode;
		tail = head;
	}
	else  // Otherwise, insert newNode at end
	{
		//set our new nodes previous node to the current tail
		newNode->previous = tail;

		// Insert newNode as the last node
		tail->next = newNode;

		//set the new tail to the new node (which is now the tail)
		tail = newNode;
	}
	

}

//**************************************************
// The print function displays the value           *
// stored in each node of the linked list          *
// pointed to by head.                             *
//**************************************************

void IntList::print()
{
	ListNode* nodePtr = nullptr;

	nodePtr = head;
	while (nodePtr)
	{
		cout << nodePtr->value << endl;
		nodePtr = nodePtr->next;
	}
}

//**************************************************
// The insertNode function inserts a node with     *
// num copied to its value member.                 *
//**************************************************

void IntList::insertNode(int num)
{
	ListNode* newNode, * nodePtr, * previousNode = nullptr;

	// Allocate a new node & store num
	newNode = new ListNode;
	newNode->value = num;

	// If there are no nodes in the list
	// make newNode the first node
	if (!head)
	{
		head = newNode;
		newNode->next = nullptr;
	}
	else  // Otherwise, insert newNode
	{
		// Initialize nodePtr to head of list and
		// previousNode to a null pointer.
		nodePtr = head;
		previousNode = nullptr;

		// Skip all nodes whose value member is less
		// than num.
		while (nodePtr != nullptr && nodePtr->value < num)
		{
			nodePtr = nodePtr->next;
		}

		// If the new node is to be the 1st in the list,
		// insert it before all other nodes.
		if (previousNode == nullptr)
		{
			head = newNode;
			newNode->next = nodePtr;
		}
		else  // Otherwise, insert it after the prev node
		{
			newNode->previous = nodePtr;	//set our added nodes previous to the last node that was valid
			newNode->next = nodePtr->next;	//set the next node after our added node to the next valid node

			nodePtr->next = newNode;	//set the last found valid nodes next node to our new node
		}
	}
}

//**************************************************
// The deleteNode function searches for a node     *
// with num as its value. The node, if found, is   *
// deleted from the list and from memory.          *
//**************************************************

void IntList::deleteNode(int num)
{
	ListNode* nodePtr, * previousNode = nullptr;

	// If the list is empty, do nothing.
	if (!head)
		return;

	// Determine if the first node is the one.
	if (head->value == num)
	{
		nodePtr = head->next;
		delete head;
		head = nodePtr;
		head->previous = nullptr;
	}
	else
	{
		// Initialize nodePtr to head of list
		nodePtr = head;

		// Skip all nodes whose value member is 
		// not equal to num.
		while (nodePtr != nullptr && nodePtr->value != num)
		{
			nodePtr = nodePtr->next;
		}

		// If nodePtr is not at the end of the list, 
		// link the previous node to the node after
		// nodePtr, then delete nodePtr.
		if (nodePtr)
		{
			nodePtr->previous->next = nodePtr->next;
			nodePtr->next->previous = nodePtr->previous;
			delete nodePtr;
		}
	}
}

void IntList::reverse()
{
	ListNode* newHead = nullptr;
	ListNode* nodePtr = tail;

	// Traverse the list, building a
	// copy of it in reverse order.
	//start at the end of the list and work backwards.
	while (nodePtr)
	{
		//append the current nodes value to a new list
		newHead.append(tail->value);

		// Go to the previous node in the list.
		nodePtr = nodePtr->previous;
	}

	// Destroy the existing list.
	destroy();

	// Make head point to the new list.
	head = newHead;
}

//**************************************************
// The destroy function destroys all the nodes     *
// in the list.                                    *
//**************************************************

void IntList::destroy()
{
	ListNode* nodePtr, * nextNode = nullptr;

	nodePtr = head;
	while (nodePtr != nullptr)
	{
		nextNode = nodePtr->next;
		delete nodePtr;
		nodePtr = nextNode;
	}

	head = nullptr;
}

//**************************************************
// Destructor                                      *
// This function deletes every node in the list.   *
//**************************************************

IntList::~IntList()
{
	destroy();
}
