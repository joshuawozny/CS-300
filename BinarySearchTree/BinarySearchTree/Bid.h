#pragma once
//============================================================================
// Name         : Bid.h
//Last Updated  : February 5, 2023
// Author       : Joshua Wozny
// Version      : 1.0
// Copyright    : Copyright © 2023,  portions Copyright © 2017 SNHU COCE
// Description  : Binary Tree Project, CS-300: Bid object
//============================================================================

#include <iostream>

using std::string;

// define a structure to hold bid information
class Bid {
public:
    string bidId; // unique identifier
    string title;
    string fund;
    double amount;
    Bid();
};