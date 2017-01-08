#include "sqlite3.h"
#include <string>
#include "db_connect.h"
#include <iostream>
#include "headers/classes.h"
#include <vector>

using namespace std;


Person GetUserFromStatement(sqlite3_stmt *statement){
    //returned person
    Person person;
    //get column count

    int columnCount = sqlite3_column_count(statement);

    //console log column count
    //out<<"Column count: "<<columnCount<<endl;

    //for each column
    for(int i = 0; i<columnCount;i++){

        //check if row column has data
        if(sqlite3_column_type(statement,i) != SQLITE_NULL){

            //get value and column name
            string result = (char*)sqlite3_column_text(statement,i);
            string columnName = sqlite3_column_name(statement,i);


            //cout<<"Row Name : "<<i<<" - "<<columnName<<endl;
            //cout<<"Row result "<<i<<" - "<<result<<endl;

            //set current object value
            person.SetValue(columnName,result);


        }

    }

    return person;

}


//constructor
Db_Connect::Db_Connect(string address){
    this->SetAddress(address);
};

//destructor
Db_Connect::~Db_Connect(){

    //discconnect from db
    sqlite3_close(this->GetDb());

    cout<<"Db_Connect Destroyed!"<<endl;
};

//connect to db
bool Db_Connect::Connect(){

    //sets vars
    int connected;

    //gets address
    string address = this->GetAddress();

    //gets dbref
    sqlite3** dbRef = this->GetDbRef();

    //connect to db
    connected = sqlite3_open(address.c_str(),dbRef);

    //check if connected
    if(connected == SQLITE_OK){
        return true;
    }
    else{
        return false;
    }
};


// --- MANIPULATING / READING FROM DB ---- //

//GET PLAYERS FROM DB
vector<Person> Db_Connect::GetDbPersons(){


    //returned players
    vector<Person> players;

    //sql statement
    sqlite3_stmt *sqliteStatement;

    //each step result
    int stepResult;

    //get statement
    const string getStatement = "SELECT * FROM PERSON;";

    //prepare statement
    sqlite3_prepare(this->GetDb(),getStatement.c_str(),-1,&sqliteStatement,NULL);

    //read all rows
    while(true){

        //go to next step in bytes
        stepResult = sqlite3_step(sqliteStatement);

        //if returned is row
        if( stepResult == SQLITE_ROW){

            //ref to new person object
            Person newPerson = GetUserFromStatement(sqliteStatement);

            //add player to list of players
            players.push_back(newPerson);
        }
        //check if returned error or done with query
        else if(stepResult == SQLITE_DONE || stepResult == SQLITE_ERROR || stepResult == SQLITE_MISUSE){
            sqlite3_reset(sqliteStatement);
            break;
        }
        else{
            //break if anything else
            break;

        }

    }
    //finalize sqlite statement
    sqlite3_finalize(sqliteStatement);

    //return players
    return players;
};

// CHECK AUTHENTICATION
Person Db_Connect::CheckAuthentication(string username, string password){

    Person person;

    //check auth db string
    const string checkAuthString = "SELECT * FROM PERSON WHERE USERNAME = '"+username+"' AND PASSWORD = '"+password+"';";

    //sqlite statement with binary data
    sqlite3_stmt *sqliteStatement;

    //db result
    int dbResult;

    //prepare statement for db
    sqlite3_prepare(this->GetDb(),checkAuthString.c_str(),-1,&sqliteStatement,NULL);

    while(true){


        dbResult = sqlite3_step(sqliteStatement);

        if(dbResult == SQLITE_ROW){

            //get person data from statement
            person = GetUserFromStatement(sqliteStatement);

            return person;
        }
        else {
            return person;
        }
    }
};


