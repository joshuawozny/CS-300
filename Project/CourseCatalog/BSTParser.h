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
		//Constructors
		BSTParser();
		BSTParser(BinarySearchTree* bst);
		//Destructor
		~BSTParser();
		void ParseFile(string fileName);
		//Getter
		bool isFileLoaded();

	private:
		// Private variables to hold objects private data
		string line, word;
		BinarySearchTree* bst;
		bool isLoaded;
	};
	
}


