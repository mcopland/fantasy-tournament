/*******************************************************************************
** Program: fantasyTournament
** File:    Tournament.hpp
** -----------------------------------------------------------------------------
** This is the Tournament class specification (header) file. This class inherits
** from the Creature class. Blue Men are actually a swarm of small individuals.
** For every 4 points of damage, they lose one defense die.
*******************************************************************************/

#ifndef FANTASY_TOURNAMENT_HPP
#define FANTASY_TOURNAMENT_HPP

#include "Game.hpp"
#include "inputValidation.hpp"
#include "Menu.hpp"

// fighters
#include "Barbarian.hpp"    
#include "BlueMen.hpp"      
#include "HarryPotter.hpp"
#include "Medusa.hpp"
#include "Vampire.hpp"

#include <iostream>

class Tournament : public Game {
private:
    struct CreatureList {
        Creature *fighter;
        CreatureList *next;
        CreatureList(Creature *creatureIn, std::string nameIn = "",
            CreatureList *nextIn = nullptr) {

            fighter = creatureIn;
            fighter->setName(nameIn);
            next = nextIn;
        }
    };

    CreatureList *player1 = nullptr;
    CreatureList *player2 = nullptr;
    CreatureList *defeated = nullptr;

public:
    Tournament();
    ~Tournament();
    
    void runTournament();

    // movers
    void moveToBack(CreatureList * &player);
    void moveToDefeated(CreatureList * &player);

    // setters
    void setRoster(CreatureList * &player, int numCreatures);
    Creature *setCreature(int creatureIn);
};

#endif