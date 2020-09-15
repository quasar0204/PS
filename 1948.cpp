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
int s, f;
const int mxn = 10001;
vector<pii> adj[mxn], rev[mxn];
int indeg[mxn], result[mxn];
bool chk[mxn];

void solve() {
	queue<int> q;
	q.push(s);

	int maxTime = -1;
	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (auto next : adj[now]) {
			int nextNode = next.first;
			int cost = next.second;

			result[nextNode] = max(result[nextNode], result[now] + cost);
			if (--indeg[nextNode] == 0) {
				q.push(nextNode);
				maxTime = max(maxTime, result[nextNode]);
			}

		}
	}

	q.push(f);

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (auto next : rev[now]) {
			int nextNode = next.first;
			int cost = next.second;

			if (result[now] - result[nextNode] == cost) {
				cnt++;
				if (!chk[nextNode]) {
					q.push(nextNode);
					chk[nextNode] = true;
				}
			}
		}
	}

	cout << maxTime << '\n';
	cout << cnt << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> n >> m;

	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		adj[a].push_back({ b, c });
		rev[b].push_back({ a, c });
		indeg[b]++;
	}
	cin >> s >> f;

	solve();
	//code end
	return 0;
}