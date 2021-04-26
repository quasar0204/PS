class Solution {
public:
	int ch(char c) {
		if (c == '(') return 1;
		if (c == '{') return 2;
		if (c == '[') return 3;
		if (c == ')') return -1;
		if (c == '}') return -2;
		return -3;
	}

	bool isValid(string str) {
		stack<char> st;

		for (auto s : str) {
			if (ch(s) > 0) {
				st.push(s);
			}
			else {
				if (st.empty() || (ch(st.top()) + ch(s) != 0)) {
					return false;
				}
				st.pop();
			}
		}

		return st.empty();
	}
};