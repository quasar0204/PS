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
using pii = pair<int, int>;
using lint = long long;

const int MOD = 1e9 + 7, INF = 987654321;
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, -1, 0, 1 };
const double PI = 3.14159265359;

int tc, cnt;
int n;
string str[100];
int R, C;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start

	cin >> R >> C;

	for (int y = 0; y < R; y++)
		cin >> str[y];

	for (int x = C-1; x >=0; x--) {
		for (int y = 0; y < R; y++) {
			switch (str[y][x]) {
			case '.' :
				cout << '.';
				break;
			case 'O':
				cout << 'O';
				break;
			case '-':
				cout << '|';
				break;
			case '|':
				cout << '-';
				break;
			case '/':
				cout << '\\';
				break;
			case '\\':
				cout << '/';
				break;
			case '^' :
				cout << '<';
				break;
			case '<':
				cout << char(118);
				break;
			case char(118):
				cout << '>';
				break;
			case '>':
				cout << '^';
				break;
			}
		}
		cout << '\n';
	}

	//code end
	return 0;
}