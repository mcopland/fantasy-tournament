/*******************************************************************************
** Program: fantasyTournament
** File:    Tournament.cpp
** -----------------------------------------------------------------------------
** This is the Tournament class function implementation file. The Tournament
** class gets Creatures from the user, then simulates battles and displays
** the results.
*******************************************************************************/

#include "Tournament.hpp"

/*
** Default constructor and destructor.
*/
Tournament::Tournament() {}

Tournament::~Tournament() {
    CreatureList *tempPtr = nullptr;
    
    // delete player1
    if (player1 != nullptr) {
        while (player1 != nullptr) {
            tempPtr = player1;
            player1 = player1->next;
            delete tempPtr;
        }
    }

    // delete player2
    if (player2 != nullptr) {
        while (player2 != nullptr) {
            tempPtr = player2;
            player2 = player2->next;
            delete tempPtr;
        }
    }

    // delete defeated
    if (defeated != nullptr) {
        while (defeated != nullptr) {
            tempPtr = defeated;
            defeated = defeated->next;
            delete tempPtr;
        }
    }
}

/*
** Runs Tournament. Gets Creatures from user, then simulates battles and
** displays results.
*/
void Tournament::runTournament() {
    using std::cout;
    using std::endl;
    
    int creatures;

    // get number of creatures
    cout << "How many creatures would you like for either team (1-10)? ";
    creatures = getValidInt(1, 10);

    // sets Creature rosters
    cout << "\nPlease choose player 1's heroes.\n" << endl;
    setRoster(player1, creatures);
    cout << "\nPlease choose player 2's heroes.\n" << endl;
    setRoster(player2, creatures);

    // simulate battles
    int tournamentWinner = 0;
    int round = 1;
    
    // run while either player has fighters
    while (player1 != nullptr && player2 != nullptr) {
        cout << "\nRound " << round << endl
            << "Player 1: " << player1->fighter->getName()
            << " vs " << "Player 2: " << player2->fighter->getName()
            << endl;

        // Creature fight
        int winner = fight(player1->fighter, player2->fighter);

        // player1 wins
        if (winner == 1) {
            cout << endl << player1->fighter->getName() << " wins!" << endl;
            moveToBack(player1);
            moveToDefeated(player2);
        }
        // player2 wins
        else if (winner == 2) {
            cout << endl << player2->fighter->getName() << " wins!" << endl;
            moveToBack(player2);
            moveToDefeated(player1);
        }
        // draw
        else if (winner == 0) {
            cout << "\nDraw! Both died!" << endl;
            moveToDefeated(player1);
            moveToDefeated(player2);
        }

        // determine winner
        if (player1 == nullptr) {
            if (player2 == nullptr) {
                tournamentWinner = 0;       // draw
            }
            tournamentWinner = 2;           // player2 wins
        }
        if (player2 == nullptr) {
            if (player1 == nullptr) {
                tournamentWinner = 0;       // draw
            }
            tournamentWinner = 1;           // player1 wins
        }

        round++;
    }

    // display winner
    if (tournamentWinner == 1) {
        cout << "\nPlayer 1 wins!" << endl;
    }
    else if (tournamentWinner == 2) {
        cout << "\nPlayer 2 wins!" << endl;
    }
    else if (tournamentWinner == 0) {
        cout << "\nDraw!" << endl;
    }

    // prompt user if they want to see the defeated Creatures
    bool viewDefeated;
    viewDefeated = getYesNo("\nWould you like to see the list of defeated Creatures? (y/n) ");
    cout << endl;

    // display defeated
    if (viewDefeated) {
        CreatureList *defeatedList = defeated;
        int position = 1;

        while (defeatedList != nullptr) {
            cout << position++ << ": " << defeatedList->fighter->getName() << endl;
            defeatedList = defeatedList->next;
        }
    }
}

/*
** Takes winning Creature, recovers their health, and moves them to the back.
**
** @param CreatureList  Winning player.
*/
void Tournament::moveToBack(CreatureList * &player) {
    CreatureList *head = player;
    
    // move to back of queue
    while (player->next != nullptr)
    {
        player = player->next;
    }

    // recovers health for winner
    int recoverHealth = rand() % 5 + 2;
    head->fighter->setStrength(head->fighter->getStrength() + recoverHealth);

    // move head to end of queue
    player->next = head;
    player = head->next;
    head->next = nullptr;
    
}

/*
** Moves defeated Creature to the back of the defeated queue.
**
** @param CreatureList*  Reference to defeated Creature.
*/
void Tournament::moveToDefeated(CreatureList * &player) {
    CreatureList *head = player;
    
    // moves head to next
    player = head->next;
    head->next = nullptr;

    // if queue is empty
    if (defeated == nullptr) {
        defeated = head;
    }
    // add to back of queue
    else {
        CreatureList *defeatedHead = defeated;

        while (defeated->next != nullptr) {
            defeated = defeated->next;
        }

        defeated->next = head;
        defeated = defeatedHead;
    }   
}

/*
** Creates roster of Creatures.
**
** @param CreatureList*  Reference to player.
** @param int            Number of Creatures to add.
*/
void Tournament::setRoster(CreatureList * &player, int numCreatures)
{   // number of Creatures
    int *creatureArr = new int[numCreatures];
    // names
    std::string *nameArr = new std::string[numCreatures];

    // loops until array is filled
    for (int i = 0; i < numCreatures; ++i) {
        creatureArr[i] = creatureMenu();
        nameArr[i] = getValidString("What is this Creature's name? ");
        std::cout << std::endl;
    }

    // create Creature nodes
    for (int i = numCreatures - 1; i >= 0; --i) {
        if (i == numCreatures - 1) {
            player = new CreatureList(setCreature(creatureArr[i]), nameArr[i]);
        }
        else {
            player = new CreatureList(setCreature(creatureArr[i]), nameArr[i], player);
        }
    }

    delete[] creatureArr;
    creatureArr = nullptr;
    delete[] nameArr;
    nameArr = nullptr;
}

/*
** Returns class of selected Creature.
**
** @param int  Chosen Creature type.
*/
Creature *Tournament::setCreature(int creaturePick) {
    switch (creaturePick) {
        case 1:
            return new Barbarian;
            break;
        case 2:
            return new BlueMen;
            break;
        case 3:
            return new HarryPotter;
            break;
        case 4:
            return new Medusa;
            break;
        case 5:
            return new Vampire;
        default:
            return 0;
    }
}