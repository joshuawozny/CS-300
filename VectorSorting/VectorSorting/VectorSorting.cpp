//============================================================================
// Name        : VectorSorting.cpp
// Author      : Joshua Wozny
// Version     : 1.0
// Copyright   : Copyright 2023, some material Copyright © 2017 SNHU COCE
// Description : Vector Sorting Algorithms
//============================================================================

#include <algorithm>
#include <time.h>

#include "Bidding.hpp"
#include "VectorSorting.hpp"

using namespace std;



// DONE (2a): Implement the quick sort logic over bid.title
    // MOVED Quicksort and Partition FUNCTIONS to header file
// DONE (1a): Implement the selection sort logic over bid.title
    // MOVED Selectionsort FUNCTION to header file

// The one and only main() method

int main(int argc, char* argv[]) {

    // process command line arguments
    string csvPath;
    switch (argc) {
    case 2:
        csvPath = argv[1];
        break;
    default:
        csvPath = "eBid_Monthly_Sales.csv";   //Performance difference is only really noticeable with the larger file.
    }

    // Define a vector to hold all the bids
    vector<Bid> bids;

    // Define a timer variable
    clock_t ticks;

    clock_t quick_ticks = 0;   //used to hold performance of quick sort
    clock_t select_ticks = 0;  //used to hold performance of select sort

    bool isSorted = false;  // tracks if the vector is in a sorted state or not.

    int choice = 0;
    while (choice != 9) {
        cout << "Menu:" << endl;
        cout << "  1. Load Bids" << endl;
        cout << "  2. Display All Bids" << endl;
        cout << "  3. Selection Sort All Bids" << endl;
        cout << "  4. Quick Sort All Bids" << endl;
        cout << "  5. Report Performance Difference" << endl;    //Added to display performance difference
        cout << "  9. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            // Initialize a timer variable before loading bids
            ticks = clock();

            // Complete the method call to load the bids
            bids = loadBids(csvPath);

            cout << bids.size() << " bids read" << endl;

            // Calculate elapsed time and display result
            ticks = clock() - ticks; // current clock ticks minus starting clock ticks
            cout << "time: " << ticks << " clock ticks" << endl;
            cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;

            isSorted = false;  // each time this is called vector is no longer sorted
            break;

        case 2:
            // Loop and display the bids read
            for (int i = 0; i < bids.size(); ++i) {
                displayBid(bids[i]);
            }
            cout << endl;

            break;

        // DONE (1b): Invoke the selection sort and report timing results
        case 3:
            // If list is already sorted, do not need to sort again
            if (isSorted == true) {
                cout << "Please import list again before sorting" << endl;
                continue;
            }
            // Initialize a timer variable before sorting bids
            ticks = clock();

            // Complete the method call to selectionSort the bids
            selectionSort(bids);

            cout << bids.size() << " bids sorted" << endl;

            // Calculate elapsed time and display result
            ticks = clock() - ticks; // current clock ticks minus starting clock ticks
            cout << "time: " << ticks << " clock ticks" << endl;
            cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;

            select_ticks = ticks;  // stores performance of this sort
            isSorted = true;  // marks vector as sorted
            break;

        // TODO (2b): Invoke the quick sort and report timing results
        case 4:
            // If list is already sorted, do not need to sort again
            if (isSorted == true) {
                cout << "Please import list again before sorting" << endl;
                continue;
            }
            // Initialize a timer variable before sorting bids
            ticks = clock();

            // Complete the method call to quickSort the bids
            quickSort(bids, 0, bids.size() - 1);

            cout << bids.size() << " bids sorted" << endl;

            // Calculate elapsed time and display result
            ticks = clock() - ticks; // current clock ticks minus starting clock ticks
            cout << "time: " << ticks << " clock ticks" << endl;
            cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;

            quick_ticks = ticks;  // stores performance of this sort
            isSorted = true;  // marks vector as sorted

            break;

        // Add case to display the perfomance difference between sort algorithms
        case 5:
            // Check to see if data has been collected for both sort functions
            if (quick_ticks == 0 || select_ticks==0) {
                cout << "Perform at least one Quick Sort and one Select Sort" << endl;
                continue;
            }
            // Outputs perfomance in seconds
            cout << "SelectSort time: " << select_ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;
            cout << "QuickSort time: " << quick_ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;
            cout << "Performance difference between algorithms is: " << (select_ticks - quick_ticks) * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;


            break;
        default:

            if (choice != 9) {
                cout << "Selection not recognized. Please try again." << endl;
            }
        }
    }

    cout << "Good bye." << endl;

    return 0;
}
