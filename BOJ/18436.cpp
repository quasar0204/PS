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

class Seg {
public:
	int leaf = 1;
	vector<int> tree;

	int init(const vector<int >& arr, int left, int right, int node) {
		if (left == right) {
			if (left < arr.size())
				return tree[node] = arr[left] % 2;
			else
				return tree[node] = 0;
		}

		int mid = (left + right) / 2;
		int leftMin = init(arr, left, mid, node * 2);
		int rightMin = init(arr, mid + 1, right, node * 2 + 1);
		return tree[node] = func(leftMin, rightMin);
	}

	int init(const vector<int>& arr) {
		for (leaf = 1; arr.size() > leaf; leaf <<= 1);
		tree.resize(leaf << 1);
		return init(arr, 0, leaf - 1, 1);
	}

	int update(int idx, int newVal, int node, int nodeLeft, int nodeRight) {
		if (idx < nodeLeft || nodeRight < idx)
			return tree[node];

		if (nodeLeft == nodeRight)
			return tree[node] = newVal;

		int mid = (nodeLeft + nodeRight) / 2;

		return tree[node] = func(update(idx, newVal, node * 2, nodeLeft, mid),
			update(idx, newVal, node * 2 + 1, mid + 1, nodeRight));
	}

	int update(int idx, int newVal) {
		return update(idx - 1, newVal, 1, 0, leaf - 1);
	}

	int query(int left, int right, int node, int nodeLeft, int nodeRight) {
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

vector<int> arr;
Seg seg;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> n;
	
	int tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		arr.push_back(tmp);
	}

	seg.init(arr);

	int m;
	cin >> m;
	int a, b, c;
	while (m--) {
		cin >> a >> b >> c;
		if (a == 1) {
			seg.update(b, c % 2);
		}
		else if (a == 2) {
			cout << c-b+1 - seg.query(b, c) << '\n';
		}
		else {
			cout << seg.query(b, c) << '\n';
		}
	}



	//code end
	return 0;
}