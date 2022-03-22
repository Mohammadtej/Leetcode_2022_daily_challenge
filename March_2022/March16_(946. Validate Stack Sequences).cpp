class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        
        vector<int> v;
        
        int j = 0;
        
        for(int i=0; i<pushed.size(); i++)
        {
            v.push_back(pushed[i]);
            if(pushed[i] == popped[0])
            {
                j = i + 1;
                break;
            }
        }
        
        
        for(int i=0; i<popped.size(); i++)
        {
            if(find(v.begin(), v.end(), popped[i]) == v.end())
            {
                for(; j<pushed.size(); j++)
                {
                    v.push_back(pushed[j]);
                    
                    if(pushed[j] == popped[i])
                    {
                        j++;
                        break;
                    }
                }
            }
            
            if(popped[i] != v[v.size()-1])
                return false;
            v.pop_back();
        }
        
        return true;
    }
};