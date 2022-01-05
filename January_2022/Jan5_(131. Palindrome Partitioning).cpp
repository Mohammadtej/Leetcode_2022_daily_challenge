class Solution {
public:
    vector<vector<string>> ans;
    vector<string> res;

    void rec(string &s, int st)
    {
        if(st == s.size())
        {
            ans.push_back(res);
            return;
        }
        
        bool check;
        
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
                rec(s, j+1);
                res.pop_back();
            }
        }
        
        return;
    }
    vector<vector<string>> partition(string s) {
        rec(s, 0);
        return ans;
    }
};