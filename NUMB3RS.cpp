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
int n, day, p;
double dp[50][101];

vector<int> adj[50];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> tc;

	while (tc--) {
		cin >> n >> day >> p;
		for (int i = 0; i < n; i++) {
			adj[i].clear();
			fill(dp[i], dp[i] + day + 2, 0.0);
		}

		int tmp;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> tmp;
				if (tmp)
					adj[i].push_back(j);
			}
		}

		for (auto x : adj[p]) {
			dp[x][1] = 1.0 / (int)adj[p].size();
		}

		for (int d = 2; d <= day; d++) {
			for (int i = 0; i < n; i++) {
				if (dp[i][d - 1]) {
					for (auto x : adj[i]) {
						dp[x][d] += (dp[i][d - 1] / (int)adj[i].size());
					}
				}
			}
		}

		int t, q;
		cin >> t;
		cout << fixed;
		cout.precision(11);
		for (int i = 0; i < t; i++) {
			cin >> q;
			cout << dp[q][day] << ' ';
		}

		cout << '\n';
	}

	//code end
	return 0;
}