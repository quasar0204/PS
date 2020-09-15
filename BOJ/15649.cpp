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
int n, k;

vector<int> vec;
int in[9];
bool visit[9];
set <vector<int>> s;

void solve(vector<int>& v, int idx) {
	if (v.size() == k) {
		s.insert(v);
		return;
	}

	for (int i = idx; i <= n; i++) {
		v.push_back(in[i]);
		solve(v, i);
		v.pop_back();
		
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> in[i];
	}
	sort(in + 1, in + n + 1);


	solve(vec, 1);

	for (auto x : s) {
		for (auto a : x) {
			cout << a << ' ';
		}
		cout << '\n';
	}

	//code end
	return 0;
}