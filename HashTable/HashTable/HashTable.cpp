//============================================================================
// Name        : HasTable.cpp
// Author      : Joshua Wozny
// Version     : 1.0
// Last Updated: January 30, 2023
// Copyright   : Copyright © 2023,  portions Copyright © 2017 SNHU COCE
// Description : CS-300 Project: HashTables
//============================================================================

#include "HashTable.h"

unsigned int hash(string bidId, int size) {
	return atoi(bidId.c_str()) % size;
}

HashTable::HashTable() {
	this->tableSize = TABLE_DEFAULT_SIZE;
	this->hashTable = vector<LinkedList*>(this->tableSize, nullptr);
}
HashTable::HashTable(int size) {
	this->tableSize = size;
	this->hashTable = vector<LinkedList*>(this->tableSize, nullptr);
}
HashTable::~HashTable() {
	vector<LinkedList*>().swap(this->hashTable);
}
void HashTable::Insert(Bid bid) {
	unsigned int key = hash(bid.getBidId(), this->tableSize);
	if (this->hashTable.at(key) == nullptr) {
		this->hashTable.at(key) = new LinkedList();	
	}
	this->hashTable.at(key)->Append(bid, key);
}
void HashTable::PrintAll() {
	for (int key = 0; key < this->tableSize; ++key) {
		if (this->hashTable.at(key) != nullptr) {
			this->hashTable.at(key)->PrintList();
		}
	}

}
void HashTable::Remove(string bidId) {
	unsigned int key = hash(bidId, this->tableSize);
	if (this->hashTable.at(key) != nullptr) {
		this->hashTable.at(key)->Remove(bidId);
	}
}
Bid HashTable::Search(string bidId) {
	Bid bid;

	unsigned int key = hash(bidId, this->tableSize);
	if (this->hashTable.at(key) != nullptr) {
		bid = this->hashTable.at(key)->Search(bidId);
	}
	else {
		bid = Bid();
	}

	return bid;
}
