/*
# Full name : Zuleyka Urieta
# Student ID : 2431835
# Chapman email : urieta@chapman.edu
# CPSC 350 - Data Structures & Algorithms, Section 03
# Programming Assignment #4
*/

#include "DNASeq.h"
#include "PalindromeFinder.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    PalindromeFinder finder; // an instance of the PF class

    const char* inputFileName = "input.txt"; // provide input file name

    ifstream inputFile(inputFileName); // create an input file stream.

    // * error handeling if file can't be oppned *
    if (!inputFile.is_open()) {
        cerr << "Error: Cannot open input file." << endl;
        return 1;
    }

    cout << endl;
    string dnaString;
    while (getline(inputFile, dnaString)) {
        if (dnaString == "END") {
            break; // exit the loop when "END" is encountered
        }

        cout << dnaString; // print the DNA string to the console
        finder.checkIfPalindrome(dnaString); // call the checkIfPalindrome method from PF
        cout << endl;
    }

    inputFile.close(); // close the file

    return 0; // exit 
}