#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
int m, a;
int a_load[100];
int b_load[100];
int direction[5][2] = { {0,0},{-1, 0}, {0, 1}, {1, 0}, {0, -1} };
typedef struct BC {
	int x;
	int y;
	int c; //범위
	int p; //성능
	int id;
};
typedef struct PERSON {
	int x;
	int y;
};
vector<BC> bc_arr;
vector<BC> a_cur;
vector<BC> b_cur;
PERSON a_p;
PERSON b_p;
int result = 0;
bool dist(int x1, int y1, int x2, int y2, int c) {
	return  (c>=(abs(x1 - x2) + abs(y1 - y2)));
}
void cur_sum() {
	for (int i = 0; i < bc_arr.size(); i++) {
		if (dist(a_p.x, a_p.y, bc_arr[i].x, bc_arr[i].y, bc_arr[i].c)) { //a한테 되는지 
			a_cur.push_back(bc_arr[i]);
		}
		if (dist(b_p.x, b_p.y, bc_arr[i].x, bc_arr[i].y, bc_arr[i].c)) { //b한테 되는지 거리체크
			b_cur.push_back(bc_arr[i]);
		}
	}
	if (!a_cur.size() && !b_cur.size()) {
		return;
	}
	else if (a_cur.size() > 0 && b_cur.size() == 0) {
		int max_n = 0;
		for (int i = 0; i < a_cur.size(); i++) {
			if (a_cur[i].p > max_n) {
				max_n = a_cur[i].p;
			}
		}
		result += max_n;
		return;
	}
	else if (a_cur.size() == 0 && b_cur.size() > 0) {
		int max_n = 0;
		for (int i = 0; i < b_cur.size(); i++) {
			if (b_cur[i].p > max_n) {
				max_n = b_cur[i].p;
			}
		}
		result += max_n;
		return;
	}
	else {
		int max_n = 0;
		for (int i = 0; i < a_cur.size(); i++) {
			for (int j = 0; j < b_cur.size(); j++) {
				if (a_cur[i].id == b_cur[j].id) {
					if (max_n < a_cur[i].p) {
						max_n = a_cur[i].p;
					}
				}
				else {
					if (max_n < a_cur[i].p + b_cur[j].p) {
						max_n = a_cur[i].p + b_cur[j].p;
					}
				}
			}
		}
		result += max_n;
		return;
	
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;

	for (int i = 1; i <= t; i++) {
		cin >> m >> a;
		bc_arr.clear();
		result = 0;
		for (int j = 0; j < m; j++) {
			cin >> a_load[j];
		}
		for (int j = 0; j < m; j++) {
			cin >> b_load[j];
		}
		for (int j = 0; j < a; j++) {
			int y, x, c_, p_;
			cin >> y >> x >> c_ >> p_;
			BC temp = { x, y, c_, p_, j+1};
			bc_arr.push_back(temp);
		}
		a_p.x = 1;
		a_p.y = 1;
		b_p.x = 10;
		b_p.y = 10;
		// 이동
		cur_sum(); // 현재위치에서 충전값 확인
		for (int j = 0; j < m; j++) {
			
			
			//위치이동
			
			a_p.x = a_p.x + direction[a_load[j]][0];
			a_p.y = a_p.y + direction[a_load[j]][1];

			b_p.x = b_p.x + direction[b_load[j]][0];
			b_p.y = b_p.y + direction[b_load[j]][1];
			cur_sum(); // 현재위치에서 충전값 확인
			a_cur.clear();
			b_cur.clear();
		}

		cout << "#" << i << " " << result << "\n";
	}
	return 0;
}