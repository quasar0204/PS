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
const int mxn = 1001;

int tc, cnt;
vector<int> adj[mxn];
int s[mxn][3];
int d[mxn];
bool c[mxn];
int n;

bool solve(int x) {
	for (auto w : adj[x]) {
		if (c[w]) continue;
		c[w] = true;

		if (d[w] == 0 || solve(d[w])) {
			d[w] = x;
			return true;
		}
	}
	return false;
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> s[i][0] >> s[i][1] >> s[i][2];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (s[i][0] >= s[j][0] && s[i][1] >= s[j][1] && s[i][2] >= s[j][2]) {
				adj[i].push_back(j);
			}
			else if (s[i][0] <= s[j][0] && s[i][1] <= s[j][1] && s[i][2] <= s[j][2]) {
				adj[j].push_back(i);
			}
		}
	}

	for (int k = 0; k < 2; k++) {
		for (int i = 1; i <= n; i++) {
			fill(c, c + mxn, false);
			if (solve(i)) cnt++;
		}
	}

	cout << n - cnt;
	//code end
	return 0;
}