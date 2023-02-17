#include "Course.h"

//Default constructor, all variables are already intialized upon creation
Course::Course(){}
//Contructor with all course members are passed a value
Course::Course(string courseNumber, string courseName, vector<string> coursePrerequisites) : Course()
{
	this->courseNumber = courseNumber;
	this->courseName = courseName;
	this->coursePrerequisites = coursePrerequisites;
}
//Destructor, although vector handles its own garbage collection this will release memory more quickly (potentially) 
//than waiting for garbage collection to occur
Course::~Course()
{
	vector<string>().swap(this->coursePrerequisites);
}
//Getters
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
//Method to display pre-requisites by looping through the prerequisites vector
//with logic to include a comma except for the last prerequisite
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
