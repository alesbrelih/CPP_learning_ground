#include "ShipMissilesController.h"


//removes missiles
void ShipMissilesController::RemoveMissiles(deque<SI_shipMissile> outmissiles){

    //lock
    //number of out of boundsmissiles
    int outMissilesCount = outmissiles.size();

    //all missiles on map
    int missilesCount = this->shipMissiles->size();

    //over all outbound missiles iteration
    for(int i = 0;i<outMissilesCount;i++){

        //current outbound missile values
        SI_shipMissile outMissile = outmissiles.at(i);

        //try from back to dodge failing at index when deleting
        for(int j = missilesCount-1;j>=0;j--){

            //current missile in iteration
            SI_shipMissile current = this->shipMissiles->at(j);

            //check if matching coordinates
            if(current.GetX() == outMissile.GetX() && current.GetY() == outMissile.GetY()){

                this->shipMissiles->erase(this->shipMissiles->begin()+j);
                missilesCount--; //one missile was deleted in this iteration
                break;

            }

        }

    }

};

// ---- DEFINE ---- //

//constructor
ShipMissilesController::ShipMissilesController(){

    cout<<"Ship missiles controller object created!"<<endl;

};


//destructor
ShipMissilesController::~ShipMissilesController(){

    cout<<"Ship missiles controller object destroyed!"<<endl;

};

// ---- METHODS --- //

//draw

void ShipMissilesController::DrawMissiles(){

    //lock
    lock_guard<mutex> lock(this->missiles_lock);

    //count number of elements
    int missilesCount = this->shipMissiles->size();

    //draw each ship missile
    for(int i = 0;i<missilesCount;i++){

        //get missile coords
        int coordX = this->shipMissiles->at(i).GetX();
        int coordY = this->shipMissiles->at(i).GetY();

        //print missile on screen
        mvprintw(coordY,coordX,"|");

    }

};

//move

void ShipMissilesController::MoveMissiles(bool &gameRunning){


    //create lock mutex for missiles
    unique_lock<mutex> lock(this->missiles_lock,defer_lock);


    //ame running flag
    while(gameRunning == true){




        //out of bounds missiles
        deque<SI_shipMissile> outOfBounds;

        deque<SI_shipMissile> hitAlien;

        //lock mutex
        lock.lock();

        //this->aliensController->LockMutex();


        //size of missiles
        int currentMissilesCount = this->shipMissiles->size();

        //for each existin missle -> move and check if hit something
        for(int i = 0;i<currentMissilesCount;i++){

            //missile ref
            SI_shipMissile *missile = &(this->shipMissiles->at(i));

            //move missile
            missile->MoveMissile();

            //check if hit alien

            bool alienHit = (this->aliensController->CheckIfAlienHit(missile));

            if(alienHit == true){

                //alien was hit -> add missle to hit allien missiles
                hitAlien.push_back(*missile);

            }
            else{ //redundant to check if border hit once alien was hit -> better performance

                //check if border hit
                int borderHit = missile->CheckIfHitBorder();
                if(borderHit == true){

                    //border was hit
                    outOfBounds.push_back(*missile);

                }
            }
        }

        if(outOfBounds.size()>0){

            //remove ship missiles and clear out of bounds
            this->RemoveMissiles(outOfBounds);


        }

        if(hitAlien.size()>0){

            this->RemoveMissiles(hitAlien);

        }


        //unlock before sleep
        lock.unlock();

        //this->aliensController->UnlockMutex();

        this_thread::sleep_for(chrono::milliseconds(Constants::GetShipMissilesSleep()));
    }
};

//add new missile - missile shot
void ShipMissilesController::AddMissile(signed int x){

    //lock
    lock_guard<mutex> lock(this->missiles_lock);

    //get starting y
    int coordY = Constants::GetPlaygroundHeight()-1;

    //Create missile object
    SI_shipMissile missile(x,coordY);

    //its copy its passed to vector
    this->shipMissiles->push_back(missile);


};
