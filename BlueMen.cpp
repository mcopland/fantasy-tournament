/*******************************************************************************
** Program: fantasyTournament
** File:    BlueMen.cpp
** -----------------------------------------------------------------------------
** This is the BlueMen class function implementation file. This class inherits
** from the Creature class. Blue Men are actually a swarm of small individuals.
** For every 4 points of damage, they lose one defense die.
*******************************************************************************/

#include "BlueMen.hpp"

/*
** Default constructor and destructor.
*/
BlueMen::BlueMen() {
    name = "Blue Men";
    setArmor(3);
    setStrength(12);

    // dice
    setDieSides(10);
    setNumAttackDie(2);
    setNumDefendDie(3);
}

BlueMen::~BlueMen() {}

/*
** Calcualtes damage taken.
**
** @int  Initial damage from attacker.
*/
void BlueMen::defendSelf(int damageIn) {
    if (damageIn > 0) {
        damageIn -= getArmor();
        setStrength(getStrength() - damageIn);

        // Mob ability
        setNumDefendDie(getStrength() / 4);
    }
}

/*
** Returns name of BlueMen.
*/
std::string BlueMen::getName() {
    return name;
}