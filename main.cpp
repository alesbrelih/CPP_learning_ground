#include <iostream>
#include "headers/classes.h"
#include <string>
#include <vector>


using namespace std;

int main()
{
    //initialize list of persons
    vector<Person> persons;

    //create persons
    Person marjan; // no parentheses because else compiler thinks we are defining a function
    Person ales("Ales","Brelih",27,"krneki07@gmail.com");

    //number of persons
    cout<<"Number of persons: "<<Person::GetNumberOfPersons()<<". "<<endl;

    //add them to vector
    persons.push_back(marjan);
    persons.push_back(ales);

    cout<<"Vector size: "<<persons.size()<<endl;

    //introduce each
    //using unsigned because this iteration will always have positive iteration nubers
    for(unsigned int i = 0;i<persons.size();i++){
        persons[i].Introduce();
    }


    //marjan.Introduce();
    //ales.Introduce();
    return 0;
}
