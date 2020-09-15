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

const int MOD = 1000000, INF = 987654321;
const lint LINF = 987654321987654321;
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, -1, 0, 1 };
const int mxn = 10000;

int tc, cnt;
lint n;

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
	for (lint i = 0; i < size; i++) {
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

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start

	cin >> n;
	matrix a(2, vector<lint>(1));
	a[1][0] = 1;
	matrix m(2, vector<lint>(2));
	m[0][1] = 1;
	m[1][0] = 1;
	m[1][1] = 1;
	
	matrix ans = power(m, n);

	cout << ans[0][1];

	//code end
	return 0;
}