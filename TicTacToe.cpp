#include "TicTacToe.h"

//Constructors and Destructor
TicTacToe::TicTacToe()
{
    allocateMemory();
}

TicTacToe::TicTacToe(const TicTacToe& obj)
{
    allocateMemory();
    clone(obj);
}

TicTacToe::~TicTacToe()
{
    deallocateMemory();
}


//Beahavior of the class:
//Function to display the board
void TicTacToe::drawBoard()
{
    cout<<"-------------"<<endl;
    for(int r = 0; r < NUMROWS ; r++)
    {
        cout<<"|"<<' ';
        for(int c = 0; c < NUMCOLS ; c++)
        {
            cout<<GAMEFEATURES[_board[r][c].eFeature]<<' '<<"|"<<' ';
        }
        cout<<endl;
        cout<<"-------------"<<endl;
    }
}

//Function to update the board
void TicTacToe::updateBoard(int intRow,int intCol,Feature efeature)
{
    if(_board[intRow - 1][intCol - 1].isEmpty){
        setFeature(intRow - 1,intCol - 1,efeature);
        _board[intRow - 1][intCol - 1].isEmpty = false;
    }
    else
        _eStatus = ERRORPLAY;
}

//Function to check game state
void TicTacToe::checkBoard()
{
    //Check horizontally
    for(int r = 0; r < NUMROWS ; r++)
    {
        if(!(_board[r][1].isEmpty)){
            if((_board[r][1].eFeature == _board[r][0].eFeature) && (_board[r][1].eFeature == _board[r][2].eFeature))
            {
                _eStatus = WON;
            }
        }
    }

    //Check vertically
    for(int c = 0; c < NUMCOLS ; c++)
    {
        if(!(_board[1][c].isEmpty)){
            if((_board[1][c].eFeature == _board[c][0].eFeature) && (_board[1][c].eFeature == _board[2][c].eFeature))
            {
                _eStatus = WON;
            }
        }
    }

    //Check Diagonally
    if(!(_board[1][1].isEmpty)){
        if((_board[1][1].eFeature == _board[0][2].eFeature) && (_board[1][1].eFeature == _board[2][0].eFeature))
        {
            _eStatus = WON;
        }

        if((_board[1][1].eFeature == _board[0][0].eFeature) && (_board[1][1].eFeature == _board[2][2].eFeature))
        {
            _eStatus = WON;
        }
    }
}

//Getters and setters
Feature TicTacToe::getFeature(int intRow,int intCol) const
{
    return _board[intRow][intCol].eFeature;
}

void TicTacToe::setFeature(int intRow,int intCol,Feature feature)
{
    _board[intRow][intCol].eFeature = feature;
}

GAMESTATE TicTacToe::getStatus() const
{
    return _eStatus;
}

void TicTacToe::setGameState(GAMESTATE eStatus)
{
    _eStatus = eStatus;
}

//Utility Methods
void TicTacToe::allocateMemory()
{
    _board = new OneD[NUMROWS];
    for(int r = 0; r < NUMROWS ; r++)
    {
        _board[r] = new Cell[NUMCOLS];
        for(int c = 0; c < NUMCOLS ; c++)
        {
            _board[r][c].eFeature = SPACE;
        }
    }
}

void TicTacToe::clone(const TicTacToe& obj)
{
    for(int r = 0; r < NUMROWS ; r++)
    {
        _board[r] = new Cell[NUMCOLS];
        for(int c = 0; c < NUMCOLS ; c++)
        {
            _board[r][c].eFeature = obj.getFeature(r,c);
        }
    }
}

void TicTacToe::deallocateMemory()
{
    for(int r = 0; r < NUMROWS ; r++)
        delete[] _board[r];
    delete[] _board;
}
