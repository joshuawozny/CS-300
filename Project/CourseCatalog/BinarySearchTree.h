#pragma once
//============================================================================
// Name        : BinarySearchTree.h
// Author      : Joshua Wozny
// Version     : 1.0
// Last Updated: January 30, 2023
// Copyright   : Copyright © 2023,  portions Copyright © 2017 SNHU COCE
// Description : CS-300 Project Two, BinarySearchTree object
//============================================================================

#include "Course.h"

//Defines a Node object
struct Node
{
    // member vars
    Course course;
    Node* left;
    Node* right;

    // constructor
    Node() : left(nullptr), right(nullptr) {};
    Node(Course course) : Node() {
        this->course = course;
    }
    //Destructor deletes right and left node pointers, which will recusively delete all node pointers from the tree
    ~Node() {
        delete left;
        delete right;
    }
};

class BinarySearchTree
{
    // private variables and methods used by the class
    Node* root;

    void printInorder(struct Node* node);
    Node* addNode(Node* node, Course course);

public:
    //Constructors
    BinarySearchTree();
    BinarySearchTree(Node* rootNode);
    //Destructor
    virtual ~BinarySearchTree();
    //Public methods
    void Insert(Course course);
    void PrintCourseList();
    void PrintCourse(string courseNumber);
};

