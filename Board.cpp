#include <iostream>
using namespace std;

#include "Board.h"

//constructor, get int(size of the board)
Board::Board(int n)
{

    boardSize = n;

    // create&allocat matrix of BoardChar's
    BoardMat = new BoardChar *[n];

    for (int i = 0; i < boardSize; i++)
    {
        BoardMat[i] = new BoardChar[boardSize];
    }
}

// //destractor
Board::~Board()
{
    //free memory
    for (int i = 0; i < boardSize; i++)
    {
        delete[] BoardMat[i];
    }
    delete[] BoardMat;
}

//getSize
int Board::size() const
{
    return boardSize;
}

//fill the board with some char
Board &Board::operator=(char c)
{

    if (c != '.' && c != 'O' && c != 'X')
    {
        throw IllegalCharException{c};
    }

    for (int i = 0; i < boardSize; ++i)
    {
        for (int j = 0; j < boardSize; j++)
        {
            BoardMat[i][j] = '.';
        }
    }
    return *this;
}

//get char place from the matrix
char Board::operator[](BoardIndex c) const
{
    if (c.i >= boardSize || c.j >= boardSize)
        throw IllegalCoordinateException{c};
    return BoardMat[c.i][c.j];
}

//get BoardChar place from the matrix
BoardChar Board::operator[](BoardIndex c)
{
    if (c.i >= boardSize || c.j >= boardSize)
        throw IllegalCoordinateException{c};
    return BoardMat[c.i][c.j];
}

//get char in loction
char Board::getBoardChar(int i, int j) const
{
    return BoardMat[i][j];
}
