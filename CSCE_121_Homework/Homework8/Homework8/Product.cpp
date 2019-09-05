//
//  Product.cpp
//  Homework8
//
//  Created by Julian Tiu on 3/25/16.
//  Copyright © 2016 Julian Tiu. All rights reserved.
//

#include <stdio.h>
#include <string>
#include "Product.h"
using namespace std;

Product::Product() {}
Product::Product(int productNum, string productName) {
    this->productNum = productNum;
    this->productName = productName;
}

void Product::setDescription(string description) {
    this->description = description;
}

string Product::getDescription() const {
    return this->description;
}

int Product::getInventoryCount() const {
    return this->inventory;
}

void Product::setDefaultReturnPeriod(int days){
    this->days = days;
}

int Product::getReturnPeriod() const {
    return this->days;
}

int Product::getNumberSold() const {
    return this->numSold;
}

int Product::getProductNum() const {
    return this->productNum;
}

double Product::getTotalCost() const {
    return this->totalCost;
}

void Product::addShipment(int quantity, double cost) {
    this->inventory += quantity;
    this->totalCost += cost;
}


void Product::processOrder(int quantity) {
    if(this->inventory < quantity ) {
        throw runtime_error("Not enough inventory");
    }
    else {
        this->inventory -= quantity;
        this->numSold += quantity;
    }
}

double Product::getPrice() const {
    double price = (( getTotalCost() ) / (( getInventoryCount() ) + ( getNumberSold() ))) * 1.15;
    return price;
}

ostream& operator<<(ostream& os, Product *p) {
    os << "Product Information: " << endl;
    os << "Product Number: " << p->getProductNum() << endl;
    os << "Product Description: " << p->getDescription();
    os << "Price: " << p->getPrice();
    os << "Number sold: " << p->getNumberSold() << endl;
    os << "Days until the final return day: " << p->getReturnPeriod();
    
    return os;
}







