#include <iostream>
using namespace std;

#include "Player.h"

void Player::setChar(char c){
    myChar = c;
}

char Player::getChar() const{ 
    return myChar; 
}

