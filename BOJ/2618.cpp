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
int N, W;

class place {
public :
	place(int a, int b) {
		this->x = a;
		this->y = b;
	}
	place() {

	}
	int x;
	int y;
	int operator-(place &rhs) {
		return abs(this->x - rhs.x) + abs(this->y - rhs.y);
	}
};

place arr[1002];

int dp[1001][1001];
int visit[1001][1001];
vector<int> path;

int solve(int c1, int c2) {
	if (c1 == W || c2 == W) 
		return 0;
	
	int& ret = dp[c1][c2];

	if (ret >= 0)
		return ret;

	int next = max(c1, c2) + 1;
	place p1 = (c1 == 0) ? place(1, 1) : arr[c1];
	place p2 = (c2 == 0) ? place(N, N) : arr[c2];
	int d1 = solve(next, c2) + (arr[next] - p1);
	int d2 = solve(c1, next) + (arr[next] - p2);
	if (d1 > d2) {
		ret = d2;
		visit[c1][c2] = 2;
	}
	else {
		ret = d1;
		visit[c1][c2] = 1;
	}
	return ret;

}



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> N;
	cin >> W;
	for (int i = 1; i <= W; i++) {
		cin >> arr[i].x >> arr[i].y;
	}
	memset(dp, -1, sizeof(dp));
	cout << solve(0, 0) << '\n';

	int c1 = 0, c2 = 0;
	while (visit[c1][c2]) {
		path.push_back(visit[c1][c2]);
		if (visit[c1][c2] == 1) {
			c1 = max(c1, c2) + 1;
		}
		else
			c2 = max(c1, c2) + 1;
	}

	for (auto x : path)
		cout << x << '\n';
	//code end
	return 0;
}