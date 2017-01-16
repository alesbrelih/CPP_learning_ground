#ifndef SHIPCONTROLLER_H_INCLUDED
#define SHIPCONTROLLER_H_INCLUDED

#include "../spaceinvaders_classes/SI_ship.h"
#include <mutex>
#include <thread>
#include <ncurses.h>
#include "ShipMissilesController.h"
#include "AlienMissilesController.h"

using namespace std;

// ------------------------- //
// -- Ship Conroller Class --//
// ------------------------- //

class ShipController{

    //privates
    private:

        //ship object
        SI_ship *ship = NULL;

        //ship missiles controller
        ShipMissilesController *shipMissilesController = NULL;

        //alien missiles controller
        AlienMissilesController *alienMissilesController = NULL;

        //mutex
        mutex lock_ship;

    public:

        //contructor
        ShipController(ShipMissilesController *shipMissController, AlienMissilesController *alienMisController);

        //destructor
        ~ShipController();

        //move
        void MoveShip(bool &gameRunning);

        //draw ship
        void DrawShip();



};

#endif // SHIPCONTROLLER_H_INCLUDED
