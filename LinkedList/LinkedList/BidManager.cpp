//============================================================================
// Name        : BidManager.cpp
// Author      : Joshua Wozny
// Version     : 1.0
// Copyright   : Copyright © 2023,  portions Copyright © 2017 SNHU COCE
// Description : Lab 3-3 Lists and Searching
//============================================================================

#include "CSVparser.h"
#include "BidManager.h"
#include "Helpers.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;

BidManager::BidManager() {


}

BidManager::~BidManager() {

}

/**
 * Prompt user for bid information
 *
 * @return Bid struct containing the bid info
 */
Bid BidManager::getBid() {
	Bid bid;

	cout << "Enter Id: ";
	cin.ignore();
	string _bidId;
	getline(cin, _bidId);
	bid.setBidId(_bidId);

	cout << "Enter title: ";
	string _title;
	getline(cin, _title);
	bid.setTitle(_title);

	cout << "Enter fund: ";
	string _fund;
	getline(cin, _fund);
	bid.setFund(_fund);

	cout << "Enter amount: ";
	string strAmount;
	getline(cin, strAmount);
	bid.setAmount(strToDouble(strAmount, '$'));

	return bid;
}

/**
 * Load a CSV file containing bids into a LinkedList
 *
 * @return a LinkedList containing all the bids read
 */
void BidManager::loadBids(std::string csvPath) {
	cout << "Loading CSV file " << csvPath << endl;

	// initialize the CSV Parser
	csv::Parser file = csv::Parser(csvPath);

	try {
		// loop to read rows of a CSV file
		for (int i = 0; i < file.rowCount(); i++) {

			// initialize a bid using data from current row (i)
			Bid bid;
			bid.setBidId(file[i][1]);
			bid.setTitle(file[i][0]);
			bid.setFund(file[i][8]);
			bid.setAmount(strToDouble(file[i][4], '$'));

			bid.display();

			// add this bid to the end
			bids.Append(bid);
		}
	}
	catch (csv::Error& e) {
		std::cerr << e.what() << std::endl;
	}
}

const LinkedList& BidManager::getBids() const {
	return bids;
}

void BidManager::setBids(const LinkedList& bids) {
	this->bids = bids;
}


