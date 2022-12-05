#include <iostream>

using namespace std;
int vt_cong[3];
int n_ng_cong[3];
int visit_cong[3];
int visit_spot[60];
int spot;
int KQ;

int tinh(int vt_cong, int sl_ng, int uu_tien) {
	int kq = 0;
	if (visit_spot[vt_cong] == 0) {
		kq++;
		visit_spot[vt_cong] = 1;
		sl_ng--;
	}
	int i = vt_cong+1;
	int j = vt_cong-1;
	while (sl_ng > 0) {
		if (uu_tien == 0) { // uu tien xet phai
			if (visit_spot[i] == 0 && i < spot && sl_ng >0) {
				sl_ng--;
				kq += (i - vt_cong + 1);
				visit_spot[i] = 1;
			}
			if (visit_spot[j] == 0 && j >= 0 && sl_ng > 0) {
				sl_ng--;
				kq += (vt_cong - j + 1);
				visit_spot[j] = 1;
			}
			i++;
			j--;
		}
		else { // uu tien xet trai
			if (visit_spot[j] == 0 && j >= 0 && sl_ng > 0) {
				sl_ng--;
				kq += (vt_cong - j + 1);
				visit_spot[j] = 1;
			}
			if (visit_spot[i] == 0 && i < spot && sl_ng >0) {
				sl_ng--;
				kq += (i - vt_cong + 1);
				visit_spot[i] = 1;
			}
			i++;
			j--;
		}
	}
	return kq;
}

void back_track(int dem, int kq, int uu_tien) {
	if (dem == 3) {
		if (kq < KQ)	KQ = kq;
		return;
	}
	for (int i = 0; i < 3; i++) {
		if (visit_cong[i] == 0) {
			visit_cong[i] = 1;
			int backup_spot[60];
			for (int i = 0; i < 60; i++) {
				backup_spot[i] = visit_spot[i];
			}
			back_track(dem + 1, kq+ tinh(vt_cong[i], n_ng_cong[i], uu_tien), uu_tien);
			visit_cong[i] = 0;
			for (int i = 0; i < 60; i++) {
				visit_spot[i] = backup_spot[i];
			}
		}
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	int T;
	cin >> T;
	for (int testCase = 0; testCase < T; testCase++) {
		KQ = 999999;
		cin >> spot;
		for (int i = 0; i < 3; i++) {
			cin >> vt_cong[i];
			vt_cong[i] --;
			cin >> n_ng_cong[i];
			visit_cong[i] = 0;
		}
		for (int i = 0; i < 60; i++) {
			visit_spot[i] = 0;
		}
		
		back_track(0, 0, 0); // uu tien xet phai
		back_track(0, 0, 1); // uu tien xet trai
		cout << "Case #" << testCase + 1 << endl << KQ << endl;
	}
	return 0;
}
