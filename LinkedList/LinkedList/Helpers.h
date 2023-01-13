//============================================================================
// Name        : Helpers.h
// Author      : Joshua Wozny
// Version     : 1.0
// Copyright   : Copyright © 2017 SNHU COCE
// Description : Lab 3-3 Lists and Searching
//============================================================================

#include <iostream>
#include <algorithm>

double strToDouble(std::string str, char ch) {
    str.erase(remove(str.begin(), str.end(), ch), str.end());
    return atof(str.c_str());
};
