vector<int> adj[mxn];
bool c[mxn];
int d[mxn];
int n, m, s;

bool solve(int x) {
	for (auto w : adj[x]) {
		if (c[w]) continue;
		c[w] = true;

		if (d[w] == 0 || solve(d[w])) {
			d[w] = x;
			return true;
		}
	}
	return false;
}