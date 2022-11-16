#include <iostream>

using namespace std;
int visit[1000][1000]; 

int map[1000][1000]; 
int list[1000000]; 
int Answer;
int row, col, r, c, s, k;


int main(){
	freopen("input.txt", "r", stdin);
	int T;
	cin >> T;
	for (int testCase = 0; testCase < T; testCase ++){
		cin >> row >> col >> r >> c >> s >> k;
		for (int i = 0 ; i< row; i++){
			for (int j = 0; j< col; j++){
				map[i][j] = 0;
				visit[i][j] = 0;
			}
		}
		for (int i = 0 ; i< 1000000; i++){
			list[i] = 0;
		}
		
		r--;
		c--;
		s--;
		k--;
		map[r][c] = 1;
		int check_point = 0;
		int listMax = 0;
		list [0] = r*1000+c;
		while (check_point<=listMax){
			int x = list[check_point]/1000;
			int y = list[check_point]%1000;
			if (x == s && y == k)	break;
			if (visit[x][y]==0){
				if (map[x-2][y-1] == 0 && x-2 < row && y-1 < col && x-2 >=0 && y-1 >=0){
					map[x-2][y-1] = map[x][y] + 1;
					listMax++;
					list[listMax] = (x-2)*1000 + (y-1);
				
				}
				if (map[x-1][y-2] == 0 && x-1 < row && y-2 < col && x-1 >=0 && y-2 >=0){
					map[x-1][y-2] = map[x][y] + 1;
					listMax++;
					list[listMax] = (x-1)*1000 + (y-2);
				
				}
				if (map[x+2][y-1] == 0 && x+2 < row && y-1 < col && x+2 >=0 && y-1 >=0){
					map[x+2][y-1] = map[x][y] + 1;
					listMax++;
					list[listMax] = (x+2)*1000 + (y-1);
				
				}
				if (map[x+1][y-2] == 0 && x+1 < row && y-2 < col && x+1 >=0 && y-1 >=0){
					map[x+1][y-2] = map[x][y] + 1;
					listMax++;
					list[listMax] = (x+1)*1000 + (y-2);
				
				}
				if (map[x-2][y+1] == 0 && x-2 < row && y+1 < col && x-2 >=0 && y+1 >=0){
					map[x-2][y+1] = map[x][y] + 1;
					listMax++;
					list[listMax] = (x-2)*1000 + (y+1);
				
				}
				if (map[x+1][y+2] == 0 && x+1 < row && y+2 < col && x+1 >=0 && y+2 >=0){
					map[x+1][y+2] = map[x][y] + 1;
					listMax++;
					list[listMax] = (x+1)*1000 + (y+2);
				
				}
				if (map[x+2][y+1] == 0 && x+2 < row && y+1 < col && x+2 >=0 && y+1 >=0){
					map[x+2][y+1] = map[x][y] + 1;
					listMax++;
					list[listMax] = (x+2)*1000 + (y+1);
				
				}
				if (map[x-1][y+2] == 0 && x-1 < row && y+2 < col && x-1 >=0 && y+2 >=0){
					map[x-1][y+2] = map[x][y] + 1;
					listMax++;
					list[listMax] = (x-1)*1000 + (y+2);
				
				}
				visit[x][y] = 1;
			}
			check_point++;
		}
		Answer = map[s][k] - 1;
		cout << "Case #" << testCase+1 << endl<< Answer<<endl;
	}
	return 0;
}
