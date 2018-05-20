#pragma once
#include <iostream>
using namespace std;
#include "Player.h"
#include "BoardIndex.h"

class Champion: public Player {
	public:
	BoardIndex lastPlace;
	int i0,j0;

	const string name() const override {
		return "Netanel Hugi";
	}
	const Coordinate play(const Board& board) override {

		int n = board.size();


		if(this->getChar()=='X'){

			for(int i=0,j=0; i<n; i++,j++){
					Coordinate c{i,j};
					
					if (board[c]=='.') {
						return c;
					}
			}
					
	
		}

		else{


			Coordinate c1{0,n-1};
			Coordinate c2{n-1,0};


			if(board[c1]=='.'){
				return c1;
			}

			else if(board[c2]=='.'){
				return c2;
			}

			else{
				for(int j=0; j<n; j++){
					
					Coordinate cj{j,n-1};

					if(board[cj]=='.'){
						return cj;
					}

				}
			}

		}


	return {0,0};  // did not find an empty square - play on the top-left
}	
};

