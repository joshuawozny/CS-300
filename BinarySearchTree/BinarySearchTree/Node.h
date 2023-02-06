#pragma once
//============================================================================
// Name         : Node.h
//Last Updated  : February 5, 2023
// Author       : Joshua Wozny
// Version      : 1.0
// Copyright    : Copyright © 2023,  portions Copyright © 2017 SNHU COCE
// Description  : Binary Tree Project, CS-300: Bid object
//============================================================================

#include "Bid.h"

// Internal structure for tree node
class Node {
public:
    Bid bid;
    Node* left;
    Node* right;
    string key() {
        return bid.bidId;
    }

    // default constructor
    Node() {
        left = nullptr;
        right = nullptr;
    }

    // initialize with a bid
    Node(Bid aBid) :
        Node() {
        bid = aBid;
    }
    ~Node() {
        delete left;
        delete right;
    }
};