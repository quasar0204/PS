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
const int mxn = 1000;

int tc, cnt;
int n;

int dp[mxn][mxn];
vector<int> arr;
bool visit[mxn];

int gcd(int a, int b) {
	int M = max(a, b);
	int m = min(a, b);

	while (true) {
		if (M % m == 0) break;
		M = M % m;
		swap(M, m);
	}

	return m;
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> tc;
	while (tc--) {
		cin >> n;
		arr.resize(n);
		memset(visit, false, sizeof(visit));
		for (int i = 0; i < n; i++)
			cin >> arr[i];

		sort(all(arr), greater<int>());

		

		queue<int> q;
		q.push(0);
		int pregcd = arr[0];
		while (!q.empty()) {
			int now = q.front();
			q.pop();
			visit[now] = true;
			cout << arr[now] << ' ';

			for (int i = 0; i < n; i++) {
				dp[now][i] = gcd(pregcd, arr[i]);
			}

			int next = -1;
			int _mxn = -1;
			for (int i = 0; i < n; i++) {
				if (visit[i]) continue;
				if (dp[now][i] > _mxn) {
					_mxn = dp[now][i];
					next = i;
				}
				else if (dp[now][i] == _mxn && arr[i] < arr[next]) {
					next = i;
				}
			}
			if (next != -1) {
				q.push(next);
				pregcd = _mxn;
			}
		}
		cout << '\n';

	}

	//code end
	return 0;
}