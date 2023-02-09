//============================================================================
// Name        : BSTParser.cpp
// Author      : Joshua Wozny
// Version     : 1.0
// Last Updated: February 9, 2023
// Copyright   : Copyright © 2023
// Description : CS-300 Project Two, BST Parser object
//============================================================================


#include <string>
#include <fstream>
#include <sstream>

#include "BSTParser.h"

namespace csv {
	BSTParser::BSTParser()
	{
		this->bst = new BinarySearchTree();
	}
	BSTParser::BSTParser(BinarySearchTree* bst)
	{
		this->bst = bst;
	}
	BSTParser::~BSTParser()
	{
	}
	void BSTParser::ParseFile(string fname)
	{
		string line, word;
		std::fstream file (fname, std::ios::in);

		if (file.is_open()) {
			while (std::getline(file, line)) {
				std::stringstream str(line);
				string courseNumber;
				string courseName;
				vector<string> prerequisites;
				int counter = 1;

				while (getline(str, word, ',')) {
					if (counter == 1) {
						courseNumber = word;
					}
					if (counter == 2) {
						courseName = word;
					}
					if (counter > 2) {
						prerequisites.push_back(word);
					}
					++counter;
				}
				Course course = Course(courseNumber, courseName, prerequisites);
				this->bst->Insert(course);
				this->isLoaded = true;
			}
		}
		else {
			std::cout << "Could not open file" << std::endl;
		}

	}
	bool BSTParser::isFileLoaded()
	{
		return this->isLoaded;
	}
}


