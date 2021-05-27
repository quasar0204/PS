class Solution {
public:
    int solve(int idx, vector<int>& dp, vector<int>& nums) {
        if (idx >= nums.size()) return 0;
        
        int &ret = dp[idx];
        
        if (ret != -1) return ret;
        
        return ret = max(solve(idx + 2, dp, nums) + nums[idx], solve(idx + 1, dp, nums));
    }
    
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        
        return solve(0, dp, nums);
    }
};