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
int n, k;
vector<int> arr[101];
int in[101];
int tab[101];

void solve(int x, int idx) {

	for (int i = 1; i <= n; i++) {
		if (tab[i] == x)
			return;
	}

	for (int i = 1; i <= n; i++) {
		if (tab[i] == 0) {
			tab[i] = x;
			return;
		}
	}

	int change_idx = 1;
	int last_use = 0;
	for (int i = 1; i <= n; i++) {
		for (auto a : arr[tab[i]]) {
			if (a > idx) {
				if (last_use < a) {
					last_use = a;
					change_idx = i;
				}
				break;
			}
		}
	}

	tab[change_idx] = x;
	cnt++;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> n >> k;
	
	for (int i = 1; i <= k; i++) {
		cin >> in[i];
		arr[in[i]].push_back(i);
	}
	
	for (int i = 1; i <= k; i++) {
		arr[i].push_back(INF);
	}

	for (int i = 1; i <= k; i++) {
		solve(in[i], i);
	}

	cout << cnt;
	//code end
	return 0;
}