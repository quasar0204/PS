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
using namespace std;

using pii = pair<int, int>;
using lint = long long;

#define min2(x,y) x>y? y:x
#define max2(x,y) x<y? y:x

const int MOD = 1e9 + 7, INF = 987654321;
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, -1, 0, 1 };

int tc, cnt;

int N;
string str[64];
string answer;

void solve(int n, int cur_r, int cur_c) {
	bool flag = true;

	for (int r = cur_r; r < cur_r + n; r++) {
		for (int c = cur_c; c < cur_c + n; c++) {
			if (str[cur_r][cur_c] != str[r][c]) {
				flag = false;
				break;
			}
		}
		if (!flag)
			break;
	}

	if (flag) {
		answer.push_back(str[cur_r][cur_c]);
	}
	else {
		int nn = n / 2;
		answer.push_back('(');
		solve(nn, cur_r, cur_c);
		solve(nn, cur_r, cur_c + nn);
		solve(nn, cur_r + nn, cur_c);
		solve(nn, cur_r + nn, cur_c + nn);
		answer.push_back(')');
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0);
	//code start
	cin >> N;

	for (int i = 0; i < N; i++) 
		cin >> str[i];

	solve(N, 0, 0);

	cout << answer;

//code end
	return 0;
}