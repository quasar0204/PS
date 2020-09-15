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

int tc;
int n;
int clk[16];

int sw[10][6] = {
	{0,1,2,-1},
{3,7,9,11,-1},
{4,10,14,15,-1},
{0,4,5,6,7,-1},
{6,7,8,10,12,-1},
{0,2,14,15,-1},
{3,14,15,-1},
{4,5,7,14,15,-1},
{1,2,3,4,5,-1},
{3,4,5,9,13,-1}
};

bool check(int c[]) {
	for (int i = 0; i < 16; i++) 
		if (c[i])
			return false;
	
	return true;
}

int solve(int c[], int idx) {
	int ret = INF;
	if (idx == 10) {
		if (check(c))
			return 0;
		return ret;
	}

	for (int t = 0; t < 4; t++) {
		ret = min(ret, t + solve(c, idx + 1));
	
		for (int i = 0; i < 6; i++) {
			if (sw[idx][i] == -1)
				break;
			c[sw[idx][i]] = (c[sw[idx][i]] + 3) % 12;
		}
	}
	
	return ret;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> tc;
	while (tc--) {
		int ans = INF;

		for (int i = 0; i < 16; i++) {
			cin >> clk[i];
			clk[i] %= 12;
		}

		ans = min(solve(clk, 0), ans);

		if (ans == INF)
			cout << -1 << '\n';
		else
			cout << ans << '\n';
		
	}

	//code end
	return 0;
}