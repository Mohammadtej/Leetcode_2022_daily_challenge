class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        
        if(n == 0 || n == 1)
            return 0;
        map<int, set<int>> mp;
        vector<int> vis(n, 0);
        
        for(int i=0; i<n; i++)
        {
            mp[arr[i]].insert(i);
        }
        
        queue<int> q;
        q.push(0);
        vis[0] = 1;
        
    
        
        int level = 0;
        while(!q.empty())
        {
            int sz = q.size();
            
            while(sz--)
            {
                int curr = q.front();
                q.pop();
                
                if(curr+1 < n && !vis[curr+1]){
                    q.push(curr+1), vis[curr+1] = 1;
                    
                    if(curr + 1 == n-1)
                        return level + 1;
                }
                if(curr-1 >= 0 && !vis[curr-1]){
                    q.push(curr-1), vis[curr-1] = 1;
                    
                    if(curr - 1 == n-1)
                        return level + 1;
                }
                
                for(int x : mp[arr[curr]])
                {
                    if(!vis[x])
                    {
                        if(x == n-1)
                            return level + 1;
                        q.push(x);
                        vis[x] = 1;
                        mp[arr[curr]].erase(mp[arr[curr]].find(x));
                    }
                }
            }
            
            level++;
        }
        
        return level;
    }
};