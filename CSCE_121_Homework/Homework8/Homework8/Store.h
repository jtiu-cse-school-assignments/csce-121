//
//  Store.h
//  Homework8
//
//  Created by Julian Tiu on 3/25/16.
//  Copyright © 2016 Julian Tiu. All rights reserved.
//

#pragma once
#include <stdexcept>
#include <iostream>
#include <string>
#include <vector>
#include "Product.h"
#include "Customer.h"
#include "Household.h"
#include "Electronics.h"
#include "Clothing.h"

class Store {
    
private:
    std::string name;
    std::vector<Product*> products;
    std::vector<Customer*> customers;
public:
    
    Store();
    Store(std::string name);
    
    std::string getStorename() const;
    
    void setStorename(std::string name);
    void addProduct(int productNum, std::string productName, Product::Category category);
    void addCustomer(int customerID, std::string name);
    void takeShipment(int productNum, int quantity, double cost);
    void makePurchase(int customerID, int productNum, int quantity);
    void takePayment(int customerID, double amount);
    void listProducts();
    void listCustomers();
    
    Product& getProduct(int productNum);
    Customer& getCustomer(int customerID);
    
};
