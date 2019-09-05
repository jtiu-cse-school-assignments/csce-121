//
//  main.cpp
//  Homework7
//
//  Created by Julian Tiu on 3/8/16.
//  Copyright © 2016 Julian Tiu. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <string>
using namespace std;

// ************ Output for Not Enough Parameters
void printUsageInfo(const string &inputString) {
    
    cout << "Usage: " << inputString << " [-c] string1 string2 ..." << endl;
    
    return;
}

// *********************** Checks to see if word is palindrome
bool isPalindrome(const string &inputString, bool caseCheck) {
    
    bool isIt = true;
    bool palinChecker = true;
    int i = 0;
    int start = 0;
    long n = inputString.size() - 1;
    string wordCopy = inputString;

    if(wordCopy.size() > 1) {
        if(caseCheck == false) {
            // Checks for palindrome *WITHOUT* case sensitivity
            for(i = 0; i < wordCopy.length(); i++) {
                wordCopy.at(i) = tolower(wordCopy.at(i));
            }
            
            if(wordCopy.at(start) != wordCopy.at(n)) {
                isIt = false;
            }
            
            wordCopy.erase(0, 1);
            wordCopy.pop_back();
            
            if(isIt == true){
                palinChecker = isPalindrome(wordCopy, false);
                if(palinChecker == false){
                    isIt = false;
                }
            }
        }
        else {
            // Check for palindrome *WITH* case sensitivity
            if(wordCopy.at(start) != wordCopy.at(n)) {
                isIt = false;
            }
            
            wordCopy.erase(0, 1);
            wordCopy.pop_back();
            
            if(isIt == true){
                palinChecker = isPalindrome(wordCopy, true);
                if(palinChecker == false){
                    isIt = false;
                }
            }
        }
    }
    
    return isIt;
    
}

// *************************** MAIN
int main(int argc, char * argv[]) {
    
    bool caseCheck = true;
    bool palinChecker;
    int i = 0;

    if(argc == 1) {
        
        printUsageInfo(argv[0]);
    }
    else if (((string(argv[1]) == "-c" || string(argv[1]) == "-C")) && (argc == 2)) {
        
        printUsageInfo((argv[0]));
    }
    else if ((argc == 2) && ((string(argv[1]) != "-c" || string(argv[1]) != "-C")) ) {
        
        caseCheck = false;
        
        palinChecker = isPalindrome(string(argv[1]), caseCheck);
        
        if (palinChecker == true) {
            cout << argv[1] << " is a palindrome." << endl;
        }
        else {
            cout << argv[1] << " is not a palindrome." << endl;
        }
    }
    // flip the bottom two condition orders and ask why order matters in this case
    else if(argc >= 3 && ((string(argv[1]) == "-c" || string(argv[1]) == "-C"))) {
        caseCheck = true;
        
        for(i = 2; i < argc; i++){
            
            palinChecker = isPalindrome(string(argv[i]), caseCheck);
            
            if (palinChecker == true) {
                cout << argv[i] << " is a palindrome." << endl;
            }
            else {
                cout << argv[i] << " is not a palindrome." << endl;
            }
        }
    }
    else if(argc >= 3 && ((string(argv[1]) != "-c" || string(argv[1]) != "-C"))) {
        caseCheck = false;
        
        for(i = 1; i < argc; i++){
            
            palinChecker = isPalindrome(string(argv[i]), caseCheck);
            
            if (palinChecker == true) {
                cout << argv[i] << " is a palindrome." << endl;
            }
            else {
                cout << argv[i] << " is not a palindrome." << endl;
            }
        }
    }
    
    return 0;
}
