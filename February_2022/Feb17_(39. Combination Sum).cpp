class Solution {
public:
    vector<vector<int>> res;
    vector<int> v;
    
    void rec(vector<int> &c, int k, int i)
    {
        if(i == 0 || k == 0)
        {
            if(k == 0)
                res.push_back(v);
            return;
        }
        
        if(c[i-1] <= k)
        {
            v.push_back(c[i-1]);
            rec(c, k - c[i-1], i);
            v.pop_back();
        }
        
        rec(c, k, i-1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        res.clear();
        sort(begin(candidates), end(candidates));
        rec(candidates, target, candidates.size());
        return res;
    }
};