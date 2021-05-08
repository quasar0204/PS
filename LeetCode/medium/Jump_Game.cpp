class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size() - 1;
        int last = nums[0];
        
        for (int i = 0; i <= n; i++) {
            if (last < i) break;
            
            last = max(last, i + nums[i]);
        }
        
        return n <= last; 
    }
};