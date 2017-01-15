#include "AlienMissilesController.h"

bool operator== ( const SI_alienMissile &m1, const SI_alienMissile &m2)
{
        return addressof(m1) == addressof(m2);
}

//constructor
AlienMissilesController::AlienMissilesController(){

    cout<<"Alien missiles controller created!"<<endl;
    this->alienMissiles;
    cout<<"Alien missiles controller created!"<<endl;
};

//destructor
AlienMissilesController::~AlienMissilesController(){

    cout<<"Alien missiles controller destroyed!"<<endl;

};

//move missiles
void AlienMissilesController::MoveMissiles(bool &gameRunning){


    vector<SI_alienMissile> *outofbounds = new vector<SI_alienMissile>;

    //game still runs
    while(gameRunning == true)
    {
        //lock aliens missiles
        unique_lock<mutex> lock(this->lock_missiles_array,defer_lock);

        //lock
        lock.lock();

        //missiles count
        int missilesCount = this->alienMissiles->size();

        //iterate through evey missile in array
        for(int i = 0; i<missilesCount; i++){

            SI_alienMissile *missile = &(this->alienMissiles->at(i));

            missile->MoveMissile();

            //if hit border
            bool hitBorder = missile->CheckIfHitBorder();

            //if hits border, remove missile from array
            if(hitBorder == true){

                outofbounds->push_back(*missile);
                //this->RemoveMissile(missile);

            }

        }



        if(outofbounds->size()>0){
            this->RemoveMissles(outofbounds);
            outofbounds->clear();
        }


        //unlock before sleep
        lock.unlock();

        //sleep thread unil new missile move
        this_thread::sleep_for(chrono::milliseconds(Constants::GetAlienMissileSleep()));
    }
};

//remove missile from array
void AlienMissilesController::RemoveMissile(SI_alienMissile *missile){


    //missiles count
    int missilesCount = this->alienMissiles->size();

    //iterate through each missile
    for(int i = 0;i<missilesCount;i++){

        //remove if same memory
        if(missile == &(this->alienMissiles->at(i))){

            auto iter = (std::find(this->alienMissiles->begin(),this->alienMissiles->end(),*missile));
            if(iter != this->alienMissiles->end()){
                this->alienMissiles->erase(iter);
            }

            //missile->SetX(-100);

            //this->alienMissiles->erase(this->alienMissiles->begin()+i);
            //this->alienMissiles->resize(missilesCount-1);
            break;


        }
    }
};

void AlienMissilesController::RemoveMissles(vector<SI_alienMissile> *outboundMissiles){

    //lock aliens array
    //lock_guard<mutex> lock(this->lock_missiles_array);

    int outofboundCount = outboundMissiles->size();

    for(int i = 0;i<outofboundCount;i++){

        this->alienMissiles->pop_front();
    }

};

//add new missile to array
void AlienMissilesController::AddMissile(signed int x, signed int y){

    //lock aliens array
    lock_guard<mutex> lock(this->lock_missiles_array);

    //create new missile with given coord
    SI_alienMissile missile(x,y);

    //push it to missle vector pointer
    this->alienMissiles->push_back(missile);

};

//draw missiles
void AlienMissilesController::DrawMissiles(){

    //lock aliens array
    lock_guard<mutex> lock(this->lock_missiles_array);

    //missiles count
    int missilesCount = this->alienMissiles->size();

    //redraw every missile available
    for(int i = 0;i<missilesCount;i++){

        SI_alienMissile *missile = &(this->alienMissiles->at(i));

        int cordY = (*(this->alienMissiles))[i].GetY();
        int cordX = (*(this->alienMissiles))[i].GetX();

        //print * for every missile
        mvprintw(cordY,cordX,"*");

    }



};
