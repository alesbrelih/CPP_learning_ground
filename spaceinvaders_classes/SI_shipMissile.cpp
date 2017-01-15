#include "SI_shipMissile.h"


//constructor
SI_shipMissile::SI_shipMissile(signed int x, signed int y):SI_base(x,y){};

//destructor
SI_shipMissile::~SI_shipMissile(){
    //cout<<"Ship missile object destroyed!"<<endl;
};

// --- METHODS --- //

//check if hit an border
bool SI_shipMissile::CheckIfHitBorder(){

    if(this->GetY() <= 1){

        return true;

    }

};

//move missile method
void SI_shipMissile::MoveMissile(){

    //get new y value
    int newY = this->GetY();

    //check that it doesnt go out of borders
    if(newY>=1){

        this->SetY(newY-1);

    }



};


