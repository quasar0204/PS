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
int wjdtn;
double thtn;
double dp[256];

int pow10(int l) {
	int ret = 1;
	for (int i = 0; i < l; i++) {
		ret *= 10;
	}
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//code start

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < (1 << i); j++) {
			dp[cnt] = (double)j / (1 << i);
			cnt++;
		}
	}
	cin >> tc;
	for (int t = 0; t < tc; t++) {
		string strthtn;
		cin >> strthtn;

		wjdtn = stod(strthtn) / 1;
		thtn = stod(strthtn) - wjdtn;

		int leg = strthtn.length();

		if (strthtn[0] == '.')
			leg -= 1;
		else
			leg -= 2;


		
		
		if (leg <= 0 || thtn == 0.) {
			cout << wjdtn << "\"" << '\n';
			continue;
		}
		else {
			if (wjdtn)
				cout << wjdtn << ' ';

			for (int i = 0; i < 256; i++) {
				string tmp1 = to_string(dp[i]);
				string tmp2;
				for (int k = 0; k < leg + 2; k++) {
					tmp2.push_back(tmp1[k]);
				}
				int itmp1 = stod(tmp2) * pow10(leg+1);
				int ithtn = thtn * pow10(leg + 1);
				if (itmp1 % 10 >= 5) {
					itmp1 = itmp1 / 10 + 1;
				}
				else
					itmp1 /= 10;

				int itmp2 = itmp1 + 1;
				int itmp3 = itmp1;
		

				if (leg == 6) {
					itmp3 -= 1;
				}
				

				if (ithtn % 10 >= 5) {
					ithtn = ithtn / 10 + 1;
				}
				else
					ithtn /= 10;
				if (itmp1 == ithtn || itmp2 == ithtn || itmp3 == ithtn) {
					int low = 2;
					for (; low < 256 && low * 2 <= i; low *= 2);
					cout << (i - low + 1) << '/' << low << '"' << '\n';
					break;
				}
			}
				
		}


	}

	//code end
	return 0;
}