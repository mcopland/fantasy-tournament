/*******************************************************************************
** Program: fantasyTournament
** File:    main.cpp
** -----------------------------------------------------------------------------
** This is the fantasyTournament main file. A Menu is created, then the program
** is looped until the user decides to quit. This program simulates a tournament
** between two players with up to ten Creatures selected by the user. The game
** is played by using Die objects to generate random attack and defense values.
*******************************************************************************/

#include "inputValidation.hpp"
#include "Menu.hpp"
#include "Tournament.hpp"

#include <iostream>
#include <cstdlib>      // srand()
#include <ctime>        // time()

int main() {
    using std::cout;
    using std::endl;

    // set random seed
    srand(static_cast<unsigned>(std::time(0)));

    bool programExit = false;
    
    // create a menu and add options
    Menu combatMenu;
    combatMenu.addOption("Play Fantasy Combat Tournament");
    combatMenu.addOption("Exit program");

    // tournament variables
    Tournament fantasyGame;
    
    // loop program until the user terminates
    while (!programExit) {
        cout << "\n+" << std::string(50, '-') << "+" << endl;
        combatMenu.printMenu();
        cout << "+" << std::string(50, '-') << "+\n" << endl;
        
        int userMenuChoice;
        cout << "Enter your selection: ";
        userMenuChoice = getValidInt(1, combatMenu.getMenuSize());
        cout << endl;

        // start processes based on user choice
        switch (userMenuChoice) {
        case 1:         // starts game
            fantasyGame.runTournament();
            break;
        case 2:         // exits program
            programExit = true;
            break;
        default:
            break;
        }
    }

    return 0;
}