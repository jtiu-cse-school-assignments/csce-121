//
//  Product.h
//  Homework8
//
//  Created by Julian Tiu on 3/25/16.
//  Copyright © 2016 Julian Tiu. All rights reserved.
//

#pragma once
#include <stdexcept>
#include <iostream>
#include <string>
#include <ostream>

class Product {
    
private:
    double totalCost;
    
    int days;
    int productNum = 0;
    int numSold;
    int inventory = 0;
    
    std::string description;
    
    
public:
    Product();
    Product(int productNum, std::string productName);
    
    void setDescription(std::string description);
    void setDefaultReturnPeriod(int days = 90);
    
    std::string getDescription() const;
    
    virtual int getReturnPeriod() const;
    int getNumberSold() const;
    int getProductNum() const;
    int getInventoryCount() const;
    
    double getTotalCost() const;
    virtual double getPrice() const;
    
    void addShipment(int quantity, double cost);
    void processOrder(int quantity);
    
    enum Category {
        Electronics,
        Clothing,
        Household
    };
    
    virtual Category getType() const = 0;
    virtual std::string getInfo() const = 0;
    
protected:
    std::string productName;
};

std::ostream& operator<<(std::ostream& os, Product *p);

