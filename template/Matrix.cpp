typedef vector<vector<lint>> matrix;


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