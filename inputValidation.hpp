/*******************************************************************************
** Program: fantasyTournament
** File:    inputValidation.hpp
** -----------------------------------------------------------------------------
** This is the inputValidation class specification (header) file. There are
** functions to validate yes or no questions, ints, floats, and strings for use
** throughout the program.
*******************************************************************************/

#ifndef INPUTVALIDATION_HPP
#define INPUTVALIDATION_HPP

#include <ios>          // <streamsize>
#include <iostream>
#include <limits>       // numeric_limits
#include <string>

bool getYesNo(std::string);
float getValidFloat(std::string prompt);
int getValidInt(int min, int max);
std::string getValidString(std::string prompt);

#endif