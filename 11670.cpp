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
using pll = pair<lint, lint>;

const int MOD = 1e9 + 7, INF = 987654321;
const lint LINF = 987654321987654321;
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, -1, 0, 1 };
const double PI = 3.14159265359;
const int mxn = 2501;

int tc, cnt;
int n;
int op[mxn];
pll arr[mxn];
vector<int> adj[mxn];
vector<lint> IDX;
vector<int> d;
vector<bool> c;

int getIndex(lint x) {
	return lower_bound(all(IDX), x) - IDX.begin() + 1;
}

bool solve(int x) {
	for (int i = 0; i < 3; i++) {
		int w = adj[x][i];
		if (c[w]) continue;
		c[w] = true;

		if (d[w] == 0 || solve(d[w])) {
			d[w] = x;
			op[x] = i;
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
		cin >> arr[i].first >> arr[i].second;
		IDX.push_back(arr[i].first + arr[i].second);
		IDX.push_back(arr[i].first - arr[i].second);
		IDX.push_back(arr[i].first * arr[i].second);
	}
	
	IDX.erase(unique(all(IDX)), IDX.end());
	sort(all(IDX));

	for (int i = 1; i <= n; i++) {
		adj[i].push_back(getIndex(arr[i].first + arr[i].second));
		adj[i].push_back(getIndex(arr[i].first - arr[i].second));
		adj[i].push_back(getIndex(arr[i].first * arr[i].second));
	}
	d.resize(IDX.size() + 1);
	c.resize(IDX.size() + 1);

	for (int i = 1; i <= n; i++) {
		fill(all(c), false);
		if (solve(i)) cnt++;
		else {
			cout << "impossible";
			return 0;
		}
	}

	for (int i = 1; i <= n; i++) {
		if (op[i] == 0) {
			cout << arr[i].first << " + " << arr[i].second << " = " << arr[i].first + arr[i].second << '\n';
		}
		else if (op[i] == 1) {
			cout << arr[i].first << " - " << arr[i].second << " = " << arr[i].first - arr[i].second << '\n';
		}
		else {
			cout << arr[i].first << " * " << arr[i].second << " = " << arr[i].first * arr[i].second << '\n';
		}
	}
	//code end
	return 0;
}