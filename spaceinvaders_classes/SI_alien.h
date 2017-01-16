#ifndef SI_ALIEN_H_INCLUDED
#define SI_ALIEN_H_INCLUDED

#include "SI_base.h"
#include "../constants.hpp"
#include <cstdlib>

class SI_alien:public SI_base{

    public:
        //constructor
        SI_alien(signed int x, signed int y);

        //destructor
        ~SI_alien();

        // -- method -- //

        //check if at border
        void CheckIfAtBorder(AlienDirection current, AlienDirection *game, bool &nextrow, bool &gameRunning);

        //move method
        void Move(AlienDirection current, bool nextrow);

};


#endif // SI_ALIEN_H_INCLUDED
