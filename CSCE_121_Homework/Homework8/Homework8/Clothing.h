//
//  Clothing.h
//  Homework8
//
//  Created by Julian Tiu on 4/11/16.
//  Copyright © 2016 Julian Tiu. All rights reserved.
//

#pragma once
#include "Product.h"
#include <string>

class Clothing : public Product {
    
private:
    int size;
public:
    
    Clothing();
    Clothing(int productNum, std::string productName);
    
    std::string getInfo() const;
    
    double getPrice() const;
    
    int getReturnPeriod() const;
    int getSize() const;
    void setSize(int size);
    
    Product::Category getType() const;
};