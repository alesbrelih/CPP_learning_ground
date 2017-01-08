#ifndef CLASSES_H_INCLUDED
#define CLASSES_H_INCLUDED

#include <string>

using namespace std;

class Person{
    //privates
    private:
        int id;
        string name;
        string lastname;
        int age;
        string email;
        string username;
        string password;
        static int numberOfPersons;
    public:
        //----Properties Getters----- //
        int GetId(){return id;}
        string GetName(){return name;}
        string GetLastName(){return lastname;}
        string GetFullName(){ return name+" "+lastname;}
        int GetAge(){return age;}
        string GetEmail(){return email;}
        string GetUsername(){return username;}
        string GetPassword(){return password;}
        static int GetNumberOfPersons(){return numberOfPersons;}

        // ---- Properties Setters ---- //
        void SetId(int id){this->id = id;}
        void SetName(string name){this->name=name;}
        void SetLastName(string lastname){this->lastname=lastname;}
        void SetAge(int age){this->age=age;}
        void SetEmail(string email){this->email=email;}
        void SetUsername(string username){this->username=username;}
        void SetPassword(string password){this->password = password;}

        //define construcotrs
        Person();
        Person(int id,string name, string lastname, int age,string username,string password, string email);
        ~Person();

        //methods
        void Introduce();

        // set value of an object
        void SetValue(string prop, string value);


};

class PersonScore{
    private:
        string username;
        int score;
    public:
        //getters
        string GetUsername(){return username;}
        int GetScore(){return score;}

        //setters
        void SetUsername(string username){this -> username = username;}
        void SetScore(int score){this->score = score;}

        //constructor
        PersonScore();
        PersonScore(string username,int score);

        //destructor
        ~PersonScore();
};

#endif // CLASSES_H_INCLUDED
