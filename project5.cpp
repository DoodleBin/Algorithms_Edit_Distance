/*
 * CSC-301
 * project5.cpp
 * Fall 2025
 *
 * Partner 1:
 * Partner 2:
 * Date:
 */

#include "project5.hpp"

using namespace std;

/*
 * ED - solves the given ED problem using DP or Memoization.
 */
vector<int> ED(string &src, string &dest, bool useASM, bool useDP) {
    vector<int> table;
    if (useDP) {
        table = ED_DP(src, dest, useASM);
    } else {
        table = ED_Mem(src, dest, useASM);
    }
    return table;
}

/*
 * ED_DP - create and fill the table iteratively using dynamic programming.
 */
vector<int> ED_DP(string &src, string &dest, bool useASM) {
    // Get string lengths for ease of use.
    int n = src.length(); // Number of rows (-1).
    int m = dest.length(); // Number of cols (-1).
    int numCols = m+1;

    // Setup the table, size (n+1)x(m+1), filled with -1s.
    vector<int> table( (n+1)*(m+1), -1 );

    // Return the completed table.
    return table;
}

/*
 * ED_Mem - create and fill the table recursively using memoization.
 */
vector<int> ED_Mem(string &src, string &dest, bool useASM) {
    // Get string lengths for ease of use.
    int n = src.length(); // Number of rows (-1).
    int m = dest.length(); // Number of cols (-1).
    int numCols = m+1;

    // Setup the table, size (n+1)x(m+1), filled with -1s.
    vector<int> table( (n+1)*(m+1), -1 );

    // Return the completed table.
    return table;
}

/*
 * ED_Mem_helper - recursive helper function for memoization.
 *                 Note: numCols input for ease of indexing.
 */
int ED_Mem_helper(string &src, string &dest, bool useASM, int numCols,
                  int i, int j, vector<int> &table) {
    return -1;
}

/*
 * getNumEdits - given a filled table, return the min number of edits.
 */
int getNumEdits(string &src, string &dest, vector<int> &table) {
    int numEdits;
    return numEdits;
}

/*
 * getEdits - reconstruct the optimal edits given a filled table.
 */
vector<Edit> getEdits(string &src, string &dest, vector<int> &table) {
    vector<Edit> edits;
    return edits;
}

/*
 * printTable: prints the table so it looks nice.
 *
 * INPUTS
 * string src: the source string for ED (or ASM).
 * string dest: the destination string for ED (or ASM).
 * vector<int> &table: the table itself.
 *
 * OUTPUTS
 * string tableString.str(): the pretty string.
 */
string printTable(string &src, string &dest, vector<int> &table) {
    // Create the stringstream for the table.
    stringstream tableString;

    // Shift the first row for the dest letters and write the letters.
    // tableString << setw(labelWidth) << fixed;
    tableString << " " << " " << " " << " ";
    for (int j=0; j<dest.length(); j++) {
        // tableString << setprecision(prec) << setw(numWidth) << fixed;
        tableString << dest[j] << " ";
    }
    tableString << endl;

    // Write each line of the table, with the proper src letter at front.
    int entry;
    for (int i=0; i<src.length()+1; i++) {
        // tableString << setw(labelWidth) << fixed;
        if (i > 0) {
            tableString << src[i-1] << " ";
        } else {
            tableString << " " << " ";
        }
        for (int j=0; j<dest.length()+1; j++) {
            // tableString << setprecision(prec) << setw(numWidth) << fixed;
            entry = table[i*(dest.length()+1) + j];
            if (entry > -1) {
                tableString << entry << " "; // filled
            } else {
                tableString << "X" << " "; // unfilled
            }
        }
        tableString << endl;
    }
    tableString << endl;

    return tableString.str();
}