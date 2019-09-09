/*******************************************************************************
** Program: fantasyTournament
** File:    Game.hpp
** -----------------------------------------------------------------------------
** This is the Game class specification (header) file. The Game class represents
** a battle between two user-selected Creature objects.
*******************************************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include "inputValidation.hpp"
#include "Game.hpp"
#include "Menu.hpp"

// creatures
#include "Barbarian.hpp"    
#include "BlueMen.hpp"      
#include "Medusa.hpp"
#include "HarryPotter.hpp"
#include "Vampire.hpp"

#include <iostream>

class Game {
private:
    Creature *player1 = nullptr;
    Creature *player2 = nullptr;

public:
    Game();
    ~Game();

    int fight(Creature *player1, Creature *player2);
    int creatureMenu();
};

#endif