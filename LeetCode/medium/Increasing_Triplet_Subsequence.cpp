class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        long long a = 987654321897654321, b = 987654321897654321;
        
        for (auto num : nums) {
            if (num <= a)
                a = num;
            else if (num <= b)
                b = num;
            else
                return true;
        }
        
        return false;
    }
};