//
//  Homework2.cpp
//  Homework2
//  Quadratic formula
//
//  Created by Julian Tiu on 2/6/16.
//  Copyright © 2016 Julian Tiu. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    
    /*
     * Coefficient variables are doubles
     * just incase the a, b, and c input
     * values are decimals.
     */
    double aCo = 0.0;
    double bCo = 0.0;
    double cCo = 0.0;
    double disc = 0.0;
    double x1 = 0.0;
    double x2 = 0.0;
    double x1a = 0.0;
    double x2a = 0.0;
    
    // Prompt user to enter a, b, and c coefficients
    cin >> aCo;
    cin >> bCo;
    cin >> cCo;
    
    
    // Calculations
    if (aCo == 0 && bCo > 0) {
        x1 = (-cCo) / bCo;
        
        // Output when the a value is equal to 0
        cout << bCo << "x + " << cCo << " = 0" << endl;
        cout << "x = " << x1;
        
    }
    else if (aCo > 0 || aCo < 0) {
        disc = sqrt( (pow(bCo, 2)) - (4 * aCo * cCo) );
        
        if (disc >= 0) {
            x1 = (-bCo - disc) / (2 * aCo);
            x2 = (-bCo + disc) / (2 * aCo);
            
            // Output when the discriminant is positive
            cout << aCo << "x^2 + " << bCo << "x + " << cCo << " = 0" << endl;
            cout << "x = " << x1 << endl;
            cout << "x = " << x2;
        }
        else {
            disc = sqrt( (-1) * ((pow(bCo, 2)) - (4 * aCo * cCo)) );
            x1 = (-bCo) / (2 * aCo);
            x2 = (-bCo) / (2 * aCo);
            x1a = (disc) / (2 * aCo);
            x2a = (disc) / (2 * aCo);
            
            // Output when the discriminant is negative (imaginary numbers (i) )
            cout << aCo << "x^2 + " << bCo << "x + " << cCo << " = 0" << endl;
            cout << "x = " << x1 << " - " << x1a << "i" << endl;
            cout << "x = " << x2 << " + " << x2a << "i";
            
        }
    }
    else {
        cout << "Unable to determine root(s).";
    }
    
    return 0;
}