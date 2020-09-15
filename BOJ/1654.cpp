#include <bits/stdc++.h>
using namespace std;

long long int length[10000];
long long int K, N;
long long int MAX;

void bs(long long int left, long long int right) {
	long long int count = 0;

	if (left <= right) {
		long long int mid = (left + right) / 2;

		for (int i = 0; i < K; i++) {
			count += length[i] / mid;
		}
		if (count >= N) {
			MAX = max(MAX, mid);
			bs(mid + 1, right);
		}
		else
			bs(left, mid - 1);
	}

}

int main() {
	freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> K >> N;
	for (int i = 0; i < K; i++) {
		cin >> length[i];
	}
	bs(1, *max_element(length, length + K));
	
	cout << MAX;

	return 0;
}