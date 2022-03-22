class Solution {
public:
    string removeDuplicateLetters(string s) {
        string res = "";
        
        int freq[26];
        
        memset(freq, 0, sizeof(freq));
        
        for(char &ch : s)
        {
            freq[ch - 'a']++;    
        }
        
        vector<int> vis(26, 0);
        
        for(char &ch : s)
        {
            freq[ch - 'a']--;
            
            if(vis[ch - 'a'] == 1)
                continue;
            
            while(res.size() != 0 && res.back() > ch && freq[res.back() - 'a'] != 0)
            {
                vis[res.back() - 'a'] = 0;
                res.pop_back();   
            }
            
            res.push_back(ch);
            vis[ch - 'a'] = 1;
        }
        
        return res;
    }
};