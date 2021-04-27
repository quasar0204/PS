class Solution {
public:
    int myAtoi(string s) {
        stringstream ss;
        string ps, pss;
        bool flag = false;
        ss.str(s);
        
        ss >> ps;
        for (int i = 0; i < ps.size(); i++) {
            char x = ps[i];
            if (('0' <= x && x <= '9') || (i == 0 && ((x == '-') || (x == '+')))) {
                if ('1' <= x && x <= '9') {
                    flag = true;
                }
                if (flag) {
                    pss.push_back(x);
                }
                else {
                    if (x != '0') {
                        pss.push_back(x);
                    }
                }
                continue;
            }
            
            break;
        }
        if (pss.size() > 13) pss = pss.substr(0, 13);
        if (pss.size() == 0 || pss == "+" || pss == "-") pss = "0";
        
        long long num = stol(pss);
        
        if (num < -2147483648)
            num = -2147483648;
        if (num > 2147483647)
            num = 2147483647;
        
        return num;
    }
};