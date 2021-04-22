class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> ret;
		int sz = nums.size();

		for (int i = 0; i < sz; i++) {
			bool flag = false;

			for (int j = i + 1; j < sz; j++) {
				if (nums[i] + nums[j] == target) {
					ret.push_back(i);
					ret.push_back(j);
				}
			}

			if (flag) {
				break;
			}
		}

		return ret;
	}
};