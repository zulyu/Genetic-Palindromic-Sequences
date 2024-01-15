/*
# Full name : Zuleyka Urieta
# Student ID : 2431835
# Chapman email : urieta@chapman.edu
# CPSC 350 - Data Structures & Algorithms, Section 03
# Programming Assignment #4
*/

#include "PalindromeFinder.h"
#include "DNASeq.h"
#include <iostream>

using namespace std;

// ! CONSTRUCTOR 
// -->  called when an object of PF is created
PalindromeFinder::PalindromeFinder() {
}

// ! DESTRUCTOR 
// -->  called when an object of PF is deleted/out of scope
PalindromeFinder::~PalindromeFinder() {
}

// ! METHOD: checkIfPalindrome() 
// --> check if a DNA sequence is a palindrome & its substrings

// * check if the DNA sequence contains any characters that are not A, T, C, G *
void PalindromeFinder::checkIfPalindrome(const std::string& dnaString) {
    bool containsInvalidCharacter = false;
    for (char nucleotide : dnaString) {
        if (nucleotide != 'A' && nucleotide != 'T' && nucleotide != 'C' && nucleotide != 'G') {
            containsInvalidCharacter = true;
            break;
        }
    }

    if (containsInvalidCharacter) {
        cout << " - INVALID" << endl; // print message if invalid characters are found
        return;
    }

    DNASeq mySequence(dnaString.c_str()); // create a DNASeq object from the input DNA sequence

    std::string complement = mySequence.complement();
    std::string reversed = complement;
    
    // * reverse the complement string *
    for (int i = 0, j = reversed.length() - 1; i < j; ++i, --j) {
        std::swap(reversed[i], reversed[j]);
    }

    if (dnaString == reversed) { // if the original sequence is equal to the reversed complement = palindrome!
        cout << " - Genetic Palindrome" << endl;
    } else { // if not a palindrome display this message:
        cout << " - Not a Genetic Palindrome" << endl;
    }

    // * generate & check DNA sequence substrings *
    int sequenceLength = dnaString.length();
    for (int start = 0; start < sequenceLength; ++start) {
        for (int end = start + 6; end <= sequenceLength; ++end) {
            DNASeq subSeq = mySequence.substring(start, end);
        }
    }
}
