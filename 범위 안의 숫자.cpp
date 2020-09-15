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

#define all(v) (v).begin(),(v).end()
using pii = pair<int, int>;
using lint = long long;

const int MOD = 1e9 + 7, INF = 987654321;
const lint LINF = 987654321987654321;
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, -1, 0, 1 };
const int mxn = 50000;
vector<int> arr;
//vector<int> IDX;
int tc, cnt;
int n, k, m;
string str;
string sub;

class FenwickTree {
public:
	vector<int> tree;

	void init(vector<int>& arr) {
		tree.resize((int)pow(10, k) + 2);

		for (int i = 0; i < arr.size(); i++)
			add(arr[i], 1);
	}

	int sum(int pos) {
		int ret = 0;

		while (pos > 0) {
			ret += tree[pos];
			pos &= (pos - 1);
		}
		return ret;
	}

	void add(int pos, int val) {
		while (pos < tree.size()) {
			tree[pos] += val;
			pos += (pos & -pos);
		}
	}
};

FenwickTree fw;



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> tc;

	for (int c = 1; c <= tc; c++) {
		//IDX.clear();
		int _max = 0;
		cout << "Case #" << c << '\n';
		cin >> n >> k >> m;
		cin >> str;

		arr.resize(str.length() - k + 1);
		for (int i = 0; i < str.length() - k + 1; i++) {
			arr[i] = stoi(str.substr(i, k));
		}

		fw.init(arr);

		for (int i = 0; i < arr.size(); i++) {
			_max = max(_max, fw.sum(arr[i] + m + 1) - fw.sum(arr[i]));
		}

		cout << _max + 1 << '\n';
	}

	return 0;
}