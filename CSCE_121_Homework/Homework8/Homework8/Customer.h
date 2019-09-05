//
//  Customer.h
//  Homework8
//
//  Created by Julian Tiu on 3/25/16.
//  Copyright © 2016 Julian Tiu. All rights reserved.
//

#pragma once
#include <stdexcept>
#include <iostream>
#include <vector>
#include <string>
#include "Product.h"


class Customer {
    
private:
    
    std::string name;
    
    double balance;
    
    int customerID;
    
    bool credit;
    
    std::vector<const Product*> productPurchased;
    
public:
    
    Customer(std::string name, int customerID, bool credit = false);
    
    void setName(std::string name);
    void setCredit(bool hasCredit);
    void processPayment(double amount);
    void processPurchase(double amount, const Product* p);
    
    std::string getName() const;
    
    int getID() const;
    
    bool getCredit() const;
    
    double getBalance() const;
    
};

std::ostream& operator<<(std::ostream& os, Customer c);