class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        vector<vector<int>> tmp(nums.size() + 1);
        vector<int> ret;
        
        for (auto x : nums) cnt[x]++;
        
        for (auto x : cnt) tmp[x.second].push_back(x.first);
    
        reverse(tmp.begin(), tmp.end());
        
        for (auto v : tmp) 
            for (auto x : v) {
                ret.push_back(x);
                
                if (ret.size() == k) return ret;
            }
        
        return ret;
    }
};