#include <iostream>
using namespace std;

#include "IllegalCoordinateException.h"

//constructor, set the illegal coordinate
IllegalCoordinateException::IllegalCoordinateException(BoardIndex b){
        this->ij = b;
}

//return the illegal coordinate
BoardIndex IllegalCoordinateException::theCoordinate() const{
        return this->ij;
}