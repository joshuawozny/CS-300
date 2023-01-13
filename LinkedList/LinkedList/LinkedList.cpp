//============================================================================
// Name        : LinkedList.cpp
// Author      : Joshua Wozny
// Version     : 1.0
// Copyright   : Copyright © 2023,  portions Copyright © 2017 SNHU COCE
// Description : Lab 3-3 Lists and Searching
//============================================================================

#include "LinkedList.h"

/**
 * Default constructor
 */
LinkedList::LinkedList() {
	//set head and tail equal to null
	head = nullptr;
	tail = nullptr;
}

/**
 * Destructor
 */
LinkedList::~LinkedList() {
	// start at the head
	Node* current = head;
	Node* temp;

	// loop over each node, detach from list then delete
	while (current != nullptr) {
		temp = current; // hang on to current node
		current = current->next; // make current the next node
		delete temp; // delete the orphan node
	}
}

/**
 * Append a new bid to the end of the list
 */
void LinkedList::Append(Bid bid) {
	if (this->keyExists(bid.getBidId())) {
		std::cout << "Duplicate key in BidId Enter another bid" << std::endl;
		return;
	}
	//Create new node
	Node* new_node = new Node(bid);
	//if there is nothing at the head...
	if (head == nullptr) {
		// new node becomes the head and the tail
		head = new_node;
		tail = new_node;
	}
	//else
	else {
		// make current tail node point to the new node
		// and tail becomes the new node
		tail->next = new_node;
		tail = new_node;
	}
	//increase size count
	++size;
}

/**
 * Prepend a new bid to the start of the list
 */
void LinkedList::Prepend(Bid bid) {
	if (this->keyExists(bid.getBidId())) {
		std::cout << "Duplicate key in BidId Enter another bid" << std::endl;;
		return;
	}
	// Create new node
	Node* new_node = new Node(bid);
	// if there is already something at the head...
	if (head != nullptr) {
		// new node points to current head as its next node
		new_node->next = head;
	}

	// head now becomes the new node
	head = new_node;
	//increase size count
	++size;

}

/**
 * Simple output of all bids in the list
 */
void LinkedList::PrintList() {
	// start at the head
	Node* current = head;
	// while loop over each node looking for a match
	while (current != nullptr) {
		//output current bidID, title, amount and fund
		current->bid.display();
		//set current equal to next
		current = current->next;
	}
}

/**
 * Remove a specified bid
 *
 * @param bidId The bid id to remove from the list
 */
void LinkedList::Remove(std::string bidId) {
	// special case if matching node is the head
	if (head->bid.getBidId() == bidId) {
		// make head point to the next node in the list
		head = head->next;
		//decrease size count
		--size;
		//return
		return;
	}

	// start at the head
	Node* current = head;
	// while loop over each node looking for a match
	while (current != nullptr) {
		if (current->next == nullptr) {
			return;
		}
		// if the next node bidID is equal to the current bidID
		if (current->next->bid.getBidId() == bidId) {
			// hold onto the next node temporarily
			Node* temp = current->next;
			// make current node point beyond the next node
			current = temp->next;
			// now free up memory held by temp
			temp = nullptr;
			// decrease size count
			--size;
			//return
			return;
		}

		// current node is equal to next node
		current = current->next;
	}

}

/**
 * Search for the specified bidId
 *
 * @param bidId The bid id to search for
 */
Bid LinkedList::Search(std::string bidId) {
	// start at the head of the list
	Node* current = head;

	while (current != nullptr) {
		if (current->bid.getBidId() == bidId) {
			// if the current node matches, return it
			return current->bid;
		}
		// else current node is equal to next node
		current = current->next;
	}
	Bid bid = Bid();
	return bid;
}

/**
 * Returns the current size (number of elements) in the list
 */
int LinkedList::Size() {
	return size;
}

bool LinkedList::keyExists(std::string key)
{
	Node* current = head;
	for (int i = 0; i < this->Size(); i++) {
		if (current->bid.getBidId() == key) {
			return true;
		}
		current = current->next;
		++i;
	}

	return false;
}

