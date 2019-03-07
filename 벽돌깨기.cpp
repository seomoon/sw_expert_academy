#include "pch.h"
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <stack>
using namespace std;
//int direction[5][2] = { {0, 0}, {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
int n, w, h;
vector<vector<int>> map;
int result;
typedef struct node {
	int x;
	int y;
	int power;
};
void dfs(int index, int count, vector<vector<int>> temp_map) {
	if (count == n) {
		int sum=0; 
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (temp_map[i][j] != 0) {
					sum++;
				}
			}
		}
		if (sum < result) result = sum;
		return;
	// º®µ¹ count
	}
	stack<node> s;
	for (int i = 0; i < h; i++) {
		if (temp_map[i][index] != 0) {
			s.push({ i, index, temp_map[i][index] });
			break;
		}
		
	}
	if (s.size() == 0) {
		return;
	}
	while (!s.empty()) {
		node cur = s.top();
		s.pop();
		temp_map[cur.x][cur.y] = 0;
		//»ó
		int n_x = cur.x;
		int n_y = cur.y;
		for (int j = 0; j < cur.power; j++) {
			//{-1, 0}
			n_x = cur.x - j;
			if (n_x < 0) break;
			if (temp_map[n_x][n_y] == 0) {
			
			}
			else if(temp_map[n_x][n_y] == 1) {
				temp_map[n_x][n_y] = 0;
			}
			else {
				s.push({ n_x, n_y, temp_map[n_x][n_y] });
				temp_map[n_x][n_y] = 0;
			}
		}
		//ÇÏ
		n_x = cur.x;
		n_y = cur.y;
		for (int j = 0; j < cur.power; j++) {
			n_x = cur.x + j;
			if (n_x >= h) break;
			if (temp_map[n_x][n_y] == 0) {
			}
			else if (temp_map[n_x][n_y] == 1) {
				temp_map[n_x][n_y] = 0;
			}
			else {
				s.push({ n_x, n_y, temp_map[n_x][n_y] });
				temp_map[n_x][n_y] = 0;
			}
		}
		//ÁÂ
		n_x = cur.x;
		n_y = cur.y;
		for (int j = 0; j < cur.power; j++) {
			n_y = cur.y - j;
			if (n_y < 0) break;
			if (temp_map[n_x][n_y] == 0) {
			}
			else if (temp_map[n_x][n_y] == 1) {
				temp_map[n_x][n_y] = 0;
			}
			else {
				s.push({ n_x, n_y, temp_map[n_x][n_y] });
				temp_map[n_x][n_y] = 0;
			}

		}
		//¿ì
		n_x = cur.x;
		n_y = cur.y;
		for (int j = 0; j < cur.power; j++) {
			n_y = cur.y + j;
			if (n_y >= w) break;
			if (temp_map[n_x][n_y] == 0) {
			}
			else if (temp_map[n_x][n_y] == 1) {
				temp_map[n_x][n_y] = 0;
			}
			else {
				s.push({ n_x, n_y, temp_map[n_x][n_y] });
				temp_map[n_x][n_y] = 0;
			}

		}
	}
	
	queue<int> q;
	for (int i = 0; i < w; i++) {
		for (int j = h-1; j >=0; j--) {
			if (temp_map[j][i] != 0) {
				q.push(temp_map[j][i]);
				temp_map[j][i] = 0;
			}
			
		}
		int k = h - 1;
		while (!q.empty()) { 
			temp_map[k][i] = q.front();
			q.pop();
			k--;
		}
	}
	
	for (int i = 0; i < w; i++) {
		dfs(i, count+1, temp_map);
	}

	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;

	for (int i = 1; i <= t; i++) {
		cin >> n >> w >> h;
		result = 2100000000;
		map = vector<vector<int>>(h, vector<int>(w, 0));
		for (int j = 0; j < h; j++) {
			for (int k = 0; k < w; k++) {
				cin >> map[j][k];
			}
		}

		for (int j = 0; j < w; j++) {
			dfs(j, 0, map); // ¶³¾î¶ß¸± °÷ È½¼ö
		}
		if (result == 2100000000) {
			cout << "#" << i << " " << 0 << "\n";
		}
		else {
			cout << "#" << i << " " << result << "\n";
		}
		
	}
	return 0;
}