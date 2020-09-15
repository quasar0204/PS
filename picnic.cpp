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

int tc, cnt;
int n, m;
bool fr[10][10];
bool visit[10];

int solve(bool v[]) {
	int _first = -1;

	for (int i = 0; i < n; i++) {
		if (!v[i]) {
			_first = i;
			v[i] = true;
			break;
		}
	}

	if (_first == -1)
		return 1;

	int ret = 0;
	for (int i = _first + 1; i < n; i++) {
		if (!v[i] && fr[_first][i]) {
			v[i] = true;
			ret = ret + solve(v);
			v[i] = false;
		}
	}
	visit[_first] = false;

	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> tc;
	while (tc--) {
		cin >> n >> m;
		memset(fr, false, sizeof(fr));
		memset(visit, false, sizeof(visit));
		int a, b;
		while (m--) {
			cin >> a >> b;
			fr[a][b] = fr[b][a] = true;
		}

 		cout << solve(visit) << '\n';
	}
	//code end
	return 0;
}