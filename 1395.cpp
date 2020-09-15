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
vector<int> arr;

class LazyPropagation {
public:
	int leaf = 1;
	int N;
	vector<int> tree;
	vector<int> lazy;


	int init(const vector<int>& arr, int left, int right, int node) {
		if (left == right) {
			if (left < arr.size())
				return tree[node] = arr[left];
			else
				return tree[node] = 0;
		}

		int mid = (left + right) / 2;
		lint leftSum = init(arr, left, mid, node * 2);
		lint rightSum = init(arr, mid + 1, right, node * 2 + 1);
		return tree[node] = func(leftSum, rightSum);
	}

	int init(const vector<int>& arr) {
		for (leaf = 1; arr.size() > leaf; leaf <<= 1);
		tree.resize(leaf << 1);
		lazy.resize(leaf << 1);
		N = arr.size();
		return init(arr, 0, leaf - 1, 1);
	}

	void update(int left, int right, int addVal, int node, int nodeLeft, int nodeRight) {
		if (lazy[node] != 0) {
			tree[node] = (nodeRight - nodeLeft + 1) - tree[node];
			if (nodeLeft != nodeRight) {
				lazy[node * 2 + 1] ^= 1;
				lazy[node * 2] ^= 1;
			}
			lazy[node] = 0;
		}

		if (right < nodeLeft || nodeRight < left)
			return;

		if (left <= nodeLeft && nodeRight <= right) {
			tree[node] = (nodeRight - nodeLeft + 1) - tree[node];
			if (nodeLeft != nodeRight) {
				lazy[node * 2 + 1] ^= 1;
				lazy[node * 2] ^= 1;
			}
			return;
		}

		int mid = (nodeLeft + nodeRight) / 2;

		update(left, right, addVal, node * 2, nodeLeft, mid);
		update(left, right, addVal, node * 2 + 1, mid + 1, nodeRight);

		tree[node] = func(tree[node * 2], tree[node * 2 + 1]);
	}

	void update(int left, int right, int addVal) {
		update(left - 1, right - 1, addVal, 1, 0, leaf - 1);
	}

	int query(int left, int right, int node, int nodeLeft, int nodeRight) {
		if (lazy[node] != 0) {
			tree[node] = (nodeRight - nodeLeft + 1) - tree[node];
			if (nodeLeft != nodeRight) {
				lazy[node * 2 + 1] ^= 1;
				lazy[node * 2] ^= 1;
			}
			lazy[node] = 0;
		}

		if (right < nodeLeft || nodeRight < left)
			return 0;

		if (left <= nodeLeft && nodeRight <= right)
			return tree[node];

		int mid = (nodeLeft + nodeRight) / 2;

		return func(query(left, right, node * 2, nodeLeft, mid),
			query(left, right, node * 2 + 1, mid + 1, nodeRight));
	}

	int query(int left, int right) {
		return query(left - 1, right - 1, 1, 0, leaf - 1);
	}

	int func(int a, int b) {
		return a + b;
	}
};

LazyPropagation seg;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> n >> m;

	arr.resize(n);
	seg.init(arr);

	int a, b, c;
	while (m--) {
		cin >> a >> b >> c;
		if (a == 0) {
			seg.update(b, c, 1);
		}
		else {
			cout << seg.query(b, c) << '\n';
		}
	}


	//code end
	return 0;
}