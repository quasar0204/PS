class Solution {
public:
	int mySqrt(int x) {
		int ret = x;

		for (long long i = 1; i * i <= x; i++) {
			ret = i;
		}

		return ret;
	}
};