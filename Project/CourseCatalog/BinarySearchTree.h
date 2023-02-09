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
    ~Node() {
        delete left;
        delete right;
    }
};

class BinarySearchTree
{
    Node* root;

    void printInorder(struct Node* node);
    Node* addNode(Node* node, Course course);

public:
    BinarySearchTree();
    BinarySearchTree(Node* rootNode);
    virtual ~BinarySearchTree();

    void Insert(Course course);
    void PrintCourseList();
    void PrintCourse(string courseNumber);
};

