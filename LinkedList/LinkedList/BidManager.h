//============================================================================
// Name        : BidManager.h
// Author      : Joshua Wozny
// Version     : 1.0
// Copyright   : Copyright © 2023,  portions Copyright © 2017 SNHU COCE
// Description : Lab 3-3 Lists and Searching
//============================================================================

#ifndef BIDMANAGER_H_
#define BIDMANAGER_H_

#include "Bid.h"
#include "LinkedList.h"

class BidManager {
public:
	BidManager();
	virtual ~BidManager();

	Bid getBid();
	void loadBids(std::string csvPath);
	const LinkedList& getBids() const;
	void setBids(const LinkedList& bids);

private:
	LinkedList bids;
};

#endif /* BIDMANAGER_H_ */
