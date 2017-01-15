#ifndef SI_BASE_H_INCLUDED
#define SI_BASE_H_INCLUDED

//SPACE INVADER BASE CLASS

//include input output for console
#include <iostream>
#include <vector>
#include <memory>

using namespace std;

//alien direction enum
enum AlienDirection{
    Left,
    Right
};

//space invader base class
class SI_base{

    //privates
    private:
        signed int x;
        signed int y;



    //publics
    public:

        // --- getters --- //
        //x
        signed int GetX(){return this->x;}

        //y
        signed int GetY(){return this->y;}


        // --------------- //

        // --- setters --- //
        //x
        void SetX(signed int x){
            this->x = x;
        }
        //y
        void SetY(signed int y){
            this->y = y;
        }
        // --------------- //

        // --- Constructor --- //
        SI_base(signed int x, signed int y);

        // --- Destructor --- //
        ~SI_base();

};


#endif // SI_BASE_H_INCLUDED
