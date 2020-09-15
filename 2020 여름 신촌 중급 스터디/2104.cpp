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
using pll = pair<lint, lint>;

const int MOD = 1e9 + 7, INF = 987654321;
const lint LINF = 987654321987654321;
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, -1, 0, 1 };
const int mxn = 100001;
int tc, cnt;
int n;
lint arr[mxn], sum[mxn];


pll solve(int left, int right) {
	if (left > right)
		return { 0, LINF };
	if (left == right)
		return { arr[left], arr[left] };

	int mid = (left + right) / 2;
	pll leftPair = solve(left, mid);
	pll rightPair = solve(mid + 1, right);

	int curLeft = mid;
	int curRight = mid + 1;
	lint curMin = min(arr[curLeft], arr[curRight]);
	pll between = {sum[curRight] - sum[curLeft-1], curMin};

	while (left < curLeft || curRight < right) {
		if ((curLeft != left) && (curRight == right || arr[curLeft - 1] >= arr[curRight + 1])) {
			curLeft--;
			curMin = min(curMin, arr[curLeft]);
			if ((sum[curRight] - sum[curLeft - 1]) * curMin > between.first * between.second)
				between = { sum[curRight] - sum[curLeft - 1], curMin };
		}
		else {
			curRight++;
			curMin = min(curMin, arr[curRight]);
			if ((sum[curRight] - sum[curLeft - 1]) * curMin > between.first * between.second)
				between = { sum[curRight] - sum[curLeft - 1], curMin };
		}
	}

	if (between.first * between.second >= leftPair.first * leftPair.second
		&& between.first * between.second >= rightPair.first * rightPair.second)
		return between;
	else if (between.first * between.second <= leftPair.first * leftPair.second
		&& leftPair.first * leftPair.second >= rightPair.first * rightPair.second)
		return leftPair;
	else
		return rightPair;
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		sum[i] = sum[i - 1] + arr[i];
	}

	pll ans = solve(1, n);
	cout << ans.first * ans.second;

	//code end
	return 0;
}