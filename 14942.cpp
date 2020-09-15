#include <bits/stdc++.h>
using namespace std;

int n;
int energy[100001];
int cost[100001];
bool visit[100001];
vector<pair<int,int>> v[100001];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> energy[i];
	for (int i = 0; i < n - 1; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		v[a].push_back({ b,w });
		v[b].push_back({ a,w });
	}

}