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
const int mxn = 100000;

int tc, cnt;
int n;

typedef struct _node {
	int d;
	int h;
	int line;

	bool operator<(const _node& rhs) const {
		if (d < rhs.d) return true;
		if (d == rhs.d) {
			if (h < rhs.h) return true;
			if (h == rhs.h)
				if (line > rhs.line) return true;
		}
		return false;
	}
} node;

priority_queue<node> pq;
queue<node> l[mxn];

int lcnt;
int want;



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	int m, k;
	cin >> n >> m >> k;

	int d, h, lin;
	node tmp;
	for (int i = 0; i < n; i++) {
		cin >> d >> h;
		lin = i % m;
		tmp.d = d; tmp.h = h; tmp.line = lin;
		l[lin].push(tmp);

		if (i == k) {
			lcnt = l[lin].size();
			want = lin;
		}
	}

	for (int i = 0; i < m; i++)
		if (!l[i].empty()) pq.push(l[i].front());

	node now;
	while (lcnt) {
		now = pq.top();
		pq.pop();
		l[now.line].pop();
		if (!l[now.line].empty()) pq.push(l[now.line].front());
		if (now.line == want) lcnt--;

		cnt++;
	}

	cout << cnt - 1;

	//code end
	return 0;
}