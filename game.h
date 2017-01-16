#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "spaceinvaders_classes/SI_ship.h"
#include "spaceinvaders_classes/SI_alien.h"
#include "spaceinvaders_classes/SI_shipMissile.h"
#include "spaceinvaders_classes/SI_alienMissile.h"
#include <vector>
#include "constants.hpp"
#include <iostream>
#include <ncurses.h>
#include <unistd.h>
#include <thread>
#include <chrono>
#include <mutex>
#include "controllers/AliensController.h"
#include "controllers/AlienMissilesController.h"
#include "controllers/ShipController.h"

using namespace std;



class Game{

    //privates
    private:
        //score
        int score = 0;

        //game objects

        ShipController *shipController = NULL;
        AlienMissilesController *alienMissilesController = NULL;
        AliensController *aliensController = NULL;
        ShipMissilesController *shipMissilesController = NULL;


    public:

        // -- GETTERS ---//

        //aliens
        AliensController* GetAliensController(){return this->aliensController;}

        //shipMissiles
        ShipMissilesController* GetShipMissilesController(){return this->shipMissilesController;}

        //alien missiles
        AlienMissilesController* GetAlienMissilesController(){return this->alienMissilesController;}

        //ship
        ShipController* GetShipController(){return this->shipController;}

        //constructor
        Game();

        //destructor
        ~Game();

        // -- METHODS -- //

        //game starts
        void GameStart();

        //print all objects
        void PrintGame();

        //game ended
        void GameEnded();

        //get game score
        int GetScore();




};


#endif // GAME_H_INCLUDED
