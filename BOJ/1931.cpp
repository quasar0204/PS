#include <bits/stdc++.h>
using namespace std;

int N;
vector<pair<long long int, long long int>> vp;

int main() {
	freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long int start, finish;
	long long last = 0;
	int cnt = 0;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> start >> finish;
		vp.push_back({ finish,start });
	}
	sort(vp.begin(), vp.end());
	for (auto x : vp) {
		if ( x.second >= last) {
			last = x.first;
			cnt++;
		}
	}
	cout << cnt;

	return 0;
}