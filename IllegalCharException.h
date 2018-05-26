#pragma once

#include <iostream>
#include <exception>
#include <sstream>

using namespace std;

//char exception
class IllegalCharException{

    //the illegal char
    char argu;
    
    public:
    //constructor
    IllegalCharException(const char c);
    //get the illegal char
    char theChar() const;

};