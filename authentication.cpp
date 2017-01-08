#include "headers/classes.h"
#include <iostream>
#include "db_connect.h"
#include "authentication.h"

using namespace std;

// authentication constructor
Authentication::Authentication(){


};

//destructor
Authentication::~Authentication(){

    cout<<"Authentication destroyed!"<<endl;

};

//check authentication method
bool Authentication::CheckAuthentication(string username, string password){
    //address for db
    const string current_address = "/home/ales/Databases/sqlite/spaceinvaders/spaceInvaders.db";

    //set db connection address
    Db_Connect spaceInvaderDb(current_address);

    //connects to db
    bool connectedToDb = spaceInvaderDb.Connect();

    //if connection successful
    if(connectedToDb){

        //gets players from dn
        Person currentUser = spaceInvaderDb.CheckAuthentication(username,password);

        //user username
        string currentUsername = currentUser.GetUsername();

        //check if exist
        if(currentUsername != "undefined"){

            //set current user and return true
            this->SetCurrentUser(currentUser);
            return true;
        }
        else{

            //return false since failed auth
            return false;
        }
    }
};
