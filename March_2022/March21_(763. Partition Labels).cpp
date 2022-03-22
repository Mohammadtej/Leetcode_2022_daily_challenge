class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> v(26, -523);
        
        for(int i=0; i<s.size(); i++)
        {           
            v[s[i] - 'a'] = max(v[s[i] - 'a'], i);
        }
        
        vector<int> ans;
        
        for(int i=0; i<s.size();)
        {
            int l = i;
            int r = v[s[i] - 'a'];
            
            for(int j=l; j<=r; j++)
            {
                r = max(r, v[s[j] - 'a']);
            }
            
            ans.push_back(r-l+1);
            i = r + 1;
        }
        
        return ans;
    }
};