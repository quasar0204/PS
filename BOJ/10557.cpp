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
#include <cstdlib>
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
string str;
set<int> s;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> tc;
	while (tc--) {
		cin >> str;
		int op = 0;
		int eq = 0;
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == '*' || str[i] == '+') {
				op = i;
				continue;
			}
			if (str[i] == '-' && op == 0 && i != 0) {
				op = i;
				continue;
			}
			if (str[i] == '=') {
				eq = i;
				continue;
			}
		}
		
		int flag = 1;
		for (int k = 0; k <= 9; k++) {
			string l, r;
			string ans;

			int flagzero = 0;
			for (int i = 0; i < op; i++) {
				if (str[i] != '?') {
					l.push_back(str[i]);
					if (str[i] - '0' == k)
						flagzero = 1;
				}
				else {
					if ((i == 0 || (i == 1 && str[i - 1] == '-')) && k == 0 && (op - 1 != 0)) {
						flagzero = 1;
						break;
					}

					l.push_back(k + '0');
				}
			}
			for (int i = op + 1; i < eq; i++) {
				if (str[i] != '?') {
					r.push_back(str[i]);
					if (str[i] - '0' == k)
						flagzero = 1;
				}
				else {
					if ((i == op + 1 || (i == op + 2 && str[i - 1] == '-')) && k == 0 && (eq - op - 1 != 1)) {
						flagzero = 1;
						break;
					}
					r.push_back(k + '0');
				}
			}
			for (int i = eq + 1; i <= str.length(); i++) {
				if (str[i] != '?') {
					ans.push_back(str[i]);
					if (str[i] - '0' == k)
						flagzero = 1;
				}
				else {
					if ((i == eq + 1 || (i == eq + 2 && str[i - 1] == '-')) && k == 0 && (str.length() - eq - 1 != 1)) {
						flagzero = 1;
						break;
					}
					ans.push_back(k + '0');
				}
			}
			if (flagzero) {
				continue;
			}

			if (str[op] == '-') {
				if (stol(l) - stol(r) == stol(ans)) {
					cout << k << '\n';
					flag = 0;
					break;
				}
			} else if (str[op] == '*') {
				if (stol(l) * stol(r) == stol(ans)) {
					cout << k << '\n';
					flag = 0;
					break;
				}
			} else if (str[op] == '+') {
				if (stol(l) + stol(r) == stol(ans)) {
					cout << k << '\n';
					flag = 0;
					break;
				}
			}
		}
		if (flag)
			cout << -1 << '\n';
	}
	//code end
	return 0;
}