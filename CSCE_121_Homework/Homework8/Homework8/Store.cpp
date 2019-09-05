//
//  Store.cpp
//  Homework8
//
//  Created by Julian Tiu on 3/25/16.
//  Copyright © 2016 Julian Tiu. All rights reserved.
//

#include "Store.h"
#include <string>
using namespace std;

Store::Store() {
}

Store::Store(string name) : name(name) {
}

string Store::getStorename() const {
    return this->name;
}

void Store::setStorename(string name) {
    this->name = name;
}

void Store::addProduct(int productNum, string productName, Product::Category category) {
    if (category == Product::Household) {
        this->products.push_back(new Household(productNum, productName));
    }
    else if (category == Product::Electronics){
        this->products.push_back(new Electronics(productNum, productName));
    }
    else {
        this->products.push_back(new Clothing(productNum, productName));
    }
    
}

void Store::addCustomer(int customerID, string name) {
    this->customers.push_back(new Customer(name, customerID));
}

void Store::takeShipment(int productNum, int quantity, double cost) {
        getProduct(productNum).addShipment(quantity, cost);
}

void Store::makePurchase(int customerID, int productNum, int quantity) {
    getProduct(productNum).processOrder(quantity);
    getCustomer(customerID).processPurchase(( getProduct(productNum).getNumberSold() * getProduct(productNum).getPrice() ), &getProduct(productNum));
}

void Store::takePayment(int customerID, double amount) {
        getCustomer(customerID).processPayment(amount);
}

void Store::listProducts() {
    for(int i = 0; i < products.size(); i++) {
        cout << this->products.at(i);
    }
}

void Store::listCustomers() {
    for(int i = 0; i < customers.size(); i++) {
        cout << this->customers.at(i);
    }
}


Product& Store::getProduct(int productNum) {
    for(int i = 0; i < this->products.size(); i++) {
        if (this->products.at(i)->getProductNum() == productNum) {
            return *products.at(i);
        }
    }
    throw runtime_error("The product aint in here, bruh");
    
}

Customer& Store::getCustomer(int customerID) {
    for(int i = 0; i < this->customers.size(); i++) {
        if (this->customers.at(i)->getID() == customerID) {
            return *customers.at(i);
        }
    }
    throw runtime_error("The product aint in here, bruh");
}








