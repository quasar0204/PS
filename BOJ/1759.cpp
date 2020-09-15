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

int tc, cnt;
int L, C;
vector<char> ch;

void solve(vector<char>& c, int ja, int mo, int idx) {
	if (ja + mo == L) {
		if (ja >= 2 && mo >= 1) {
			for (auto x : c)
				cout << x;
			cout << '\n';
			return;
		}
		else
			return;
	}

	if (idx >= C)
		return;

	if (ch[idx] == 'a' || ch[idx] == 'e' || ch[idx] == 'i' ||
		ch[idx] == 'o' || ch[idx] == 'u') {
		c.push_back(ch[idx]);
		solve(c, ja, mo + 1, idx + 1);
		c.pop_back();
		solve(c, ja, mo, idx + 1);
	}
	else {
		c.push_back(ch[idx]);
		solve(c, ja + 1, mo, idx + 1);
		c.pop_back();
		solve(c, ja, mo, idx + 1);
	}

}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> L >> C;

	char tmp;
	for (int i = 0; i < C; i++) {
		cin >> tmp;
		ch.push_back(tmp);
	}
	sort(all(ch));
	vector<char> t;

	solve(t, 0, 0, 0);

	//code end
	return 0;
}