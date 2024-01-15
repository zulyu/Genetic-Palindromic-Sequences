/*
# Full name : Zuleyka Urieta
# Student ID : 2431835
# Chapman email : urieta@chapman.edu
# CPSC 350 - Data Structures & Algorithms, Section 03
# Programming Assignment #4
*/

#ifndef PALINDROMEFINDER_H
#define PALINDROMEFINDER_H

#include <string>

class PalindromeFinder {
public:
// ! CONSTRUCTOR
    PalindromeFinder();
// ! DESTRUCTOR
    virtual ~PalindromeFinder();
// ! METHOD
    void checkIfPalindrome(const std::string& dnaString);
};

#endif // PALINDROMEFINDER_H
