#ifndef SHIPMISSILESCONTROLLER_H_INCLUDED
#define SHIPMISSILESCONTROLLER_H_INCLUDED

#include <mutex>
#include <thread>
#include <deque>
#include "../spaceinvaders_classes/SI_shipMissile.h"
#include "AliensController.h"

using namespace std;



// --------------------------------- //
// -- Ship Missiles Controller ----- //
// --------------------------------- //


class ShipMissilesController{

    //privates

    private:

        //dequeue for ship missiles
        deque<SI_shipMissile> *shipMissiles = new deque<SI_shipMissile>;

        //mutex for deque
        mutex missiles_lock;

        //ref to aliensController
        AliensController *aliensController = NULL;


    //public

    public:

        //constructor
        ShipMissilesController();

        //destructor
        ~ShipMissilesController();


        // ---- METHODS ---- //

        //move missiles
        void MoveMissiles(bool &gameRunnin);

        //draw
        void DrawMissiles();

        //add new missile
        void AddMissile(signed int x);

        //remove deque of missiles
        void RemoveMissiles(deque<SI_shipMissile> outmissiles);


};

#endif // SHIPMISSILESCONTROLLER_H_INCLUDED
