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
const lint LINF = 9223372036854775807;
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, -1, 0, 1 };
const double PI = 3.14159265359;

int tc, cnt;
int n, m;

class Seg {
	public :
		int leaf = 1;
		vector<pair<lint,int>> tree;

		pair<lint, int> init(const vector<lint >& arr, int left, int right, int node) {
		if (left == right) {
			if (left < arr.size())
				return tree[node] = { arr[left], left + 1 };
			else
				return tree[node] = { LINF, LINF };
		}

		int mid = (left + right) / 2;
		pair<lint, int> leftMin = init(arr, left, mid, node * 2);
		pair<lint, int> rightMin = init(arr, mid+1, right, node * 2 + 1);
		return tree[node] = func(leftMin, rightMin);
		}

		pair<lint, int>  init(const vector<lint>& arr) {
			for (leaf = 1; arr.size() > leaf; leaf <<= 1);
			tree.resize(leaf << 1);
			return init(arr, 0, leaf - 1, 1);
		}

		pair<lint, int>  update(int idx, lint newVal, int node, int nodeLeft, int nodeRight) {
			if (idx < nodeLeft || nodeRight < idx)
				return tree[node];

			if (nodeLeft == nodeRight)
				return tree[node] = { newVal, idx + 1 };

			int mid = (nodeLeft + nodeRight) / 2;

			return tree[node] = func(update(idx, newVal, node * 2, nodeLeft, mid),
				update(idx, newVal, node * 2 + 1, mid + 1, nodeRight));
		}

		pair<lint, int>  update(int idx, int newVal) {
			return update(idx - 1, newVal, 1, 0, leaf - 1);
		}

		pair<lint, int>  query(int left, int right, int node, int nodeLeft, int nodeRight) {
			if (right < nodeLeft || nodeRight < left)
				return { LINF,LINF };

			if (left <= nodeLeft && nodeRight <= right)
				return tree[node];

			int mid = (nodeLeft + nodeRight) / 2;

			return func(query(left, right, node * 2, nodeLeft, mid),
				query(left, right, node * 2 + 1, mid + 1, nodeRight));
		}

		pair<lint, int>  query(int left, int right) {
			return query(left - 1, right - 1, 1, 0, leaf - 1);
		}


		pair<lint, int>  func(pair<lint, int>  a, pair<lint, int>  b) {
			return min(a, b);
		}
};

Seg seg;
vector<lint> arr;

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

	int a;
	lint b, c;
	while (m--) {
		cin >> a >> b >> c;
		if (a == 1) {
			seg.update(b, c);
		}
		else {
			cout << seg.query(b, c).second << '\n';
		}
	}

	//code end
	return 0;
}