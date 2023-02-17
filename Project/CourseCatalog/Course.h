#pragma once
//============================================================================
// Name        : Course.h
// Author      : Joshua Wozny
// Version     : 1.0
// Last Updated: January 30, 2023
// Copyright   : Copyright © 2023,  portions Copyright © 2017 SNHU COCE
// Description : CS-300 Project Two, Course object
//============================================================================

#include <iostream>
#include <vector>

using std::string;
using std::vector;

class Course
{
	//Private course objects
	string courseNumber;
	string courseName;
	vector<string> coursePrerequisites;
public:	
	//Constructors
	Course();
	Course(string courseNumber, string courseName, vector<string> coursePrerequisites);
	//Destructor
	virtual ~Course();
	//Public Getters and methods
	string Number();
	string Name();
	string Description();
	void DisplayCoursePreprequisites();
};

