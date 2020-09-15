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
int dp[301][301];
int L[500000];
int R[500000];
const lint inf = 2000000001;

vector<pair<lint, lint>> in;

int left(int idx) {
	int& ret = L[idx];
	
	if (ret != -1)
		return ret;

	int num = lower_bound(all(in), make_pair(in[idx].first - in[idx].second , -1LL )) - in.begin();

	for (ret = num; num < idx; num++)
		ret = min(ret, left(num));

	return ret;
}

int right(int idx) {
	int& ret = R[idx];

	if (ret != -1)
		return ret;

	int num = upper_bound(all(in), make_pair(in[idx].first + in[idx].second, inf)) - in.begin();

	ret = num - 1;
	for (int _idx = idx; _idx < num; _idx++)
		ret = max(ret, right(_idx));

	return ret;
}

int solve(int l, int r) {
	int &ret = dp[l][r];

	if (l > r)
		return 0;

	if (ret != -1)
		return ret;

	if (R[l] >= r) 
		return 1;

	if (L[r] <= l) 
		return 1;

	ret = inf;
	for (int i = l; i <= r; i++) {
		ret = min(ret, solve(l, L[i] - 1) + solve(L[i], R[i]) + solve(R[i] + 1, r));
	}

	return ret;
	
}



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start

	cin >> n;

	memset(dp, -1, sizeof(dp));
	memset(L, -1, sizeof(L));
	memset(R, -1, sizeof(R));

	lint x, h;
	for (int i = 0; i < n; i++) {
		cin >> x >> h;
		in.push_back({ x,h });
	}

	sort(all(in));

	for (int i = 0; i < n; i++) {
		left(i);
		right(i);
	}

	cout << solve(0, n - 1);


	//code end
	return 0;
}