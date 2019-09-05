//
//  main.cpp
//  Homework3
//  bulls and cows
//
//  Created by Julian Tiu on 2/10/16.
//  Copyright © 2016 Julian Tiu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    
    char userIn;     // 'y' or 'n'
    
    int rseed = 0; // seed number
    cout << "Enter seed: ";
    cin >> rseed;  // User's seed number input
    srand(rseed);  // pseudo random generator
    
    do {
        
        /*
        int rseed = 0; // seed number
        cout << "Enter seed: ";
        cin >> rseed;  // User's seed number input
        srand(rseed);  // pseudo random generator
        */
        char a = 'z';    // Used to check if counter == 0 is true;
        char b = 'z';    // Used to check if counter == 0 is true;
        char c = 'z';    // Used to check if counter == 0 is true;
        int userGuess;   // User's guess
        int val;         // Individual values of random number to be stored in vals
        int RANGE = 10;  // The range of the random number generator
        int counter = 0; // Counts # of instances digit appears in user guess
        int cows = 0;    // Counts # of cows
        int bulls = 0;   // Counts # of bulls
        int finalNum = 0;     // Final output answer
        int i = 0;
        int j = 0;
        
        vector<int> numsRef {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};  // *Vector reference
        vector<int> vals;                                    // *"Number" to guess (actually a vector)
        vector<int> userG;                                   // *User's guess turned to a vector
        vector<int> numsRef2 {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; // *Second vector reference
        vector<int> userG2;                                  // *The final vector for user guess used for the
        // rest if the program
        
        // Generating random number to guess **********************************
        for (j = 0; j < 5; j++) {
            
            val = rand() % RANGE;
            for (i = 0; i < numsRef.size(); i++) {
                
                if (numsRef.at(i) == val) {
                    vals.push_back(val);
                    numsRef.erase(numsRef.begin() + i);
                }
            }
        }
        if (vals.size() > 4) {
            vals.resize(4);
        }
        if (vals.size() < 4) {
            vals.push_back(0);
        }
        
        cout << "Number to guess: ";
        
        for (i = 0; i < vals.size(); i++) {
            cout << vals.at(i);
        }
        
        cout << endl;
        
        // User's turn ********************************************
        
        do {
            do{
                bulls = 0;
                cows = 0;
                a = 'z';
                b = 'z';
                c = 'z';
                userG.resize(0);
                cout << "Enter guess: ";
                cin >> userGuess;
                
                //Checking to see if user guess is a number
                while (cin.fail()) {
                    cout << "Input must be an integer." << endl;
                    cin.clear();
                    cin.ignore(256,'\n');
                    cout << "Enter guess: ";
                    cin >> userGuess;
                }
                
                // Checking to see if user guess has more than 4 digits
                while (userGuess > 9999) {
                    cout << "You can only enter four digits." << endl;
                    cin.clear();
                    cout << "Enter guess: ";
                    cin >> userGuess;
                }
                
                if (userGuess <= 999) {
                    
                    
                    userGuess += 1000;
                    
                    userG.push_back(userGuess / 1000);
                    userGuess = userGuess - (1000 * userG.at(0));
                    userG.push_back(userGuess/100);
                    userGuess = userGuess - (100 * userG.at(1));
                    userG.push_back(userGuess/10);
                    userGuess = userGuess - (10 * userG.at(2));
                    userG.push_back(userGuess);
                    userG.at(0) = 0;
                    
                }
                else {
                    userG.push_back(userGuess / 1000);
                    userGuess = userGuess - (1000 * userG.at(0));
                    userG.push_back(userGuess/100);
                    userGuess = userGuess - (100 * userG.at(1));
                    userG.push_back(userGuess/10);
                    userGuess = userGuess - (10 * userG.at(2));
                    userG.push_back(userGuess);
                }
                
                // Checking to see if user guess has the same digits
                for (i = 0; i < userG.size() - 3; i++) {
                    if (userG.at(i) == userG.at(i+1)) {
                        counter++;
                    }
                    else if (userG.at(i) == userG.at(i+2)) {
                        counter++;
                    }
                    else if (userG.at(i) == userG.at(i+3)) {
                        counter++;
                    }
                    else {
                        a = 'a';
                    }
                }
                for (i = 1; i < userG.size() - 2; i++) {
                    if (userG.at(i) == userG.at(i+1)) {
                        counter++;
                    }
                    else if (userG.at(i) == userG.at(i+2)) {
                        counter++;
                    }
                    else {
                        b = 'b';
                    }
                }
                for (i = 2; i < userG.size() - 1; i++) {
                    if (userG.at(i) == userG.at(i+1)) {
                        counter++;
                    }
                    else {
                        c = 'c';
                    }
                }
                if (a == 'a' && b == 'b' && c == 'c') {
                    counter = 0;
                }
                else if (counter > 0) {
                    cout << "Each number must be different." << endl;
                }
                
            } while (counter > 0);
            
            // Checks to see for bulls and cows
            for (int i = 0; i < vals.size(); i++) {
                for (int j = 0; j < userG.size(); j++) {
                    if (vals.at(i) == userG.at(j) && i != j) {
                        cows++;
                    }
                    if (vals.at(i) == userG.at(j) && i == j) {
                        bulls++;
                    }
                }
            }
            
            if (bulls != 4){
                cout << bulls << " bulls" << endl;
                cout << cows << " cows" << endl;
            }
            
        } while (bulls != 4);
        
        // Final game results output
        finalNum = (userG.at(3)) + (userG.at(2) * 10) + (userG.at(1) * 100) + (userG.at(0) * 1000);
        cout << "4 bulls - " << finalNum << " is Correct!" << endl;
        
        // Prompt user if they want to play again
        cout << "Enter 'y' to play again: ";
        cin >> userIn;
    
    } while (userIn == 'y');
    
    // Output when userIn is no longer 'y'
    cout << "Goodbye";
}

