#include "pch.h"
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
int direction[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
int n, k;
int map[9][9];
bool visit[9][9];
int max_n = 0;
int result = 0;
typedef struct point {
	int x;
	int y;
};
vector<point> start_point;
void dfs(int x, int y, int cut, int count) { //
	visit[x][y] = true;
	if (result < count) {
		result = count;
	}
	for (int i = 0; i < 4; i++) {
		int n_x = x + direction[i][0];
		int n_y = y + direction[i][1];
		if (n_x<1 || n_y<1 || n_x>n || n_y>n) continue;
		if (visit[n_x][n_y]) continue;
		if (map[x][y] > map[n_x][n_y]) {
			dfs(n_x, n_y, cut, count + 1);
			visit[n_x][n_y] = false;
		}
		else if (cut==1 && map[x][y] <= map[n_x][n_y] && map[n_x][n_y]- map[x][y] <k) {
			int temp = map[n_x][n_y];
			map[n_x][n_y] = map[x][y] - 1;
			dfs(n_x, n_y, 0, count + 1);
			visit[n_x][n_y] = false;
			map[n_x][n_y] = temp;
		}
	}

}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;

	for (int i = 1; i <= t; i++) {
		cin >>n >> k;
		max_n = 0;
		result = 0;
		start_point.clear();
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				cin >> map[j][k];
				if (map[j][k]>max_n) {
					max_n = map[j][k];
				}
			}
		}
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (map[j][k] == max_n) {
					start_point.push_back({ j, k });
				}
			}
		}
		
		for (int j = 0; j < start_point.size(); j++) {
			
			dfs(start_point[j].x, start_point[j].y, 1, 1); //¾ÆÁ÷ ÇÑ¹ø ±ïÀ»¼ö ÀÕ´Ù   ±íÀÌ
			visit[start_point[j].x][start_point[j].y] = false;
		}


		cout << "#" << i << " " << result << "\n";
	}
	return 0;
}