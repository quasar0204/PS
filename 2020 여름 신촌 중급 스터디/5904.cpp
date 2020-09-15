#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif
#define _USE_MATH_DEFINES

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
const int mxn = 28;

int tc, cnt;
int n;
int arr[mxn + 1];

char solve(int l) {
	if (l == 1)
		return 'm';
	if (l == 2 || l == 3)
		return 'o';

	cnt = 0;
	while (arr[cnt] < l)
		cnt++;

	if (arr[cnt] == l)
		return 'o';

	cnt--;
	if (l == arr[cnt] + 1)
		return 'm';
	if (l - arr[cnt] <= cnt + 4)
		return 'o';

	return solve(l - (arr[cnt] + cnt + 4));
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> n;

	arr[0] = 3;
	for (int i = 1; i <= mxn; i++)
		arr[i] = 2 * arr[i - 1] + (i + 3);

	cout << solve(n);
	//code end
	return 0;
}