#include <iostream>
#include "headers/classes.h"
#include <string>


using namespace std;

int main()
{
    Person marjan;
    Person ales("Ales","Brelih",27,"krneki07@gmail.com");
    cout<<"Number of persons: "<<Person::GetNumberOfPersons()<<". "<<endl;
    marjan.Introduce();
    ales.Introduce();
    return 0;
}
