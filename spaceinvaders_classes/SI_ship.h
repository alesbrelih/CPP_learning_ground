#ifndef SI_SHIP_H_INCLUDED
#define SI_SHIP_H_INCLUDED

#include "SI_base.h"
#include "../constants.hpp"

//ship is a subclass of SI base
class SI_ship : public SI_base{

    // --- constructor --- //
    SI_ship(signed int x, signed int y);

    // --- destructor --- //
    ~SI_ship();


    // --- METHODS ---- //

    //move left
    void MoveLeft();

    //move right
    void MoveRight();

    //------------------//

};

#endif // SI_SHIP_H_INCLUDED
