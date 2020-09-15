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

typedef struct _dia{
	double w;
	double c;

	bool operator<(_dia& b) {
		return (this->c > b.c) && (this->w < b.w);
	}
} dia;

dia d[1010];
int dp[1010];


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start

	cin >> tc;
	for (int t = 0; t < tc; t++) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> d[i].w >> d[i].c;
		}

		fill(dp, dp + 1010, 1);
		for (int i = 2; i <= n; i++) {
			for (int j = 1; j < i; j++) {
				if (d[j] < d[i]) {
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
		}
		cout << *max_element(dp, dp + 1010) << '\n';
	}


	//code end
	return 0;
}