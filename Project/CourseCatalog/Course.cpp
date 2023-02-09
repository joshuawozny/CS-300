#include "Course.h"

Course::Course(){}

Course::Course(string courseNumber, string courseName, vector<string> coursePrerequisites) : Course()
{
	this->courseNumber = courseNumber;
	this->courseName = courseName;
	this->coursePrerequisites = coursePrerequisites;
}

Course::~Course()
{
	vector<string>().swap(this->coursePrerequisites);
}

string Course::Number()
{
	return this->courseNumber;
}

string Course::Name()
{
	return this->courseName;
}

string Course::Description()
{
	return this->courseNumber + ", " + this->courseName;
}

void Course::DisplayCoursePreprequisites()
{
	int preRequisitieCount = coursePrerequisites.size();
	int loopCount = 1;

	if (preRequisitieCount == 0) {
		std::cout << "None" << std::endl;
	}
	else {
		std::cout << "Prerequisites: ";
		for (string course : coursePrerequisites)
		{
			string endStr="";
			if (loopCount != preRequisitieCount) {
				endStr = ", ";
			}
			std::cout << course << endStr;
			++loopCount;
		}
		std::cout << "\n";
	}
}
