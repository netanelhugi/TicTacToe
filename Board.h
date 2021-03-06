#pragma once
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

#include "IllegalCharException.h"
#include "IllegalCoordinateException.h"
#include "BoardIndex.h"
#include "BoardChar.h"
#include "RGB.h"

//TicTacToe board
class Board
{
	BoardChar **BoardMat; //num of rows&cols
	int boardSize;		  //matrix of BoardChar objects

  public:
	Board();
	Board(int n);			  //constructor
	~Board();				  //destructor
	int size() const;		  //get boardSize
	Board &operator=(char c); //Operator to fill the matrix
	char operator[](BoardIndex c) const;
	BoardChar operator[](BoardIndex c);
	char getBoardChar(int i, int j) const;
	void setSize(int n);
	string draw(int n); //draw the board
	void drawBorders(RGB **image, int n);
	void drawX(RGB **image, int n, int i, int j);
	void drawO(RGB **image, int n, int i, int j);

	//output operator
	friend ostream &operator<<(ostream &os, Board const &b);
	//input operator
	friend istream &operator>>(istream &input, Board &b);
	//== operator
	friend bool operator==(const Board &b, string s);
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

//Board input operator
/**
 *this operator get .txt file as input(./a.out < board3.txt)
 *count the number of signs in row, and create board
 *the function save the signs from the input in temp
 *and finally swap between temp and b(board object) 
 */
inline istream &operator>>(istream &input, Board &b)
{

	Board *temp;
	string str;

	char sign;
	int rowSize = 0;
	bool firstRowItr = true;

	while (input.get(sign))
	{

		if (sign == '\n')
		{
			firstRowItr = false;
		}
		else
		{
			str += sign;
		}

		if (firstRowItr)
		{
			rowSize++;
		}
	}

	temp = new Board(rowSize);
	int ind = 0;

	for (int i = 0; i < rowSize; i++)
	{
		for (int j = 0; j < rowSize; j++)
		{
			BoardChar bc(str[ind++]);

			temp->BoardMat[i][j] = bc;
		}
	}

	b = *temp;

	return input;
}

inline bool operator==(const Board &b, string s)
{

	string str = "";

	for (int i = 0; i < b.size(); i++)
	{
		for (int j = 0; j < b.size(); j++)
		{
			str += b.getBoardChar(i, j);
		}
	}

	int i = str.compare(s);

	return i;
}
