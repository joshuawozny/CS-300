#pragma once
//============================================================================
// Name        : HasTable.h
// Author      : Joshua Wozny
// Version     : 1.0
// Last Updated: January 30, 2023
// Copyright   : Copyright © 2023,  portions Copyright © 2017 SNHU COCE
// Description : CS-300 Project: HashTables
//============================================================================

#include <iostream>
#include <vector>

#include "Bid.h"
#include "LinkedList.h"

using std::string;
using std::vector;

//GLOBAL Constants
const unsigned int TABLE_DEFAULT_SIZE = 179;

class HashTable
{
	unsigned int tableSize;
	vector<LinkedList*> hashTable;

public:
	HashTable();
	HashTable(int size);
	virtual ~HashTable();
	void Insert(Bid bid);
	void PrintAll();
	void Remove(string bidId);
	Bid Search(string bidId);

};

