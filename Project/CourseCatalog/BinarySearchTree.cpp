//============================================================================
// Name        : BinarySearchTree.cpp
// Author      : Joshua Wozny
// Version     : 1.0
// Last Updated: January 30, 2023
// Copyright   : Copyright © 2023,  portions Copyright © 2017 SNHU COCE
// Description : CS-300 Project Two, BinarySearchTree object
//============================================================================

#include "BinarySearchTree.h"

//Default constructor
// intializes root to nullptr
BinarySearchTree::BinarySearchTree()
{
	this->root = nullptr;
}
//Constructor passing a node pointer to intialize root with
BinarySearchTree::BinarySearchTree(Node* rootNode)
{
	this->root = rootNode;
}
//Destructor, delete the root pointer, which will also call the destructor for roots right and left pointers
BinarySearchTree::~BinarySearchTree()
{
	delete root;
}

/**
 * Insert a bid
 */
void BinarySearchTree::Insert(Course course) {
    // if root equarl to null ptr
        // root is equal to new node bid
    if (root == nullptr)
        root = new Node(course);
    // else
        // add Node root and bid
    else
        addNode(root, course);

    std::cout << "\Course added: " << course.Description() << std::endl;
}
/**
 * Add a bid to some node (recursive)
 *
 * @param node Current node in tree
 * @param bid Bid to be added
 */
Node* BinarySearchTree::addNode(Node* node, Course course) {
    // Return a new node if the tree is empty
    if (node == nullptr) return new Node(course);

    // Traverse to the right place and insert the node
    if (course.Number() < node->course.Number())
        node->left = addNode(node->left, course);
    else
        node->right = addNode(node->right, course);

    return node;


}
void BinarySearchTree::printInorder(Node* node)
{
    if (node == nullptr)
        return;

    /* first recur on left child */
    printInorder(node->left);

    /* then print the data of node */
    std::cout << node->course.Description() << std::endl;;

    /* now recur on right child */
    printInorder(node->right);
}
void BinarySearchTree::PrintCourseList()
{
    printInorder(this->root);
}

void BinarySearchTree::PrintCourse(string courseNumber)
{
    // set current node equal to root
    // keep looping downwards until bottom reached or matching bidId found
        // if match found, return current bid
        // if bid is smaller than current node then traverse left
        // else larger so traverse right
    Node* temp = this->root;
    // Run the loop untill temp points to a NULL pointer.
    while (temp != nullptr)
    {
        if (temp->course.Number() == courseNumber)
        {
            std::cout << "*************************************************\n" << temp->course.Description() << std::endl;
            temp->course.DisplayCoursePreprequisites();
            return;
        }
        // Shift pointer to left child.
        else if (temp->course.Number() > courseNumber)
            temp = temp->left;
        // Shift pointer to right child.
        else
            temp = temp->right;
    }

    std::cout << "\n Course not found\n" << std::endl;
    return;
}

