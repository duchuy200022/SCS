#include <iostream>

using namespace std;

typedef struct Point {
	int x;
	int y;
}Point;

class Queue {
private:
	int rear, front, size;
	Point data[10000];
public:
	Queue() {
		rear = front = 0;
		size = 0;
		for (int i = 0; i < 10000; i++) {
			data[i].x = 0;
			data[i].y = 0;
		}
	}
	void reset();
	bool push(Point c);
	Point pop();
	bool isEmty();
	Point getFront();
	Point getRear();
};

void Queue::reset() {
	rear = front = 0;
	size = 0;
	for (int i = 0; i < 10000; i++) {
		data[i].x = 0;
		data[i].y = 0;
	}
}

bool Queue::push(Point c) {
	if (size < 10000) {
		data[rear].x = c.x;
		data[rear].y = c.y;
		rear++;
		size++;
		return true;
	}
	return false;
}

Point Queue::pop() {
	if (size > 0) {
		Point temp;
		temp.x = data[front].x;
		temp.y = data[front].y;
		for (int i = 0; i < size - 1; i++) {
			data[i] = data[i + 1];
		}
		rear--;
		size--;
		return temp;
	}
	else
	{
		cout << "Queue is empty";
	}
}

bool Queue::isEmty(){
	return size == 0;
}

Point Queue::getFront() {
	if (!isEmty()) {
		return data[front];
	}
	else
	{
		cout << "Queue is empty";
		return;
	}
}

Point Queue::getRear() {
	if (!isEmty()) {
		return data[rear];
	}
	else
	{
		cout << "Queue is empty";
		return;
	}
}

int board[100][100];
int KQ;
int size_row;
int size_col;
int dx[8] = { 1, -1, -2, -2, -1, 1, 2, 2 };
int dy[8] = { -2, -2, -1, 1, 2, 2, 1, -1 };
int so_dich_den;
Point cac_dich_den[5];
Point diem_bat_dau;
int visit_dich_den[5];

int map[100][100][3];
Queue cac_buoc_di;

bool checkSafe(Point c) {

}

void tim_cac_buoc_di() {
	for (int i = 0; i < so_dich_den; i++) {
		cac_buoc_di.reset();
		
	}
}

void back_track(int kq, int dem) {
	if (dem == so_dich_den) {
		if (kq < KQ) KQ = kq;
		return;
	}
	for (int i = 0; i < so_dich_den; i++) {
		if (visit_dich_den[i] == 0) {
			visit_dich_den[i] = 1;
			back_track(kq + map[cac_dich_den[i].x][cac_dich_den[i].y][i], dem+1)
		}
	}
}

int main() {
	freopen("text.txt", "r", stdin);
	int T;
	cin >> T;
	for (int testCase = 0; testCase < T; testCase++) {
		cin >> size_row >> size_col;
		so_dich_den = 0;
		for (int i = 0; i < size_row; i++) {
			for (int j = 0; j < size_col; j++) {
				cin >> board[i][j];
				if (board[i][j] == 3) {
					cac_dich_den[so_dich_den].x = i;
					cac_dich_den[so_dich_den].y = j;
					so_dich_den++;
				}
				else if (board[i][j] == 1) {
					diem_bat_dau.x = i;
					diem_bat_dau.y = j;
				}
			}
		}
	}
}
