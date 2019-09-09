/*******************************************************************************
** Program: fantasyTournament
** File:    HarryPotter.cpp
** -----------------------------------------------------------------------------
** This is the HarryPotter class function implementation file. This class
** inherits from the Creature class. Attack and defense dice are rolled with
** random values. Harry Potter has an extra life and strength is restored to 20
** if killed.
*******************************************************************************/

#include "HarryPotter.hpp"

#include <iostream>

/*
** Default constructor and destructor.
*/
HarryPotter::HarryPotter() {
    name = "Harry Potter";
    setArmor(0);
    setStrength(10);

    // dice
    setDieSides(6);
    setNumAttackDie(2);
    setNumDefendDie(2);
}

HarryPotter::~HarryPotter() {}

/*
** Calcualtes damage taken.
**
** @int  Initial damage from attacker.
*/
void HarryPotter::defendSelf(int damageIn) {
    if (damageIn > 0) {
        damageIn -= getArmor();
        setStrength(getStrength() - damageIn);
        
        // Hogwarts ability
        if (getStrength() < 1 && hogwarts) {
            setStrength(20);
            hogwarts = false;
        }
    }
}

/*
** Returns HarryPotter's name.
*/
std::string HarryPotter::getName() {
    return name;
}