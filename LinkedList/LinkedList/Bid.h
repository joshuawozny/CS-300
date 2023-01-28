//============================================================================
// Name        : Bid.h
// Author      : Joshua Wozny
// Version     : 1.0
// Copyright   : Copyright © 2023,  portions Copyright © 2017 SNHU COCE
// Description : Lab 3-3 Lists and Searching
//============================================================================

#ifndef BID_H_
#define BID_H_

#include <iostream>

class Bid {
public:
	Bid();
	virtual ~Bid();
	double getAmount() const;
	void setAmount(double amount);
	const std::string& getBidId() const;
	void setBidId(const std::string& bidId);
	const std::string& getFund() const;
	void setFund(const std::string& fund);
	const std::string& getTitle() const;
	void setTitle(const std::string& title);

	void display();

private:
	std::string bidId; // unique identifier
	std::string title;
	std::string fund;
	double amount;
};

#endif /* BID_H_ */
