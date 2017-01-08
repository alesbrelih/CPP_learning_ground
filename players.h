#ifndef PLAYERS_H_INCLUDED
#define PLAYERS_H_INCLUDED

#include <vector>
#include "headers/classes.h"

using namespace std;

class Players{
    private:
        vector<Person> players_list;
    public:
        //get
        vector<Person> GetPlayers(){return players_list;}

        //set
        void SetPlayers(vector<Person> players){players_list = players;}

        //constructor
        Players();

        //destructor
        ~Players();

        // -- methods -- //
        void RefreshPlayers();

};

#endif // PLAYERS_H_INCLUDED
