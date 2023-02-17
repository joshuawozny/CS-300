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
	//Default constructor, creates a new Binary Search Tree to hold the parsed data
	BSTParser::BSTParser()
	{
		this->bst = new BinarySearchTree();
	}
	// Contstructor with a pointer to a provided Binary Search Tree
	BSTParser::BSTParser(BinarySearchTree* bst)
	{
		this->bst = bst;
	}
	//Destructor
	BSTParser::~BSTParser()
	{ 
	}
	// Method to parse a csv file with a string passed with the file name
	void BSTParser::ParseFile(string fname)
	{
		// string variables to hold a line and a word from the csv file
		// fstream object used to read the text file
		string line, word;
		std::fstream file (fname, std::ios::in);

		if (file.is_open()) {
			//gets each line of the file, one at a time
			//loops over each line looking for a comma and places each separated word into a variable
			while (std::getline(file, line)) {
				std::stringstream str(line);
				string courseNumber;
				string courseName;
				vector<string> prerequisites;
				int counter = 1;
				//for the first word in a line, assign to coursenumber, 2nd to coursename, 
				//then any other words added to prerequisites
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
				//Create the course object from the parsed line
				Course course = Course(courseNumber, courseName, prerequisites);
				this->bst->Insert(course);
				this->isLoaded = true;
			}
		}
		//If file cannot be opened
		else {
			std::cout << "Could not open file" << std::endl;
		}

	}
	// Indicate that a file has been loaded, used to prevent duplicated data
	// This would be latered if in the future you wanted to load multiple files with different courses
	bool BSTParser::isFileLoaded()
	{
		return this->isLoaded;
	}
}


