//
//  Customer.cpp
//  Homework8
//
//  Created by Julian Tiu on 3/25/16.
//  Copyright © 2016 Julian Tiu. All rights reserved.
//

#include <stdio.h>
#include <string>
#include "Customer.h"
using namespace std;

int defaultNum = 0;

Customer::Customer(string name, int customerID, bool credit) : name(name), customerID(customerID), credit(credit) {
    
}

void Customer::setName(string name) {
    this->name = name;
}

string Customer::getName() const {
    return this->name;
}

int Customer::getID() const {
    return this->customerID;
}

void Customer::setCredit(bool hasCredit) {
    this->credit = hasCredit;
}

void Customer::processPayment(double amount) {
    this->balance += amount;
}

void Customer::processPurchase(double amount, const Product* p) {
    if (credit == true) {
        this->balance -= amount;
        this->productPurchased.push_back(p);
    }
    else if (credit == false) {
        if (this->balance > amount) {
            this->balance -= amount;
            this->productPurchased.push_back(p);

        }
        else {
            throw runtime_error("Not enough credits in balance");
        }
    }
    
    
}

bool Customer::getCredit() const {
    return this->credit;
}

double Customer::getBalance() const {
    return this->balance;
}


ostream& operator<<(ostream& os, Customer c) {
    os << "Customer Information: " << endl;
    os << "Name: " << c.getName() << endl;
    os << "ID Number: " << c.getID() << endl;
    os << "Credit Status: " << c.getCredit() << endl;
    os << "Balance: " << c.getBalance() << endl;
    
    return os;
}








