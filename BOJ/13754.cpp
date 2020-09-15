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

lint tc, cnt;
int n;
priority_queue<lint> pq;
lint ans;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0);
	//code start
	cin >> n;

	for (int i = 0; i < n; i++) {
		lint tmp;
		cin >> tmp;
		pq.push(tmp);
		cnt += tmp;
	}

	if (2 * pq.top() >= cnt) {
		cout << cnt - pq.top();
		return 0;
	}

	cout << cnt/2;

	//code end
	return 0;
}