
#include <iostream>
#include "headers/classes.h"
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//enum - person props
enum PersonProp {Id,Name,Lastname,Age,Email,Username,Password};
vector<string> personPropStr = {"ID","NAME","LASTNAME","AGE","EMAIL","USERNAME","PASSWORD"};



//define Person class
int Person::numberOfPersons = 0;

// ---- constructors ---- //
Person::Person(){
    this->id = -1;
    this->name = "undefined";
    this->lastname = "undefined";
    this->age = -1;
    this->email = "undefined";
    this->username="undefined";
    this->password = "undefined";

    //increase number of persons created
    Person::numberOfPersons++;

};

//constructor with data
Person::Person(int id, string name, string lastname, int age,string username,string password, string email):Person::Person(){
    this->id = id;
    this->name = name;
    this->lastname = lastname;
    this->age = age;
    this->email = email;
    this->username = username;
    this->password = password;
};

//destructor
Person::~Person(){
    //cout<<this->GetFullName()<<" Destroyed!"<<endl;
};

// methods
void Person::Introduce(){
    cout<<"I am "<<this->GetFullName()<<" and I am "<<this->GetAge()<<" years old! "<<endl;

};

// sets property
// prop is property name
// value is property value
void Person::SetValue(string prop, string value){

    //get index from helper vector
    std::vector<string>::iterator it = find(personPropStr.begin(),personPropStr.end(),prop);

    int index = it-personPropStr.begin();

    //set appropriate enum value
    PersonProp property = PersonProp(index);

    //set object value based on value recieved
    switch(property){

        //Set id
        case Id:
        {
            int id = atoi(value.c_str()); //convert to int
            this->SetId(id);
            break;
        }

        //set name
        case Name:
        {
            this->SetName(value);
            break;
        }
        //set lastname
        case Lastname:
        {
            this->SetLastName(value);
            break;
        }
        //set age
        case Age:
        {
            int age = atoi(value.c_str()); //convert to int
            this->SetAge(age);
            break;
        }
        //set username
        case Username:
        {
            this->SetUsername(value);
            break;
        }
        //set password
        case Password:
        {
            this->SetPassword(value);
            break;
        }
        //set email
        case Email:
        {
            this->SetEmail(value);
            break;
        }
        //default
        default:
            break;

    }
}





