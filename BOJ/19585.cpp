#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

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
#include <random>
using namespace std;

#define all(v) (v).begin(),(v).end()
using pii = pair<int, int>;
using lint = long long;
using pll = pair<lint, lint>;

const int MOD = 1e9 + 7, INF = 987654321;
const lint LMOD = 1e9 + 9;
const lint LINF = 987654321987654321;
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, -1, 0, 1 };
const double PI = 3.14159265359;
const int mxn = 1001;

int tc, cnt;
int c, n;


set<pll> name[mxn], color[mxn];
set<pll> name2[mxn], color2[mxn];
lint p2[mxn], p3[mxn], p5[mxn],p7[mxn];

lint mod(lint x) {
	if (x < 0) return (x + (-x / LMOD + 1) * LMOD) % LMOD;
	return x % LMOD;
}

pll getHash(string& str, int start, int end) {
	lint h2 = 0, h3 = 0;
	lint pow2 = 1, pow3 = 1;

	for (int i = start; i < end; i++) {
		h2 = mod(h2 + str[i] * pow2);
		pow2 = mod(pow2 * 2);
		h3 = mod(h3 + str[i] * pow3);
		pow3 = mod(pow3 * 3);
	}

	return { mod(h2), mod(h3) };
}

pll getrHash(string& str, int start, int end) {
	lint h2 = 0, h3 = 0;
	lint pow2 = 1, pow3 = 1;

	for (int i = end - 1; i >= start; i--) {
		h2 = mod(h2 + str[i] * pow2);
		pow2 = mod(2 * pow2);
		h3 = mod(h3 + str[i] * pow3);
		pow3 = mod(3 * pow3);
	}

	return { mod(h2), mod(h3) };
}

pll getHash2(string& str, int start, int end) {
	lint h5 = 0, h7 = 0;
	lint pow5 = 1, pow7 = 1;

	for (int i = start; i < end; i++) {
		h5 = mod(h5 + str[i] * pow5);
		pow5 = mod(pow5 * 5);
		h7 = mod(h7 + str[i] * pow7);
		pow7 = mod(pow7 * 7);
	}

	return { mod(h5), mod(h7) };
}

pll getrHash2(string& str, int start, int end) {
	lint h5 = 0, h7 = 0;
	lint pow5 = 1, pow7 = 1;

	for (int i = end - 1; i >= start; i--) {
		h5 = mod(h5 + str[i] * pow5);
		pow5 = mod(pow5 * 5);
		h7 = mod(h7 + str[i] * pow7);
		pow7 = mod(pow7 * 7);
	}

	return { mod(h5), mod(h7) };
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> c >> n;

	p2[0] = p3[0] = p5[0] = p7[0] = 1;
	for (int i = 1; i < mxn; i++) {
		p2[i] = mod(p2[i - 1] * 2);
		p3[i] = mod(p3[i - 1] * 3);
		p5[i] = mod(p5[i - 1] * 5);
		p7[i] = mod(p7[i - 1] * 7);
	}

	string str;
	for (int i = 0; i < c; i++) {
		cin >> str;
		color[str.size()].insert(getHash(str, 0, str.size()));
		color2[str.size()].insert(getHash2(str, 0, str.size()));
	}

	for (int i = 0; i < n; i++) {
		cin >> str;
		name[str.size()].insert(getrHash(str, 0, str.size()));
		name2[str.size()].insert(getrHash2(str, 0, str.size()));
	}

	int q;
	cin >> q;
	while (q--) {
		cin >> str;
		int sz = str.size();
		bool flag = false;
		pll lh, rh;
		pll lh2, rh2;
		bool first = true;
		for (int l = 1; l <= 1000; l++) {
			int r = sz - l;
			if (r < 1) break;
			if (r > 1000) continue;

			if (first) {
				lh = getHash(str, 0, l);
				rh = getrHash(str, l, sz);
				lh2 = getHash2(str, 0, l);
				rh2 = getrHash2(str, l, sz);
				first = false;
			}
			else {
				lh.first = mod(lh.first + str[l - 1] * p2[l - 1]);
				lh.second = mod(lh.second + str[l - 1] * p3[l - 1]);
				rh.first = mod(rh.first - str[l - 1] * p2[r]);
				rh.second = mod(rh.second - str[l - 1] * p3[r]);
				lh2.first = mod(lh2.first + str[l - 1] * p5[l - 1]);
				lh2.second = mod(lh2.second + str[l - 1] * p7[l - 1]);
				rh2.first = mod(rh2.first - str[l - 1] * p5[r]);
				rh2.second = mod(rh2.second - str[l - 1] * p7[r]);
			}

			if (color[l].empty() || name[r].empty() || color[l].find(lh) == color[l].end() ||
				name[r].find(rh) == name[r].end()) continue;
			if (color2[l].empty() || name2[r].empty() || color2[l].find(lh2) == color2[l].end() ||
				name2[r].find(rh2) == name2[r].end()) continue;

			flag = true;
			break;
		}
		if (flag) cout << "Yes\n";
		else cout << "No\n";
	}



	//code end
	return 0;
}