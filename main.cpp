#include "TicTacToe.h"
#include <cctype>

int main()
{
    //Variables declaration
    //char playerOnePiece,playerTwoPiece = '/0';
    bool blnContinue = true;
    int currentPlayer = 1;
    int intRow , intCol,countMoves = 0;

    //Tic Tac Toe object
    TicTacToe objTicTacToe;
    objTicTacToe.setGameState(RUNNING);


    //Allowing the player to choose a piece
    /*cout<<"Player 1,choose which piece to play with (X / O) : ";
    //cin>>playerOnePiece;
    //playerOnePiece = toupper(playerOnePiece);

    //Assigning Player two
    if(playerOnePiece != 'X')
        playerTwoPiece = 'X';
    else
        playerTwoPiece = 'O';

    */

    //Drawing the initial board
    cout<<"Begin the game!!!"<<endl;
    objTicTacToe.drawBoard();
    cout<<"Player 1 you are: "<< 'X'<<endl;
    cout<<"Player 2 you are: "<< 'O'<<endl;
    cout<<endl;

    do{

        switch(currentPlayer)
        {
            case 1:
            {
                countMoves++;
                cout<<"Player One's Turn"<<endl;
                cout<<"Row(1, 2 or 3) : ";
                cin>>intRow;
                cout<<"Col(1, 2 or 3) : ";
                cin>>intCol;
                objTicTacToe.updateBoard(intRow,intCol,CROSS);
                objTicTacToe.drawBoard();
                if(countMoves > 4)
                    objTicTacToe.checkBoard();
                break;
            }

            case 2:
            {
                countMoves++;
                cout<<"Player Two's Turn"<<endl;
                cout<<"Row(1, 2 or 3) : ";
                cin>>intRow;
                cout<<"Col(1, 2 or 3) : ";
                cin>>intCol;
                objTicTacToe.updateBoard(intRow,intCol,DISK);
                objTicTacToe.drawBoard();
                if(countMoves > 4)
                    objTicTacToe.checkBoard();
                break;
            }

            case 0:
            {
                break;
            }
        }

        //Switch between the players
        if(currentPlayer == 1)
            currentPlayer = 2;
        else
            currentPlayer = 1;

        //Checking the game state
        if(objTicTacToe.getStatus() != RUNNING)
            blnContinue = false;

    }while(blnContinue);

    return 0;
}
