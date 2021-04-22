class Solution {
public:
	int maxArea(vector<int>& height) {
		int l = 0;
		int r = height.size() - 1;
		int ret = r * min(height[l], height[r]);

		while (l < r) {
			if (height[l] < height[r])
				l++;
			else
				r--;

			ret = max(ret, (r - l) * min(height[l], height[r]));
		}

		return ret;
	}
};
