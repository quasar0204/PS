class Solution {
public:
	long long h1, h2, n1, n2, p1, p2;

	bool check() {
		return h1 == n1 && h2 == n2;
	}

	int strStr(string haystack, string needle) {
		int hsz = haystack.size();
		int nsz = needle.size();

		if (hsz < nsz) return -1;

		const long long mod = 1e9 + 7;
		h1 = h2 = n1 = n2 = 0;
		p1 = p2 = 1;

		for (int i = 0; i < nsz; i++) {
			if (i != 0) {
				h1 *= 7;
				h2 *= 27;
				n1 *= 7;
				n2 *= 27;
				p1 *= 7;
				p2 *= 27;
			}

			h1 += (haystack[i] - 'a');
			h2 += (haystack[i] - 'a');
			n1 += (needle[i] - 'a');
			n2 += (needle[i] - 'a');

			h1 %= mod;
			h2 %= mod;
			n1 %= mod;
			n2 %= mod;
			p1 %= mod;
			p2 %= mod;
		}

		if (check()) return 0;
		for (int i = 1; i + nsz <= hsz; i++) {

			h1 -= p1 * (haystack[i - 1] - 'a');
			h2 -= p2 * (haystack[i - 1] - 'a');
			h1 *= 7;
			h2 *= 27;
			h1 += (haystack[i + nsz - 1] - 'a');
			h2 += (haystack[i + nsz - 1] - 'a');

			h1 %= mod;
			h2 %= mod;
			h1 += mod;
			h2 += mod;
			h1 %= mod;
			h2 %= mod;

			if (check()) return i;
		}

		return -1;
	}
};