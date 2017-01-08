#include "headers/classes.h"
#include <iostream>
#include "db_connect.h"
#include "authentication.h"
#include "constants.hpp"
#include <ncurses.h>

using namespace std;

// authentication constructor
Authentication::Authentication(){


};

//destructor
Authentication::~Authentication(){

    //cout<<"Authentication destroyed!"<<endl;

};

//check authentication method
bool Authentication::CheckAuthentication(string username, string password){

    //address for db
    const string current_address = Constants::GetDbConnection();

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

//creates new account
void Authentication::CreateAccountObject(){

    //declare needed variables
    string newUsername, newPwdStr, newPwdConfirmStr;
    char newPassword[20],newPasswordConfirm[20];

    //get valid username
    while(true){

        //get username
        cout<<"Please enter username you desire"<<endl;
        cin>>newUsername;

        bool usernameAvaliable = this->UsernameDoesntExists(newUsername);

        //if username avaliable
        if(usernameAvaliable == true){

            break;

        }

        //not avaliable notify user
        else{
            cout<<"Username: "<<newUsername<<" Already exists!"<<endl;
            cout<<"Please select a new username."<<endl;
        }




    }


    //inits ncurses // TODO: DO COMPATIBLE FOR WINS
    initscr();

    //failed counter
    int failedCounter = 0;

    while(true){

        // strings to be displayed

        char mesg[]="Please insert your password: ";

        char mesgRepeat[] = "Please repeat your password";

        char pwdsNotMatch[] = "Passwords don't match!";

        //if it isnt first try show that pwds didn't match
        if(failedCounter>0){
            mvprintw(0,0,pwdsNotMatch);
        }

        //if not first try then print it on second row.
        if(failedCounter>0){
            //print please insert pwd message
            mvprintw(1,0,mesg);
        }
        else{
            mvprintw(0,0,mesg);
        }


        //no echo for pwd insert
        noecho();

        //get string from input
        getstr(newPassword);

        //convert to string
        newPwdStr = string(newPassword);

        //clear console

        clear();

        //enable echo

        echo();

        //print please insert pwd message

        mvprintw(0,0,mesgRepeat);

        noecho();

        //get newpassword confirm
        getstr(newPasswordConfirm);

        newPwdConfirmStr = string(newPasswordConfirm);

        //check if password match
        if(newPwdStr.compare(newPwdConfirmStr)==0){

            break;
        }

        failedCounter++;
        clear();

    }

    //end ncurses
    endwin();


    //create person object
    Person account;
    account.SetUsername(newUsername);
    account.SetPassword(newPwdStr);

    //register account on db
    this->RegisterAccount(&account);

};

//register Authentication
void Authentication::RegisterAccount(Person *person){

    //database connection string
    const string databaseConn = Constants::GetDbConnection();

    //space invaders db connection
    Db_Connect spaceInvadersDb(databaseConn);

    //connect flag
    bool connected = spaceInvadersDb.Connect();

    //if connected to db
    if(connected == true){

        spaceInvadersDb.RegisterAccount(person);

    }


}

//edit Profile Info
void Authentication::EditProfile(){

    //define variables
    string name = "", lastname = "", email = "";
    int age = -1;


    //display header
    cout<<endl<<"######################"<<endl;
    cout<<"# -- Edit Profile -- #"<<endl;
    cout<<"######################"<<endl<<endl;

    cout<<"Enter your name: "<<endl;
    cin>>name;

    cout<<endl<<"Enter your lastname: "<<endl;
    cin>>lastname;

    cout<<endl<<"Enter your email: "<<endl;
    cin>>email;

    cout<<endl<<"Enter your age"<<endl;
    cin>>age;

    cout<<endl;

    //change in db
    const string dbUrl = Constants::GetDbConnection();
    Db_Connect spaceInvadersDb(dbUrl);

    bool connected = spaceInvadersDb.Connect();

    if(connected == true){
        spaceInvadersDb.EditProfile(this->GetCurrentUser().GetId(),name,lastname,email,age);
    }
    else{
        cout<<"Could not connect to DB at the moment. Please try later.";
    }



};
//method to check if username exists
bool Authentication::UsernameDoesntExists(string username){

    //get db connection
    const string db_connection = Constants::GetDbConnection();

    //get db object
    Db_Connect spaceInvadersDb(db_connection);

    //connect to db
    bool connected = spaceInvadersDb.Connect();

    //if connection established
    if(connected){

        //check if username exists
        bool result = spaceInvadersDb.UsernameDoesntExist(username);

        //close db

        return result;

    }
    else{


        //return false
        return false;
    }

}
