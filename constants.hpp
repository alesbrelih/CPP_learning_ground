#ifndef CONSTANTS_HPP_INCLUDED
#define CONSTANTS_HPP_INCLUDED

#include <string>

class Constants{
    public:
        static string GetDbConnection(){return "/home/ales/Databases/sqlite/spaceinvaders/spaceInvaders.db";}

        //playground sizing
        static int GetPlaygroundWidth(){return 10;}
        static int GetPlaygroundWidthForArray(){

            int playgroundWidth = GetPlaygroundWidth();
            return playgroundWidth-1;

        }
};


#endif // CONSTANTS_HPP_INCLUDED
