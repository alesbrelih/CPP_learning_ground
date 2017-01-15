// ref to headers
#include "SI_ship.h"

//DEFINE CONSTRUCTOR
SI_ship::SI_ship(signed int x, signed int y):SI_base(x,y){};

//DEFINE DESTRUCTOR
SI_ship::~SI_ship(){

    //each class has just one destructor
    cout<<"Ship class destroyed!";
}

//DEFINE METHODS

//move left
void SI_ship::MoveLeft(){

    //check if x is not 0 already
    if(!(this->GetX() == 0)){

        //lower x value == move left
        int newX = this->GetX();
        newX--;

        //set new value
        this->SetX(newX);

    }

};

//move right
void SI_ship::MoveRight(){

    //current x
    int currentX = this->GetX();

    //ship not at end
    if(currentX < Constants::GetPlaygroundWidth()){

        //increase current x
        currentX++;

        //set new x
        this->SetX(currentX);

    }

};

