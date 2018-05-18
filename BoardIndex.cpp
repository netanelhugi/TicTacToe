#include <iostream>
using namespace std;

#include "BoardIndex.h"

    //BoardIndex default constructor
    BoardIndex::BoardIndex(){ 
        this->i = 0;
        this->j = 0;
    }

    //BoardIndex constructor
    BoardIndex::BoardIndex(int i0,int j0){
        this->i = i0;
        this->j = j0;
    }

    //BoardIndex copy constructor
    BoardIndex::BoardIndex(const BoardIndex& other){
        i = other.i;
        j = other.j;
    }

    //= operator for copy constractor
    BoardIndex& BoardIndex::operator=(const BoardIndex& bi){
        i = bi.i;
        j = bi.j;

        return *this;
    }
    