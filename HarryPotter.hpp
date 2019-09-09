/*******************************************************************************
** Program: fantasyTournament
** File:    HarryPotter.hpp
** -----------------------------------------------------------------------------
** This is the HarryPotter class specification (header) file. This class
** inherits from the Creature class. Attack and defense dice are rolled with
** random values. Harry Potter has an extra life and strength is restored to 20
** if killed.
*******************************************************************************/

#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP

#include "Creature.hpp"

class HarryPotter : public Creature {
private:
    bool hogwarts = true;
public:
    HarryPotter();
    ~HarryPotter();

    virtual std::string getName();
    virtual void defendSelf(int damageIn);
};

#endif