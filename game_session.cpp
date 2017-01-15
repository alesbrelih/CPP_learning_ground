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
    vector<int> scores = this->GetScores();
    scores.push_back(score);

};

//save score to database
void Game_Session::SaveScore(int score){

    //TODO: SAVE SCORE TO DB

};

//starts new game
void Game_Session::NewGame(){

    Game *game = new Game();
    game->GameStart();

}

