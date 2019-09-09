/*******************************************************************************
** Program: fantasyTournament
** File:    Creature.hpp
** -----------------------------------------------------------------------------
** This is the Creature class specification (header) file. The Creature is an
** abstract class acting as a base for the five Creature derived classes.
*******************************************************************************/

#ifndef CREATURE_HPP
#define CREATURE_HPP

#include <cstdlib>      // srand()
#include <string>

class Creature {
protected:
    std::string name;

private:
    int armor;
    int strength;

    // dice
    int dieSides;
    int numAttackDie;
    int numDefendDie;

public:
    Creature();
    ~Creature();

    bool stillAlive();

    // getters
    int getArmor();
    int getStrength();
    int getDieSides();
    int getNumAttackDie();
    int getNumDefendDie();

    // setters
    void setName(std::string nameIn);
    void setArmor(int armorIn);
    void setStrength(int strengthIn);
    void setDieSides(int dieSidesIn);
    void setNumAttackDie(int numAttackDieIn);
    void setNumDefendDie(int numDefendDieIn);

    // virtual functions
    virtual int attackRoll();
    virtual int defendRoll();
    virtual std::string getName() = 0;
    virtual void defendSelf(int damageIn);
};

#endif