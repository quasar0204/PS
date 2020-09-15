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
int n, k;
const int mxn = 5000;
vector<int> adj[2*mxn+1];
int c[2*mxn + 1][2*mxn + 1], f[2*mxn + 1][2*mxn + 1], visit[2*mxn + 1];
vector<vector<int>> ans;

void maxFlow(int start, int end) {
	while (true) {
		queue<int> q;
		q.push(start);
		fill(visit, visit + 2 * mxn + 1, -1);
		
		while (!q.empty()) {
			int now = q.front();
			q.pop();

			for (int next : adj[now]) {
				if (visit[next] == -1 && c[now][next] - f[now][next] > 0) {
					q.push(next);
					visit[next] = now;
					
					if (next == end)
						break;
				}
			}
		}


		if (visit[end] == -1)
			break;

		int flow = INF;
		for (int i = end; i != start; i = visit[i]) {
			flow = min(flow, c[visit[i]][i] - f[visit[i]][i]);
		}
		vector<int> v;
		int cnt = 1;
		for (int i = end; i != start; i = visit[i]) {
			f[visit[i]][i] += flow;
			f[i][visit[i]] -= flow;
			if (flow > 0 && cnt++ % 2)
				v.push_back((i+1)/2);
		}
		if (v.size()) {
			v.push_back((start + 1) / 2);
			reverse(all(v));
			ans.push_back(v);
		}

		if (ans.size() >= k)
			return;

	}
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	
	string str;

	while (true) {
		cin >> k >> n;
		if (n == 0 && k == 0)
			break;

		cout << "Case " << ++tc << ":\n";

		for (int i = 1; i <= 2*n; i++)
			adj[i].clear();
		memset(c, 0, sizeof(c));
		memset(f, 0, sizeof(f));
		ans.clear();

		for (int i = 1; i <= n; i++) {
			adj[2 * i - 1].push_back(2 * i);
			adj[2 * i].push_back(2 * i - 1);
			c[2 * i - 1][2 * i] = 1;
		}

		getline(cin, str);
		for (int i = 1; i <= n; i++) {
			getline(cin, str);
			int _front = 0;
			for (int idx = 0; idx < str.length(); idx++) {
				if (str[idx] == ' ' || idx == str.length() -1) {
					string tmp = str.substr(_front, max(idx - _front,1));
					int itmp = stoi(tmp);
					adj[2*i].push_back(2*itmp-1);
					adj[2*itmp-1].push_back(2*i);
					c[2 * i][2 * itmp - 1] = 1;
					
					adj[itmp * 2].push_back(2 * i - 1);
					adj[2 * i - 1].push_back(itmp * 2);
					c[itmp * 2][2 * i - 1] = 1;
					_front = idx + 1;
				}
			}
		}

		maxFlow(2, 3);

		if (ans.size() >= k) {
			for (int i = 0; i < k; i++) {
				for (auto x : ans[i]) {
					cout << x << ' ';
				}
				cout << '\n';
			}
		}
		else {
			cout << "Impossible\n";
		}


	}

	//code end
	return 0;
}