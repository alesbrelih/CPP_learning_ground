#include "SI_alien.h"

//constructor
SI_alien::SI_alien(signed int x, signed int y):SI_base(x,y){};

//destructor
SI_alien::~SI_alien(){
    cout<<"Alien object destroyed!"<<endl;
};

//methods
void SI_alien::CheckIfAtBorder(AlienDirection current, AlienDirection *game){

    //if current direction is left
    if(current == Left){

        //check if alient object didnt move to 0
        if(this->GetX() == 0){

            //change direction to right
            *game = Right;

        }

    }

    //if current direction is right
    else if(current == Right){

        //check if x was changed to max of array
        if(this->GetX() == Constants::GetPlaygroundWidthForArray()){

            //change direction
            *game = Left;

        }

    }

};

//move method
void SI_alien::Move(AlienDirection current){

    //if current alient direction is left then reduce X value by 1
    if(current == Left){

        int newX = this->GetX();
        newX++;

        this->SetX(newX);

    }

    //if current alien direction is right then increase X value by 1
    else if(current == Right){

        int newX = this->GetX();
        newX--;

        this->SetX(newX);

    }

};
