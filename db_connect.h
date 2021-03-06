#ifndef DB_CONNECT_H_INCLUDED
#define DB_CONNECT_H_INCLUDED

#include <string>
#include "sqlite3.h"
#include <vector>
#include "headers/classes.h"

using namespace std;

class Db_Connect{

    //privates
    private:
        string address;
        sqlite3 *db;

    //public methods
    public:

        //setter / getter for address for sqlite
        void SetAddress(string address){ this->address = address;}
        string GetAddress(){return this->address;}

        //get db ref
        sqlite3** GetDbRef(){ return &db;}
        sqlite3* GetDb() {return db;}

        //reset db
        void ResetDb(){db = NULL;}

        //constructor
        Db_Connect(string address);

        //destructor
        ~Db_Connect();

        //connect to db
        bool Connect();

        //disconnect
        void Disconnect();


        // ---- MANIPULATING DB ----- //

        //get next id
        int GetNextId(string tablename);

        //get all person
        vector<Person> GetDbPersons();

        //check if valid authentication
        Person CheckAuthentication(string username, string password);

        //get high scores
        vector<PersonScore> GetHighScores();

        //check if username doesnt exists alredy
        bool UsernameDoesntExist(string username);

        //register Account
        void RegisterAccount(Person *user);

        //edit Profile
        void EditProfile(int id, string name, string lastname, string email, int age);

        //get profile info
        Person GetProfile(int id);
};


#endif // DB_CONNECT_H_INCLUDED
