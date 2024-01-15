/*
# Full name : Zuleyka Urieta
# Student ID : 2431835
# Chapman email : urieta@chapman.edu
# CPSC 350 - Data Structures & Algorithms, Section 03
# Programming Assignment #4
*/

#ifndef DNASEQ_H
#define DNASEQ_H

#include "DblList.h"
#include <iostream>

class DNASeq {
public:
// ! CONSTRUCTOR
    DNASeq();
// ! DESTRUCTOR
    virtual ~DNASeq();
// ! OVERLOADED CONSTRUCTOR
    DNASeq(const std::string& sequence);
// ! METHODS
    std::string complement();
    DNASeq substring(int s, int e);
    bool isGeneticPalindrome();
    std::string getSequence();

private:
    DblList<char> sequenceList; // can only be accessed and modified by member functions of DNASeq
};

#endif // DNASEQ_H
