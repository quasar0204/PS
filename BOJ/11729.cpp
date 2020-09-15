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
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, -1, 0, 1 };
const double PI = 3.14159265359;

int tc, cnt;
int n;
vector<pii> ans;

void solve(int from, int to, int n) {
	if (n == 0)
		return;

	solve(from, 6 - from - to, n - 1);
	ans.push_back({ from, to });
	solve(6 - from - to, to, n - 1);


}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> n;

	solve(1, 3, n);

	cout << ans.size() << '\n';
	for (auto x : ans) {
		cout << x.first << ' ' << x.second << '\n';
	}
	//code end
	return 0;
}