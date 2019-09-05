//
//  Header.h
//  Homework8
//
//  Created by Julian Tiu on 4/11/16.
//  Copyright © 2016 Julian Tiu. All rights reserved.
//

#pragma once
#include "Product.h"
#include <string>

class Household : public Product {
    
private:
    
public:
    
    Household();
    Household(int productNum, std::string productName);
    
    std::string getInfo() const;
    
    Product::Category getType() const;
    
};
