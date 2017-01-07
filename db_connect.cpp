#include "sqlite3.h"
#include <string>
#include "db_connect.h"
#include <iostream>
#include "headers/classes.h"
#include <vector>

using namespace std;

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
            Person newPerson;

            //get column count
            int columnCount = sqlite3_column_count(sqliteStatement);

            //console log column count
            cout<<"Column count: "<<columnCount<<endl;

            //for each column
            for(int i = 0; i<columnCount;i++){

                //check if row column has data
                if(sqlite3_column_type(sqliteStatement,i) != SQLITE_NULL){

                    //get value and column name
                    string result = (char*)sqlite3_column_text(sqliteStatement,i);
                    string columnName = sqlite3_column_name(sqliteStatement,i);


                    //cout<<"Row Name : "<<i<<" - "<<columnName<<endl;
                    //cout<<"Row result "<<i<<" - "<<result<<endl;

                    //set current object value
                    newPerson.SetValue(columnName,result);


                }

            }

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
