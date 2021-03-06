#include "Board.h"

#include <iostream>
#include <string>
using namespace std;


#include "TicTacToe.h"
#include "DummyPlayers.h"

#include "Champion.h"

void printResults(const TicTacToe& game) {
	cout << endl << "The final board is " << endl << game.board();
	cout << "And the winner is " << game.winner().name() 
	     << ", playing as " << game.winner().getChar() << "!" << endl;
}

void playAndPrintResults(TicTacToe& game, Player& xPlayer, Player& oPlayer) {
	game.play(xPlayer, oPlayer);
	printResults(game);
}

void playAndPrintWinner(TicTacToe& game, Player& xPlayer, Player& oPlayer) {
	game.play(xPlayer, oPlayer);
	cout << "The winner is " << game.winner().name() 
	     << ", playing as " << game.winner().getChar() << "!" << endl;
}


int main() {
	// Assignment 6 main:
	Board board1{4};  // Initializes a 4x4 board
	cout << board1 << endl;   /* Shows an empty board:
	....
	....
	....
	....
	*/
	cout << board1[{1,2}] << endl; // .
	board1[{1,1}]='X';
	board1[{1,2}]='O';
	char c = board1[{1,2}]; cout << c << endl; // O
	cout << board1 << endl;  /* Shows the following board:
	....
	.XO.
	....
	....
	*/

	try {
		board1[{3,4}]='O';   // This should raise an exception
	} catch (const IllegalCoordinateException& ex) {
		cout << "Illegal coordinate: " << ex.theCoordinate() << endl;  // prints "Illegal coordinate: 3,4"
	}

	board1 = '.';     // Fill the entire board with "."
	cout << board1 << endl;  /* Shows an empty board, as above */
	try { 
		board1 = 'a';        // This should raise an exception
	} catch (const IllegalCharException& ex) {
		cout << "Illegal char: " << ex.theChar() << endl;  // "Illegal char: a"
	}

	try {
		board1[{0,1}] = 'x';  // This should raise an exception
	} catch (const IllegalCharException& ex) {
		cout << "Illegal char: " << ex.theChar() << endl;  // "Illegal char: x"
	}

	Board board2 = board1;
	board2[{0,0}] = 'X';
	cout << board1 << endl;  /* Shows an empty board, as above */
	cout << board2 << endl;  /* Shows a board with an X at top-left */

	board1 = board2;
	board1[{3,3}] = 'O';
	cout << board2 << endl;  /* Shows a board with an X at top-left */
	cout << board1 << endl;  /* Shows a board with an X at top-left and O at bottom-right */

	cout << "Good bye!" << endl;


	// Assignment 7 main:
	TicTacToe game(4);       // Initializes a game on a 4x4 board
	XYPlayer player1;
	YXPlayer player2;
	IllegalPlayer player3;
	ExceptionPlayer player4;

	playAndPrintResults(game, player1, player2);
	/*
		The final board is 
		XXXX
		O...
		O...
		O...
    	And the winner is XYPlayer, playing as X!
	*/

	playAndPrintResults(game, player2, player1);  
	/*
		The final board is 
		XOOO
		X...
		X...
		X...
        And the winner is YXPlayer, playing as X!
	*/

	playAndPrintResults(game, player1, player3);  
	/*
		The final board is 
		X...
		....
		....
		....
        And the winner is XYPlayer, playing as X!
	*/


	playAndPrintResults(game, player3, player1);  
	/*
		The final board is 
		XO..
		....
		....
		....
        And the winner is XYPlayer, playing as O!
	*/

	playAndPrintResults(game, player2, player4);  
	/*
		The final board is 
		X...
		....
		....
		....
		And the winner is YXPlayer, playing as X!
	*/

	playAndPrintResults(game, player4, player2);  
	/*
		The final board is 
		....
		....
		....
		....
		And the winner is YXPlayer, playing as O!
	*/


	Champion champion;
	playAndPrintWinner(game, champion, player1);
		// The winner is <your name>, playing as X!
	playAndPrintWinner(game, player1, champion);
		// The winner is <your name>, playing as O!
	playAndPrintWinner(game, champion, player2);
		// The winner is <your name>, playing as X!
	playAndPrintWinner(game, player2, champion);
		// The winner is <your name>, playing as O!
	playAndPrintWinner(game, champion, player3);
		// The winner is <your name>, playing as X!
	playAndPrintWinner(game, player3, champion);
		// The winner is <your name>, playing as O!
	playAndPrintWinner(game, champion, player4);
		// The winner is <your name>, playing as X!
	playAndPrintWinner(game, player4, champion);
		// The winner is <your name>, playing as O!

	Board board;
	cin >> board;
	string filename = board.draw(600);
	cout << filename << endl;

	return 0;

}




