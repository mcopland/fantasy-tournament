/*******************************************************************************
** Program: fantasyTournament
** File:    Menu.hpp
** -----------------------------------------------------------------------------
** This is the Menu class specification (header) file. The Menu is modular,
** allowing multiple options to be added from the main file.
*******************************************************************************/

#ifndef MENU_HPP
#define MENU_HPP

#include "inputValidation.hpp"

#include <iostream>
#include <string>
#include <vector>

class Menu {
    private:
        std::vector<std::string> menuOptions;
    public:
        Menu();
        int getMenuSize();
        void addOption(std::string prompt),
             printMenu();
};

#endif