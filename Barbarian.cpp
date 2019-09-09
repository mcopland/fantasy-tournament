/*******************************************************************************
** Program: fantasyTournament
** File:    Barbarian.cpp
** -----------------------------------------------------------------------------
** This is the Barbarian class function implementation file. This class
** inherits from the Creature class. Attack and defense dice are rolled with
** random values.
*******************************************************************************/

#include "Barbarian.hpp"

/*
** Default constructor and destructor.
*/
Barbarian::Barbarian() {
    name = "Barbarian";
    setArmor(0);
    setStrength(12);

    // dice
    setDieSides(6);
    setNumAttackDie(2);
    setNumDefendDie(2);
}

Barbarian::~Barbarian() {}

/*
** Returns Barbarian's name.
*/
std::string Barbarian::getName() {
    return name;
}