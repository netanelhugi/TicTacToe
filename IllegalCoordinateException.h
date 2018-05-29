#include <iostream>
#include "BoardIndex.h"

using namespace std;

//coordinate exception
class IllegalCoordinateException{

    //the illegal coordinate
    BoardIndex ij;
    
    public:
    //constructor
    IllegalCoordinateException(BoardIndex b);
    //get the illegal coordinate
    BoardIndex theCoordinate() const;

};