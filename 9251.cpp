#include <bits/stdc++.h>
using namespace std;

const int MAX = 1001;
string str_a, str_b;
int dp[MAX][MAX];

int main() {
	freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);


	cin >> str_a >> str_b;

	str_a = ' ' + str_a;
	str_b = ' ' + str_b;

	for (int i = 1; i < str_a.size(); i++) {
		for (int j = 1; j < str_b.size(); j++) {
			dp[i][j] = max(max(dp[i - 1][j], dp[i][j - 1]),
				dp[i - 1][j - 1] + (int)(str_a[i] == str_b[j]));
		}
	}
	
	cout << dp[str_a.size()-1][str_b.size()-1];
	return 0;
}