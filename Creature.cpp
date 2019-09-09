/*******************************************************************************
** Program: fantasyTournament
** File:    Creature.cpp
** -----------------------------------------------------------------------------
** This is the Creature class function implementation file. The Creature is an
** abstract class acting as a base for the five Creature derived classes.
*******************************************************************************/

#include "Creature.hpp"

/*
** Default constructor and destructor.
*/
Creature::Creature() {}
Creature::~Creature() {}

/*
** Returns health status of Creature.
*/
bool Creature::stillAlive() {
    return getStrength() > 0;
}

/*
** Returns value of attack for each die roll.
*/
int Creature::attackRoll() {
    int roll = 0;

    for (int i = 0; i < getNumAttackDie(); ++i) {
        roll += rand() % getDieSides() + 1;
    }

    return roll;
}

/*
** Calcualtes damage taken.
**
** @int  Initial damage from attacker.
*/
void Creature::defendSelf(int damageIn) {
    if (damageIn > 0) {
        damageIn -= getArmor();
        setStrength(getStrength() - damageIn);
    }
}

/*
** Returns value of defense for each die roll.
*/
int Creature::defendRoll() {
    int roll = 0; 

    for (int i = 0; i < getNumDefendDie(); ++i) {
        roll += rand() % 6 + 1;
    }

    return roll;
}

/*
** Creature class getters (accessors).
*/
int Creature::getArmor() {
    return armor;
}

int Creature::getStrength() {
    return strength;
}

int Creature::getDieSides() {
    return dieSides;
}

int Creature::getNumAttackDie() {
    return numAttackDie;
}

int Creature::getNumDefendDie() {
    return numDefendDie;
}

/*
** Creature class setters (mutators).
*/
void Creature::setName(std::string nameIn) {
    name = nameIn;
}

void Creature::setArmor(int armorIn) {
    armor = armorIn;
}

void Creature::setStrength(int strengthIn) {
    strength = strengthIn;
}

void Creature::setDieSides(int dieSidesIn) {
    dieSides = dieSidesIn;
}

void Creature::setNumAttackDie(int numAttackDieIn) {
    numAttackDie = numAttackDieIn;
}

void Creature::setNumDefendDie(int numDefendDieIn) {
    numDefendDie = numDefendDieIn;
}