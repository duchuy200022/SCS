#include <iostream>

using namespace std;

typedef struct Point {
	int x;
	int y;
};

class Queue {
private:
	int rear, front;
	Point data[10005];
public:
	void reset();
	bool isEmpty();
	Point pop();
	void push(Point c);
	Queue() {
		rear = -1;
		front = -1;
	}
};

void Queue::reset() {
	rear = -1;
	front = -1;
}
bool Queue::isEmpty() {
	return rear == front;
}
Point Queue::pop() {
	front++;
	return data[front];
}
void Queue::push(Point c) {
	rear++;
	data[rear] = c;
	return;
}

int size_map;
int map[101][101];
int visit[101][101];
Queue step;
int d_row[4] = { 0, 0, -1, 1 };
int d_col[4] = { 1, -1, 0, 0 };
int max_map;

bool checkSafe(Point c) {
	if (c.x >= 0 && c.x < size_map && c.y >= 0 && c.y < size_map)	return true;
	return false;
}

bool BFS(int low, int high) {
	if (map[0][0] > high || map[0][0] < low)	return false;
	step.reset();
	Point buoc_dau;
	buoc_dau.x = 0;
	buoc_dau.y = 0;
	step.push(buoc_dau);
	while (!step.isEmpty()) {
		Point current = step.pop();
		if (visit[current.x][current.y] == 0) {
			visit[current.x][current.y] = 1;
			for (int i = 0; i < 4; i++) {
				Point temp;
				temp.x = current.x + d_row[i];
				temp.y = current.y + d_col[i];
				if (checkSafe(temp) && map[temp.x][temp.y] >= low && map[temp.x][temp.y] <= high) {
					if (temp.x == size_map - 1 && temp.y == size_map - 1)	return true;
					if (visit[temp.x][temp.y] == 0)	step.push(temp);
				}
			}
		}
	}
	return false;
}

bool check_kc(int kc) {
	
	for (int i = 0; i + kc <= max_map; i++) {
		for (int j = 0; j < size_map; j++) {
			for (int k = 0; k < size_map; k++) {
				visit[j][k] = 0;
			}
		}
		if (BFS(i, i + kc) == true)	return true;
	}
	return false;
}

int main() {
	freopen("Text.txt", "r", stdin);
	int T; cin >> T;
	for (int testCase = 0; testCase < T; testCase++) {
		cin >> size_map;
		max_map = 0;
		for (int i = 0; i < size_map; i++) {
			for (int j = 0; j < size_map; j++) {
				cin >> map[i][j];
				if (map[i][j] > max_map)	max_map = map[i][j];
			}
		}
		int low = 0;
		int high = max_map;
		while (high > low) {
			int mid = (low + high) / 2;
			if (check_kc(mid) == true)	high = mid;
			else
			{
				low = mid + 1;
			}
		}
		cout << "#" << testCase + 1 << " " << high << endl;

	}
	return 0;
}
