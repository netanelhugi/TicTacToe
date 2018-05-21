#pragma once
#include <iostream>
using namespace std;

#include "Board.h"
#include "Player.h"
#include "BoardIndex.h"


class TicTacToe {

	Board gameBoard;//TicTacToe board
	int size;//size of row/col
	Player* Pwinner;//pointer to the winner

	public:
	TicTacToe(int n);//constructor
	void play(Player& pX, Player& pO);
	const Board& board() const;//get the board
	const Player& winner() const;//get the winner
	void nextMove(Player& p, Player& other);//do the next step
	
	bool checkWin(char c, BoardIndex bi);//check if the game over
	bool checkRow(char c, int i);//check if row is full
	bool checkCol(char c, int j);//check if col is full
	bool checkDiag(char c,int i,int j);//check if diagonal is full
	bool fullBoard();////check if the board is full



};
