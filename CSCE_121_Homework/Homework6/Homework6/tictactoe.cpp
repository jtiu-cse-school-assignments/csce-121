//
//  main.cpp
//  Homework6
//
//  Created by Julian Tiu on 3/2/16.
//  Copyright © 2016 Julian Tiu. All rights reserved.
//

#include <cmath>
#include <vector>
#include <iostream>
using namespace std;


//**************************** Prints the game board
void printBoard(const vector<vector<char>> &board) {
    int i = 0;
    int j = 0;
    
    for (i = 0; i < board.size(); i++) {
        for (j = 0; j < board.size(); j++) {
            cout << board.at(i).at(j) << ' ';
        }
        
        cout << endl;
    }
    
    return;
}


//************************ Checks to see if location input is valid location
bool locationInRange(const vector<vector<char> > &board, int row, int col) {
    
    bool checkLoc = false;
    
    if(row > 3 || row < 1 || col > 3 || col < 1) {
        
        cout << "Invalid location. Numbers must be between 1 and 3." << endl;
    }
    else {
        
        checkLoc = true;
    }
    
    return checkLoc;
}

//************************* Checks to see if if the loction input is taken
bool locationTaken(const vector<vector<char> > &board, int row, int col) {
    bool checkLoc = false;
    bool locChecker = false;
    
    locChecker = locationInRange(board, row, col);
    
    if(locChecker == true) {
        if (board.at(row - 1).at(col - 1) != '_') {
            cout << "Location already taken." << endl;
            
            checkLoc = false;
        }
        else {
            checkLoc = true;
        }
    }
    
    return checkLoc;
}

//*************************************************** Prompts the user for location
void getLocation(const vector<vector<char> > &board, int &row, int &col, char currLetter) {
    bool locChecker = false;
    
    if (currLetter == 'X') {
        
        do {
            cout << "Enter location for X. ";
            cin >> row;
            cin >> col;

            locChecker = locationTaken(board, row, col);
            
        } while (locChecker == false);
    }
    else {
        
        do {
            cout << "Enter location for O. ";
            cin >> row;
            cin >> col;
            
            locChecker = locationTaken(board, row, col);
            
        } while (locChecker == false);
    }
    
}

//********************** Checks to see winning char
char checkWin(const vector<vector<char> > &board) {
    char winCheck = 'T';
    
    // Checking for X winner vertically or horizontally
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 1; j++) {
            if(board.at(i).at(j) == 'X' && board.at(i).at(j+1) == 'X' && board.at(i).at(j+2) == 'X') {
                winCheck = 'X';
            }
        }
    }
    for(int i = 0; i < 1; i++) {
        for(int j = 0; j < 3; j++) {
            if(board.at(i).at(j) == 'X' && board.at(i+1).at(j) == 'X' && board.at(i+2).at(j) == 'X') {
                winCheck = 'X';
            }
        }
    }
    
    // Checking for O winner vertically or horizontally
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 1; j++) {
            if(board.at(i).at(j) == 'O' && board.at(i).at(j+1) == 'O' && board.at(i).at(j+2) == 'O') {
                winCheck = 'O';
            }
        }
    }
    for(int i = 0; i < 1; i++) {
        for(int j = 0; j < 3; j++) {
            if(board.at(i).at(j) == 'O' && board.at(i+1).at(j) == 'O' && board.at(i+2).at(j) == 'O') {
                winCheck = 'O';
            }
        }
    }
    
    // Checking for X or O winner diagonally
    if (board.at(0).at(0) == 'X' && board.at(1).at(1) == 'X' && board.at(2).at(2) == 'X') {
        winCheck = 'X';
    }
    else if (board.at(2).at(0) == 'X' && board.at(1).at(1) == 'X' && board.at(0).at(2) == 'X') {
        winCheck = 'X';
    }
    if (board.at(0).at(0) == 'O' && board.at(1).at(1) == 'O' && board.at(2).at(2) == 'O') {
        winCheck = 'O';
    }
    else if (board.at(2).at(0) == 'O' && board.at(1).at(1) == 'O' && board.at(0).at(2) == 'O') {
        winCheck = 'O';
    }
    
    return winCheck;
}

//********************************** MAIN
int main() {
    
    bool xTurn = true;
    bool oTurn = false;
    int row = 0;
    int col = 0;
    int size = 3;
    int numTurns = 0;
    char winCheck = '_';
    vector<char> boardBoard(size, '_');
    vector<vector<char>> board(size, boardBoard);
    
    cout << "Welcome to Tic Tac Toe" << endl;
    printBoard(board);
    
    do {

        if (xTurn == true) {
            getLocation(board, row, col, 'X');
            board.at(row - 1).at(col - 1) = 'X';
            printBoard(board);
            xTurn = false;
            oTurn = true;
                
        }
        else {
            getLocation(board, row, col, 'O');
            board.at(row - 1).at(col - 1) = 'O';
            printBoard(board);
            xTurn = true;
            oTurn = false;
        }
        
        winCheck = checkWin(board);
        if (winCheck == 'X') break;
        if (winCheck == 'O') break;
        
        numTurns++;
        
    } while (numTurns <  9);
    
    if(numTurns == 9){
        cout << "Cat!!!";
    }
    else {
        cout << winCheck << " Won!!!";
    }
    
    return 0;
}
