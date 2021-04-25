class Solution {
public:
	int romanToInt(string s) {
		int ret = 0;

		for (int i = 0; i < s.size(); i++) {
			if ((i + 1 < s.size()) && symbol(s[i]) < symbol(s[i + 1])) {
				ret -= symbol(s[i]);
			}
			else {
				ret += symbol(s[i]);
			}
		}

		return ret;
	}

	int symbol(char ch) {
		if (ch == 'I') return 1;
		if (ch == 'V') return 5;
		if (ch == 'X') return 10;
		if (ch == 'L') return 50;
		if (ch == 'C') return 100;
		if (ch == 'D') return 500;
		return 1000;
	}
};