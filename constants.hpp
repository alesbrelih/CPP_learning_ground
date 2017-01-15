#ifndef CONSTANTS_HPP_INCLUDED
#define CONSTANTS_HPP_INCLUDED

#include <string>


class Constants{
    //privates
    private:
        const static int playgroundWidth = 20;
        const static int playgroundHeight = 10;
        const static int playgroundHeightWithContainer = playgroundHeight+2;
        const static int playgroundWidthWithContainer = playgroundWidth+2;
        const static int rowsOfAliens = 4;
        const static int numberOfAliensInRow = 10;
        constexpr static auto dbconnection = "/home/ales/Databases/sqlite/spaceinvaders/spaceInvaders.db";

        //microseconds for sleep
        const static int gamesleep = 50;
        const static int aliensleep = 800;
        const static int alienMissileSleep = 600;
        const static int shipSleep = 200;
        const static int shipMissilesSleep = 300;

        //chance to shoot for aliens
        const static int alienChanceToShoot = 2;

    //public access
    public:

        static string GetDbConnection(){return dbconnection;}

        //playground sizing

        //width
        static int GetPlaygroundWidth(){return playgroundWidth;}
        static int GetPlaygroundWidthForArray(){return playgroundWidthWithContainer-1;}
        static int GetPlaygroundWidthWithContainers(){return playgroundWidthWithContainer;}

        //height
        static int GetPlaygroundHeight(){return playgroundHeight;}
        static int GetPlaygroundHeightForArray(){return playgroundHeightWithContainer-1;}
        static int GetPlaygroundHeightWithContainers(){return playgroundHeightWithContainer;}

        //rows of aliens
        static int GetNumberOfRowsForAliens(){return rowsOfAliens;}
        static int GetNumberOfAliensInRow(){return numberOfAliensInRow;}

        //wait times
        static int GetGameSleep(){return gamesleep;}
        static int GetAlienSleep(){return aliensleep;}
        static int GetAlienMissileSleep(){return alienMissileSleep;}
        static int GetShipSleep(){return shipSleep;}
        static int GetShipMissilesSleep(){return shipMissilesSleep;}
        static int GetAlienChanceToShoot(){return alienChanceToShoot;}
};


#endif // CONSTANTS_HPP_INCLUDED
