#include <iostream>
using namespace std;

#include "TicTacToe.h"


TicTacToe::TicTacToe(int n): gameBoard(n), Pwinner(nullptr) {
			this->size = n;
}

void TicTacToe::play(Player& pX, Player& pO) {
		gameBoard = '.';//init game board

		Pwinner = nullptr;
		pX.setChar('X');
		pO.setChar('O');
		
		for (int i=0; i<(size*size+1)/2; i++) {
			nextMove(pX, pO);//pX turn
			if(Pwinner!=0){
				break;
			} 
			nextMove(pO, pX);
			if(Pwinner!=0){//pO turn
				break;
			} 
		}
	}

const Board& TicTacToe::board() const { 
		return gameBoard; 
	}

const Player& TicTacToe::winner() const {
		return *Pwinner;
	}

void TicTacToe::nextMove(Player& p, Player& other){

		BoardIndex next;

		try {
			next = p.play(gameBoard);
		} 
		catch (...) {
			Pwinner = &other;
			return;
		}

		if (gameBoard[next]=='.') {
			gameBoard[next] = p.getChar();
		} 
		else {
			Pwinner = &other;
		}

		bool Cwin = checkWin(p.getChar(),next);

		if(Cwin){
			Pwinner = &p;
		}

		//for full board case
		//check who is the 'O' player
		bool OP;

		if(p.getChar()=='O'){
			OP = true;
		}
		else{
			OP = false;
		}

		if(fullBoard()!=0){
			if(OP==true){
				Pwinner = &p;
			}
			else{
				Pwinner = &other;
			}
		}
		
	}

bool TicTacToe::checkWin(char c,BoardIndex bi){

	if(checkRow(c,bi.i)){
		return true;
	}

	if(checkCol(c,bi.j)){
		return true;
	}

	if(checkDiag(c,bi.i,bi.j)){
			return true;
	}

	return false;
}

bool TicTacToe::checkRow(char c, int i){
	
	for(int j=0; j<gameBoard.size(); j++) {
			if(gameBoard[{i,j}]!=c)
				return false;
		}
	return true;
}

bool TicTacToe::checkCol(char c, int j){
	
	for(int i=0; i<gameBoard.size(); i++) {
			if(gameBoard[{i,j}]!=c)
				return false;
		}
	return true;
}

bool TicTacToe::checkDiag(char c,int i,int j){
    
    //this function check if there 4 in diagonal
    int counter = 1;
    
    for(int k=i-1,l=j+1;k>=0 && l<size;k--,l++) {
        //this loop count the num of the similar signs up and right from the point
            if(gameBoard[{k,l}]!=c){
                break;
            }
            counter++;
        }
        
    for(int k=i+1,l=j-1;k<size && l>=0;k++,l--) {
        //this loop count the num of the similar signs down and left from the point
			if(gameBoard[{k,l}]!=c){
                break;
            }
            counter++;
        }
        
        if(counter==size){
            return true;
        }
        
        counter = 1;
    
    for(int k=i-1,l=j-1;k>=0 && l>=0;k--,l--) { 
        //this loop count the num of the similar signs up and left from the point
            if(gameBoard[{k,l}]!=c){
                break;
            }
            counter++;
        }
        
    for(int k=i+1,l=j+1;k<size && l<size;k++,l++) {
        //this loop count the num of the similar signs down and right from the point
            if(gameBoard[{k,l}]!=c)
                break;
            counter++;
        }
        
        if(counter==size){
            return true;
        }
        
    return false;
    
    
}

bool TicTacToe::fullBoard(){

	bool full = false;

	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){

			BoardIndex bi{i,j};

			if(gameBoard[bi]=='.'){
				return false;
			}
		}
	}

	return true;

}

