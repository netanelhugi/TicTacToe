#include "Board.h"

#include <iostream>
#include <string>
using namespace std;

int main(int argc , char *argv[]) { 
	Board board;
	cin >> board;
	cout << board << endl;
	string filename = board.draw(600);
	cout << filename << endl;
}

