#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <algorithm>
#include <cmath>
#include<cstring>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <map>
#include <set>
#include <deque>
using namespace std;

#define f(i,n) for(int i=0;i<n;i++)
using pii = pair<int, int>;
using lint = long long;

const int MOD = 1e9 + 7, INF = 987654321;
const int dr[] = { -1,0,1,0 };
const int dc[] = { 0,-1,0,1 };
const double PI = 3.14159265359;

typedef struct {
	int m;
	lint f;
	int w;
} sc;

bool compair(sc m1, sc m2) {
	return m1.m < m2.m;
}

bool compair2(sc m1, sc m2, int i) {
	return m1.m < m2.m + i;
}

int tc, cnt;
int n;
lint arr[2010101];
sc in[2010101];
int m, f, w;
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//
	int i, j;
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> in[i].m >> in[i].f >> in[i].w;

	sort(in, in + n, compair);

	for (i = n - 1; i > -1; i--) {
		j = i + 1;
		while (j <= n && compair2(in[j], in[i], in[i].w))
			j++;
		arr[i] = max(arr[i + 1], arr[j] + in[i].f);
	
	}

	cout << arr[0];
	//
	return 0;
}