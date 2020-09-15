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
using pii = pair<int, int>;
using lint = long long;

const int MOD = 1e9 + 7, INF = 987654321;
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, -1, 0, 1 };
const double PI = 3.14159265359;

int tc, cnt;
int n;
int adj[500][500];
int visit[500][500];
queue<pii> q;
int R, C;

void bfs(int x, int y) {
	q.push({ y, x });

	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i] * adj[r][c];
			int nc = c + dc[i] * adj[r][c];
			
			if (nr >= R || nr < 0)
				continue;

			if (nc >= C || nc < 0)
				continue;

			if (visit[nr][nc])
				continue;

			q.push({ nr, nc });
			visit[nr][nc] = visit[r][c] + 1;

			if (nr == R - 1 && nc == C - 1) {
				cout << visit[nr][nc];
				return;
			}
		}
	}
	cout << "IMPOSSIBLE";
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	cin.tie(0); cout.tie(0);
	//code start
	cin >> R >> C;
	for (int y = 0; y < R; y++)
		for (int x = 0; x < C; x++)
			scanf("%1d", &adj[y][x]);

	bfs(0, 0);
	//code end
	return 0;
}