
#include <iostream>
#include "headers/classes.h"

using namespace std;



//define Person class
int Person::numberOfPersons = 0;

// ---- constructors ---- //
Person::Person(){

    cout<<"inside default constructor"<<endl;

    this->name = "undefined";
    this->lastname = "undefined";
    this->age = -1;
    this->email = "undefined";

    //increase number of persons created
    Person::numberOfPersons++;

};

//constructor with data
Person::Person(string name, string lastname, int age, string email):Person::Person(){
    this->name = name;
    this->lastname = lastname;
    this->age = age;
    this->email = email;
};

//destructor
Person::~Person(){
    cout<<this->GetFullName()<<" Destroyed!"<<endl;
};

// methods
void Person::Introduce(){
    cout<<"I am "<<this->GetFullName()<<" and I am "<<this->GetAge()<<" years old! "<<endl;
};





