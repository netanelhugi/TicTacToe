#include <iostream>
using namespace std;

#include "Board.h"

Board::Board(int n){
        boardSize = n;

        // create&allocat matrix of BoardChar's
        BoardMat = new BoardChar*[n];
        
        for(int i = 0; i < boardSize; i++){
            BoardMat[i] = new BoardChar[boardSize];
        }
	}

//destractor
    Board::~Board(){
        //free memory
        for(int i=0; i<boardSize;i++){
            delete[] boardMat[i];
        }
        delete[] boardMat;
    }

int Board::size() const {
		return boardSize;
	}

Board& Board::operator=(char c) {

    if(c!='.' && c!='O' && c!='X'){
		throw IllegalCharException{c}; 
    }
        
		for(int i=0; i<boardSize; ++i) {
            for(int j=0; j<boardSize; j++){
                	BoardMat[i][j] = '.';
        }

		}
		return *this;
	}

char Board::operator[] (BoardIndex c) const {
		if (c.i>=boardSize || c.j>=boardSize)
			throw IllegalCoordinateException{c};
		return BoardMat[c.i][c.j];
	}

BoardChar Board::operator[] (BoardIndex c) {
		if (c.i>=boardSize || c.j>=boardSize)
			throw IllegalCoordinateException{c};
		return BoardMat[c.i][c.j];
	}

char Board::getBoardChar(int i,int j) const{
    return BoardMat[i][j];
}
