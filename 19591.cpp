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

#define f(i,n) for(int i=0;i<n;i++)
#define all(v) (v).begin(),(v).end()
using pii = pair<int, int>;
using lint = long long;

const int MOD = 1e9 + 7, INF = 987654321;
const lint LINF = 987654321987654321;
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, -1, 0, 1 };

int tc, cnt;
int n;
string str;
vector<char> op;
vector<lint> num;

int opl, opr;
lint numl, numr;
int npl, npr;

int getPriority(char oper) {
	if (oper == '*' || oper == '/')
		return 2;

	return 1;
}

lint cal(lint left, char oper, lint right) {
	if (oper == '+')
		return left + right;

	if (oper == '-')
		return left - right;

	if (oper == '*')
		return left * right;

	return left / right;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start
	cin >> str;

	int idx = 0;
	string tmp;
	size_t sz;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') {
			if (i == 0)
				continue;
			op.push_back(str[i]);
			sz = i - idx;
			tmp = str.substr(idx, i - idx);
			num.push_back(stoll(tmp, &sz, 10));
			idx = i + 1;
		}
	}
	tmp = str.substr(idx, str.length() - idx);
	sz = str.length() - idx;
	num.push_back(stoll(tmp, &sz, 10));

	if (op.size() == 0) {
		cout << num[0];
		return 0;
	}

	opr = op.size() - 1;
	npr = num.size() - 1;
	npl = 1;
	numl = num[0];
	numr = num[npr--];
	
	while (opr > opl) {
		if (getPriority(op[opl]) > getPriority(op[opr])) {
			numl = cal(numl, op[opl], num[npl]);
			npl++;
			opl++;
		}
		else if ((getPriority(op[opl]) == getPriority(op[opr])) &&
			(cal(numl, op[opl], num[npl]) >= cal(num[npr], op[opr], numr))) {
			numl = cal(numl, op[opl], num[npl]);
			npl++;
			opl++;
		}
		else {
			numr = cal(num[npr], op[opr], numr);
			npr--;
			opr--;
		}
	}

	cout << cal(numl, op[opl], numr);

	//code end
	return 0;
}