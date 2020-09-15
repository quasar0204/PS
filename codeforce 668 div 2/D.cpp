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
vector<int>vec[mxn];
int dis1[mxn], dis2[mxn];

void dfs(int now, int pre, int step, int *dis)
{
	dis[now] = step;
	for (int i = 0; i < vec[now].size(); i++)
	{
		int nex = vec[now][i];
		if (nex == pre) continue;
		dfs(nex, now, step + 1, dis);
	}
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> tc;
	int a, b, da, db;
	while (tc--) {
		cin >> n >> a >> b >> da >> db;
		if (a > b) {
			cout << "Alice\n";
			continue;
		}
		for (int i = 1; i <= n; i++) {
			vec[i].clear();
		}
		int to, from;
		for (int i = 0; i < n - 1; i++) {
			cin >> to >> from;
			vec[to].push_back(from);
			vec[from].push_back(to);
		}
		dfs(a, -1, 0, dis1);
		dfs(b, -1, 0, dis2);
		int ans = 0;
		for (int i = 2; i <= n; i++) {
			if (dis1[i] > dis2[i]){
				ans = max(ans, dis1[i]);
			}
		}
		if (ans > dis1[b])
			cout << "Bob\n";
		else
			cout << "Alice\n";
	}
	return 0;
}
