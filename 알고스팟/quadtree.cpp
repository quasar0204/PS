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
using namespace std;

#define f(i,n) for(int i=0;i<n;i++)
#define all(v) (v).begin(),(v).end()
using pii = pair<int, int>;
using lint = long long;

const int MOD = 1e9 + 7, INF = 987654321;
const lint LINF = 987654321987654321;
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, -1, 0, 1 };
const double PI = 3.14159265359;

int tc;
int n;

string solve(string& in) {
	vector<string> str;
	string ret;

	int idx = 1;
	int _size = 1;
	int cnt = 0;
	if (in[0] == 'x') {
		while (str.size() < 4) {
			_size = 1;
			cnt = 0;
			for (int j = idx; j < in.length(); j++) {
				cnt++;
				if (in[j] == 'x')
					_size += 4;

				if (cnt == _size)
					break;
			}
			str.push_back(in.substr(idx, _size));
			idx += _size;
		}
		ret = "x" + solve(str[2]) + solve(str[3]) + solve(str[0]) + solve(str[1]);
	}
	else
		ret = in.substr(0, 1);
		
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> tc;
	string in;
	while (tc--) {
		cin >> in;

		cout << solve(in) << '\n';
	}

	//code end
	return 0;
}