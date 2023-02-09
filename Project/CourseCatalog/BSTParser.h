#pragma once
//============================================================================
// Name        : BSTParser.h
// Author      : Joshua Wozny
// Version     : 1.0
// Last Updated: February 9, 2023
// Copyright   : Copyright © 2023
// Description : CS-300 Project Two, BST Parser object
//============================================================================


# include <iostream>
#include "BinarySearchTree.h"

using std::string;

namespace csv
{
	class BSTParser
	{
		
	public:
		BSTParser();
		BSTParser(BinarySearchTree* bst);
		~BSTParser();
		void ParseFile(string fileName);
		bool isFileLoaded();

	private:
		string line, word;
		BinarySearchTree* bst;
		bool isLoaded;
	};
	
}


