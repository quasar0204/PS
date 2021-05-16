class Solution {
public:
    static bool comp(int A, int B) {
        string a = to_string(A);       
        string b = to_string(B);       

        return a + b > b + a;
    }
    
    string largestNumber(vector<int>& nums) {
        string ret = "";
        
        sort(nums.begin(), nums.end(), comp);
        
        for (auto num : nums)
            ret += to_string(num);
        
        int zero = 0;
        for (auto x : ret) {
            if (x == '0') zero++;
            else break;
        }
        
        if (zero != 0)
            ret = ret.substr(zero - 1, ret.size() - zero + 1);
        
        
        return ret;
    }
};