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
#include <random>
using namespace std;

#define all(v) (v).begin(),(v).end()
using pii = pair<int, int>;
using lint = long long;
using pll = pair<lint, lint>;

const int MOD = 1e9 + 7, INF = 987654321;
const lint LMOD = 1e9 + 7;
const lint LINF = 987654321987654321;
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, -1, 0, 1 };
const double PI = 3.14159265359;
const int mxn = 10000;

vector<int> failure(string& pattern) {
	int patternSize = pattern.size();
	vector<int> table(patternSize, 0);
	int j = 0;
	for (int i = 1; i < patternSize; i++) {
		while (j > 0 && pattern[i] != pattern[j]) {
			j = table[j - 1];
		}
		if (pattern[i] == pattern[j]) {
			table[i] = ++j;
		}
	}
	return table;
}

int kmp(string& parent, string& pattern) {
	vector<int> table = failure(pattern);
	int parentSize = parent.size();
	int patternSize = pattern.size();
	int j = 0;
	int ret = 0;

	for (int i = 0; i < parentSize; i++) {
		while (j > 0 && parent[i] != pattern[j]) {
			j = table[j - 1];
		}
		if (parent[i] == pattern[j]) {
			if (j == patternSize - 1) {
				ret++;
				j = table[j];
			}
			else
				j++;
		}
	}
	return ret;
}

int tc, cnt;
int n;
string A, W, S;


int idx(char c) {
	int sz = A.size();
	for (int i = 0; i < sz; i++)
		if (A[i] == c) return (i + 1) % sz;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> tc;
	while (tc--) {
		cin >> A >> W >> S;
		vector<int> ans;
		if (kmp(S, W) == 1) ans.push_back(0);
		for (int i = 1; i < A.size(); i++) {
			for (int j = 0; j < W.size(); j++) W[j] = A[idx(W[j])];
			if (kmp(S, W) == 1) ans.push_back(i);
		}
		
		if (ans.size() == 0) cout << "no solution\n";
		else if (ans.size() == 1) cout << "unique: " << ans[0] << '\n';
		else {
			cout << "ambiguous: ";
			for (auto x : ans) cout << x << ' ';
			cout << '\n';
		}
		
	}

	//code end
	return 0;
}