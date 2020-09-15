#include <iostream>
#include <vector>
using namespace std;

vector<int> coin;
int dp[10001];

int main() {
	int n, k;

	cin >> n >> k;

	coin.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}

	dp[0] = 1;

	for (auto c : coin) {
		for (int i = 1; i <= k; i++) {
			if (i - c >= 0)
				dp[i] += dp[i - c];
		}
	}

	cout << dp[k];
	return 0;
}