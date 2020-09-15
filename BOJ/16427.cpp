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
int n, s;
int t;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0);
	//code start
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		t = max(t, tmp);
	}
	t = t * s;
	if (t % 1000 == 0) {
		t = t / 1000;
	}
	else {
		t = (t / 1000) + 1;
	}

	cout << t;
	//code end
	return 0;
}