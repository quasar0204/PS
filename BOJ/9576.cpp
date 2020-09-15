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

pii in[1001];
bool visit[1001];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> tc;
	while (tc--) {
		cin >> n >> m;
		cnt = 0;
		for (int i = 1; i <= n; i++)
			visit[i] = false;

		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			in[i] = { b, a };
		}
		sort(in, in + m);
		for (int i = 0; i < m; i++) {
			for (int x = in[i].second; x <= in[i].first; x++) {
				if (!visit[x]) {
					visit[x] = true;
					cnt++;
					break;
				}
			}
		}
		cout << cnt << '\n';
	}


	//code end
	return 0;
}