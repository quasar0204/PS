#include <bits/stdc++.h>
using namespace std;

queue<int> q;
vector<int> v[101];
bool visit[101];

int main() {
	freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, E;
	int v1, v2;
	int cnt = 0;

	cin >> N >> E;
	for (int i = 0; i < E; i++) {
		cin >> v1 >> v2;
		v[v1].push_back(v2);
		v[v2].push_back(v1);
	}
	q.push(1);
	while (!q.empty()) {
		int idx = q.front();
		q.pop();
		if (visit[idx]) continue;

		visit[idx] = true;

		for (auto x : v[idx]) {
				q.push(x);
		}
	}
	for (int i = 1; i <= N; i++) {
		if (visit[i])
			cnt++;
	}
	cout << cnt - 1;

	return 0;
}