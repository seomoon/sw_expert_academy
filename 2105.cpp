#include "pch.h"
#include <iostream>
#include <vector>
#define MAX_N 20
using namespace std;

int n;
int map[MAX_N][MAX_N];
int direction[4][2] = { {1,1}, {1, -1}, {-1, -1}, {-1, 1} };
int d_type[101];
int ans;
void init_d_type() {
	for (int i = 0; i <= 100; i++) {
		d_type[i] = 0;
	}
}

void solve() {
	int break_point = 0;
	
	for (int a = 1; a <= n-1; a++) {
		for (int b = 1; b <= n-1; b++) { //conbination find
			for (int i = 0; i <n-1; i++) {
				for (int j = 0; j <n-1; j++) { //start point 
					int length = 0;
					init_d_type();


					int x_1 = i;
					int y_1 = j;
					int x_2 = i + (a * 1);
					int y_2 = j + (a * 1);
					int x_3 = i + (a * 1) + (b * 1);
					int y_3 = j + (a * 1) + (b*-1);
					int x_4 = i + (b * 1);
					int y_4 = j + (b * -1);
					int c_x = x_1;
					int c_y = y_1;
					
					if (x_1 <0 || x_2<0 || x_3 <0 || x_4 <0 || x_1 >n - 1 || x_2 >n - 1 || x_3 >n - 1 || x_4 >n - 1) continue;
					if (y_1 <0 || y_2<0 || y_3 <0 || y_4 <0 || y_1 >n - 1 || y_2 >n - 1 || y_3 >n - 1 || y_4 >n - 1) continue; //지도 벗어나면

					while (c_x < x_2) {
						
						if (d_type[map[c_x][c_y]] == 0) {

							d_type[map[c_x][c_y]] = 1;
							length++;
						}
						else {
							break_point = 1;
							break;
						}
						c_x++;
						c_y++;
						
					}
					if (break_point) {
						break_point = 0;
						continue;
					}
					while (c_x < x_3) {

						if (d_type[map[c_x][c_y]] == 0) {

							d_type[map[c_x][c_y]] = 1;
							length++;
						}
						else {
							break_point = 1;
							break;
						}
						c_x++;
						c_y--;
						
					}
					if (break_point) {
						break_point = 0;
						continue;
					}
					while (c_x > x_4) {

						if (d_type[map[c_x][c_y]] == 0) {

							d_type[map[c_x][c_y]] = 1;
							length++;
						}
						else {
							break_point = 1;
							break;
						}
						c_x--;
						c_y--;
						
					}
					if (break_point) {
						break_point = 0;
						continue;
					}
					while (c_x > x_1) {

						if (d_type[map[c_x][c_y]] == 0) {

							d_type[map[c_x][c_y]] = 1;
							length++;
						}
						else {
							break_point = 1;
							break;
						}
						c_x--;
						c_y++;
						
					}
					
					if (break_point) {
						break_point = 0;
						continue;
					}
					
					if (length > ans) {
						ans = length;
					}
					
				}
			}
		}
	}

}

int main() {
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cin >> n;
		ans = -1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
			}
		}
		
		// d_type init
		init_d_type();
		solve();
	
		cout << "#" << tc << " " << ans << endl;
	}



	return 0;
}