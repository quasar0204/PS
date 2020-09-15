#include <bits/stdc++.h>
using namespace std;

long long int N;
long long int Q, m, d;
long long int ans[10];

long long int di(long long int x) {
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
	d /= 10;
	m = N;
	Q = m / d;
	m = m % d;
	
	if (Q > 0) {
		for (int i = 0; i < 10; i++) {
			ans[i] += ((Q - 1)*d*di(d))/10;
		}
	}
	
	for (auto x : ans)
		cout << x << " ";

	return 0;
}