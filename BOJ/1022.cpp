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
const int mxn = 10001;

int tc, cnt;
int num[50][5];
int cr, cc;


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	int r1, c1, r2, c2;
	cin >> r1 >> c1 >> r2 >> c2;

	cr = mxn / 2;
	cc = mxn / 2;


	int nr = cr, nc = cc;
	int n = 0;
	while (cnt < mxn * mxn) {
		++cnt;
		if (nr - cr >= r1 && nr - cr <= r2) {
			if (nc - cc >= c1 && nc - cc <= c2) {
				num[nr - cr - r1][nc - cc - c1] = cnt;
			}
		}
		
		if (nr == cr + n && nc == cc + n) {
			nc++;
			n++;
			continue;
		}

		if (nc == cc + n && nr > cr - n) nr--;
		else if (nr == cr - n && nc > cc - n) nc--;
		else if (nc == cc - n && nr < cc + n) nr++;
		else nc++;
	}
	
	int l = 0;
	for (int r = 0; r <= r2 - r1; r++) 
		for (int c = 0; c <= c2 - c1; c++) 
			l = max(l, num[r][c]);
	
	int L = 0;
	while (l) {
		L++;
		l /= 10;
	}

	for (int r = 0; r <= r2 - r1; r++) {
		for (int c = 0; c <= c2 - c1; c++) {
			int now = num[r][c];
			int leg = 0;
			while (now) {
				now /= 10;
				leg++;
			}
			for (int i = 0; i < L - leg; i++) cout << ' ';
			cout << num[r][c];
			if (c != cc + c2) cout << ' ';
		}
		if (r != cr + r2) cout << '\n';
	}
	//code end
	return 0;
}