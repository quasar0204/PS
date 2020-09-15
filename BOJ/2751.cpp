#include <iostream>
#include <algorithm>
using namespace std;

int v[1000001];
int n;

int main() {
	freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> v[i];

	sort(v, v + n);

	for (int i = 0; i < n; i++)
		cout << v[i] << '\n';

	return 0;
}