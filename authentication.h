#ifndef AUTHENTICATION_H_INCLUDED
#define AUTHENTICATION_H_INCLUDED

#include "headers/classes.h"

class Authentication{
    private:
        Person current_user;
    public:
        //set current user
        void SetCurrentUser(Person player){current_user = player;}

        //get current user
        Person GetCurrentUser(){return current_user;}

        //constructor
        Authentication();

        //desructor
        ~Authentication();

        // -- METHODS -- //
        bool CheckAuthentication(string username, string password);
};

#endif // AUTHENTICATION_H_INCLUDED
