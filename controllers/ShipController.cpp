#include "ShipController.h"

//define constructor
ShipController::ShipController(ShipMissilesController *shipMisController){

    //place it at middle
    int xCoord = Constants::GetPlaygroundWidth()/2;
    int yCoord = Constants::GetPlaygroundHeight();

    //create object
    this->ship = new SI_ship(xCoord,yCoord);

    //set ship missiles controller
    this->shipMissilesController = shipMisController;


};

//destructor
ShipController::~ShipController(){

    cout<<"Ship object destroyed!"<<endl;

};

//move ship
void ShipController::MoveShip(bool &gameRunning){

    //unique mutex lock
    unique_lock<mutex> lock(this->lock_ship, defer_lock);

    //while game running
    while(gameRunning == true){

        //lock mutex
        lock.lock();

        //move ship

        //currently pressed key
        int pressed_key = getch();

        //if a key was pressed
        if(pressed_key != ERR){


            //move left
            if(pressed_key == KEY_LEFT){

                this->ship->MoveLeft();

            }

            //move right
            if(pressed_key == KEY_RIGHT){

                this->ship->MoveRight();

            }

            //shoot
            if(pressed_key == KEY_UP){

                //add new missile
                this->shipMissilesController->AddMissile(this->ship->GetX());

            }
        }

        //unlock before sleep
        lock.unlock();

        //sleep thread
        this_thread::sleep_for(chrono::milliseconds(Constants::GetShipSleep()));
    }

};

//draw ship
void ShipController::DrawShip(){

    //lock object
    lock_guard<mutex> lock(this->lock_ship);

    //print ship on screen
    mvprintw(this->ship->GetY(),this->ship->GetX(),"W");

};
