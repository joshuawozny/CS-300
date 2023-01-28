//============================================================================
// Name        : LinkedList.h
// Author      : Joshua Wozny
// Version     : 1.0
// Copyright   : Copyright © 2023,  portions Copyright © 2017 SNHU COCE
// Description : Lab 3-3 Lists and Searching
//============================================================================

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <iostream>
#include <time.h>

#include "Bid.h"

class LinkedList {
public:
	LinkedList();
	virtual ~LinkedList();
	void Append(Bid bid);
	void Prepend(Bid bid);
	void PrintList();
	void Remove(std::string bidId);
	Bid Search(std::string bidId);
	int Size();

private:
	//Internal structure for list entries, housekeeping variables
	struct Node {
		Bid bid;
		Node* next;

		// default constructor
		Node() {
			next = nullptr;
		}

		// initialize with a bid
		Node(Bid aBid) {
			bid = aBid;
			next = nullptr;
		}
	};

	Node* head;
	Node* tail;
	int size = 0;

	bool keyExists(std::string key);
};

#endif /* LINKEDLIST_H_ */
