#include "pch.h"
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m, s_x, s_y, l;
int result;
vector<vector<int>> map;
vector<vector<bool>> visit;
int direction[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} }; //╩С го аб ©Л
int pipe[8][4] = {
	{0, 0, 0, 0},
	{1, 1, 1, 1},
	{1, 1, 0, 0},
	{0, 0, 1, 1},
	{1, 0, 0, 1},
	{0, 1, 0, 1},
	{0, 1, 1, 0},
	{1, 0, 1, 0}
};
typedef struct node {
	int x;
	int y;
	int time;
};
void count() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			//cout << visit[i][j] << " ";
			if (visit[i][j] == true) {
				result++;
			}
		}
		//cout << "\n";
	}
}
void bfs(int x, int y) {
	visit[x][y] = true;
	queue<node> q;
	q.push({ x, y, 1 });
	while (!q.empty()) {
		node cur = q.front();
		visit[cur.x][cur.y] = true;
		q.pop();
		if (cur.time >= l) {
			continue;
		}
		for (int i = 0; i < 4; i++) {
			if (pipe[map[cur.x][cur.y]][i] == 1) {
				int n_x = cur.x + direction[i][0];
				int n_y = cur.y + direction[i][1];

				if (n_x<1 || n_x>n || n_y<1 || n_y>m) continue;
				if (visit[n_x][n_y] || map[n_x][n_y]==0 ) continue;
				if (i == 0 && pipe[map[n_x][n_y]][1] == 1) {
					q.push({ n_x, n_y, cur.time + 1 });
				}
				else if (i == 1 && pipe[map[n_x][n_y]][0] == 1) {
					q.push({ n_x, n_y, cur.time + 1 });
				}
				else if (i == 2 && pipe[map[n_x][n_y]][3] == 1) {
					q.push({ n_x, n_y, cur.time + 1 });
				}
				else if (i == 3 && pipe[map[n_x][n_y]][2] == 1) {
					q.push({ n_x, n_y, cur.time + 1 });
				}
			}
		}
	}

}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> n >> m >> s_x >> s_y >> l;
		result = 0;

		map = vector<vector<int>>(n + 1, vector<int>(m + 1));
		visit = vector<vector<bool>>(n + 1, vector<bool>(m + 1, false));
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> map[i][j];
			}
		}
		bfs(s_x+1, s_y+1);
		count();
	
		cout << "#" << t << " " << result;
	}

	return 0;
}
