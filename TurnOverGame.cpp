#include <iostream>
#define MAX	5

using namespace std;
char board[MAX][MAX];
int visit[16];
int KQ;
int d_row[4] = { 1, -1, 0, 0 };
int d_col[4] = { 0, 0, 1, -1 };

bool checkEnd() {
	if (board[0][0] == 'w') {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (board[i][j] == 'b')	return false;
			}
		}
	}
	else {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (board[i][j] == 'w')	return false;
			}
		}
	}
	return true;
}

void thay_doi_quan_co(int row, int col) {
	if (board[row][col] == 'w')	board[row][col] = 'b';
	else
	{
		board[row][col] = 'w';
	}
	return;
}

void thay_doi_ban_co(int i) {
	int row = i / 4;
	int col = i % 4;
	thay_doi_quan_co(row, col);
	for (int i = 0; i < 4; i++) {
		int row1 = row + d_row[i];
		int col1 = col + d_col[i];
		if (row1 < 4 && row1 >= 0 && col1 < 4 && col1 >= 0)	thay_doi_quan_co(row1, col1);
	}
}

void back_track(int kq) {
	if (checkEnd() == true) {
		if (kq < KQ)	KQ = kq;
		return;
	}
	for (int i = 0; i < 16; i++) {
		if (visit[i] == 0) {
			visit[i] = 1;
			char temp_board[4][4];
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					temp_board[i][j] = board[i][j];
				}
			}
			thay_doi_ban_co(i);
			back_track(kq + 1);
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					board[i][j] = temp_board[i][j];
				}
			}
			visit[i] = 0;
		}
	}
}

int main() {
	freopen("text.txt", "r", stdin);
	int T;
	cin >> T;
	for (int testCase = 0; testCase < T; testCase++) {
		for (int i = 0; i < 4; i++) {
			cin >> board[i];
		}
		KQ = 17;
		back_track(0);
		if (KQ == 17)	cout << "impossible" << endl;
		else
		{
			cout << "Case #"<<testCase+1<< " "<< KQ << endl;
		}
	}
	return 0;
}
