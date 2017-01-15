#ifndef ALIENSCONTROLLER_H_INCLUDED
#define ALIENSCONTROLLER_H_INCLUDED

#include <mutex>
#include <vector>
#include "../spaceinvaders_classes/SI_alien.h"
#include "../spaceinvaders_classes/SI_shipMissile.h"
#include "../constants.hpp"
#include <iostream>
#include <unistd.h>
#include <ncurses.h>
#include <thread>
#include <chrono>
#include "AlienMissilesController.h"

using namespace std;

class AliensController{

    //privates
    private:
        //mutex lock
        mutex aliens_lock;
        mutex move_lock;

        //unique lock
        unique_lock<mutex> *lock = NULL;

        //vector aliens
        vector<SI_alien> *aliens = new vector<SI_alien>;

        //alien missiles controller ref
        AlienMissilesController *alienMissilesController = NULL;

    public:

        //get reference to aliens mutex
        void LockMutex();

        void UnlockMutex();

        //initialize aliens
        void InitializeAliens();

        //move aliens
        void MoveAliens(bool &gameRunning);

        //draw aliens
        void DrawAliens();

        //check if hit alien with shipMissile
        bool CheckIfAlienHit(SI_shipMissile *missile);

        //constructor
        AliensController(AlienMissilesController *alienMissilesController);

        //destructor
        ~AliensController();
};


#endif // ALIENSCONTROLLER_H_INCLUDED