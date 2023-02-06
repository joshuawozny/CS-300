#pragma once
//============================================================================
// Name         : BinarySearchTree.h
//Last Updated  : February 5, 2023
// Author       : Joshua Wozny
// Version      : 1.0
// Copyright    : Copyright © 2023,  portions Copyright © 2017 SNHU COCE
// Description  : Binary Tree Project, CS-300: Binary Search Tree object
//============================================================================

#include "CSVparser.h"
#include "Node.h"

/**
 * Define a class containing data members and methods to
 * implement a binary search tree
 */
class BinarySearchTree {

private:
    Node* root;

    Node* addNode(Node* node, Bid bid);
    void inOrder(Node* node);
    void postOrder(Node* node);
    void preOrder(Node* node);
    Node* removeNode(Node* node, string bidId);

public:
    BinarySearchTree();
    virtual ~BinarySearchTree();
    void InOrder();
    void PostOrder();
    void PreOrder();
    void Insert(Bid bid);
    void Remove(string bidId);
    Bid Search(string bidId);
};