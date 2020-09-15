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
const int mxn = 101;

int tc, cnt;
int n;

string str;

lint cal(lint a, char op, lint b) {
	if (op == '+')
		return a + b;
	else if (op == '-')
		return a - b;
	else
		return a * b;
}


lint solve(int idx, lint pre) {
	if (idx == n - 1)
		return cal(pre, str[idx - 1], str[idx] - '0');

	if (idx == n - 3)
		return max(solve(idx + 2, cal(pre, str[idx - 1], str[idx] - '0')),
			cal(pre, str[idx - 1], cal(str[idx] - '0', str[idx + 1], str[idx + 2] - '0')));

	lint next_pre = cal(pre, str[idx-1], cal(str[idx] - '0', str[idx + 1], str[idx + 2] - '0'));
	return max(solve(idx + 2, cal(pre, str[idx - 1], str[idx] - '0')),
		solve(idx+4, next_pre));
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> n;

	cin >> str;
	if (str.length() == 1)
		cout << str;
	else 
		cout << solve(2, str[0] - '0');
	//code end
	return 0;
}