#include <iostream>
using namespace std;

#include "IllegalCharException.h"

    //constructor, set c be the illegal char
    IllegalCharException::IllegalCharException(const char c){
        argu = c;
    }

    //retrun the illegal char
    char IllegalCharException::theChar() const{
        return argu;
    }