class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> arr;
        
        for (int num : nums) {
            if (arr.empty() || arr.back() < num)
                arr.push_back(num);
            else {
                auto it = lower_bound(arr.begin(), arr.end(), num);
                *it = num;
            }
        }
        
        return arr.size();
    }
};