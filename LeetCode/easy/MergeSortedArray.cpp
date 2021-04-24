class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		vector<int> tmp;

		int a, b;
		a = 0; b = 0;
		while (a < m || b < n) {
			if (a == m)
				tmp.push_back(nums2[b++]);
			else if (b == n)
				tmp.push_back(nums1[a++]);
			else {
				if (nums1[a] < nums2[b])
					tmp.push_back(nums1[a++]);
				else
					tmp.push_back(nums2[b++]);
			}
		}

		nums1 = tmp;
	}
};