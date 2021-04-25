class Solution {
public:
	long long reverse(int x) {
		long long ret = 0;

		while (x) {
			ret *= 10;
			ret += (x % 10);
			x /= 10;
		}

		if (ret < -2147483648LL || ret > 2147483647LL) {
			ret = 0;
		}

		return ret;
	}
};