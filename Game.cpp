/*******************************************************************************
** Program: fantasyTournament
** File:    Game.cpp
** -----------------------------------------------------------------------------
** This is the Game class function implementation file. The Game class represents
** a battle between two user-selected Creature objects.
*******************************************************************************/

#include "Game.hpp"

/*
** Default constructor and destructor.
*/
Game::Game() {}
Game::~Game() {}

/*
** Simulates two Creatures fighting.
**
** @param Creature*  Pointer to player1.
** @param Creature*  Pointer to player2.
*/
int Game::fight(Creature *player1, Creature *player2) {
    int roundCounter = 1;
    int attackerRoll;
    int defenderRoll;

    while (player1->stillAlive() && player2->stillAlive()) {
        roundCounter++;

        // player1 attacks, player2 defends
        attackerRoll = player1->attackRoll();
        defenderRoll = player2->defendRoll();

        player2->defendSelf(attackerRoll - defenderRoll);

        // player2 attacks, player1 defends
        attackerRoll = player2->attackRoll();
        defenderRoll = player1->defendRoll();

        player1->defendSelf(defenderRoll - attackerRoll);

        // end results
        if (!player1->stillAlive()) {
            if (!player2->stillAlive()) {
                return 0;                       // draw
            }
            return 2;                           // player2 wins
        }
        else if (!player2->stillAlive()) {
            if (!player1->stillAlive()) {
                return 0;                       // draw
            }
            return 1;                           // player1 wins
        }
    }
}

/*
** Prints the heroes list then returns which character has been chosen.
*/
int Game::creatureMenu() {
    // create menu
    Menu creatureMenu;
    creatureMenu.addOption("Barbarian");
    creatureMenu.addOption("Blue Men");
    creatureMenu.addOption("Harry Potter");
    creatureMenu.addOption("Medusa");
    creatureMenu.addOption("Vampire");

    creatureMenu.printMenu();

    // user chooses character from menu
    std::cout << "\nChoose your Creature: ";
    int creatureChoice = 0;
    creatureChoice = getValidInt(1, 5);

    return creatureChoice;
}