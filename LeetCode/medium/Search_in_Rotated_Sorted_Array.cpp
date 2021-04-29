class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, rot;
        
        while(l < r) {
            int m = (l + r) / 2;
            
            if (nums[m] > nums[r]) l = m + 1;
            else r = m;
        }
        
        rot = l;
        l = 0, r = nums.size() - 1;
        
        while(l <= r) {
            int m = (l + r) / 2;
            int rm = (m + rot) % (int)(nums.size());
            
            if (nums[rm] == target) return rm;
            else if (nums[rm] < target) l = m + 1;
            else r = m - 1;
        }
        return -1;
    }
};