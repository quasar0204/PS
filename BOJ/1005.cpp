#include <bits/stdc++.h>
using namespace std; 

const int MN = 1001; 
int DP[MN], ADJ[MN][MN], D[MN]; 

int solve(int w, int n) { 
	
	if (DP[w] >= 0) return DP[w]; 

	int Max = 0; 
	for (int i = 1; i <= n; ++i) { 
		if (ADJ[w][i] == 1) Max = max(Max, solve(i, n)); 
	} 
	return DP[w] = Max + D[w]; 
} 

int main() { 
	freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t, n, k, w; 

	cin >> t;

	for (int i = 0; i < t; ++i) { 
		cin >> n >> k;
		fill(DP, DP + MN, -1);
		for (int j = 0; j < MN; ++j) 
			for (int k = 0; k < MN; ++k) 
				ADJ[j][k] = 0; 
		for (int j = 1; j <= n; ++j)
			cin >> D[j];
		for (int j = 1, x, y; j <= k; ++j) { 
			cin >> x >> y;
			ADJ[y][x] = 1; 
		} 
		cin >> w;
		cout << solve(w, n) << '\n';
	} 
	return 0; 
}
