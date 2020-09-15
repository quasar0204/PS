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

const int MOD = 1e9 + 7, INF = 987654321;
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, -1, 0, 1 };
const double PI = 3.14159265359;

int tc, cnt;
char ch;
int cur_sum;
int max_idx = -1, min_idx = -1;
int max_sum, min_sum;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0);
	//code start
	while (cin >> ch) {
		if (ch == 'B') {
			cur_sum++;
			if (max_sum < cur_sum) {
				max_sum = cur_sum;
				max_idx = cnt;
			}
		}
		else {
			cur_sum--;
			if (min_sum > cur_sum) {
				min_sum = cur_sum;
				min_idx = cnt;
			}
		}
		cnt++;
	}
	if (min_idx > max_idx) {
		cout << max_idx + 2 << " " << min_idx + 1;
	}
	else {
		cout << min_idx + 2 << " " << max_idx + 1;
	}

	//code end
	return 0;
}