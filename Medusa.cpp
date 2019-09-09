/*******************************************************************************
** Program: fantasyTournament
** File:    Medusa.cpp
** -----------------------------------------------------------------------------
** This is the Medusa class function implementation file. This class inherits
** from the Creature class. If a Medusa rolls a 12 when attacking then the
** target instantly gets turned into stone and Medusa wins.
*******************************************************************************/

#include "Medusa.hpp"

/*
** Default constructor and destructor.
*/
Medusa::Medusa() {
    name = "Medusa";
    setArmor(3);
    setStrength(8);

    // dice
    setDieSides(6);
    setNumAttackDie(2);
    setNumDefendDie(1);
}

Medusa::~Medusa() {}

/*
** Calculates attack damage for each dice roll.
*/
int Medusa::attackRoll() {
    int attackRoll = 0;

    for (int i = 0; i < getNumAttackDie(); ++i) {
        attackRoll += rand() % getDieSides() + 1;
        
        // Glare ability
        if (attackRoll == 12) {
            return 100;
        }
    }

    return attackRoll;
}

/*
** Returns Medusa's name.
*/
std::string Medusa::getName() {
    return name;
}