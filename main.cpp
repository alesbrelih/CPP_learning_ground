#include <iostream>
#include "headers/classes.h"
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

int main()
{
    string userInput;

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
    //using unsigned because this iteration
    //will always have positive iteration nubers
    for(unsigned int i = 0;i<persons.size();i++){
        persons[i].Introduce();
    }

    cout<<"Do you wish to create a new person? [y/n]"<<endl;
    cin>>userInput;
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
            Person newUser(name,lastname,age,email);

            //add to vector
            persons.push_back(newUser);

            //introduce new user
            newUser.Introduce();

            //check is user number static var was changed
            cout<<"Number of persons: "<<Person::GetNumberOfPersons()<<endl;

            //size of vector
            cout<<"Size of vector: "<<persons.size()<<endl;
        }


    }


    //marjan.Introduce();
    //ales.Introduce();
    return 0;
}
