#pragma once
// Specification file for the IntList class
#ifndef INTLIST_H
#define INTLIST_H

class IntList
{
private:
	// Declare a structure for the list
	struct ListNode
	{
		int value;
		struct ListNode* next;
		struct ListNode* previous;
	};

	ListNode* head;   // List head pointer
	ListNode* tail;   // List tail pointer

	// Destroy function
	void destroy();

public:
	// Constructor
	IntList()
	{
		head = nullptr;
		tail = nullptr;
	}

	// Copy constructor
	IntList(const IntList&);

	// Destructor
	~IntList();

	// List operations
	void appendNode(int);
	void insertNode(int);
	void deleteNode(int);
	void print();
	void reverse();
};

#endif
