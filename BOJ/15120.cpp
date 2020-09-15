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
using namespace std;

using pii = pair<int, int>;
using lint = long long;

const int MOD = 1e9 + 7, INF = 987654321;
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, -1, 0, 1 };
const double PI = 3.14159265359;

int tc, cnt;
double arr[7];
double old, sum;
double ans;
double mxn;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0);
	//code start
	for (int i = 1; i <= 6; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i <= 6; i++) {
		mxn = max(mxn, arr[i]);
		sum += arr[i] * (double)i;
	}
	
	printf("%.3lf", abs((sum - 3.5) / mxn));

	//code end
	return 0;
}