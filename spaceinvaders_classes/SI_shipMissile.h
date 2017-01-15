#ifndef SI_SHIPMISSILE_H_INCLUDED
#define SI_SHIPMISSILE_H_INCLUDED

#include "SI_base.h"
#include "SI_alien.h"
#include <vector>



class SI_shipMissile : public SI_base{

    public:
        //constructor
        SI_shipMissile(signed int x, signed int y);

        //destructor
        ~SI_shipMissile();

        //check if hit an alien
        bool CheckIfHitBorder();


        //move TODO:how to implement speed
        void MoveMissile();

};

#endif // SI_SHIPMISSILE_H_INCLUDED
