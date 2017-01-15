#ifndef SI_ALIENMISSILE_H_INCLUDED
#define SI_ALIENMISSILE_H_INCLUDED

#include "SI_base.h"
#include "SI_ship.h"

class SI_alienMissile : public SI_base{

    //public
    public:

        friend bool operator== (SI_alienMissile &m1, SI_alienMissile &m2);

        // -- constructor -- //
        SI_alienMissile(signed int x, signed int y);

        // -- destructor -- //
        ~SI_alienMissile();

        // -- methods -- //

        //check if hit border so its deleted from array
        bool CheckIfHitBorder();

        //check if hit player
        void CheckIfHitShip(bool &gameRunning, SI_ship *ship);

        //move missile
        void MoveMissile();




};

#endif // SI_ALIENMISSILE_H_INCLUDED
