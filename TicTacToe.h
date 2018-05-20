#pragma once
#include <iostream>
using namespace std;

#include "Board.h"
#include "Player.h"
#include "BoardIndex.h"


class TicTacToe {
	Board gameBoard;
	int size;
	Player* Pwinner;

	public:
	TicTacToe(int n);
	void play(Player& pX, Player& pO);
	const Board& board() const;
	const Player& winner() const;
	void nextMove(Player& p, Player& other);
	bool checkWin(char c, BoardIndex bi);
	bool checkRow(char c, int i);
	bool checkCol(char c, int j);
	bool checkDiag(char c,int i,int j);
	bool fullBoard();



};
