#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
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
const int mxn = 10000;

int tc, cnt;
int n;
int w;
string str;
stack<char> st;
int cntl, cntb, cnts;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> w;
	getline(cin, str);
	getline(cin, str);

	for (char s : str) {
		if (!(s == 'L' || s == 'B' || s == 'S' || s == ',' || s == '(' || s == ')'
			|| s == '[' || s == ']' || s == ' ')) {
			cout << -1;
			return 0;
		}

		if (s == ' ') {
			if (!st.empty() && (st.top() == 'L' || st.top() == 'B')) {
				cout << -1;
				return 0;
			}
			continue;
		}
	

		if (s == '(' || s == '[') {
			if (st.empty() || !(st.top() == 'L' || st.top() == 'B')) {
				cout << -1;
				return 0;
			}
		}

		if (s == 'L' || s == 'B' || s == 'S') {
			if (!st.empty() && (st.top() == 'S' || st.top() == 'L' || st.top() == 'B')) {
				cout << -1;
				return 0;
			}
		}

		if (s == ')') {
			bool flag = true;
			while (!st.empty()) {
				if (st.top() == '(') {
					st.pop();
					flag = false;
					break;
				}
				st.pop();
			}
			if (flag) {
				cout << -1;
				return 0;
			}
		}

		if (s == ']') {
			bool flag = true;
			while (!st.empty()) {
				if (st.top() == '[') {
					st.pop();
					flag = false;
					break;
				}
				st.pop();
			}
			if (flag) {
				cout << -1;
				return 0;
			}
		}

		if (s == ',') {
			if (st.empty() || st.top() == 'L' || st.top() == 'B' || st.top() == ',') {
				cout << -1;
				return 0;
			}
		}



		if (s == 'L') cntl++;
		if (s == 'S') cnts++;
		if (s == 'B') cntb++;

		st.push(s);
	}

	if (st.top() == ',') {
		cout << -1;
		return 0;
	}

	int v = 2 * cntl + 2 * cntb + cnts;
	int b = cntl;

	cout << v - 1 + cntb + w * b - v + 2;

	//code end
	return 0;
}