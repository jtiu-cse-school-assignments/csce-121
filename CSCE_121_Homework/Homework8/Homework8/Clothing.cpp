//
//  Clothing.cpp
//  Homework8
//
//  Created by Julian Tiu on 4/11/16.
//  Copyright © 2016 Julian Tiu. All rights reserved.
//

#include <stdio.h>
#include "Clothing.h"
using namespace std;

Clothing::Clothing() {}
Clothing::Clothing(int productNum, string productName) : Product(productNum, productName) {}

double Clothing::getPrice() const {
    double price = 0.00;
    if(getTotalCost() / (getInventoryCount() + getNumberSold()) > 100) {
        price = getTotalCost() / (getInventoryCount() + getNumberSold()) * 1.35;
    }
    else if (getTotalCost() / (getInventoryCount() + getNumberSold()) > 50) {
        price = getTotalCost() / (getInventoryCount() + getNumberSold()) * 1.4;
    }
    else if(getTotalCost() / (getInventoryCount() + getNumberSold()) > 25) {
        price = getTotalCost() / (getInventoryCount() + getNumberSold()) * 1.45;
    }
    else {
        price = getTotalCost() / (getInventoryCount() + getNumberSold()) * 1.50;
    }
    
    return price;
}

int Clothing::getReturnPeriod() const {
    return 60;
}

int Clothing::getSize() const {
    return this->size;
}

void Clothing::setSize(int size) {
    this->size = size;
}

string Clothing::getInfo() const {
    string info = "";
    info = getDescription();
    return info;

}

Product::Category Clothing::getType() const {
    return Product::Clothing;
}
