//
//  main.cpp
//  Homework4
//  Finding the mode
//
//  Created by Julian Tiu on 2/14/16.
//  Copyright © 2016 Julian Tiu. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    // get a seed value for the pseudo-random number generator (no user prompt)
    int rseed;
    cin >> rseed; // ********* IMPORTANT ********** IT WILL NOT PROMPT THE USER
    srand(rseed);
    
    // define constants for random values
    const int NUM_VALUES = 100;
    const int RANGE = 100;
    
    
    // populate a vector with random values
    vector<int> values;
    for (int i = 0; i < NUM_VALUES; i++) {
        int val = rand() % RANGE;
        values.push_back(val);
    }
     

    /*
    // iterate through vector and print values
    for (int i = 0; i < NUM_VALUES; i++) {
        cout << values.at(i) << endl;
    }
    */
    
    // Finding the mode
    cout << endl << endl;
    
    // Mode algorithm
    int counter = 0;
    int max = 0;
    vector<int> vec2;
    vector<int> vec3;
    vector<int> vec4;
    
    sort(values.begin(), values.end());
    vec2 = values;
    
    /*
    for (int i = 0; i < vec2.size(); i++) {
        cout << vec2.at(i) << " ";
    }
    */
    
    //cout << endl << endl;
    
    for (int i = 0; i < values.size(); i++) {
        for(int j = 0; j < vec2.size(); j++) {
            if (values.at(i) == vec2.at(j)) {
                counter += 1;
            }
        }
        vec3.push_back(counter);
        counter = 0;
    }
    
    /*
    for (int i = 0; i < vec3.size(); i++) {
        cout << vec3.at(i) << " ";
    }
     */
    
    for (int i = 0; i < vec3.size(); i++) {
        if (vec3.at(i) > max) {
            max = vec3.at(i);
        }
    }
    
    //cout << "Max is: " << max << endl;
    
    //appends vec4
    for (int i = 0; i < vec3.size(); i++) {
        if (vec3.at(i) == max) {
            vec4.push_back(vec2.at(i));
        }
    }
    
    vec4.push_back(0);
    
    //prints vec4 (Modes)
    for (int i = 0; i < vec4.size() - 1; i++) {
        if (vec4.at(i) != vec4.at(i + 1)) {
            cout << vec4.at(i) << " ";
        }
    }
    
    cout << endl << max << endl;
    
}

/*
************************** PROTOTYPE DONE IN C++ SHELL ***************************


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
 
int main() {
 
    vector<int> vec {1, 2, 1, 4, 5, 3, 4, 5, 4, 5};
    sort(vec.begin(), vec.end());
 
    for (int i = 0; i < vec.size(); i++) {
        cout << vec.at(i) << " ";
    }
 
    cout << endl << endl;
 
    // Mode algorithm
    int counter = 0;
    int max = 0;
    int val = 0;
    vector<int> vec2;
    vector<int> vec3;
    vector<int> vec4;

    vec2 = vec;
 
    for (int i = 0; i < vec2.size(); i++) {
        cout << vec2.at(i) << " ";
    }
 
    cout << endl << endl;
 
    for (int i = 0; i < vec.size(); i++) {
         for(int j = 0; j < vec2.size(); j++) {
             if (vec.at(i) == vec2.at(j)) {
                 counter += 1;
             }
         }
         vec3.push_back(counter);
         counter = 0;
    }
 
    for (int i = 0; i < vec3.size(); i++) {
        cout << vec3.at(i) << " ";
    }
 
    for (int i = 0; i < vec3.size(); i++) {
        if (vec3.at(i) > max) {
            max = vec3.at(i);
        }
    }
 
    cout << endl << endl << "Max is: " << max << endl << endl;
 
    //appends vec4
    for (int i = 0; i < vec3.size(); i++) {
        if (vec3.at(i) == max) {
            vec4.push_back(vec2.at(i));
        }
    }
 
    vec4.push_back(0);
 
    //prints vec4
    for (int i = 0; i < vec4.size() - 1; i++) {
        if (vec4.at(i) != vec4.at(i + 1)) {
            cout << vec4.at(i) << " ";
        }
    }
 
}
*/

