//
//  Electronics.h
//  Homework8
//
//  Created by Julian Tiu on 4/11/16.
//  Copyright © 2016 Julian Tiu. All rights reserved.
//

#pragma once
#include <string>
#include "Product.h"

class Electronics : public Product {

private:
    
public:
    
    Electronics();
    Electronics(int productNum, std::string productName);
    
    std::string getInfo() const;
    
    double getPrice() const;
    
    int getReturnPeriod() const;
    
    Product::Category getType() const;
};
