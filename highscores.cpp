#include "highscores.h"
#include "db_connect.h"
#include "constants.hpp"
#include <string>
#include "headers/classes.h"
#include <vector>
#include <iostream>

using namespace std;

void Highscores::Show(){

    string dbConnection = Constants::GetDbConnection();
    Db_Connect spaceInvaders(dbConnection);

    //check if connected to db
    bool connected = spaceInvaders.Connect();

    if(connected){

        //get highscores
        vector<PersonScore> highscores = spaceInvaders.GetHighScores();

        //Size of highscore table
        int highscore_size = highscores.size();

        //declare needed vars
        string username,scorestring;
        int score;

        //print every score in console
        for(int i = 0;i<highscore_size;i++){

            username = highscores[i].GetUsername();
            score = highscores[i].GetScore();
            scorestring = to_string(score);

            cout<<username<<"   "<<scorestring<<endl;
        }



    }
};
