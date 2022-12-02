#include <iostream>

using namespace std;

typedef struct KieuChay {
	int phut;
	int giay;
	int nl_tieu_ton;
};

int nl_max, chieu_dai_s;
KieuChay cac_kieu_chay[5];
int KQ;

int visit_quang_duong[41];

void back_track(int kq, int dem, int nl_tieu_ton) {
	if (kq > KQ)	return;
	if (nl_tieu_ton > nl_max)	return;
	if (dem == chieu_dai_s && nl_tieu_ton <= nl_max) {
		if (kq < KQ)	KQ = kq;
		return;
	}
		for (int j = 0; j < 5; j++) {
			back_track(kq + cac_kieu_chay[j].giay, dem + 1, nl_tieu_ton + cac_kieu_chay[j].nl_tieu_ton);
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
			cin >> cac_kieu_chay[i].phut >> cac_kieu_chay[i].giay >> cac_kieu_chay[i].nl_tieu_ton;
			cac_kieu_chay[i].giay += cac_kieu_chay[i].phut * 60;
			cac_kieu_chay[i].phut = 0;
		}

		back_track(0, 0, 0);

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
