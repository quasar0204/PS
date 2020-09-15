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
int n, m;

pii arr[32001];



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		arr[i].second = i;

	int from, to;
	for (int i = 1; i <= m; i++) {
		cin >> from >> to;
		arr[to].first = max(arr[to].first, arr[from].first) + 1;
	}

	sort(arr + 1, arr + n + 1);

	for (int i = 1; i <= n; i++) {
		cout << arr[i].second << ' ';
	}



	//code end
	return 0;
}