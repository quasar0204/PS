#include <bits/stdc++.h>
using namespace std;

int ans[10];

int main() {
	freopen("in.txt", "r", stdin);
	int A, B, C;
	int num;

	cin >> A >> B >> C;
	num = A * B * C;
	
	while (num) {
		ans[num % 10]++;
		num /= 10;
	}
	for (auto pf : ans)
		cout << pf << '\n';

	return 0;
}