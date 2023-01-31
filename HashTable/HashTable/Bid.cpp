//============================================================================
// Name        : Bid.cpp
// Author      : Joshua Wozny
// Version     : 1.1
// Copyright   : Copyright © 2023,  portions Copyright © 2017 SNHU COCE
// Description : Lab 3-3 Lists and Searching
//============================================================================

#include <string>
#include "Bid.h"

Bid::Bid() {
	amount = 0.0;
}

Bid::~Bid() {

}

double Bid::getAmount() const {
	return amount;
}

void Bid::setAmount(double amount) {
	this->amount = amount;
}

const std::string& Bid::getBidId() const {
	return bidId;
}

void Bid::setBidId(const std::string& bidId) {
	this->bidId = bidId;
}

const std::string& Bid::getFund() const {
	return fund;
}

void Bid::setFund(const std::string& fund) {
	this->fund = fund;
}

const std::string& Bid::getTitle() const {
	return title;
}

void Bid::setTitle(const std::string& title) {
	this->title = title;
}

void Bid::display() {
	std::cout << this->getBidId() << ": " << this->getTitle() << " | " << this->getAmount()
		<< " | " << this->getFund() << std::endl;
}
