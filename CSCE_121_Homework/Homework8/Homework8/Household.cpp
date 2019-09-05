//
//  Household.cpp
//  Homework8
//
//  Created by Julian Tiu on 4/11/16.
//  Copyright © 2016 Julian Tiu. All rights reserved.
//

#include "Household.h"
#include <string>
using namespace std;

Household::Household() {}
Household::Household(int productNum, string productName) : Product(productNum, productName) {}

string Household::getInfo() const {
    string info = "";
    info = getDescription();
    return info;
}

Product::Category Household::getType() const {
    return Product::Household;
}