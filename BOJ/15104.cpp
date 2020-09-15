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
string str;
bool flag;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0);
	//code start
	cin >> str;

	for (int i = 2; i <= str.length(); i += 2) {
		for (int idx = 0; idx + i < str.length(); idx++) {
			for (int k = 0; k < i / 2; k++) {
				if (str[idx + k] != str[idx + i-1 - k]) {
					break;
				}
				if (k == (i / 2) - 1) {
					flag = true;
				}
			}
			if (flag) {
				cout << "Or not.";
				return 0;
			}
		}
	}
	cout << "Odd.";
	//code end
	return 0;
}