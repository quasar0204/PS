class Solution {
public:

	int solve(vector<int>& nums, int l, int r) {
		if (l == r) return nums[l];

		int mid = (l + r) / 2;
		int rmax = -987654321, lmax = -987654321, sum = 0;
		int ret = max(solve(nums, l, mid), solve(nums, mid + 1, r));

		for (int i = mid; i >= l; i--) {
			sum += nums[i];
			lmax = max(lmax, sum);
		}

		sum = 0;
		for (int i = mid + 1; i <= r; i++) {
			sum += nums[i];
			rmax = max(rmax, sum);
		}

		return ret = max(ret, lmax + rmax);
	}

	int maxSubArray(vector<int>& nums) {
		int sz = nums.size();

		return solve(nums, 0, sz - 1);
	}
};