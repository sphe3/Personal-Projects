#ifndef TICTACTOE_H_INCLUDED
#define TICTACTOE_H_INCLUDED
#include <iostream>

using namespace std;

#include "LibTicTacToe.h"

using namespace TicTacToeSpace;

class TicTacToe
{
public:
    //Constructors and Destructor
    TicTacToe();
    TicTacToe(const TicTacToe& obj);
    ~TicTacToe();

    //Getter and setter
    void setFeature(int intRow,int intCol,Feature);
    Feature getFeature(int intRow,int intCol) const;
    GAMESTATE getStatus() const;
    void setGameState(GAMESTATE eStatus);

    //Beahavior of the class:
    //Function to display the board
    void drawBoard();

    //Function to update the board
    void updateBoard(int intRow,int intCol,Feature efeature);

    //Function to check game state
    void checkBoard();


private:
    //Intance variables
    TwoD _board;

    //State of the game
    GAMESTATE _eStatus;

    //Utility Methods
    void allocateMemory();
    void clone(const TicTacToe& obj);
    void deallocateMemory();
};

#endif // TICTACTOE_H_INCLUDED
