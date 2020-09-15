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

typedef struct _node{
	lint w1, w2;

	bool operator<(_node& rhs) {
		return w1 * w2 < rhs.w1*rhs.w2;
	}

	lint getCost() {
		return w1 * w2;
	}

	_node operator+(_node& rhs) {
		node tmp;
		tmp.w1 = w1 + rhs.w1;
		tmp.w2 = w2 + rhs.w2;
		return tmp;
	}
} node;

bool cmp(pair<node, int> a, pair<node, int> b) {
	return a.first.w1 * a.first.w2 < b.first.w1 * b.first.w2;
}

int tc, cnt;
int n;
node in[20][20];
vector<pair<node, int>> adj[20];
node dist[20];
priority_queue <pair<node, int>, vector<pair<node,int>>> pq;

lint dijkstra(int start, int end) {
	dist[start].w1 = 0;
	dist[start].w2 = 0;

	pq.push({ dist[0], start });

	while (!pq.empty()) {
		node cost = pq.top().first;
		int now = pq.top().second;
		pq.pop();

		if (dist[now].getCost() < cost.getCost())
			continue;

		for (auto next : adj[now]) {
			node nextCost = next.first + cost;
			int nextNode = next.second;

			if (nextCost.getCost() < dist[nextNode].getCost()) {
				dist[nextNode] = nextCost;
				pq.push({ nextCost, nextNode });
			}
		}
	}
	if (dist[end].w1 == LINF)
		return -1LL;

	return dist[end].getCost();
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> n;
	string tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		for (int j = 0; j < n; i++) {
			if (tmp[j] == '.')
				continue;
			in[i][j].w1 = (lint)(tmp[j] + '0');
			in[j][i].w1 = (lint)(tmp[j] + '0');
		}
	}

	for (int i = 0; i < n; i++) {
		cin >> tmp;
		for (int j = 0; j < n; i++) {
			if (tmp[j] == '.')
				continue;
			in[i][j].w2 = (lint)(tmp[j] + '0');
			in[j][i].w2 = (lint)(tmp[j] + '0');
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (in[i][j].w1 == '.')
				continue;
			adj[i].push_back({ in[i][j], j });
			adj[j].push_back({ in[i][j], i });
		}
	}

	memset(dist, LINF, sizeof(dist));

	cout << dijkstra(0, 1);

	//code end
	return 0;
}