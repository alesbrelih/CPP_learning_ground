#include "db_connect.h"
#include <iostream>

using namespace std;


Person GetUserFromStatement(sqlite3_stmt *statement){
    //returned person
    Person person;

    //get column count
    int columnCount = sqlite3_column_count(statement);


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

PersonScore GetHighScoreFromStatement(sqlite3_stmt *statement){

    //from SQL statement we KNOW its only 2 columns

    //declare needed vars
    string username;
    int score;

    //get vars
    score = sqlite3_column_int(statement,0);
    username = (char*)sqlite3_column_text(statement,1);

    //create new object and return it
    PersonScore highscore(username,score);

    return highscore;

}

int Db_Connect::GetNextId(string tablename){
    //1. get next id

    //sql string statement
    const string sqlStatement = "SELECT MAX(ID) FROM "+tablename+";";  //TODO: CHECK WHAT IF TABLE EMPTY
    sqlite3_stmt *statement;

    //prepare
    sqlite3_prepare(this->GetDb(),sqlStatement.c_str(),-1,&statement,NULL);

    //execute statement
    int statementResult = sqlite3_step(statement);

    if(statementResult == SQLITE_ROW){
        //get max id from returned values and increment it
        int maxId = sqlite3_column_int(statement,0);
        maxId++;

        //return maxid
        return maxId;
    }
    //error getting value from db
    return -1;

}
//constructor
Db_Connect::Db_Connect(string address){
    this->SetAddress(address);
};

//destructor
Db_Connect::~Db_Connect(){

    //discconnect from db
    sqlite3_close(this->GetDb());

    //cout<<"Db_Connect Destroyed!"<<endl;
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

    sqlite3_close(this->GetDb());
    //return players
    return players;
};

// ---- GET HIGH SCORES ---- //
vector<PersonScore> Db_Connect::GetHighScores(){

    const string sqlString = "SELECT SCORE.SCORE, PERSON.USERNAME"
                             " FROM SCORE JOIN PERSON ON SCORE.PERSONID = PERSON.ID"
                             " ORDER BY SCORE.SCORE DESC LIMIT 10;";

    //returned list initialization
    vector<PersonScore> highscores;

    //init sqlite3 statement
    sqlite3_stmt *statement;

    //prepare statement
    sqlite3_prepare(this->GetDb(),sqlString.c_str(),-1,&statement,NULL);

    //statement result
    int statementResult;

    //get data
    while(true){

        //get statement result
        statementResult = sqlite3_step(statement);

        if(statementResult == SQLITE_ROW){

            //get highscore
            PersonScore highscore = GetHighScoreFromStatement(statement);

            //add to vector
            highscores.push_back(highscore);

        }
        else{
            //break infinite loop
            break;
        }
    }
    //finalize
    sqlite3_finalize(statement);
    //close connection
    sqlite3_close(this->GetDb());
    return highscores;



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
        }
        //finalize
        sqlite3_finalize(sqliteStatement);
        //close db connection
        sqlite3_close(this->GetDb());
        return person;
    }
};

//check if username doesnt exist
bool Db_Connect::UsernameDoesntExist(string username){

    //sql statement, COLALTE NOCASE means undependant on lower or uppercase
    const string sqlStatement = "SELECT COUNT(*) FROM PERSON WHERE "
                                "USERNAME = '"+username+"' COLLATE NOCASE;";

    //sqlite binary statement
    sqlite3_stmt *statement;

    //define sql statement
    sqlite3_prepare(this->GetDb(),sqlStatement.c_str(),-1,&statement,NULL);

    //get statement values
    int statementResult = sqlite3_step(statement);



    //check if sqlite row
    if(statementResult == SQLITE_ROW){
        //check returned int
        int sqlResult = sqlite3_column_int(statement,0);
        //if 0 == no such username in db then return true
        if(sqlResult == 0){
            //finalize
            sqlite3_finalize(statement);

            sqlite3_close(this->GetDb());
            return true;
        }
    }

    //finalize
    sqlite3_finalize(statement);

    sqlite3_close(this->GetDb());
    //return false
    return false;



}

//register account
void Db_Connect::RegisterAccount(Person *user){

    //id for the new user
    int id = this->GetNextId("PERSON");
    string idStr = to_string(id);

    //get values
    string username = user->GetUsername();
    string password = user->GetPassword();

    //sql string statement
    const string sqlStatement = "INSERT INTO PERSON (ID,USERNAME,PASSWORD) VALUES ("+idStr+",'"+username+"','"+password+"');";

    //binary statement
    sqlite3_stmt *statement;

    //prepare statement
    sqlite3_prepare(this->GetDb(),sqlStatement.c_str(),-1,&statement,NULL);

    //step over statement
    int statementResult = sqlite3_step(statement);

    //check if valid
    if(statementResult == SQLITE_OK || statementResult == SQLITE_DONE){

        cout<<"Account successfuly created."<<endl;

    }
    else{

        cout<<"Account couldn't be created. Error connecting to DB. Please try later.";

    }

    //finalize
    sqlite3_finalize(statement);

    sqlite3_close(this->GetDb());



}
