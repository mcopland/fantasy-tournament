/*******************************************************************************
** Program: fantasyTournament
** File:    Vampire.cpp
** -----------------------------------------------------------------------------
** This is the Vampire class function implementation file. This class inherits
** from the Creature class. The Vampire rolls one 12-sided attack die and one
** 6-sided defense die. Vampires can charm an opponent into not attacking. For a
** given attack, there is a 50% chance that their opponent does not actually
** attack them.
*******************************************************************************/

#include "Vampire.hpp"

/*
** Default constructor and destructor.
*/
Vampire::Vampire() {
    name = "Vampire";
    setArmor(1);
    setStrength(18);

    // dice
    setDieSides(12);
    setNumAttackDie(1);
    setNumDefendDie(1);
}

Vampire::~Vampire() {}

/*
** Calculates damage taken.
*/
void Vampire::defendSelf(int damageIn) {
    if (damageIn > 0) {
        // Charm ability
        if (rand() % 2 == 0) {
            damageIn -= getArmor();
            setStrength(getStrength() - damageIn);
        }
    }
}

/*
** Return Vampire's name.
*/
std::string Vampire::getName() {
    return name;
}