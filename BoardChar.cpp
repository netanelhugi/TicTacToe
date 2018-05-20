#include <iostream>
using namespace std;

#include "BoardChar.h"
#include "IllegalCharException.h"

//constructor with char reference
BoardChar::BoardChar(char& c):sign(c){
	/*constructor*/
}

//assignment operator(for char)
BoardChar& BoardChar::operator=(char c) {
			
		if (c!='.' && c!='X' && c!='O'){
			throw IllegalCharException(c);
		}
		sign = c;
		return *this;
}

//cast "toChar" operator
BoardChar::operator char() const { 
    return sign; 
}

char BoardChar::getChar(){
    return sign;
}

void BoardChar::setChar(char c){
    sign = c;
}


    //boardChar=boardChar operator
    BoardChar& BoardChar::operator=(const BoardChar& bc){
        sign = bc.sign;
    
        return *this;
    }

    //compare operator, boardChar==char
    bool operator==(const BoardChar bc , const char c){
        return bc.sign == c;
    } 

