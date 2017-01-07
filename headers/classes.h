#ifndef CLASSES_H_INCLUDED
#define CLASSES_H_INCLUDED

#include <string>

using namespace std;

class Person{
    //privates
    private:
        string name;
        string lastname;
        int age;
        string email;
        static int numberOfPersons;
    public:
        //----Properties Getters----- //
        string GetName(){return name;}
        string GetLastName(){return lastname;}
        string GetFullName(){ return name+" "+lastname;}
        int GetAge(){return age;}
        string GetEmail(){return email;}
        static int GetNumberOfPersons(){return numberOfPersons;}

        // ---- Properties Setters ---- //
        void SetName(string name){this->name=name;}
        void SetLastName(string lastname){this->lastname=lastname;}
        void SetAge(int age){this->age=age;}
        void SetEmail(string email){this->email=email;}

        //define construcotrs
        Person();
        Person(string name, string lastname, int age, string email);
        ~Person();

        //methods
        void Introduce();


};

#endif // CLASSES_H_INCLUDED
