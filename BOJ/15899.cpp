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

const lint MOD = 1e9 + 7, INF = 987654321;
const lint LINF = 987654321987654321;
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, -1, 0, 1 };
const double PI = 3.14159265359;

class Seg {
public:
	int leaf = 1;
	vector<vector<int>> tree;

	vector<int> init(const vector<int >& arr, int left, int right, int node) {
		if (left == right) {
			if (left < arr.size()) {
				tree[node].push_back(arr[left]);
			}
			return tree[node];
		}

		int mid = (left + right) / 2;
		vector<int> leftPart = init(arr, left, mid, node * 2);
		vector<int> rightPart = init(arr, mid + 1, right, node * 2 + 1);
		tree[node].resize(leftPart.size() + rightPart.size());
		func(leftPart, rightPart, tree[node]);
		return tree[node];
	}

	vector<int> init(const vector<int>& arr) {
		for (leaf = 1; arr.size() > leaf; leaf <<= 1);
		tree.resize(leaf << 1);
		return init(arr, 0, leaf - 1, 1);
	}

	vector<int> query(int left, int right, int node, int nodeLeft, int nodeRight) {
		vector<int> ret;
		if (right < nodeLeft || nodeRight < left)
			return ret;

		if (left <= nodeLeft && nodeRight <= right)
			return tree[node];

		int mid = (nodeLeft + nodeRight) / 2;
		vector<int> leftPart = query(left, right, node * 2, nodeLeft, mid);
		vector<int> rightPart = query(left, right, node * 2 + 1, mid + 1, nodeRight);

		ret.resize(leftPart.size() + rightPart.size());
		func(leftPart, rightPart, ret);

		return ret;
	}

	lint query(int left, int right, int c) {
		vector<int> tmp = query(left - 1, right - 1, 1, 0, leaf - 1);
		return upper_bound(all(tmp), c) - tmp.begin();
	}

	void func(vector<int>& a, vector<int>& b, vector<int>& result) {
		merge(all(a), all(b), result.begin());
	}
};

int tc, cnt;
int n, m, c;
vector<vector<int>> adj;
vector<int> arr;
int color[200001];
int IDX[200001];
int _size[200001];
lint ans;
int id;
bool visit[200001];
Seg seg;

void dfs(int x) {
	visit[x] = true;
	IDX[x] = ++id;
	int start = id;

	for (auto next : adj[x]) {
		if (!visit[next]) {
			dfs(next);
		}
	}
	_size[x] = id - start;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> n >> m >> c;

	for (int i = 1; i <= n; i++) 
		cin >> color[i];
	
	adj.resize(n + 1);
	int a, b;
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs(1);

	arr.resize(n);
	for (int i = 1; i <= n; i++) {
		arr[IDX[i] - 1] = color[i];
	}

	seg.init(arr);

	while (m--) {
		cin >> a >> b;
		ans = (ans + seg.query(IDX[a], IDX[a] + _size[a], b)) % MOD;
	}

	cout << ans;

	//code end
	return 0;
}