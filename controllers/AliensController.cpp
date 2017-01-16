#include "AliensController.h"

//define controller
AliensController::AliensController(AlienMissilesController *alienMissilesController){

    //initialize aliens
    this->InitializeAliens();

    // set alienMissiles controller ref
    this->alienMissilesController = alienMissilesController;

};

//Destructor
AliensController::~AliensController(){

    cout<<"Aliens controller object destroyed!"<<endl;

};

//initialize aliens
void AliensController::InitializeAliens(){

    //lock aliens array
    lock_guard<mutex> lock(this->aliens_lock);

    //fill aliens
    int alienXnumber = Constants::GetNumberOfAliensInRow();
    int alienYnumber = Constants::GetNumberOfRowsForAliens();

    //difference in width
    int diff = Constants::GetPlaygroundWidth() - Constants::GetNumberOfAliensInRow();

    //number of rows
    for(int y = 1; y<=alienYnumber; y++){

        //number of columns
        for(int x = 1; x<=alienXnumber; x++){
            int xLoc = x+(diff/2);
            SI_alien alien(xLoc,y);
            this->aliens->push_back(alien);
        }
    }
};

//move aliens
void AliensController::MoveAliens(bool &gameRunning){

    //set unique lock
    unique_lock<mutex> lock(this->aliens_lock,defer_lock);

     //current game direction
    AlienDirection gameDirection = Left;

    //next row ref
    bool nextrowRef = false;

    //bool gameRunning = true;
    //while game running
    while(gameRunning){

        //lock aliens
        //unique_lock<mutex> lock(this->aliens_lock,defer_lock);

        lock.lock();




        //copy current game direction
        AlienDirection currentDirection = (AlienDirection)gameDirection;

        //number of aliens
        int aliensCount = this->aliens->size();

        //next row for current iteration
        bool nextrowCurrent = nextrowRef;

        //move every alien
        for(int i = 0;i<aliensCount;i++){

            //ref alien for easier ref
            SI_alien *alien = &(this->aliens->at(i));

            //move alien
            alien->Move(currentDirection,nextrowCurrent);

            //check if at border, so change direction
            alien->CheckIfAtBorder(currentDirection,&gameDirection,nextrowRef,gameRunning);

            //try to shoot
            this->AlienShoot(alien);
        }

        //if moved to next row this iteration then set it to false
        if(nextrowCurrent == true){
            nextrowRef = false;
        }

        //unlock
        lock.unlock();
        //sleep thread
        //usleep(Constants::GetAlienSleep());
        this_thread::sleep_for(chrono::milliseconds(Constants::GetAlienSleep()));
    }

};

void AliensController::AlienShoot(SI_alien *alien){

    //random number from 1 - 100
    int randNumber = rand()%100+1;

    //alien chance to shoot
    int chanceToShoot = Constants::GetAlienChanceToShoot();

    //if value under the chance to shoot - atm 20 ->1/5 chance to shoot
    if(randNumber<=chanceToShoot){

        this->alienMissilesController->AddMissile(alien->GetX(),alien->GetY());
    }

};

//draw aliens
void AliensController::DrawAliens(){

    //lock aliens
    lock_guard<mutex> lock(this->aliens_lock);

    //print aliens
    int alienSize = this->aliens->size();

    //print aliens
    for(int a = 0;a<alienSize;a++){
        int cordY = (*(this->aliens))[a].GetY();
        int cordX = (*(this->aliens))[a].GetX();
        mvprintw(cordY,cordX,"A");
    }


};


//check if alien hit
bool AliensController::CheckIfAlienHit(SI_shipMissile *missile){

    //get number of aliens still there
    int alienNumber = this->aliens->size();

    //get alien that is at missile location
    for(int i = 0;i<alienNumber;i++){

        //alien ref for easier readibility
        SI_alien alien = this->aliens->at(i);

        //check coords
        if(alien.GetX()== missile->GetX() && alien.GetY() == missile->GetY()){

            this->aliens->erase(this->aliens->begin()+i); //remove alien for array

            return true; //There should beonly 1 alien at that location
        }

    }


    //return false because no aliens were matching coords
    return false;

};


//unlock mutex

