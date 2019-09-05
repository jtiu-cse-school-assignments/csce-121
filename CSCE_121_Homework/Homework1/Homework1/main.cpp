//
//  main.cpp
//  Homework1
//
//  Created by Julian Tiu on 1/29/16.
//  Copyright © 2016 Julian Tiu. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    
    // Variables:
    string firstName = "";
    string lastName = "";
    int yearBorn = 0;
    int age = 0;
    int heightInches = 0;
    int heightInInches = 0;
    int heightInFeet = 0;
    double heightInCentimeters = 0.0;
    double averageAnualGrowth = 0.0;
    const double HEIGHT_AT_BIRTH = 51.0;
    const double INCHES_TO_CENTIMETERS = 2.54;
    const int CURRENT_YEAR  = 2015; // The assignment specification does not prompt the user for the
                                    // current real-time year. Therefore the current year is set to
                                    // 2015, and will not be changed.
    
    // Prompting Statements:
    cout << "Enter your first name:" << endl;
    cin >> firstName;
    cout << endl;

    cout << "Enter your last name:" << endl;
    cin >> lastName;
    cout << endl;
    
    cout << "Enter what year you were born (4 digit format):" << endl;
    cin >> yearBorn;
    cout << endl;
    
    cout << "Enter height (FEET 'space' INCHES 'enter'):" << endl;
    cin >> heightInFeet;
    cin >> heightInInches;
    cout << endl;
    
    //Calculations:
    heightInches = (heightInFeet * 12) + heightInInches;
    heightInCentimeters = heightInches * INCHES_TO_CENTIMETERS;
    age = CURRENT_YEAR - yearBorn;
    averageAnualGrowth = (heightInCentimeters - HEIGHT_AT_BIRTH) / age;
    
    // Final Output:
    cout << "Hello " << firstName << " " << lastName << ".";
    cout << " You were " << age << " years old in " << CURRENT_YEAR << ", and your height is " << heightInCentimeters << " cm. That means you grew an average of " << averageAnualGrowth << " cm. per year (assuming you were " << HEIGHT_AT_BIRTH << " cm. at birth)." << endl;
    cout << endl;
    
   return 0;
}
