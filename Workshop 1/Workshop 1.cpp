#include <iostream>
#include <string>
using namespace std;

class Board {
private:
	char board[3][3];
	char playerToGo = 'x';
public:
	Board() {
		for (int x = 0; x < 3; x++) {
			for (int y = 0; y < 3; y++) {
				board[x][y] = ' ';
			}
		}
	}
	void Vissualize() {
		cout << endl;
		for (int x = 0; x < 3; x++) {
			for (int y = 0; y < 3; y++) {
				cout << board[x][y];
				if (y != 2) {
					cout << '|';
				}
				else {
					cout << ' ' << x + 1 << endl;
				}
			}
			if (x != 2) {
				cout << "-+-+-" << endl;
			}
			else {
				cout << "1 2 3" << endl << endl;
			}
		}
	}
	bool CheckPosition(int xCoord, int yCoord) {
		if ((xCoord <= 2 && xCoord >= 0) && (yCoord <= 2 && yCoord >= 0) && board[xCoord][yCoord] == ' ') {
			return true;
		}
		else {
			return false;
		}
	}
	void ChooseSquareToChange(int xCoord, int yCoord) {
		board[xCoord][yCoord] = playerToGo;
		if (playerToGo == 'x') {
			playerToGo = 'o';
		}
		else {
			playerToGo = 'x';
		}
	}
	bool CheckEnd() {
		for (int x = 0; x < 3; x++) {

		}
	}
};

int main() {
	Board currentBoard;
	bool endOfGame = true;
	char player = 'x';
	while (endOfGame) {
		currentBoard.Vissualize();
		int pos[2];
		cout << "Type in where you would like to go seperated by space or enter?\n";
		cin >> pos[0];
		cin >> pos[1];
		pos[0]--;
		pos[1]--;
		if (currentBoard.CheckPosition(pos[1], pos[0])) {
			currentBoard.ChooseSquareToChange(pos[1], pos[0]);
		}
		else {
			cout << "Incorrect Input / Taken" << endl;
		}
	}
}