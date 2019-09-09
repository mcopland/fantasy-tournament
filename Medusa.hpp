/*******************************************************************************
** Program: fantasyTournament
** File:    Medusa.hpp
** -----------------------------------------------------------------------------
** This is the Medusa class specification (header) file. This class inherits
** from the Creature class. If a Medusa rolls a 12 when attacking then the
** target instantly gets turned into stone and Medusa wins.
*******************************************************************************/

#ifndef MEDUSA_HPP
#define MEDUSA_HPP

#include "Creature.hpp"

#include <iostream>

class Medusa : public Creature {
public:
    Medusa();
    ~Medusa();

    virtual std::string getName();
    virtual int attackRoll();
};

#endif