#include <iostream>
using namespace std;


struct Point{
	int x;
	int y;
};

class Queue{
private:
	int front, rear;
	Point data[100000];
public:
	void reset(){
		front = rear = -1;
	}
	bool isEmpty(){
		return front==rear;
	}
	void push(Point a){
		rear++;
		data[rear]=a;
		
	}
	Point pop(){
		front ++;
		return data[front];
	}
};

int n, countvung;
int a[101][101],back[101][101],visit[101][101];
int moveX[]= {0, -1, 0, 1};
int moveY[]= {-1, 0, 1, 0};
Queue queue;
void BFS(Point dau){
	queue.reset();
	queue.push(dau);
	visit[dau.x][dau.y]=1;
	int k=0;
	Point luu0[10000];
	int dem[6]={0,0,0,0,0,0};
	while (!queue.isEmpty()) {
		Point p;
		p=queue.pop();
		if (a[p.x][p.y]==0) {
			k++;
			luu0[k]=p;
		}
		if (a[p.x][p.y]==0){
			for (int i=0; i<4; i++){
				Point p1;
				p1.x=p.x+moveX[i];
				p1.y=p.y+moveY[i];
				if (p1.x > n || p1.x <1 ) continue;
				if (p1.y > n || p1.y <1 ) continue;
				if (visit[p1.x][p1.y]==0){
					visit[p1.x][p1.y]=1;
					dem[a[p1.x][p1.y]]++;
					queue.push(p1);
				}
			}
		}
		if (a[p.x][p.y]!=0){
			for (int i=0; i<4; i++){
				Point p1;
				p1.x=p.x+moveX[i];
				p1.y=p.y+moveY[i];
				if (p1.x > n || p1.x <1 ) continue;
				if (p1.y > n || p1.y <1 ) continue;
				if (visit[p1.x][p1.y]==0 && a[p1.x][p1.y]==a[p.x][p.y]){
					visit[p1.x][p1.y]=1;
					dem[a[p1.x][p1.y]]++;
					queue.push(p1);
				}
			}
		}
	}
	int maxdem=0;
	int trace;
	for (int i=5; i>0 ; i--){
		if (dem[i]>maxdem) {
			maxdem=dem[i];
			trace=i;
		}
	}
	for (int i=1; i<=k; i++){
		back[luu0[i].x][luu0[i].y]=trace;
	}
};

void BFSvung(Point dau){
	queue.reset();
	queue.push(dau);
	visit[dau.x][dau.y]=1;
	
	while (!queue.isEmpty()) {
			Point p;
			p=queue.pop();
			for (int i=0; i<4; i++){
				Point p1;
				p1.x=p.x+moveX[i];
				p1.y=p.y+moveY[i];
				if (p1.x > n || p1.x <1 ) continue;
				if (p1.y > n || p1.y <1 ) continue;
				if (visit[p1.x][p1.y]==0 && back[p1.x][p1.y]==back[p.x][p.y]){
					visit[p1.x][p1.y]=1;
					queue.push(p1);
				}
			}
	}
};
void initvisit(){
	for (int i=1; i<=n; i++){
		for (int j=1; j<=n; j++){
			visit[i][j]=0;
		}
	}
};
int main(){
	freopen("Text1.txt","r",stdin);
	int tc;
	cin >>tc;
	for (int t=1; t<=tc; t++){
		cin >>n;
		for (int i=1; i<=n; i++){
			for (int j=1; j<=n; j++){
				cin >> a[i][j];
				visit[i][j]=0;
				back[i][j]=a[i][j];
			}
		}
		for (int i=1; i<=n; i++){
			for (int j=1; j<=n; j++){
				if (back[i][j]==0){
					Point p;
					p.x=i;
					p.y=j;
					BFS(p);
					initvisit();
				}
			}
		}
		
		countvung=0;
		for (int i=1; i<=n; i++){
			for (int j=1; j<=n; j++){
				if (visit[i][j]==0){
					countvung++;
					Point pdau;
					pdau.x=i;
					pdau.y=j;
					BFSvung(pdau);
				}
			}
		}
		cout <<"Case #"<< t << endl << countvung << endl;
		
	}
	return 0;
}
					
