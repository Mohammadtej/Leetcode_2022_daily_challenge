class Solution {
public:
    void store_rev(string s, vector<int> &v)
    {
        int n = 0;
        
        for(int i=0; i<s.size(); i++)
        {
            if(s[i] == '.')
            {
                v.push_back(n);
                n = 0;
            }
            else
            {
                n = n * 10 + (s[i] - '0');
            }
        }
        
        v.push_back(n);
    }
    
    void make_equal(vector<int> &v1, vector<int> &v2)
    {
        while(v1.size() < v2.size())
            v1.push_back(0);
        
        while(v1.size() > v2.size())
            v2.push_back(0);
        return;
    }
    
    int compareVersion(string version1, string version2) {
        vector<int> v1, v2;
        
        store_rev(version1, v1);        
        store_rev(version2, v2);
        
        make_equal(v1, v2);
        
        for(int i=0; i<v1.size(); i++)
        {
            if(v1[i] > v2[i])
                return 1;
            if(v1[i] < v2[i])
                return -1;
        }
            
        return 0;
    }
};