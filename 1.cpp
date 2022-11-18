#include <iostream>
#include <conio.h>

using namespace std;

int groupNum = 1;
int map[1000];
int Answer = 0;

int main(){
	freopen("input.txt","r",stdin);
	int T;
	cin >> T;
	for (int testCase = 1; testCase <=T;testCase++){
		groupNum = 0;
		cin >> groupNum;
		Answer = 0;
		for (int i = 0;i<1000;i++){
			map[i] = 0;
		}
		for (int i = 0;i<groupNum;i++){
			cin >> map[i];
		}
		int min1 = 1000000;
		int min2 = 1000000;
		int indexMin1 = 0;
		int indexMin2 = 0;

		for (int k = 0;k<groupNum-1;k++){
			min1 = 1000000;
			min2 = 1000000;
			for (int i = 0;i<groupNum;i++){
				if (map[i] != -1){
					if (map[i] < min1 && map[i] != -1) {
						min2 = min1;
						indexMin2 = indexMin1;
						min1 = map[i];
						indexMin1 = i;
					}
					else if (map[i] < min2 && map[i] != -1){
						min2 = map[i];
						indexMin2 = i;
					}
				}
			}

			map[indexMin2] += map[indexMin1];
			map[indexMin1] = -1;
			Answer += map[indexMin2];
		}

		
		cout << "Case #" << testCase << endl << Answer << endl;
	}
	getch();
	return 0;
}
