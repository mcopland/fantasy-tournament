/*******************************************************************************
** Program: fantasyTournament
** File:    Vampire.hpp
** -----------------------------------------------------------------------------
** This is the Vampire class specification (header) file. This class inherits
** from the Creature class. The Vampire rolls one 12-sided attack die and one
** 6-sided defense die. Vampires can charm an opponent into not attacking. For a
** given attack, there is a 50% chance that their opponent does not actually
** attack them.
*******************************************************************************/

#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

#include "Creature.hpp"

#include <iostream>

class Vampire : public Creature {
public:
    Vampire();
    ~Vampire();

    virtual std::string getName();
    virtual void defendSelf(int damageIn);
};

#endif