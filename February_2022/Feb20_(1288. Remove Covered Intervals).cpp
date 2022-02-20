class Solution {
public:
    static bool cmp(pair<int, int> &p1, pair<int, int> &p2)
    {
        if(p1.first != p2.first)
            return p1.first < p2.first;
        return p1.second > p2.second;
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        vector<pair<int, int>> v;
        
        for(auto x : intervals)
        {
            v.push_back({x[0], x[1]});
        }
        
        sort(v.begin(), v.end(), cmp);
        
        int res = intervals.size();
        
        set<int> st;
        
        st.insert(v[0].second);
        
        for(int i=1; i<v.size(); i++)
        {
            if(v[i].second <= *prev(st.end(), 1))
                res--;
            st.insert(v[i].second);
        }
        
        return res;
    }
};