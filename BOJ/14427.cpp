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
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, -1, 0, 1 };
const double PI = 3.14159265359;

int tc, cnt;
int n, m;

vector<pii> seg;
int leaf = 1;


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> n;
	while (n > leaf) {
		leaf <<= 1;
	}
	seg.resize(leaf << 1, { INF * 2,INF });

	for (int i = leaf; i < leaf + n; i++) {
		cin >> seg[i].first;
		seg[i].second = i - leaf + 1;
		int idx = i;
		while (idx / 2) {
			idx /= 2;
			seg[idx] = min(seg[2 * idx], seg[2 * idx + 1]);
		}
	}

	cin >> m;
	int a, b, c;
	while (m--) {
		cin >> a;
		if (a == 2) {
			cout << seg[1].second << '\n';
		}
		else {
			cin >> b >> c;
			int idx = b - 1 + leaf;
			seg[idx].first = c;
			while (idx / 2) {
				idx /= 2;
				seg[idx] = min(seg[idx * 2], seg[idx * 2 + 1]);
			}
		}
	}
	
	//code end
	return 0;
}