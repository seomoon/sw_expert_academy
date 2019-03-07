#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;
int n, k;
deque<int> dq;
vector<int> arr;
vector<int> result;
bool cmp(int& a, int& b) {
	return a > b;
}
void turn() {
	for (int i = 0; i < 4; i++) {
		int s = i * (n / 4);
		int hex=0;
		for (int j = 0; j < n / 4; j++) {
			int temp = dq[s + j];
			int pow_value = (n / 4) - j - 1;
			int hex_value = pow(16, pow_value);
			hex += (temp*hex_value);
		}
		result.push_back(hex);
	}

}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	
	for (int i = 1; i <= t; i++) {
		cin >> n >> k;
		string s;
		cin >> s;
		dq.clear();
		result.clear();
		for (int i = 0; i < s.length(); i++) {
			if (s[i] - '0' >=0 && s[i] - '0' <= 9) {
				//arr.push_back(s[i] - '0');
				dq.push_back(s[i] - '0');
			}
			else {
				//arr.push_back(10 + (s[i] - 'A'));
				dq.push_back(10 + (s[i] - 'A'));
			}
			
		}
		for (int i = 0; i < n/4; i++) {
			turn();
			int temp = dq.front();
			dq.pop_front();
			dq.push_back(temp);
		}
		sort(result.begin(), result.end(), cmp);
		/*for (int j = 0; j < result.size(); j++) {
			cout << result[j] << "\n";
		}*/
		//중복제거
		int temp = result[0];
		k--;
		for (int i = 1; i < result.size() && k>0; i++) {
			if (temp == result[i]) { continue; }
			temp = result[i];
			k--;
		}

		cout << "#" << i << " " << temp<<"\n";
	}
	return 0;
}