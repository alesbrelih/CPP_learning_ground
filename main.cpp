#include <iostream>
#include "headers/classes.h"
#include <string>
#include <vector>
#include <algorithm>
#include "sqlite3.h"
#include "db_connect.h"
#include "players.h"
#include "authentication.h"
#include <ncurses.h>
#include "highscores.h"
#include "game_session.h"

//namespace
using namespace std;

//address for db
//const string current_address = "/home/ales/Databases/sqlite/spaceinvaders/spaceInvaders.db";

vector<Person> players;


//main fnc
int main()
{

    cout<<"########################"<<endl;
    cout<<"# -- Space Invaders -- #"<<endl;
    cout<<"########################"<<endl<<endl;

    Authentication auth;

    string current_username;
    char current_password[20];

    while(true){

        //current username
        cout<<"Please insert your username / .quit to exit / .register to register an account: "<<endl;
        cin>>current_username;

        //check if user gives up
        if(current_username == ".quit"){
            return 0;
        }

        //register option
        else if(current_username == ".register"){

            //uses authentication object to create an account
            auth.CreateAccountObject();

        }
        else{
            //test for pwd
            char mesg[]="Please insert your password: ";

            //inits ncurses // TODO: DO COMPATIBLE FOR WINS
            initscr();

            //print please insert pwd message
            mvprintw(0,0,mesg);

            //no echo for pwd insert
            noecho();

            //get string from input
            getstr(current_password);

            //clear console
            clear();

            //end ncurses
            endwin();

            //check if valid auth
            bool result = auth.CheckAuthentication(current_username,current_password);

            //if auth
            if(result == true){
                system("clear"); //TODO: BAD CODE
                cout<<"########################"<<endl;
                cout<<"# -- Space Invaders -- #"<<endl;
                cout<<"########################"<<endl<<endl;
                cout<<"Authentication successful!"<<endl;
                cout<<"Hello "<<current_username<<". "<<endl;
                break;
            }
            else{
                cout<<"Authentication failed for username: "<<current_username<<endl;
            }
        }



    }


    //get player
    Person current_user = auth.GetCurrentUser();
    //initialize game session
    Game_Session session(current_user);

    //holds what player wants to do
    string action;

    //get .scores or .play command
    while(true){

        //get user prompt
        cout<<endl<<"Enter .scores to see high scores."<<endl;
        cout<<"Enter .play to start a new game session."<<endl;
        cout<<"Enter .profile to edit profile."<<endl;
        cout<<"Enter .edit to edit profile."<<endl;
        cout<<"Enter .quit to exit the program."<<endl<<endl;
        cin>>action;

        //if valid action then
        if(action == ".play" || action == ".scores" || action == ".edit" || action == ".profile" || action == ".session"){

            //show highscores
            if(action ==".scores"){
                Highscores::Show();
            }
            //session scores
            else if(action == ".session"){

                //call session method
                session.GetScoresOutput();

            }
            //edit profile
            else if(action == ".edit"){
                auth.EditProfile();
            }
            //edit profile
            else if(action == ".profile"){
                auth.GetProfile();
            }
            else if(action == ".play"){

                session.NewGame();

            }
        }
        //quit program
        else if(action == ".quit"){
            return 0;
        }

    }


    return 0;
}
