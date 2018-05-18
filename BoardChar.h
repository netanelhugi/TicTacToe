#pragma once
#include <iostream>
using namespace std;


class BoardChar {

	char& sign;

	public:
		char de = '.';
		BoardChar(char& c);
		BoardChar():sign(de){}
		BoardChar& operator=(char c);
		operator char() const;
    	BoardChar& operator=(const BoardChar& bc);
		char getChar();
		void setChar(char c);

	
	    friend bool operator == (const BoardChar bc, const char c);

};


//BoardChar output operator
    inline ostream& operator << (ostream& os,BoardChar bc) { 
        return os << bc.getChar();
    }