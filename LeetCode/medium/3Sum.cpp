class Solution {
public:
    void solve(int idx, vector<int>& nums, vector<vector<int>>& v) {
        int l = idx + 1;
        int r = nums.size() - 1;
        
        while(l < r) {
            if (-nums[idx] < nums[l] + nums[r]) 
                r--;
            
            else if (-nums[idx] > nums[l] + nums[r])
                l++;
            
            else {
                vector<int> tmp = {nums[idx], nums[l], nums[r]};
                v.push_back(tmp);
                
                while(l < r && nums[l] == tmp[1]) l++;

                while(l < r && nums[r] == tmp[2]) r--;
            }
        }
        
    }
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size(); i++) {
            solve(i, nums, ret);
            
            while(i + 1 < nums.size() && nums[i + 1] == nums[i]) i++;
        }
        
        return ret;
    }
};