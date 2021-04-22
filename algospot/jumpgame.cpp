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

int _map[100][100];
bool check[100][100];

bool solve(int y, int x) {
	queue<pii> q;
	q.push({ y,x });

	while (!q.empty()) {
		int cur_y = q.front().first;
		int cur_x = q.front().second;

		if (cur_x == n - 1 && cur_y == n - 1)
			return true;

		q.pop();

		if (check[cur_y][cur_x])
			continue;

		check[cur_y][cur_x] = true;
		int next_y = cur_y + _map[cur_y][cur_x];
		int next_x = cur_x + _map[cur_y][cur_x];

		if (next_y < n && next_y >= 0)
			q.push({ next_y, cur_x });

		if (next_x < n && next_x >= 0)
			q.push({ cur_y, next_x });
	}

	return false;
}
int main() {

	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> tc;

	while (tc--) {
		cin >> n;
		memset(check, false, sizeof(check));

		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; x++) {
				cin >> _map[y][x];
			}
		}
		
		if (solve(0,0))
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	//code end
	return 0;
}