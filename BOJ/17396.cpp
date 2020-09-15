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
int v, e;
int sight[100000];
lint dist[100000];
priority_queue<pair<lint, int>> pq;
vector<pii> adj[100000];

void dijkstra(int start) {
	dist[start] = 0;
	pq.push({ 0LL, start });

	int cur, next;
	lint curCost, nextCost;
	while (!pq.empty()) {
		cur = pq.top().second;
		curCost = -pq.top().first;
		pq.pop();

		if ((dist[cur] < curCost) || sight[cur])
			continue;

		for (auto x : adj[cur]) {
			next = x.first;
			nextCost = curCost + x.second;

			if (sight[next])
				continue;

			if (nextCost < dist[next]) {
				dist[next] = nextCost;
				pq.push({ -nextCost, next });
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
	cin >> v >> e;

	for (int i = 0; i < v; i++) {
		cin >> sight[i];
		dist[i] = LINF;
	}
	
	int a, b, c;
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		adj[a].push_back({ b, c });
		adj[b].push_back({ a, c });
	}

	sight[v - 1] = 0;

	dijkstra(0);

	if (dist[v - 1] == LINF)
		dist[v - 1] = -1;

	cout << dist[v - 1];
	//code end
	return 0;
}