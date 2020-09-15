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
int n;
int cache[101][101];
string W, S;
vector<string> ans;

bool solve(int w, int s) {
	int& ret = cache[w][s];

	if (ret != -1)
		return ret;

	while (s < S.length() && w < W.length() &&
		(W[w] == '?' || W[w] == S[s])) {
		return ret = solve(w + 1, s + 1);
	}

	if (w == W.length())
		return ret = (s == S.length());

	if (W[w] == '*') {
		if (solve(w + 1, s) || (s < S.size() && solve(w, s + 1)))
			return ret = 1;
	}

	return ret = 0;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> tc;


	while (tc--) {
		ans.clear();
		cin >> W;
		cin >> n;
		for (int i = 0; i < n; i++) {
			memset(cache, -1, sizeof(cache));
			cin >> S;

			if (solve(0, 0) == 1)
				ans.push_back(S);
		}
		sort(all(ans));

		for (auto x : ans)
			cout << x << '\n';
	}

	//code end
	return 0;
}