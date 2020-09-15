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
int n;
string str[100];
vector<set<int>> adj;
int indeg[27];
int parent[27];
bool finished[27];
int idx;
stack<int> st;
vector<vector<int>> SCC;


int dfs(int x) {
	parent[x] = ++idx;
	st.push(x);

	int ret = parent[x];
	for (int y : adj[x]) {
		if (parent[y] == 0) {
			ret = min(ret, dfs(y));
		}
		else if (!finished[y]) {
			ret = min(ret, parent[y]);
		}
	}
	if (ret == parent[x]) {
		vector<int> scc;
		while (true) {
			int t = st.top();
			st.pop();
			scc.push_back(t);
			finished[t] = true;

			if (t == x) {
				SCC.push_back(scc);
				break;
			}
		}
	}
	return ret;
}

bool real(string& a, string& b) {
	if (a.length() <= b.length())
		return false;
	for (int i = 0; i < b.length(); i++) {
		if (a[i] != b[i])
			return false;
	}
	return true;
}

bool pre(string& a, string& b, int n) {
	string str1 = "", str2 = "";
	for (int i = 0; i < n; i++) 
		str1 += a[i];
	for (int i = 0; i < n; i++)
		str2 += b[i];

	if (str1 == str2)
		return true;

	return false;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> n;
	memset(indeg, -1, sizeof(indeg));

	for (int i = 0; i < n; i++) {
		cin >> str[i];
		cnt = max(cnt, (int)str[i].length());
		for (int idx = 0; idx < str[i].length(); idx++) {
			indeg[str[i][idx] - 'a' + 1] = 0;
		}
	}

	adj.resize(27);
	for (int l = 0; l < cnt; l++) {
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (l >= str[i].length() || l >= str[j].length())
					continue;

				if (real(str[i], str[j])) {
					cout << '!';
					return 0;
				}
				if (str[i][l] == str[j][l])
					continue;

				if (pre(str[i], str[j], l)) {
					if (adj[str[i][l] - 'a' + 1].insert(str[j][l] - 'a' + 1).second) {
						indeg[str[j][l] - 'a' + 1]++;
					}
				}
			}
		}
	}

	int tmp = 0;
	for (int i = 1; i <= 26; i++) {
		if (indeg[i] != -1 && parent[i] == 0) {
			dfs(i);
		}
		if (indeg[i] != -1)
			tmp++;
	}

	if (tmp != SCC.size()) {
		cout << '!';
		return 0;
	}
	

	queue<int> q;

	for (int i = 1; i <= 26; i++) {
		if (indeg[i] == 0) {
			q.push(i);
		}
	}

	if (q.size() >= 2) {
		cout << '?';
		return 0;
	}

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		cout << char(now + 'a' - 1);

		for (int next : adj[now]) {
			indeg[next]--;

			if (indeg[next] == 0) {
				q.push(next);
			}
		}
	}
	//code end
	return 0;
}