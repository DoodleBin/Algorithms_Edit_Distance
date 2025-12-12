/*
 * CSC-301
 * project5.cpp
 * Fall 2025
 *
 * Partner 1: Alexa Hatcher
 * Partner 2: Natalie Nardone
 * Date: 12/11/25
 * Acknowledgements: Office hours, mentor session
 */

#include "project5.hpp"

using namespace std;

/*
 * ED - solves the given ED problem using DP or Memoization.
 */
vector<int> ED(string &src, string &dest, bool useASM, bool useDP)
{
    vector<int> table;
    if (useDP)
    {
        table = ED_DP(src, dest, useASM);
    }
    else
    {
        table = ED_Mem(src, dest, useASM);
    }
    return table;
}

/*
 * ED_DP - create and fill the table iteratively using dynamic programming.
 */
vector<int> ED_DP(string &src, string &dest, bool useASM)
{
    // Get string lengths for ease of use.
    int n = src.length();  // Number of rows (-1).
    int m = dest.length(); // Number of cols (-1).
    int numCols = m + 1;

    // Setup the table, size (n+1)x(m+1), filled with -1s.
    vector<int> table((n + 1) * (m + 1), -1);

    // Base case - Fill first column, cost of deletion
    for (int i = 0; i < n + 1; i++)
    {
        table[i * numCols + 0] = i;
    }

    // Base case - Fill first column, cost of insertion
    // If useASM, first row is all zeros.
    for (int j = 0; j < numCols; j++)
    {
        if(useASM){
            table[0 * numCols + j] = 0;
        } else {
            table[0 * numCols + j] = j;
        }
    }

    // Fill internal DP cells.
    for (int row = 1; row < n + 1; row++)
    {
        for (int col = 1; col < numCols; col++)
        {
            int curr = row * numCols + col;
            // Characters match → take diagonal value.
            if (src[row - 1] == dest[col - 1])
            {
                table[curr] = table[(row - 1) * numCols + col - 1];
            }
            else
            {
                // Compute delete, insert, substitute.
                int del = table[(row - 1) * numCols + col];
                int ins = table[row * numCols + col - 1];
                int sub = table[(row - 1) * numCols + col - 1];
                table[curr] = 1 + min({del, ins, sub});
            }
        }
    }

    // Return the completed table.
    return table;
}

/*
 * ED_Mem - create and fill the table recursively using memoization.
 */
vector<int> ED_Mem(string &src, string &dest, bool useASM)
{
    // Get string lengths for ease of use.
    int n = src.length();  // Number of rows (-1).
    int m = dest.length(); // Number of cols (-1).
    int numCols = m + 1;

    // Setup the table, size (n+1)x(m+1), filled with -1s.
    vector<int> table((n + 1) * (m + 1), -1);
    int i = n;
    int j = m;
    int minCost = ED_Mem_helper(src, dest, useASM, numCols, i, j, table);
    // Return the completed table.
    return table;
}

/*
 * ED_Mem_helper - recursive helper function for memoization.
 *                 Note: numCols input for ease of indexing.
 */
int ED_Mem_helper(string &src, string &dest, bool useASM, int numCols, int i, int j, vector<int> &table)
{
    int curr = i * numCols + j;

    // Only compute if value is not memoized.
    if (table[curr] == -1)
    {
        if (i == 0)
        {
            if(useASM)
            {
                // ASM overrides.
                table[0 * numCols + j] = 0;
            } 
            else 
            {
                // Insert j chars into empty src
                table[0 * numCols + j] = j;
            }
        } 
        else if (j==0)
        {
            // Delete i chars.
            table[curr] = i;
        } 
        else if (src[i - 1] == dest[j - 1])
        {
            // Characters match → no cost.
            table[curr] = ED_Mem_helper(src, dest, useASM, numCols, i - 1, j - 1, table);
        }
        else
        {
            // Recur on delete, insert, substitute.
            int del = ED_Mem_helper(src, dest, useASM, numCols, i - 1, j, table);
            int ins = ED_Mem_helper(src, dest, useASM, numCols, i, j - 1, table);
            int sub = ED_Mem_helper(src, dest, useASM, numCols, i - 1, j - 1, table);
            table[curr] = 1 + min({del, ins, sub});
        }
    }

    return table[curr];
}

/*
 * getNumEdits - given a filled table, return the min number of edits.
 */
int getNumEdits(string &src, string &dest, vector<int> &table)
{
    return table[table.size()-1];
}

/*
 * getEdits - reconstruct the optimal edits given a filled table.
 */
vector<Edit> getEdits(string &src, string &dest, vector<int> &table)
{
    vector<Edit> edits;
    int numCols = dest.length() + 1;

    int i = src.length();
    int j = dest.length();

    // Backtrack from bottom-right.
    while ((i != 0) && (j != 0))
    {
        if (src[i-1] == dest[j-1])
        {
            // Characters match → move diagonally.
            Edit firstEdit = Edit("match", src[i - 1], dest[j - 1], i-1);
            edits.push_back(firstEdit);
            i--;
            j--;
        }
        else
        {
            // Examine neighbors to determine optimal move.
            int left = table[i * numCols + j - 1];
            int up = table[(i - 1) * numCols + j];
            int diag = table[(i - 1) * numCols + j - 1];
            int minimum = min({left, up, diag});
            if (left == minimum)
            {
                // Best move: insertion.
                Edit newEdit = Edit("ins", src[i - 1], dest[j - 1], i-0);
                j--;
                edits.push_back(newEdit);
            }
            else if (up == minimum)
            {
                // Best move: deletion.
                Edit newEdit = Edit("del", src[i - 1], dest[j - 1], i-1);
                i--;
                edits.push_back(newEdit);
            }
            else
            {
                // Best move: substitution.
                Edit newEdit = Edit("sub", src[i - 1], dest[j - 1], i-1);
                i--;
                j--;
                edits.push_back(newEdit);
            }
        }
    }

    // Handle leftover characters.
    if (i == 0)
    { // add remaining letters of dest
        while (j > 0)
        {
            Edit firstEdit = Edit("ins", src[i - 1], dest[j - 1], i-0);
            edits.push_back(firstEdit);
            j--;
        }
    }
    else if (j == 0)
    { // delete preceding letters of src
        while (i > 0)
        {
            Edit firstEdit = Edit("del", src[i - 1], dest[j - 1], i-1);
            edits.push_back(firstEdit);
            i--;
        }
    }

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
string printTable(string &src, string &dest, vector<int> &table)
{
    // Create the stringstream for the table.
    stringstream tableString;

    // Shift the first row for the dest letters and write the letters.
    // tableString << setw(labelWidth) << fixed;
    tableString << " " << " " << " " << " ";
    for (int j = 0; j < dest.length(); j++)
    {
        // tableString << setprecision(prec) << setw(numWidth) << fixed;
        tableString << dest[j] << " ";
    }
    tableString << endl;

    // Write each line of the table, with the proper src letter at front.
    int entry;
    for (int i = 0; i < src.length() + 1; i++)
    {
        // tableString << setw(labelWidth) << fixed;
        if (i > 0)
        {
            tableString << src[i - 1] << " ";
        }
        else
        {
            tableString << " " << " ";
        }
        for (int j = 0; j < dest.length() + 1; j++)
        {
            // tableString << setprecision(prec) << setw(numWidth) << fixed;
            entry = table[i * (dest.length() + 1) + j];
            if (entry > -1)
            {
                tableString << entry << " "; // filled
            }
            else
            {
                tableString << "X" << " "; // unfilled
            }
        }
        tableString << endl;
    }
    tableString << endl;

    return tableString.str();
}