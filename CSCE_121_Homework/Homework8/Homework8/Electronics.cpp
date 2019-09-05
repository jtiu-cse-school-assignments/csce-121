//
//  Electronics.cpp
//  Homework8
//
//  Created by Julian Tiu on 4/11/16.
//  Copyright © 2016 Julian Tiu. All rights reserved.
//

#include "Electronics.h"
#include <string>
using namespace std;

Electronics::Electronics() {}
Electronics::Electronics(int productNum, string productName) : Product(productNum, productName) {}

string Electronics::getInfo() const {
    string info = "";
    info = getDescription();
    return info;
}

int Electronics::getReturnPeriod() const {
    return 30;
}

double Electronics::getPrice() const {
    double price = 0.00;
    if(getTotalCost() / (getInventoryCount() + getNumberSold()) > 1000) {
        price = getTotalCost() / (getInventoryCount() + getNumberSold()) * 1.05;
    }
    else if (getTotalCost() / (getInventoryCount() + getNumberSold()) > 100) {
        price = getTotalCost() / (getInventoryCount() + getNumberSold()) * 1.07;
    }
    else {
        price = getTotalCost() / (getInventoryCount() + getNumberSold()) * 1.1;
    }
    return price;
}

Product::Category Electronics::getType() const {
    return Product::Electronics;
}
