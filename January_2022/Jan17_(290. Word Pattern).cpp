class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> v;
        
        string w = "";
        for(int i=0; i<s.size(); i++)
        {
            if(s[i] == ' ')
            {
                v.push_back(w);
                w = "";
            }
            else
            {
                w += s[i];
            }
            
            if(i == s.size()-1)
                v.push_back(w);
        }
        
        if(v.size() != pattern.size())
            return 0;
        unordered_map<char, string> mp;
        unordered_set<string> st;
        unordered_set<char> cg;
        
        for(int i=0; i<pattern.size(); i++)
        {
            mp[pattern[i]] = v[i];
            st.insert(v[i]);
            cg.insert(pattern[i]);
        }
        
        if(cg.size() != st.size())
                return 0;
        string cmp = "";
        
        for(int i=0; i<pattern.size(); i++)
        {
            if(i != 0)
                cmp += ' ';
            cmp += mp[pattern[i]];
        }
        
        return (cmp.compare(s) == 0);
    }
};