class Solution {
public:
 
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> dict;
        
        for(string x : wordList)
            dict.insert(x);
        
        if(dict.find(endWord) == dict.end())
            return 0;
        
        queue<string> q;
        
        q.push(beginWord);
        
        if(dict.find(beginWord) != dict.end())
        {
            dict.erase(beginWord);
        }
        int sz;
        
        int level = 1;
        while(!q.empty())
        {
            sz = q.size();
            
            while(sz--)
            {
                string s = q.front();
                q.pop();
                
                string t = s;
                
                for(int i=0; i<s.size(); i++)
                {
                    for(char j='a'; j <= 'z'; j++)
                    {
                        t[i] = j;
                        
                        if(dict.find(t) != dict.end())
                        {
                            dict.erase(dict.find(t));
                            q.push(t);
                            
                            if(t == endWord)
                                return (level + 1);
                        }
                    }
                    t[i] = s[i];
                }
            }
            
            level++;
        }
    
        return 0;
    }
};