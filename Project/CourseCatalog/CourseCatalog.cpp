//============================================================================
// Name        : CourseCatalog.cpp
// Author      : Joshua Wozny
// Version     : 1.0
// Last Updated: February 9, 2023
// Copyright   : Copyright © 2023,  portions Copyright © 2017 SNHU COCE
// Description : CS-300 Project Two, main entry point
//============================================================================

#include <string>
#include "BSTParser.h"

using std::cin;
using std::endl;
using std::cout;

int main()
{
    //intialize the binary search tree that will store the course objects
    BinarySearchTree bst;
    //initialize the parser that will parse the selected csv file and load into the binary search tree
    csv::BSTParser parser = csv::BSTParser(&bst);

    //Initialize variables to hold the values input from the user for file name and coursenumber
    string fileName, courseNumber;
    
    
    int choice = 0;
    //Display the menu and get a menu selection from the user
    while (choice != 9) {
        cout << "\nWelcome to the course planner.\n" << endl;
        cout << "  1. Load Data Structure" << endl;
        cout << "  2. Print Course List" << endl;
        cout << "  3. Print Course" << endl;
        cout << "  9. Exit" << endl;
        cout << "\nWhat would you like to do? ";
        cin >> choice;
        cin.ignore();

        //Call appropriate methods based on the user selection
        switch (choice) {

        //Parse the file and load bids into the this -> bst
        case 1:
            if(parser.isFileLoaded()) {
                cout << "Data is already loaded" << endl;
                break;
            }
            cout << "Enter file name and path for input file: ";
            getline(cin, fileName);
            parser.ParseFile("data.csv");

            break;

        //Print a sample schedule or indicate that the list hasn't been loaded yet
        case 2:
            if (parser.isFileLoaded()) {
                cout << "\nHere is a sample schedule: \n" << endl;
                bst.PrintCourseList();
                break;
            }
            else {
                cout << "Data not loaded" << endl;
                break;
            }
        
        //Get user input to indicate what course they'd like more information for
        //Display the course information for selection or indicate that the selection does not exist 
        //or that data hasn't been loaded yet
        case 3:
            if (parser.isFileLoaded()) {
                cout << "What course do you want to know about? ";
                cin >> courseNumber;
                bst.PrintCourse(courseNumber);
                break;
            }
            else {
                cout << "Data not loaded" << endl;
                break;
            }
        //Exit program if 9 is selcted
        case 9:
            cout << "Thank you for using the course planner!" << endl;
            return 0;
        //For all other selections
        default:
            cout << choice << " is not a valid option." << endl;
        }
    }

    

    return -1;
}


