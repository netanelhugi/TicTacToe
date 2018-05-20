#pragma once
#include <iostream>
using namespace std;

//Represents char object of the TicTacToe board
class BoardChar {

	//reference to char
	char& sign;

	public:
		char de = '.';//Default char
		BoardChar(char& c);//constructor with char reference
		BoardChar():sign(de){}//default constructor
		BoardChar& operator=(char c);//assignment operator(for char)
		operator char() const;//cast "toChar" operator
    	BoardChar& operator=(const BoardChar& bc);//assignment operator(for BoardChar)
		char getChar();
		void setChar(char c);

		//Comparison operator
	    friend bool operator == (const BoardChar bc, const char c);

};


//BoardChar output operator
    inline ostream& operator << (ostream& os,BoardChar bc) { 
        return os << bc.getChar();
    }