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
const int mxn = 100001;

int tc;
int n;

vector<int> adj[mxn];
bool visit[mxn];

pll arr[mxn];

lint solve(int r, lint l) {
	visit[r] = true;
	arr[r].first = l + 1;

	lint right = l + 1;
	for (auto next : adj[r]) {
		if (visit[next]) continue;
		
		right = solve(next, right);
	}
	right++;

	return arr[r].second = right;
}




int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> n;
	int from, to;
	for (int i = 0; i < n; i++) {
		cin >> from;
		while (true) {
			cin >> to;
			if (to == -1) break;
			adj[from].push_back(to);
		}
		sort(all(adj[from]));
	}
	int root;
	cin >> root;
	solve(root, 0);

	for (int i = 1; i <= n; i++) {
		cout << i << ' ' << arr[i].first << ' ' << arr[i].second << '\n';
	}
	

	//code end
	return 0;
}