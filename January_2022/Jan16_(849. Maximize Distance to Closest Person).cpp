class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int max_dist = INT_MIN, n = seats.size();
        
        vector<int> filled;
        
        for(int i=0; i<n; i++)
        {
            if(seats[i] == 1)
            {
                filled.push_back(i);
            }
        }
        
        int k = filled.size();
        for(int i=1; i<k; i++)
        {
            max_dist = max(max_dist, (filled[i] - filled[i-1])/2);   
        }
        
        max_dist = max(max_dist, filled[0]);
        max_dist = max(max_dist, n - 1 - filled[k-1]);
        
        return max_dist;
    }
};