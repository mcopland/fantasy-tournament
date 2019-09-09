/*******************************************************************************
** Program: fantasyTournament
** File:    Menu.cpp
** -----------------------------------------------------------------------------
** This is the Menu class function implementation file. The Menu is modular,
** allowing multiple options to be added from the main file.
*******************************************************************************/

#include "Menu.hpp"

/*
** Default Menu constructor. Options are added in main.
*/
Menu::Menu() {}

/*
** Returns size of the menu.
*/
int Menu::getMenuSize() {
    return menuOptions.size();
}

/*
** Add options to the created Menu.
**
** @param string  A string that contains the text following the menu choice number.
*/
void Menu::addOption(std::string prompt) {
    menuOptions.push_back(prompt);
}

/*
** Prints the Menu.
*/
void Menu::printMenu() {
    for (unsigned int i = 0; i < menuOptions.size(); ++i) {
        std::cout << i+1 << ". " << menuOptions[i] << std::endl;
    }
}