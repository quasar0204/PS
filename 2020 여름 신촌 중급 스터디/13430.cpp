#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif
#define _USE_MATH_DEFINES

#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <map>
#include <set>
#include <deque>
using namespace std;

#define all(v) (v).begin(),(v).end()
using pii = pair<int, int>;
using lint = long long;
typedef vector<vector<lint>> matrix;

const lint MOD = 1e9 + 7, INF = 987654321;
const lint LINF = 987654321987654321;
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, -1, 0, 1 };
const int mxn = 10000;

int tc, cnt;
lint k, n;

matrix operator * (const matrix &a, const matrix &b) {
	lint size = a.size();
	matrix res(size, vector<lint>(size));
	for (lint i = 0; i < size; i++) {
		for (lint j = 0; j < size; j++) {
			for (lint k = 0; k < size; k++) {
				res[i][j] += a[i][k] * b[k][j] % MOD;
			}
			res[i][j] %= MOD;
		}
	}
	return res;
}

matrix power(matrix a, lint n) {
	lint size = a.size();
	matrix res(size, vector<lint>(size));
	for (lint i = 0; i < size; i++) { // 단위 행렬
		res[i][i] = 1;
	}
	while (n > 0) {
		if (n % 2 == 1) {
			res = res * a;
		}
		n /= 2;
		a = a * a;
	}
	return res;

}

void PrintMatrix(const matrix& a) {
	lint size = a.size();
	for (lint i = 0; i < size; i++) {
		for (lint j = 0; j < size; j++) {
			cout << a[i][j] << " ";
		}
		cout << '\n';
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> k >> n;
	matrix m(k + 2, vector<lint>(k + 2));
	for (int y = 0; y <= k + 1; y++)
		for (int x = 0; x <= y; x++)
			m[y][x] = 1;

	m = power(m, n - 1);

	lint ans = 0;
	for (int i = 0; i <= k + 1; i++) {
		ans = (ans + m[k + 1][i]) % MOD;
	}
	cout << ans;
	//code end
	return 0;
}