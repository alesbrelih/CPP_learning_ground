#include <iostream>
#include "headers/classes.h"
#include <string>
#include <vector>
#include <algorithm>
#include "sqlite3.h"
#include "db_connect.h"

//namespace
using namespace std;

//address for db
const string current_address = "/home/ales/Databases/sqlite/spaceinvaders/spaceInvaders.db";


//main fnc
int main()
{
    string userInput;

    //initialize list of persons
    vector<Person> players;

    //create persons
    Person marjan; // no parentheses because else compiler thinks we are defining a function
    Person ales(1,"Ales","Brelih",27,"ljiech","E7x0j225","krneki07@gmail.com");

    //number of persons
    cout<<"Number of persons: "<<Person::GetNumberOfPersons()<<". "<<endl;

    //add them to vector
    players.push_back(marjan);
    players.push_back(ales);

    cout<<"Vector size: "<<players.size()<<endl;

    //introduce each
    //using unsigned because this iteration
    //will always have positive iteration nubers
    for(unsigned int i = 0;i<players.size();i++){
        players[i].Introduce();
    }

    cout<<"Do you wish to create a new person? [y/n]"<<endl;
    cin>>userInput;

    //transform to lowercase
    transform(userInput.begin(), userInput.end(), userInput.begin(), ::tolower);

    //user chose to create a new person
    if(userInput == "y"){

        //declare variables
        string name, lastname,email;
        int age;

        //start the console app
        cout<<"User to be created"<<endl;

        //name
        cout<<"Please insert a name: "<<endl;
        cin>>name;

        //lastname
        cout<<"Please insert a lastname: "<<endl;
        cin>>lastname;

        //age
        cout<<"Please insert the age: "<<endl;
        cin>>age;

        //email
        cout<<"Please insert email: "<<endl;
        cin>>email;

        //confirmation
        cout<< "Is this data correct [y/n] ?: "<<endl<<name<<endl<<lastname<<endl<<age<<endl<<email<<endl;
        cin>>userInput;

        //transform input to lowercase
        transform(userInput.begin(), userInput.end(), userInput.begin(), ::tolower);

        //user wants to save data
        if(userInput == "y"){

            //create user
            Person newUser(1,name,lastname,age,"baka","babo",email);

            //add to vector
            players.push_back(newUser);

            //introduce new user
            newUser.Introduce();

            //check is user number static var was changed
            cout<<"Number of persons: "<<Person::GetNumberOfPersons()<<endl;

            //size of vector
            cout<<"Size of vector: "<<players.size()<<endl;
        }


    }

    //set db connection address
    Db_Connect spaceInvaderDb(current_address);

    //connects to db
    bool connectedToDb = spaceInvaderDb.Connect();

    if(connectedToDb){
        cout<<"Connected to db"<<endl;
        players = spaceInvaderDb.GetDbPersons();

        int players_count = players.size();
        for(int i = 0;i<players_count;i++){
            players[i].Introduce();
        }
    }


    //marjan.Introduce();
    //ales.Introduce();
    return 0;
}
