#pragma once
#include <iostream>
using namespace std;

#include "IllegalCharException.h"
#include "IllegalCoordinateException.h"
#include "BoardIndex.h"
#include "BoardChar.h"

//TicTacToe board
class Board
{
	BoardChar **BoardMat; //num of rows&cols
	int boardSize;		  //matrix of BoardChar objects

  public:
	Board(int n);			  //constructor
	~Board();				  //destructor
	int size() const;		  //get boardSize
	Board &operator=(char c); //Operator to fill the matrix
	char operator[](BoardIndex c) const;
	BoardChar operator[](BoardIndex c);
	char getBoardChar(int i, int j) const;

	//output operator
	friend ostream &operator<<(ostream &os, Board const &b);
};

//Board output operator
inline ostream &operator<<(ostream &os, Board const &b)
{

	int n = b.size();

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			os << b.getBoardChar(i, j);
		}
		os << endl;
	}

	return os;
}