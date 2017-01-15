#include "game.h"

mutex lock_screen;

void MoveAliens(AliensController * alienController,bool &gameRunning){

    alienController->MoveAliens(gameRunning);

};

void MoveMissiles(AlienMissilesController *alienMissilesController, bool &gameRunning){

    alienMissilesController->MoveMissiles(gameRunning);

};

void MoveShip(ShipController *shipController, bool &gameRunning){

    shipController->MoveShip(gameRunning);

};

void MoveShipMissiles(ShipMissilesController *shipMissilesController,bool &gameRunning){

    shipMissilesController->MoveMissiles(gameRunning);

};

//constructor
Game::Game(){

    //set score to 0
    this->score = 0;

    this->alienMissilesController = new AlienMissilesController();

    this->aliensController = new AliensController(this->alienMissilesController);

    this->shipMissilesController = new ShipMissilesController();

    this->shipController = new ShipController(this->shipMissilesController);

};

Game::~Game(){

    cout<<"Game object destroyed!"<<endl;

};



//game starts
void Game::GameStart(){

    bool gameRunning = true;
    cout<<"about to be inited"<<endl;
    WINDOW *w = initscr();
    cbreak();
    nodelay(w, TRUE);
    keypad(w,true);

    std::thread moveAliensThread (MoveAliens,this->GetAliensController(),std::ref(gameRunning));
    moveAliensThread.detach();

    std::thread moveAliensMissilesThread (MoveMissiles,this->GetAlienMissilesController(),std::ref(gameRunning));
    moveAliensMissilesThread.detach();

    std::thread moveShipThread (MoveShip,this->GetShipController(),std::ref(gameRunning));
    moveShipThread.detach();

    std::thread moveShipMissilesThread (MoveShipMissiles,this->GetShipMissilesController(),std::ref(gameRunning));
    moveShipMissilesThread.detach();

    //game in progress
    while(gameRunning){

        clear();

        this->PrintGame();

        //sleep for game sleep
        //usleep(Constants::GetGameSleep());
        this_thread::sleep_for(chrono::milliseconds(Constants::GetGameSleep()));
    }
    clear();
    endwin();


};

void Game::PrintGame(){

    //lock screen
    lock_guard<mutex> lock(lock_screen);



    //draw aliens
    this->GetAliensController()->DrawAliens();

    //draw alien missiles
    this->GetAlienMissilesController()->DrawMissiles();


    //print ship location
    this->GetShipController()->DrawShip();

    //print ship missiles
    this->GetShipMissilesController()->DrawMissiles();

    //print border
    for(int x = 0;x<Constants::GetPlaygroundWidthWithContainers();x++){

        for(int y = 0;y<Constants::GetPlaygroundHeightWithContainers();y++){

            if(x == 0 || y == 0 || x == Constants::GetPlaygroundWidthWithContainers()-1 || y == Constants::GetPlaygroundHeightWithContainers()-1){

                mvprintw(y,x,"#");
            }

        }

    }


};

//move aliens
