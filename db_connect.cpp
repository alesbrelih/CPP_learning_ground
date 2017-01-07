#include "sqlite3.h"
#include <string>
#include "db_connect.h"
#include <iostream>

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
    string address = this->GetAddress();

    //connect to db
    connected = sqlite3_open(address.c_str(),this->GetDbRef());
    if(connected){
        return true;
    }
    else{
        return false;
    }
};
