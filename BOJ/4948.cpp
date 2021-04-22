#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif
#define _USE_MATH_DEFINES

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
using namespace std;

#define all(v) (v).begin(),(v).end()
using pii = pair<int, int>;
using lint = long long;

const int MOD = 1e9 + 7, INF = 987654321;
const lint LINF = 987654321987654321;
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, -1, 0, 1 };
const int mxn = 10000;

int tc, cnt;
int n;
bool p[123456 * 2 + 1];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start

	p[1] = true;
	for (int i = 2; i <= 123456; i++) {
		if (!p[i]) {
			for (int j = i * 2; j <= 123456 * 2; j += i) {
				p[j] = true;
			}
		}
	}

	while (true) {
		cin >> n;
		if (n == 0) break;
		cnt = 0;

		for (int i = n + 1; i <= 2 * n; i++)
			if (!p[i]) cnt++;

		cout << cnt << '\n';

	}
	//code end
	return 0;
}
