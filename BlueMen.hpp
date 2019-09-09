/*******************************************************************************
** Program: fantasyTournament
** File:    BlueMen.hpp
** -----------------------------------------------------------------------------
** This is the BlueMen class specification (header) file. This class inherits
** from the Creature class. Blue Men are actually a swarm of small individuals.
** For every 4 points of damage, they lose one defense die.
*******************************************************************************/

#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP

#include "Creature.hpp"

class BlueMen : public Creature {
public:
    BlueMen();
    ~BlueMen();

    virtual std::string getName();
    virtual void defendSelf(int damageIn);
};

#endif