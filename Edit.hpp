/*
 * CSC-301
 * Edit.hpp
 * Fall 2025
 * Eric A. Autry
 * 11/01/22
 */

#ifndef EDIT_HPP_
#define EDIT_HPP_

#include <string>
#include <sstream>

/*
 * Edit Class for storing the edits in edit distance.
 */
class Edit {

    public:
        explicit Edit(std::string labelSet, char srcLetterSet, 
                      char destLetterSet, int locationSet);

        std::string label; // The label of edit: 'match', 'ins', 'sub', 'del'.
        char srcLetter;    // The letter in src to be removed or replaced.
        char destLetter;   // The letter from dest to be inserted or subbed.
        int location;      // The index of the edit in src.

        // printEdit returns a string displaying the Edit.
        std::string printEdit();
};

#endif  // EDIT_HPP_