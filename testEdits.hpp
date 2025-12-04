/*
 * CSC-301
 * testEdits.hpp
 * Fall 2025
 * Eric A. Autry
 * 11/01/22
 */

#ifndef TESTEDITS_HPP_
#define TESTEDITS_HPP_

#include <cstring>
#include <random>
#include "project5.hpp"

/*
 * makeEdits: applies the given edits to the input string.
 *
 * INPUTS
 * string src: the source string to edit.
 * vector<Edit> edits: the edits to perform (formatted according to the prompt).
 * bool verbosity: set to true for extra printing if invalid edits given.
 *
 * OUTPUTS
 * string src: the edited src string.
 */
std::string makeEdits(std::string src, std::vector<Edit> edits, bool verbosity);

/*
 * testCase: runs a specific test.
 *
 * INPUTS
 * string label: the label for the test.
 * string src: the source string for ED.
 * string dest: the destination string for ED.
 * int correctNumEdits: the correct number of edits for this case.
 * bool useDP: set to true to use DP, false to use memoization.
 * bool verbosity: set to true to print test info and results for debugging.
 *
 * OUTPUTS
 * bool: true if test succeeded, false if test failed.
 */
bool testCase(std::string &label, std::string &src, std::string &dest, 
              int correctNumEdits, bool useDP, bool verbosity);

/*
 * getRandStrings: generates two random strings of length m using sig number
 *                 of chars in the alphabet.
 *
 * INPUTS
 * int m: the length of the strings to create.
 * int sig: the number of letters in the alphabet, 0 <= sig <= 26.
 *
 * OUTPUTS
 * pair<string, string>: the two random strings.
 */
std::pair<std::string, std::string> getRandStrings(int m, int sig);

/*
 * compareRandStrings: computes the average ED or ASM over a number of trials 
 *                     for strings of length m that were generated from an 
 *                     alphabet of size sig.
 *
 * INPUTS
 * int trials: the number of trials to average over.
 * int m: the size of the test strings to generate.
 * int sig: the number of letters in the alphabet, 0 <= sig <= 26.
 * bool useASM: a flag to switch between ED and ASM (true is ASM).
 * bool useDP: set to true to use DP, false to use memoization.
 *
 * OUTPUTS
 * double avg: the average ED or ASM.
 */
double compareRandStrings(int trials, int m, int sig, bool useASM, bool useDP);

/* main
 * 
 * Runs ED on all of the test strings and checks for correctness.
 *
 * Also runs ED and ASM for a variety of strings and alphabets and outputs
 * average distances, which can be used for verifying correct behavior.
 *
 * Run this function with the command:
 *     ./testEdits
 *
 * Note: you can turn on verbosity with a -v flag:
 *     ./testEdits -v
 *
 */
int main(int argc, char* argv[]);

#endif  // TESTEDITS_HPP_