class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int max_to = 0;
        
        for(auto x : trips)
            max_to = max(max_to, x[2]);
        
        vector<int> lazy(max_to + 1, 0);
        
        for(auto x : trips)
            lazy[x[1]] += x[0], lazy[x[2]] -= x[0];
        
        int sum = 0;
        for(int i=0; i<=max_to; i++)
        {
            sum += lazy[i];
            
            if(sum > capacity)
                return 0;
        }
        return 1;
    }
};