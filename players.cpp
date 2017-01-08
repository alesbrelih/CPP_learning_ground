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

    string database_connection = Constants::GetDbConnection();

    //set db connection address
    Db_Connect spaceInvaderDb(database_connection);

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
