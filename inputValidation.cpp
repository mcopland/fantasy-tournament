/*******************************************************************************
** Program: fantasyTournament
** File:    inputValidation.cpp
** -----------------------------------------------------------------------------
** This is the inputValidation class function implementation file. There are
** functions to validate yes or no questions, ints, floats, and strings for use
** throughout the program.
*******************************************************************************/

#include "inputValidation.hpp"

/*
** Function used to validate a bool Yes or No value entered by user.
**
** @param string  Given prompt for different validations.
*/
bool getYesNo(std::string prompt) {
    using std::cin;
    using std::cout;
    
    bool yesOrNo,
         isValid = false;
    char input;

    cout << prompt;

    // input validation
    while (!isValid) {
        cin.get(input);

        if (input == 'y' || input == 'Y') {
            yesOrNo = true;
            isValid = true;
        }
        else if (input == 'n' || input == 'N'){
            yesOrNo = false;
            isValid = true;
        }
        else {
            cout << "Enter either Y or N: ";
            cin.clear();
        }

        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }

    return yesOrNo;
}

/*
** Function used to validate float values entered by user.
**
** @param string  Given prompt for different validations.
*/
float getValidFloat(std::string prompt) {
    using std::cin;
    using std::cout;
    
    float userFloat;
    cout << prompt;
    cin >> userFloat;

    // input validation
    while (cin.fail()) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        cout << "Enter a valid float value.\n";
        cout << prompt;
        cin >> userFloat;
    }

    cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

    return userFloat;
}

/*
** Function used to validate int values entered by user.
**
** @param string  Given prompt for different validations.
** @param int     Minimum value allowed.
** @param int     Maximum value allowed.
*/
int getValidInt(int min, int max) {
    using std::cin;
    using std::cout;
    
    int userInt;
    
    cin >> userInt;

    // input validation
    while (cin.fail() || userInt < min || userInt > max) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            cout << "Enter a value between " << min << " and "
                 << max << ": ";
            cin >> userInt;
        }

    cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

    return userInt;
}

/*
** Function used to validate a string entered by user.
**
** @param string  Given prompt for different validations.
*/
std::string getValidString(std::string prompt) {
    using std::cin;
    using std::cout;
    
    std::string userString;
    cout << prompt;
    cin >> userString;

    // input validation
    while (cin.fail()) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        cout << "Enter a valid string." << std::endl;
        cout << prompt;
        cin >> userString;
    }

    cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

    return userString;
}