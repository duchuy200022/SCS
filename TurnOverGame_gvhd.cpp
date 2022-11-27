#include <iostream>

using namespace std;

int sizeBoard;
char board[5][5];
int KQ = 0;

bool checkSafe(int row, int col) {
	if (board[row][col] == 'X')	return false;
	for (int i = row - 1; row >= 0; row--) {
		if (board[i][col] == 'X')	break;
		else if (board[row][col] == '+')	return false;
	}
	for (int i = col - 1; col >= 0; col--) {
		if (board[row][i] == 'X')	break;
		else if (board[row][i] == '+')	return false;
	}

	return true;
}

void back_track(int pos, int kq) {
	if (pos == sizeBoard * sizeBoard) {
		if (kq > KQ)	KQ = kq;
		return;
	}
	else {
		int row = pos / sizeBoard;
		int col = pos % sizeBoard;
		for (int i = 0; i < 2; i++) {
			if (i == 0) {
				back_track(pos + 1, kq);
			}
			else {
				if (checkSafe(row, col)) {
					board[row][col] = '+';
					back_track(pos + 1, kq + 1);
					board[row][col] = '.';
				}
			}
		}
	}
}
int main() {
	int T;
	cin >> T;
	for (int testCase = 0; testCase < T; testCase++) {
		cin >> sizeBoard;
		for (int i = 0; i < sizeBoard; i++) {
			cin >> board[i];
		}
		KQ = 0;
		back_track(0, 0);
	}
	return 0;
}
