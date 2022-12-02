#include <iostream>

using namespace std;

typedef struct Point{
	int x;
	int y;
};
int n_restaurant;
int radius_delivery;
int n_location;
Point coor_location[21];
int n_solitaire;
Point coor_solitaire[101];
int n_people_solitaire[101];
int KQ;

int visit_location[21];

bool so_sanh_khoang_cach(int location, int delivery){
	return ((coor_location[location].x - coor_solitaire[delivery].x) * (coor_location[location].x - coor_solitaire[delivery].x) + (coor_location[location].y - coor_solitaire[delivery].y) * (coor_location[location].y - coor_solitaire[delivery].y)) <= (radius_delivery * radius_delivery);
}

int tinh_tong_nguoi_trong_location(){
	int kq1 = 0;
	int temp_visit_solitair[101] = {0};
	for (int i = 0; i < n_location; i++){
		if (visit_location[i] == 1){
			for (int j = 0; j< n_solitaire; j++){
				if (so_sanh_khoang_cach(i, j) && temp_visit_solitair[j] == 0)	{
					kq1 += n_people_solitaire[j];
					temp_visit_solitair[j] = 1;
				}
			}
		}
	}
	return kq1;
}

void back_track (int c, int dem){
	if (dem == n_restaurant){
		int kq = tinh_tong_nguoi_trong_location();
		if (kq >= KQ)	KQ = kq;
		return;
	}
	for (int i =0 ; i< 2; i++){
		if (i == 0){
			back_track(c, dem+1);
		}
		else if (i == 1){
			visit_location[c] = 1;
			back_track(c+1, dem+1);
		}
	}
	/*for (int i = c; i<n_location; i++){
		visit_location[i] = 1;
		back_track(i+1, dem+1);
	}*/
}

int main(){
	freopen("Text.txt", "r", stdin);
	int T;
	cin >> T;
	for (int testCase = 0; testCase < T; testCase ++){
		KQ = 0;
		cin >> n_restaurant >>radius_delivery;
		cin >> n_location;
		for (int i = 0; i< n_location; i++){
			cin >> coor_location[i].x >> coor_location[i].y;
		}
		cin >> n_solitaire;
		for (int i = 0; i< n_solitaire; i++){
			cin >> coor_solitaire[i].x >> coor_solitaire[i].y >> n_people_solitaire[i];
		}
		back_track(0, 0);
		cout << "#" << testCase +1 << " " <<KQ << endl;
	}
	return 0;
}
