#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
using namespace std;

int n, m;
int arr[1010101];
int cnt;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		if (arr[i] == 1 && arr[i - 1] == 0)
			cnt++;
	}

	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a;
		if (a == 0)
			cout << cnt << '\n';
		else {
			cin >> b;
			if (arr[b] == 1)
				continue;
			else {
				arr[b] = 1;
				if (arr[b - 1] == 1 && arr[b + 1] == 1)
					cnt--;
				else if (arr[b - 1] == 0 && arr[b + 1] == 0)
					cnt++;
			}
		}
	}

	return 0;

}