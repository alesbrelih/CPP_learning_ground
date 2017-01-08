#include "headers/classes.h"
#include <vector>
#include "players.h"
#include "db_connect.h"
#include <iostream>

using namespace std;



//define players constructor
Players::Players(){

    this->RefreshPlayers();

};

//define destructor
Players::~Players(){
    cout<<"Destroyed players object!"<<endl;
};


//refresh players from db
void Players::RefreshPlayers(){

    //address for db
    const string current_address = "/home/ales/Databases/sqlite/spaceinvaders/spaceInvaders.db";

    //set db connection address
    Db_Connect spaceInvaderDb(current_address);

    //connects to db
    bool connectedToDb = spaceInvaderDb.Connect();

    //if connection successful
    if(connectedToDb){

        //gets players from dn
        vector<Person> players = spaceInvaderDb.GetDbPersons();

        //set players to object prop
        this->SetPlayers(players);
    }
};
