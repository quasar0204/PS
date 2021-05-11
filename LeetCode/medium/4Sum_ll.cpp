class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> m;
        int ret = 0;
        
        for (auto x : nums1)
            for (auto y : nums2)
                m[x + y]++;
        
        for (auto z : nums3)
            for (auto w : nums4)
                ret += m[-z - w];
                
        return ret;
    }
};