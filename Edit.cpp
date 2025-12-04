/*
 * CSC-301
 * Edit.cpp
 * Fall 2025
 * Eric A. Autry
 * 11/01/22
 */

#include "Edit.hpp"

using namespace std;

/*
 * Constructor for the Edit class.
 * 
 * Sets the label, src and dest letters, and location to the input values.
 */
Edit::Edit(string labelSet, char srcLetterSet, char destLetterSet, 
           int locationSet) {
    label = labelSet;
    srcLetter = srcLetterSet;
    destLetter = destLetterSet;
    location = locationSet;
}

/*
 * printEdit returns a string displaying the Edit.
 */
string Edit::printEdit() {
    stringstream toPrint;

    if (label == "match" and srcLetter==destLetter) {
        toPrint << "Match '" << srcLetter;
        toPrint << "' at index " << location << "." << endl;
    } else if (label == "ins") {
        toPrint << "Insert '" << destLetter;
        toPrint << "' at index " << location << "." << endl;
    } else if (label == "del") {
        toPrint << "Delete '" << srcLetter;
        toPrint << "' from index " << location << "." << endl;
    } else if (label == "sub") {
        toPrint << "Substitute '" << destLetter << "' for '" << srcLetter;
        toPrint << "' at index " << location << "." << endl;
    } else {
        toPrint << "INVALID EDIT:" << endl;
        toPrint << "\t" << "label: " << label;
        toPrint << ", srcLetter: " << srcLetter;
        toPrint << ", destLetter: " << destLetter;
        toPrint << ", location: " << location << "." << endl;
    }
    return toPrint.str();
}