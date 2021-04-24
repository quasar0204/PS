class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		int sz = digits.size();
		bool flag = true;
		for (int i = sz - 1; i >= 0; i--) {

			if (!flag) break;

			if (digits[i] != 9) {
				digits[i]++;
				flag = false;
			}
			else {
				digits[i] = 0;
			}
		}

		if (digits[0] == 0) {
			digits.push_back(0);
			for (int i = sz; i > 0; i--) {
				digits[i] = digits[i - 1];
			}
			digits[0] = 1;
		}

		return digits;
	}
};