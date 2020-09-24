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
int n, ml, md;
int AL[mxn], BL[mxn], DL[mxn];
int AD[mxn], BD[mxn], DD[mxn];

int dist[mxn];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> n >> ml >> md;

	for (int i = 0; i < ml; i++) 
		cin >> AL[i] >> BL[i] >> DL[i];
	
	for (int i = 0; i < md; i++) 
		cin >> AD[i] >> BD[i] >> DD[i];
	
	fill(dist, dist + n, INF);
	dist[0] = 0;

	for (int k = 0; k < n; k++) {
		for (int i = 0; i + 1 < n; i++) 
			dist[i] = min(dist[i], dist[i + 1]);
		

		for (int i = 0; i < ml; i++) 
			dist[BL[i] - 1] = min(dist[BL[i] - 1], dist[AL[i] - 1] + DL[i]);
		

		for (int i = 0; i < md; i++) 
			dist[AD[i] - 1] = min(dist[AD[i] - 1], dist[BD[i] - 1] - DD[i]);
	}
	int ans = dist[n - 1];

	if (dist[0] < 0)
		ans = -1;
	else if (ans == INF)
		ans = -2;

	cout << ans;


	//code end
	return 0;
}