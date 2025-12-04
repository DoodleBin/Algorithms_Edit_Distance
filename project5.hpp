/*
 * CSC-301
 * project5.hpp
 * Fall 2025
 *
 * Partner 1:
 * Partner 2:
 * Date:
 */

#ifndef PROJECT5_HPP_
#define PROJECT5_HPP_

#include <iostream>
#include <vector>
#include <algorithm>
#include "Edit.hpp"

/*
 * ED - solves the given ED problem using DP or Memoization.
 */
std::vector<int> ED(std::string &src, std::string &dest, bool useASM, 
                    bool useDP);

/*
 * ED_DP - create and fill the table iteratively using dynamic programming.
 */
std::vector<int> ED_DP(std::string &src, std::string &dest, bool useASM);

/*
 * ED_Mem - create and fill the table recursively using memoization.
 */
std::vector<int> ED_Mem(std::string &src, std::string &dest, bool useASM);

/*
 * ED_Mem_helper - recursive helper function for memoization.
 *                 Note: numCols input for ease of indexing.
 */
int ED_Mem_helper(std::string &src, std::string &dest, bool useASM,
                  int numCols, int i, int j, std::vector<int> &table);

/*
 * getNumEdits - given a filled table, return the min number of edits.
 */
int getNumEdits(std::string &src, std::string &dest, std::vector<int> &table);

/*
 * getEdits - reconstruct the optimal edits given a filled table.
 */
std::vector<Edit> getEdits(std::string &src, std::string &dest, 
                           std::vector<int> &table);

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
std::string printTable(std::string &src, std::string &dest, 
                       std::vector<int> &table);

#endif  // PROJECT5_HPP_