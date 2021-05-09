class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>>& ans, vector<int>& arr, int idx) {
        if (idx == nums.size()) {
            ans.push_back(arr);
            return;
        }
        
        arr.push_back(nums[idx]);
        solve(nums, ans, arr, idx + 1);
        arr.pop_back();
        solve(nums, ans, arr, idx + 1);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> arr;
        ans.push_back({});
        
        for (int i = 0; i < nums.size(); i++) {
            arr.push_back(nums[i]);
            solve(nums, ans, arr, i + 1);
            arr.pop_back();
        }
        
        return ans;
    }
};