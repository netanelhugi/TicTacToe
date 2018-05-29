#pragma once
#include <iostream>
#include <fstream>
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
	Board();
	Board(int n);			  //constructor
	~Board();				  //destructor
	int size() const;		  //get boardSize
	Board &operator=(char c); //Operator to fill the matrix
	char operator[](BoardIndex c) const;
	BoardChar operator[](BoardIndex c);
	char getBoardChar(int i, int j) const;
	void setSize(int n);
	int INtest = -1;
	string draw(int n);


	//output operator
	friend ostream &operator<<(ostream &os, Board const &b);
	//input operator
	friend istream &operator>>(istream  &input, Board &b);

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


inline istream &operator>>(istream  &input, Board &b){

	Board* temp;
	string str;

	char sign;
	int rowSize = 0;
	bool firstRowItr = true;


	while(input.get(sign)){

		if(sign=='\n'){
			firstRowItr =false;
		}
		else{
			str += sign;		
		}

		if(firstRowItr){
			rowSize++;
		}
	}

	temp = new Board(rowSize);
	int ind = 0;

	for(int i=0; i<rowSize; i++){
		for(int j=0; j<rowSize; j++){
			BoardChar bc(str[ind++]);

			temp->BoardMat[i][j] = bc;


		}
	}

	b = *temp;

	return input;

}





