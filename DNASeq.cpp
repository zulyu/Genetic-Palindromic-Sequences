/*
# Full name : Zuleyka Urieta
# Student ID : 2431835
# Chapman email : urieta@chapman.edu
# CPSC 350 - Data Structures & Algorithms, Section 03
# Programming Assignment #4
*/

#include "DNASeq.h"
#include <iostream>

using namespace std;

// ! CONSTRUCTOR 
// -->  called when an object of DNASeq is created
DNASeq::DNASeq() {
}

// ! DESTRUCTOR 
// -->  called when an object of DNASeq is deleted/out of scope
DNASeq::~DNASeq() {
}

// ! OVERLOADED CONSTRUCTOR 
// -->  creates a sequence from a character string
DNASeq::DNASeq(const std::string& sequence) {
    for (char nucleotide : sequence) {
        sequenceList.addBack(nucleotide);
    }
}

// ! METHOD: complement() 
// --> returns a DNA Sequence representing the complement
std::string DNASeq::complement() {
    DblList<char> complementList; // list to store the complement of the sequence
    
    // * iterate through each nucleotide in the sequence *
    for (int i = 0; i < sequenceList.size(); ++i) {
        char nucleotide = sequenceList.get(i);
        char complementNucleotide;

        switch (nucleotide) { // for character replacing 
            case 'A':
                complementNucleotide = 'T';
                break;
            case 'T':
                complementNucleotide = 'A';
                break;
            case 'C':
                complementNucleotide = 'G';
                break;
            case 'G':
                complementNucleotide = 'C';
                break;
            default:
                complementNucleotide = nucleotide; // if  nucleotide != A, T, C, or G, keep it the same 
                break;
        }
        complementList.addBack(complementNucleotide); // add the complemented nucleotide to the list
    }

    // * convert the complement list to a string *
    std::string complementSeq;
    for (int i = 0; i < complementList.size(); ++i) {
        complementSeq += complementList.get(i);
    }
    return complementSeq;
}

// ! METHOD: substring(int s, int e)
// --> returns a DNA Sequence based on the substring from position s (inclusive) to position e (exclusive)
DNASeq DNASeq::substring(int s, int e) {
    if (s < 0 || s >= e || sequenceList.size() == e || e > sequenceList.size()) { // check for invalid input
        return DNASeq();
    }

    DNASeq result; // DNASeq object to store the result
    std::string subsequence; // string to store the subsequence

    // * extract the nucleotides in the specified range [s, e) and add them to the result & subsequence *
    for (int i = s; i < e; ++i) {
        result.sequenceList.addBack(sequenceList.get(i));
        subsequence += sequenceList.get(i);
    }

    std::string complement = result.complement(); // find the complement of the subsequence
    
    // * generate the reverse of the complement *
    std::string reversed = complement;
    for (int i = 0, j = reversed.length() - 1; i < j; ++i, --j) {
        std::swap(reversed[i], reversed[j]);
    }

    if (subsequence == reversed) {
        cout << " Substring " << subsequence << " - Genetic Palindrome" << endl; // print message to terminal if substring = genetic palindrome
    }

    return result;
}

// ! METHOD: isGeneticPalindrome
// --> returns true if the sequence is a genetic palindrome and false otherwise
// --> referenced from YouTube video (more details in README.txt)
bool DNASeq::isGeneticPalindrome() {
    for (int i = 0; i < sequenceList.size() / 2; ++i) { // iterate through the first half of the sequence
        if (sequenceList.get(i) != sequenceList.get(sequenceList.size() - i - 1)) { // compare the nucleotide at position 'i' with the one at the mirrored position in the second half
            return false; // if a mismatch is found --> false (is not a genetic palindrome)
        }
    }
    return true;
}

// ! GETTER HELPER METHOD
// --> to access the sequence
std::string DNASeq::getSequence() {
    std::string seq;
    for (int i = 0; i < sequenceList.size(); ++i) { 
        seq += sequenceList.get(i); // append every element to seq
    }
    return seq;
}
