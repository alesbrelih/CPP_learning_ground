#ifndef GAME_SESSION_H_INCLUDED
#define GAME_SESSION_H_INCLUDED

#include "headers/classes.h"
#include <vector>
#include <iostream>
#include "game.h"

using namespace std;

class Game_Session{

    private:
        Person player;
        vector<int> scores;

    public:
        //setter for player
        void SetPlayer(Person current){player = current;}

        //getter for player
        Person GetPlayer(){return player;}

        //get scores vector
        vector<int> GetScores(){return scores;}

        //constructor
        Game_Session(Person player);

        //destructor
        ~Game_Session();

        //adds score to current session scores
        void AddScore(int score);

        //saves score to db
        void SaveScore(int score);

        //newgame
        void NewGame();
};


#endif // GAME_SESSION_H_INCLUDED
