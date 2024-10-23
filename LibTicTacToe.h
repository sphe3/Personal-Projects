#ifndef LIBTICTACTOE_H_INCLUDED
#define LIBTICTACTOE_H_INCLUDED

namespace TicTacToeSpace
{
    //Enum for game status
    enum GAMESTATE
    {
        RUNNING,
        DRAW,
        WON,
        QUIT,
        ERRORPLAY
    };

    //enum for game features
    enum Feature
    {
        SPACE,
        CROSS,
        DISK
    };

    //Struct for the game cell
    struct Cell
    {
        Feature eFeature;
        bool isEmpty = true;
    };

    //Game represation of features
    const char GAMEFEATURES[3] = {' ','X','O'};

    //Defining an array for the game
    typedef Cell* OneD;
    typedef OneD* TwoD;

    //Number of rows and cols
    static const int NUMROWS = 3;
    static const int NUMCOLS = 3;
}


#endif // LIBTICTACTOE_H_INCLUDED
