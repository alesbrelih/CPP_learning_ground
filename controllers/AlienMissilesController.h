#ifndef ALIENMISSILESCONTROLLER_H_INCLUDED
#define ALIENMISSILESCONTROLLER_H_INCLUDED

#include <vector>
#include "../spaceinvaders_classes/SI_alienMissile.h"
#include <mutex>
#include <thread>
#include <iostream>
#include <chrono>
#include <ncurses.h>
#include <algorithm>
#include <deque>

using namespace std;

// ----------------------------- //
// alien missiles controller class
// ----------------------------- //
class AlienMissilesController{

    //privates
    private:

        //vector of all missiles
        deque<SI_alienMissile> *alienMissiles = new deque<SI_alienMissile>;

        //lock missiles array
        mutex lock_missiles_array;


    public:

        //constructor
        AlienMissilesController();

        //destructor
        ~AlienMissilesController();



        // -- METHODS -- //

        //draw missiles
        void DrawMissiles();

        //move missiles
        void MoveMissiles(bool &gameRunning);

        //remove missile from array
        void RemoveMissile(SI_alienMissile *missile);

        //remove list of missles
        void RemoveMissles(vector<SI_alienMissile> *outboundMissiles);

        //add new missile to array
        void AddMissile(signed int x, signed int y);


};

#endif // ALIENMISSILESCONTROLLER_H_INCLUDED
