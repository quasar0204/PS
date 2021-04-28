class Solution {
public:
    vector<string> nums = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        
        if (digits.size()) {
            ret.push_back("");
            
            for(auto digit: digits) {
                vector<string> tmp;
                for(auto num : nums[digit - '2']) {
                    for(auto s: ret) {
                        tmp.push_back(s + num);
                    }
                }
                ret.swap(tmp);
            }
        }
        
        return ret;
    }
};