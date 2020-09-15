#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif
#define _USE_MATH_DEFINES

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

int tc, cnt;
int n;
bool visit[10001];
int w[10001];
int dp[10001][2];
vector<int> adj[10001], v[10001];
set<int> ans;

void bfs(int root) {
	queue<int> q;
	q.push(root);
	visit[root] = true;;

	while (q.size()) {
		for (auto x : v[q.front()]) {
			if (visit[x] == 0) {
				adj[q.front()].push_back(x);
				visit[x] = true;
				q.push(x);
			}
		}
		q.pop();
	}
}


int solve(int idx, int choose) {
	visit[idx] = true;

	if (dp[idx][choose])
		return dp[idx][choose];

	if (choose) {
		dp[idx][choose] = w[idx];
		for (auto chd : adj[idx]) {

			dp[idx][choose] += solve(chd, 0);
		}
	}
	else {
		for (auto chd : adj[idx]) {

			dp[idx][choose] += max(solve(chd, 1), solve(chd, 0));
		}
	}
	return dp[idx][choose];
}

void find_element(int idx, int choose) {
	if (choose) {
		ans.insert(idx);
		for (auto chd : adj[idx]) {
			find_element(chd, 0);
		}
	}
	else {
		for (auto chd : adj[idx]) {
			if (dp[chd][1] >= dp[chd][0]) {
				find_element(chd, 1);
			}
			else {
				find_element(chd, 0);
			}
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> w[i];
	}

	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	bfs(1);

	int c1 = solve(1, 1);
	int nc1 = solve(1, 0);

	cout << max(c1, nc1) << '\n';

	if (c1 >= nc1) {
		find_element(1, 1);
	}
	else {
		find_element(1, 0);
	}

	for (auto i : ans) {
		cout << i << ' ';
	}

	//code end
	return 0;
}