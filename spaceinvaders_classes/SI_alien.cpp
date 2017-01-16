#include "SI_alien.h"

//constructor
SI_alien::SI_alien(signed int x, signed int y):SI_base(x,y){};

//destructor
SI_alien::~SI_alien(){
    //cout<<"Alien object destroyed!"<<endl;
};

//methods
void SI_alien::CheckIfAtBorder(AlienDirection current, AlienDirection *gamedirection, bool &nextrow, bool &gameRunning){

    //if reached bottom corner then ame over
    if(this->GetY()==Constants::GetPlaygroundHeight()){

        gameRunning = false;

    }
    else{

        //if current direction is left
        if(current == Left){

            //check if alient object didnt move to 0
            if(this->GetX() == 1){

                //change direction to right
                *gamedirection = Right;

                //move to next row
                nextrow = true;

            }

        }

        //if current direction is right
        else if(current == Right){

            //check if x was changed to max of array
            if(this->GetX() == (Constants::GetPlaygroundWidthForArray()-1)){

                //change direction
                *gamedirection = Left;

                //move to next row
                nextrow = true;
            }
        }
    }
};

//move method
void SI_alien::Move(AlienDirection current, bool nextrow){

    //if next row == true then move y
    if(nextrow == true){

        //increase y coord
        int newY = this->GetY();
        this->SetY(newY+1);

    }
    else{ //not at end of row

        //if current alient direction is left then reduce X value by 1
        if(current == Left){
            int newX = this->GetX();

            this->SetX(newX-1);
        }
        //if current alien direction is right then increase X value by 1
        else if(current == Right){

            int newX = this->GetX();

            this->SetX(newX+1);
        }
    }
};

