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

class LazyPropagation {
public:
	int leaf = 1;
	int N;
	vector<lint> tree;
	vector<lint> lazy;


	lint init(const vector<lint>& arr, int left, int right, int node) {
		if (left == right) {
			if (left < arr.size())
				return tree[node] = arr[left];
			else
				return tree[node] = 0;
		}

		int mid = (left + right) / 2;
		lint leftPart = init(arr, left, mid, node * 2);
		lint rightPart = init(arr, mid + 1, right, node * 2 + 1);
		return tree[node] = func(leftPart, rightPart);
	}

	lint init(const vector<lint>& arr) {
		for (leaf = 1; arr.size() > leaf; leaf <<= 1);
		tree.resize(leaf << 1);
		lazy.resize(leaf << 1);
		N = arr.size();
		return init(arr, 0, leaf - 1, 1);
	}

	void update(int left, int right, lint addVal, int node, int nodeLeft, int nodeRight) {
		if (lazy[node] != 0) {
			tree[node] = tree[node] ^ (((nodeRight - nodeLeft + 1) % 2) * lazy[node]);
			if (nodeLeft != nodeRight) {
				lazy[node * 2 + 1] ^= lazy[node];
				lazy[node * 2] ^= lazy[node];
			}
			lazy[node] = 0;
		}

		if (right < nodeLeft || nodeRight < left)
			return;

		if (left <= nodeLeft && nodeRight <= right) {
			tree[node] = tree[node] ^ (((nodeRight - nodeLeft + 1) % 2) * addVal);
			if (nodeLeft != nodeRight) {
				lazy[node * 2 + 1] ^= addVal;
				lazy[node * 2] ^= addVal;
			}
			return;
		}

		int mid = (nodeLeft + nodeRight) / 2;

		update(left, right, addVal, node * 2, nodeLeft, mid);
		update(left, right, addVal, node * 2 + 1, mid + 1, nodeRight);

		tree[node] = func(tree[node * 2],  tree[node * 2 + 1]);
	}

	void update(int left, int right, lint addVal) {
		update(left - 1, right - 1, addVal, 1, 0, leaf - 1);
	}

	lint query(int left, int right, int node, int nodeLeft, int nodeRight) {
		if (lazy[node] != 0) {
			tree[node] = tree[node] ^ (((nodeRight - nodeLeft + 1) % 2) * lazy[node]);
			if (nodeLeft != nodeRight) {
				lazy[node * 2 + 1] ^= lazy[node];
				lazy[node * 2] ^= lazy[node];
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

	lint query(int left, int right) {
		return query(left - 1, right - 1, 1, 0, leaf - 1);
	}

	lint func(lint a, lint b) {
		return a ^ b;
	}
};

vector<lint> arr;
LazyPropagation seg;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> n;
	
	lint tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		arr.push_back(tmp);
	}

	seg.init(arr);

	cin >> m;
	int a, b, c, d;
	while (m--) {
		cin >> a;
		if (a == 1) {
			cin >> b >> c >> d;
			seg.update(b + 1, c + 1, d);
		}
		else {
			cin >> b >> c;
			cout << seg.query(b + 1, c + 1) << '\n';
		}
	}

	//code end
	return 0;
}