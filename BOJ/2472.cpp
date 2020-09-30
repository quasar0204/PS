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

const int MOD = 1e9 + 7, INF = 987654321 * 2;
const lint LINF = 987654321987654321;
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, -1, 0, 1 };

vector<lint> seg;
int leaf = 1;
lint cur;
vector<lint> IDX;
set<int> ans;

int getIndex(lint x) {
	return lower_bound(all(IDX), x) - IDX.begin();
}

void update(int idx, lint x) {
	seg[idx] = min(x, seg[idx]);
	idx /= 2;
	while (idx) {
		seg[idx] = min(seg[idx * 2], seg[idx * 2 + 1]);
		idx /= 2;
	}
}

void solve(int l, int r) {
	if (l > r)
		return;

	if (l == r) {
		cur = min(cur, seg[l]);
		return;
	}

	if (l % 2) {
		cur = min(cur, seg[l]);
		l++;
	}

	if ((r % 2) == 0) {
		cur = min(cur, seg[r]);
		r--;
	}

	solve(l / 2, r / 2);
}


typedef struct _node {
	lint a, b, c;
	int idx;

	bool operator<(_node& rhs) {
		if (this->a != rhs.a)
			return this->a > rhs.a;
		else {
			return this->b > rhs.b;
		}
	}
} node;

lint tc, cnt;
lint n;
lint m;
vector<vector<pair<lint, lint>>> adj;
lint dist[3][100001];
priority_queue<pair<lint, lint>> pq;
lint in[3];
node arr[100001];

void dij(lint start, lint i) {
	dist[i][start] = 0;
	pq.push({ 0LL, start });

	lint cost, now;
	while (!pq.empty()) {
		cost = -pq.top().first;
		now = pq.top().second;
		pq.pop();

		if (dist[i][now] < cost)
			continue;

		lint nextCost, nextNode;
		for (auto next : adj[now]) {
			nextNode = next.first;
			nextCost = cost + next.second;

			if (dist[i][nextNode] > nextCost) {
				dist[i][nextNode] = nextCost;
				pq.push({ -nextCost, nextNode });
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
	cin >> in[0] >> in[1] >> in[2];

	adj.resize(n + 1);

	cin >> m;
	lint x, y, z;
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> z;
		adj[x].push_back({ y,z });
		adj[y].push_back({ x,z });
	}

	for (int i = 0; i < 3; i++)
		fill(dist[i], dist[i] + n + 1, LINF);

	for (int i = 0; i < 3; i++)
		dij(in[i], i);

	for (int i = 1; i <= n; i++) {
		node tmp;
		arr[i].a = dist[0][i];
		arr[i].b = dist[1][i];
		arr[i].c = dist[2][i];
		arr[i].idx = i;
		IDX.push_back(arr[i].b);
	}

	sort(arr + 1, arr + n + 1);
	sort(all(IDX));
	IDX.erase(unique(all(IDX)), IDX.end());

	while (IDX.size() > leaf)
		leaf <<= 1;

	seg.resize(leaf << 1, LINF);

	for (int i = n; i >= 1; i--) {
		cur = LINF;
		solve(leaf, leaf + getIndex(arr[i].b));
		if (cur < arr[i].c) {
			ans.insert(arr[i].idx);
		}
		update(leaf + getIndex(arr[i].b), arr[i].c);
	}

	cin >> tc;
	int now;
	while (tc--) {
		cin >> now;
		if (ans.find(now) == ans.end()) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}

	//code end
	return 0;
}