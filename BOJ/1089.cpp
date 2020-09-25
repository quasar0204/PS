#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <map>
#include <set>
#include <deque>
#include <random>
using namespace std;

#define all(v) (v).begin(),(v).end()
using pii = pair<int, int>;
using lint = long long;
using pll = pair<lint, lint>;

const int MOD = 1e9 + 7, INF = 987654321;
const lint LMOD = 1e9 + 7;
const lint LINF = 987654321987654321;
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, -1, 0, 1 };
const double PI = 3.14159265359;
const int mxn = 10000;

lint tc, cnt[10];
int sum[10];
int n;
string str[5];
vector<int> arr[10];
lint p10[10];

const char display[10][5][3] = {
	{{'#','#','#'},{'#','.','#'},{'#','.','#'},{'#','.','#'},{'#','#','#'}},
	{{'.','.','#'},{'.','.','#'},{'.','.','#'},{'.','.','#'},{'.','.','#'}},
	{{'#','#','#'},{'.','.','#'},{'#','#','#'},{'#','.','.'},{'#','#','#'}},
	{{'#','#','#'},{'.','.','#'},{'#','#','#'},{'.','.','#'},{'#','#','#'}},
	{{'#','.','#'},{'#','.','#'},{'#','#','#'},{'.','.','#'},{'.','.','#'}},
	{{'#','#','#'},{'#','.','.'},{'#','#','#'},{'.','.','#'},{'#','#','#'}},
	{{'#','#','#'},{'#','.','.'},{'#','#','#'},{'#','.','#'},{'#','#','#'}},
	{{'#','#','#'},{'.','.','#'},{'.','.','#'},{'.','.','#'},{'.','.','#'}},
	{{'#','#','#'},{'#','.','#'},{'#','#','#'},{'#','.','#'},{'#','#','#'}},
	{{'#','#','#'},{'#','.','#'},{'#','#','#'},{'.','.','#'},{'#','#','#'}}
};

bool can(int start) {
	int idx = start / 4;

	for (int i = 0; i < 10; i++) {
		bool flag = true;
		for (int y = 0; y < 5; y++) {
			for (int x = 0; x < 3; x++) {
				if (display[i][y][x] == '.' &&  str[y][start + x] != '.') {
					flag = false;
					break;
				}
			}
			if (!flag) break;
		}
		if (flag) {
			sum[idx] += i;
			arr[idx].push_back(i);
		}
	}

	if (arr[idx].empty()) return false;
	return true;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> n;

	for (int i = 0; i < 5; i++)
		cin >> str[i];
	
	for (int i = 0; i < n; i++) {
		if (!can(i * 4)) {
			cout << -1;
			return 0;
		}
	}

	p10[0] = 1;
	for (int i = 1; i < 10; i++)
		p10[i] = p10[i - 1] * 10;

	lint cross = 1;
	for (int i = 0; i < n; i++) {
		cnt[i] = (int)arr[i].size();
		cross *= cnt[i];
	}
	
	lint ans = 0;
	for (int i = n - 1; i >= 0; i--) {
		ans += (cross / cnt[i]) * sum[i] * p10[n-1 -i];
	}

	cout << fixed;
	cout.precision(15);
	cout << (double)ans / cross;


	//code end
	return 0;
}