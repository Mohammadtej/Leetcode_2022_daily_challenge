class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        vector<pair<int, int>> v;
        
        for(auto x : points)
            v.emplace_back(x[1], x[0]);
        
        sort(v.begin(), v.end());
        
        int arrows = 1;
        int end = v[0].first;
        
        for(int i=1; i<v.size(); i++)
        {
            if(v[i].second <= end)
            {
                
            }
            else
            {
                arrows++;
                end = v[i].first;
            }
        }
        
        return arrows;
    }
};