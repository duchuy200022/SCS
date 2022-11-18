#include <iostream>

using namespace std;
int n_meeting;
int start_time[501];
int end_time[501];
int kq_cuoicung;

int main(){
	freopen("input.txt", "r", stdin);
	int T;
	cin >> T;
	for (int testCase = 0; testCase < T; testCase ++){
		kq_cuoicung = 1;
		cin >> n_meeting;
		int tr;
		for (int i= 0; i< n_meeting; i++)	cin >> tr >> start_time[i] >> end_time[i];
		for (int i = 0; i< n_meeting; i++){
			for (int j = i+1; j< n_meeting; j++){
				if (end_time[i]> end_time[j]){
					int temp_end = end_time[i];
					end_time[i] = end_time[j];
					end_time[j] = temp_end;
					int temp_start = start_time[i];
					start_time[i] = start_time[j];
					start_time[j] = temp_start;
				}
			}
		}
		int temp = end_time[0];
		for (int i = 0; i< n_meeting; i++){
			if (start_time[i] >= temp){
				temp = end_time[i];
				kq_cuoicung++;
			}
		}
		cout << "Case #" << testCase +1<< endl<< kq_cuoicung<<endl;
	}
	return 0;
}
