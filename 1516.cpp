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

vector<int> adj[501];
int indeg[501], cost[501], result[501];


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> n;

	int pre;
	for (int i = 1; i <= n; i++) {
		cin >> cost[i];

		result[i] = cost[i];
		while (true) {
			cin >> pre;

			if (pre == -1)
				break;

			adj[pre].push_back(i);
			indeg[i]++;
		}
	}

	queue<int> q;

	for (int i = 1; i <= n; i++) {
		if (indeg[i] == 0) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (auto next : adj[now]) {
			indeg[next]--;

			if (indeg[next] == 0) {
				q.push(next);
			}

			result[next] = max(result[next], cost[next] + result[now]);
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << result[i] << '\n';
	}
	//code end
	return 0;
}