class Solution {
public:
    vector<vector<int>> res;
    vector<int> set;
    void rec(vector<int> &v, int n)
    {
        if(n == 0)
        {
            res.push_back(set);
            return;
        }
        
        set.push_back(v[n-1]);
        rec(v, n-1);
        set.pop_back();
        
        rec(v, n-1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        rec(nums, nums.size());
        
        return res;
    }
};