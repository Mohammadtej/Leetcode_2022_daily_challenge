class Solution {
public:
    string simplifyPath(string path) {
        vector<string> v;
        
        for(int i=0; i<path.size(); i++)
        {
            if(path[i] == '/')
                continue;
            string str = "";
            
            while(i<path.size() && path[i] != '/')
                str += path[i++];
            
            if(str == ".")
                continue;
            
            if(str == "..")
            {
                if(v.size() != 0)
                    v.pop_back();
            }
            else
            {
                v.push_back(str);
            }
        }
        
        string ans = "";
        
        for(int i=0; i<v.size(); i++)
            ans += "/", ans += v[i];
        
        if(ans == "")
            ans = "/";
        return ans;
    }
};