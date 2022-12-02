#include <iostream>

using namespace std;

typedef struct Point {
	int x;
	int y;
}Point;

Point vt_cty;
Point vt_nha;
int n_pizza;
Point vt_pizza[12];
int KQ;
int visit_pizza[12] = {0};
Point diem_cuoi;

int abs(int c) {
	if (c < 0)	return -c;
	return c;
}

int tinh_khoang_cach(Point a, Point b) {
	return (abs((a.x - b.x)) + abs(a.y - b.y));
}

void back_track(int kq, int dem, Point diem_bat_dau) {
	if (kq > KQ)	return;
	if (diem_bat_dau.x == vt_nha.x && diem_bat_dau.y == vt_nha.y && dem < (n_pizza + 1))	return;
	if (dem == (n_pizza +1)) {
		if (kq < KQ && diem_bat_dau.x == vt_nha.x && diem_bat_dau.y == vt_nha.y) {
			KQ = kq;
		}
		return;
	}
	for (int i = 0; i <= n_pizza; i++) {
		if (visit_pizza[i] == 0) {
			visit_pizza[i] = 1;
			back_track(kq + tinh_khoang_cach(diem_bat_dau, vt_pizza[i]), dem + 1, vt_pizza[i]);
			visit_pizza[i] = 0;
		}
	}
}
int main() {
	freopen("Text.txt", "r", stdin);
	int T;
	cin >> T;
	for (int testCase = 0; testCase < T; testCase++) {
		KQ = 9999999;
		cin >> vt_cty.x >> vt_cty.y >> vt_nha.x >> vt_nha.y >> n_pizza;
		for (int i = 0; i < n_pizza; i++) {
			cin >> vt_pizza[i].x >> vt_pizza[i].y;
		}
		vt_pizza[n_pizza].x = vt_nha.x;
		vt_pizza[n_pizza].y = vt_nha.y;
		back_track(0, 0, vt_cty);
		
		cout << "Case #" << testCase + 1 << " " << KQ << endl;
	}
	return 0;
}
