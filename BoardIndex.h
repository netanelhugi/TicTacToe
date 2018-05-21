#pragma once
#include <iostream>
using namespace std;

/**-
 * class for index object
 * (int,int)
 */
class BoardIndex
{

  public:
    uint i;
    uint j;
    //constructors
    BoardIndex();//Default constructor
    BoardIndex(uint i0, uint j0);//constructor(uint type)
    BoardIndex(int i0, int j0);//constructor(int type)
    BoardIndex(const BoardIndex &bi); //copy constructor
    BoardIndex &operator=(const BoardIndex &other);//assignment operator for copy constructor
};

//BoardIndex output operator
inline ostream &operator<<(ostream &os, BoardIndex b)
{
    os << "{";
    os << b.i << "," << b.j;
    os << "}";

    return os;
}