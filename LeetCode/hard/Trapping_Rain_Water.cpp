class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int lmxn = 0, rmxn = 0;
        int ret = 0;
        
        while(l <= r) {
            if (height[l] < height[r]) {
                if (lmxn < height[l]) lmxn = height[l++];
                else ret += lmxn - height[l++];
            }
            else {
                if (rmxn < height[r]) rmxn = height[r--];
                else ret += rmxn - height[r--];
            }
        }
        
        return ret;
    }
};