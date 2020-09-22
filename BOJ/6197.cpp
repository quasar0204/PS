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
const int mxn = 5000 + 1;

int tc, cnt;
int n, r;
vector<pii> adj[mxn];
int dist1[mxn], dist2[mxn];
priority_queue<pii, vector<pii>, greater<pii>> pq;


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> n >> r;

	int a, b, c;
	for (int i = 0; i < r; i++) {
		cin >> a >> b >> c;

		adj[a].push_back({ b,c });
		adj[b].push_back({ a,c });
	}

	fill(dist1, dist1 + mxn, INF);
	fill(dist2, dist2 + mxn, INF);
	pq.push({ 0,1 });

	while (!pq.empty()) {
		pii now = pq.top();
		pq.pop();
		int v = now.second;
		int d = now.first;

		if (dist2[v] < d) continue;

		for (int i = 0; i < adj[v].size(); i++) {
			pii next = adj[v][i];

			int d2 = d + next.second;

			if (dist1[next.first] > d2) {
				pq.push({ d2, next.first });
				swap(d2, dist1[next.first]);
			}

			if (dist2[next.first] > d2 && dist1[next.first] < d2) {
				dist2[next.first] = d2;
				pq.push({ d2, next.first });
			}
		}
	}

	cout << dist2[n];

	//code end
	return 0;
}