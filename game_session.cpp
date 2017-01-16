#include "game_session.h"

//constructor for game session
Game_Session::Game_Session(Person currentplayer){

    //sets current player
    this->SetPlayer(currentplayer);

};

//destructor for game session
Game_Session::~Game_Session(){
    cout<<"Game session destroyed!"<<endl;
};

//add score function
void Game_Session::AddScore(int score){

    //pushes score to scores
    this->scores.push_back(score);

};

//save score to database
void Game_Session::SaveScore(int score){

    //TODO: SAVE SCORE TO DB

};

//starts new game
void Game_Session::NewGame(){

    Game game;
    game.GameStart();
    this->AddScore(game.GetScore());

};


//console logs all session scores
void Game_Session::GetScoresOutput(){

    int sessions = this->scores.size();

    //cosmetics
    cout<<endl<<"# --- Session Scores --- #"<<endl<<endl;

    //print every score
    for(int i = 0;i<sessions;i++){

        cout<<"Game "<<i<<" : "<<this->scores[i]<<endl;

    }

    cout<<endl<<"# --- -------------------#"<<endl<<endl;

};

