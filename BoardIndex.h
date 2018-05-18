#pragma once

#include <iostream>
// #include "IllegalCharException.hpp"

using namespace std;

/**
 * class for index object
 * (int,int)
 */
class BoardIndex{
    
    public:
    int i;
    int j;
    //constructors
    BoardIndex();
    BoardIndex(int i0,int j0);
    BoardIndex(const BoardIndex& bi);//copy
    BoardIndex& operator=(const BoardIndex& other);
    
};

    //BoardIndex output operator
    inline ostream& operator << (ostream& os,BoardIndex b) {
        os << "{";
        os << b.i << "," <<b.j;
        os << "}";
        
        return os;
    }