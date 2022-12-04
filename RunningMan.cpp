#include <iostream>

using namespace std;


int nl_max, chieu_dai_s;
int giay[5], phut[5], nl_tieu_ton[5];
int KQ;

void back_track(int kq, int dem_chieu_dai, int dem_so_hang, int tong_nl) {
	if (kq > KQ || tong_nl > nl_max)	return;
	if (dem_so_hang == 5) {
		if (dem_chieu_dai == chieu_dai_s) {
			if (kq < KQ)	KQ = kq;
		}
		return;
	}
	for (int i = 0; i <= chieu_dai_s - dem_chieu_dai; i++) {
		back_track(kq + giay[dem_so_hang] * i, dem_chieu_dai + i, dem_so_hang + 1, tong_nl + nl_tieu_ton[dem_so_hang] * i);
	}

}

int main() {
	freopen("Text.txt", "r", stdin);
	int T;
	cin >> T;
	for (int testCase = 0; testCase < T; testCase++) {
		KQ = 999999;
		cin >> nl_max >> chieu_dai_s;
		for (int i = 0; i < 5; i++) {
			cin >> phut[i] >> giay[i] >> nl_tieu_ton[i];
			giay[i] += phut[i] * 60;
			phut[i] = 0;
		}

		back_track(0, 0, 0, 0);

		if (KQ == 999999) {
			cout << "Case #" << testCase + 1 << endl << "-1 -1" << endl;
		}
		else
		{
			cout << "Case #" << testCase + 1 << endl << KQ / 60 << " " << KQ % 60 << endl;
		}
	}
	return 0;
}
