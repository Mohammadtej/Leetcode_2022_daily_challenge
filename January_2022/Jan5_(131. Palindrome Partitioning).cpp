class Solution {
public:
    vector<vector<string>> ans;
    vector<string> res;
    int dp[20];
    bool rec(string &s, int st)
    {
        if(st == s.size())
        {
            ans.push_back(res);
            return 1;
        }
        
        bool check, flag = false;
        
        for(int j=st; j<s.size(); j++)
        {
            check = true;
            int l = st, r = j;
            
            while(l < r)
            {
                if(s[l] != s[r])
                {
                    check = false;
                    break;
                }
                l++;
                r--;
            }
            if(check)
            {
                res.push_back(s.substr(st, j-st+1));
                
                if(dp[j+1] != 0)
                    flag |= rec(s, j+1);
                res.pop_back();
            }
        }
        dp[st] = flag;
        return flag;
    }
    vector<vector<string>> partition(string s) {
        memset(dp, -1, sizeof(dp));
        bool c = rec(s, 0);
        return ans;
    }
};