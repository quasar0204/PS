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
const lint LMOD = 100003;
const lint LINF = 987654321987654321;
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, -1, 0, 1 };
const double PI = 3.14159265359;
const int mxn = 10000;

int tc, cnt;
int n;

bool solve(string& str, int length) {
	lint power2 = 1, power3 = 1, power5 = 1;
	lint hash2 = 0, hash3 = 0, hash5 = 0;
	set<pii> s[LMOD];

	for (int i = 0; i <= str.size() - length; i++) {
		if (i == 0) {
			for (int j = 0; j < length; j++) {
				hash2 += str[length - 1 - j] * power2;
				hash2 %= LMOD;
				if (j != length - 1) power2 *= 2;
				power2 %= LMOD;
				hash3 += str[length - 1 - j] * power3;
				hash3 %= LMOD;
				if (j != length - 1) power3 *= 3;
				power3 %= LMOD;
				hash5 += str[length - 1 - j] * power5;
				hash5 %= LMOD;
				if (j != length - 1) power5 *= 5;
				power5 %= LMOD;
			}
		}
		else {
			hash2 = 2 * (hash2 - str[i - 1] * power2) + str[length + i - 1];
			hash3 = 3 * (hash3 - str[i - 1] * power3) + str[length + i - 1];
			hash5 = 5 * (hash5 - str[i - 1] * power5) + str[length + i - 1];
			hash2 %= LMOD;
			hash3 %= LMOD;
			hash5 %= LMOD;
		}
		hash2 = (hash2 + LMOD) % LMOD;
		hash3 = (hash3 + LMOD) % LMOD;
		hash5 = (hash5 + LMOD) % LMOD;
		auto res = s[hash2].insert({ hash3,hash5 });
		if (res.second == false) return true;
	}
	return false;
}

string str;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> n;
	cin >> str;

	int low = 0, high = n - 1;
	int ans = 0;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (solve(str, mid)) {
			ans = mid;
			low = mid + 1;
		}
		else high = mid - 1;
	}

	cout << ans;
	//code end
	return 0;
}