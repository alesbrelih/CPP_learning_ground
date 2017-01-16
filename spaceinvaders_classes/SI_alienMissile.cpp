#include "SI_alienMissile.h"

//constructor
SI_alienMissile::SI_alienMissile(signed int x, signed int y):SI_base(x,y){};

//destructor
SI_alienMissile::~SI_alienMissile(){

    //cout<<"Alien missile object destroyed!"<<endl;

};

//methods

//cehck if hit
bool SI_alienMissile::CheckIfHitBorder(){

    //check if hit border
    if(this->GetY() >= Constants::GetPlaygroundHeight()+1){
        return true;
    }

};

//check if hit player
void SI_alienMissile::CheckIfHitShip(bool &gameRunning, SI_ship *ship){

    //check if coordinates match
    if(this->GetX() == ship->GetX() && this->GetY() == ship->GetY()){

        //change the loop var to false
        gameRunning = false;

    }

}

//move
void SI_alienMissile::MoveMissile(){


        //still place to move

        //new y
        int newY = this->GetY();
        int maxY = Constants::GetPlaygroundHeight()+1;

        if(newY < maxY){

            //set new Y
            this->SetY(newY+1);

        }




};
