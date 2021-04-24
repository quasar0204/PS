class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		string ret = "";

		for (int l = 0; l <= 200; l++) {
			char ch = ' ';
			for (int i = 0; i < strs.size(); i++) {
				if (strs[i].length() <= l) {
					ch = ' ';
					break;
				}

				if (ch == ' ') {
					ch = strs[i][l];
				}
				else {
					if (ch != strs[i][l]) {
						ch = ' ';
						break;
					}
				}
			}

			if (ch == ' ') {
				break;
			}
			ret += ch;
		}
		return ret;
	}
};