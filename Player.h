#pragma once

#include "Board.h"
#include "BoardIndex.h"
using Coordinate=BoardIndex;


class Player {
protected:
	char myChar;
public:

	void setChar(char c);
	char getChar() const;


	virtual const BoardIndex play(const Board& board) = 0; 
	virtual const string name() const = 0; 
};

