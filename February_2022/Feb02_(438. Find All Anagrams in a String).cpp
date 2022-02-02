class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int freq[26] = {0}, freq1[26] = {0};
        vector<int> res;
        int n = s.size(), m = p.size();
        
        if(m > n)
            return res;
        
        for(int i=0; i<m; i++)
        {
            freq[s[i] - 'a']++;
        }
        
        for(int i=0; i<m; i++)
        {
            freq1[p[i] - 'a']++;
        }
        
        bool flag = true;
        for(int i=0; i<26; i++)
        {
            if(freq[i] != freq1[i])
            {
                flag = false;
                break;
            }
        }
        
        if(flag)
        {
            res.push_back(0);
        }
        
        for(int i=m; i<n; i++)
        {
            freq[s[i] - 'a']++;
            freq[s[i-m] - 'a']--;
            
            flag = true;
            
            for(int j=0; j<26; j++)
            {
                if(freq[j] != freq1[j])
                {
                    flag = false;
                    break;
                }
            }
            
            if(flag)
            {
                res.push_back(i-m+1);
            }
        }
        
        return res;
    }
}; 