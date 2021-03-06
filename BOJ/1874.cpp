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

int tc, cnt;
int n;
stack<int> st;
vector<int> ans;
queue<int> q;
string str;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> n;

	int tmp;
	for (int i = 1; i <= n; i++) {
		cin >> tmp;
		q.push(tmp);
	}
	for (int i = 1; i <= n; i++) {
		if (q.empty())
			break;
		st.push(i);
		str += '+';
		while (st.top() == q.front()) {
			str += '-';
			st.pop();
			q.pop();
			if (q.empty() || st.empty())
				break;
		}
	}

	if (st.empty() && q.empty()) {
		for (auto c : str)
			cout << c << '\n';
	}
	else
		cout << "NO";

	//code end
	return 0;
}