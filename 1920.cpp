#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
long long int arr[100000];

int main() {
	freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	sort(arr, arr + N);

	cin >> M;
	for (int i = 0; i < M; i++) {
		long long int tmp;
		cin >> tmp;
		if (*lower_bound(arr, arr + N, tmp) == tmp)
			cout << 1 << '\n';
		else
			cout << 0 << '\n';
	}

	return 0;
}