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
int visit[10001];
vector<pii> adj[10001];
queue<int> q;

void bfs(int root) {
	q.push(root);

	while (q.size()) {
		for (pii x : adj[q.front()]) {
			if (x.first == root)
				continue;

			if (visit[x.first] == 0) {
				visit[x.first] = visit[q.front()] + x.second;
				q.push(x.first);
			}
		}
		q.pop();
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> n;

	for (int i = 1; i < n; i++) {
		int p, c, v;
		cin >> p >> c >> v;
		adj[p].push_back({ c,v });
		adj[c].push_back({ p,v });
	}

	int next_root;

	bfs(1);
	next_root = max_element(visit, visit + n + 1) - visit;

	fill(visit, visit + n + 1, 0);
	bfs(next_root);

	cout << *max_element(visit, visit + n + 1);

	//code end
	return 0;
}