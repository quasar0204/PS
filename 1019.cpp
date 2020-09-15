#include <bits/stdc++.h>
using namespace std;

int N;
int Q, m, d;
int ans[10];

int di(int x) {
	int i;
	for (i = 0; x / 10; i++)
		x /= 10;
	return i;
}

int main() {
	freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	
	for (d = 1; (N / d); d *= 10);
	m = N;
	for (d /= 10; m; d /= 10) {
		Q = m / d;
		m = m % d;

		if (Q > 0) {
			for (int i = 0; i < 10; i++) {
				ans[i] += ((Q - 1)*d*di(d)) / 10;
			}
		}
		else
			continue;

		ans[Q] += m + 1;
		/*
		Q = m / d;
		m = m % d;
		if (Q == 0) {
			ans[Q] -= (d / 10)*di(d);
			continue;
		}
		for (int i = 1; i < Q; i++) {
			ans[i] += d;
		}
		for (int i = 0; i < 10; i++) {
			ans[i] += Q * (d / 10)*di(d);
		}
		*/
	}
	for (auto x : ans)
		cout << x << " ";

	return 0;
}