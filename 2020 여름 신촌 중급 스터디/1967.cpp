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

#define all(v) (v).begin(),(v).end()
using pii = pair<int, int>;
using lint = long long;

const int MOD = 1e9 + 7, INF = 987654321;
const lint LINF = 987654321987654321;
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, -1, 0, 1 };

int tc, cnt;
int n;
int dist[10001];
vector<pii> adj[10001];

int* maxDist(int root) {
	queue<int> q;
	q.push(root);
	memset(dist, -1, sizeof(dist));
	dist[root] = 0;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (pii next : adj[now]) {
			if (dist[next.first] == -1) {
				dist[next.first] = dist[now] + next.second;
				q.push(next.first);
			}
		}
	}

	return max_element(dist, dist + n + 1);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> n;
	int a, b, c;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c;
		adj[a].push_back({ b,c });
		adj[b].push_back({ a,c });
	}

	int nextRoot = maxDist(1) - dist;

	cout << *maxDist(nextRoot);
	//code end
	return 0;
}