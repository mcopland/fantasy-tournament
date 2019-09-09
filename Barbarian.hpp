/*******************************************************************************
** Program: fantasyTournament
** File:    Barbarian.hpp
** -----------------------------------------------------------------------------
** This is the Barbarian class specification (header) file. This class
** inherits from the Creature class. Attack and defense dice are rolled with
** random values.
*******************************************************************************/

#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

#include "Creature.hpp"

class Barbarian : public Creature {
public:
    Barbarian();
    ~Barbarian();

    virtual std::string getName();
};

#endif