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
using namespace std;

#define f(i,n) for(int i=0;i<n;i++)
#define all(v) (v).begin(),(v).end()
using pii = pair<int, int>;
using lint = long long;

const int MOD = 1e9 + 7, INF = 987654321;
const lint LINF = 987654321987654321;
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, -1, 0, 1 };
const double PI = 3.14159265359;
const int mxn = 101;

int tc, cnt;
int n;
vector<int> pre, in;

void solve(int start, int end, int root) {
	for (int i = start; i <= end; i++) {
		if (in[i] == pre[root]) {
			solve(start, i - 1, root + 1);
			solve(i + 1, end, root + (i - start) + 1);
			cout << in[i] << ' ';
		}
	}
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

		pre.resize(n);
		in.resize(n);

		for (int i = 0; i < n; i++)
			cin >> pre[i];
		for (int i = 0; i < n; i++)
			cin >> in[i];

		solve(0, n - 1, 0);
		cout << '\n';

	}

	//code end
	return 0;
}