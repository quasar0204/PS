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
const int mxn = 101;

int tc, cnt;
int n;
string str;
int last[26];

bool check(string& s) {
	memset(last, -1, sizeof(last));

	for (int i = 0; i < s.size(); i++) {
		if (last[s[i] - 'a'] == -1) last[s[i] - 'a'] = i;
		else {
			if (last[s[i] - 'a'] - i != -1) return false;
			else last[s[i] - 'a'] = i;
		}
	}
	return true;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str;
		if (check(str)) cnt++;
	}

	cout << cnt;

	//code end
	return 0;
}