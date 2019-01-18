#include "pch.h"
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
int m;
int k;
int direction[5][2] = { {0, 0}, {-1, 0}, {1, 0}, {0, -1}, {0,1} };
typedef struct {
	int num;
	int d;
	int pre_max;
}node;

node map[101][101];
node next_map[101][101];


void init() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			map[i][j] = { 0, 0, 0 };
		}
	}
}
void print() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout<< map[i][j].num<<"  " ; 
		}
		cout << endl;
	}
	cout << endl;
}
void solve() {
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j].num == 0)continue;

			int n_x = i + direction[map[i][j].d][0];
			int n_y = j + direction[map[i][j].d][1];
			

			if (n_x == 0 || n_x == n - 1 || n_y == 0 || n_y == n - 1) {
				next_map[n_x][n_y].num = map[i][j].num / 2;
				if (map[i][j].d % 2 == 1) {
					next_map[n_x][n_y].d = map[i][j].d + 1;
				}
				else {
					next_map[n_x][n_y].d = map[i][j].d - 1;
				}
			}
			else {
				if (next_map[n_x][n_y].num == 0) {
					next_map[n_x][n_y].d = map[i][j].d;
					next_map[n_x][n_y].num = map[i][j].num;
					next_map[n_x][n_y].pre_max = map[i][j].num;
				}
				else {
					if (next_map[n_x][n_y].pre_max > map[i][j].num) {
						next_map[n_x][n_y].num += map[i][j].num;
					}
					else {
						next_map[n_x][n_y].num += map[i][j].num;
						next_map[n_x][n_y].d = map[i][j].d;
						next_map[n_x][n_y].pre_max = map[i][j].num;
					}
				}
			}
	
		}
	}
	//print();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			map[i][j].d = next_map[i][j].d;
			map[i][j].num= next_map[i][j].num;
			map[i][j].pre_max = 0;
			next_map[i][j] = { 0,0,0 };
		}
	}
	//print();

	
}

int sum() {
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ans += map[i][j].num;
		}
	}
	return ans;
}

int main() {
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cin >> n >> m >> k;
		
		init();
		//read
		for (int i = 0; i < k; i++) {
			int t1, t2, t3, t4;
			cin >> t1 >> t2 >> t3 >> t4;
			map[t1][t2].num = t3;
			map[t1][t2].d = t4;
			
		
		}
		//print();
		for (int i = 0; i < m; i++) {
			solve();
		}
		
		
		cout << "#" << tc << " " << sum() << endl;
	}



	return 0;
}