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

#define all(v) (v).begin(),(v).end()
using pii = pair<int, int>;
using lint = long long;

const int MOD = 1e9 + 7, INF = 987654321;
const lint LINF = 987654321987654321;
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, -1, 0, 1 };
const int mxn = 10000;

int tc, cnt;
int n, s;

int arr[20];

void solve(int idx, int sum) {

	if (idx == n) {
		if (sum == s) cnt++;
		return;
	}

	solve(idx + 1, sum);
	solve(idx + 1, sum + arr[idx]);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> s;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	solve(0, 0);

	if (s == 0) cnt--;

	cout << cnt;


	return 0;
}
