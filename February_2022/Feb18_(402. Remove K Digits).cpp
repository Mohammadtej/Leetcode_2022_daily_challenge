class Solution {
public:
    string removeKdigits(string num, int k) {
        string res = "";
        
        for(char &c : num)
        {
            while(res.size() > 0 && res.back() > c && k > 0)
                res.pop_back(), k--;
            res.push_back(c);
        }
        
        while(k > 0 && res.size() > 0)
            res.pop_back(), k--;
        
        while(res.front() == '0')
            res.erase(res.begin());
        
        if(res.size() == 0)
            return "0";
        return res;
    }
};